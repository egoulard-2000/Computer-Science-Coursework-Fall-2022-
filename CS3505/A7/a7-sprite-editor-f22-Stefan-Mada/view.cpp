/*
// File name: view.cpp
// Author:    Stefan, Michael, Soli, Allen, and Emile
// Assignment:Sprite Editor
// Group:     AKPSE
// Date:      11/15/2022
// Course:    CS 3505, University of Utah, School of Computing
// Copyright: CS 3505 and AKPSE - This work may not be copied for use in Academic Coursework.
//
// Our group, AKPSE, certifies that we wrote this code from scratch and did not copy it in part or whole from
// another source.
//
// File Contents
//
//      This is the source file that controls the view side of the project, updating the images on the screen
//      as well as taking in user input to send to the model.
*/


#include "view.h"
#include "./ui_view.h"
#include "graphicsdrawview.h"
#include "model.h"


///
/// \brief  Constructor for the view class, makes all necessary connections with
///         model and UI.
/// \param  model to connect to for logic
/// \param  parent widget to be attached to
///
View::View(Model& model, QWidget* parent) : QMainWindow(parent), ui(new Ui::View)
{
    ui->setupUi(this);

    // Set initial cursor icon to pen
    QCursor penCursor = QCursor(QPixmap(":/images/pen_icon.png"));
    ui->canvasGraphicsView->setCursor(penCursor);

    // when the model says there's an update, the view updates
    connect(&model, &Model::updateCanvas, this, &View::updateCanvas);

    connect(&model, &Model::updateCanvas, &preview, &PreviewWindow::updateCanvas);

    // when the (temporary) next frame button is pushed, requests next frame
    connect(ui->tempNextFrameButton, &QPushButton::clicked, &model, &Model::requestedNextFrame);

    // when the (temporary) previous frame button is pushed, requests prev frame
    connect(ui->tempPrevFrameButton, &QPushButton::clicked, &model, &Model::requestedPreviousFrame);

    connect(this, &View::getNextFrame, &model, &Model::requestedNextFrame);

    connect(this, &View::getPreviousFrame, &model, &Model::requestedPreviousFrame);

    connect(this, &View::getCurrentFrame, &model, &Model::requestedFrameChange);

    // connect the changeWorkingFrame signals and slots
    connect(this, &View::changeWorkingFrame, &model, &Model::requestedFrameChange);

    // connect graphicsDrawView's getPosition (for a mouse click on the canvas) to the view's slot which will add frame
    // information
    connect(ui->canvasGraphicsView, &GraphicsDrawView::getMouseImagePosition, this, &View::getToolPos);

    // Now connects add and remove frame buttons:
    connect(ui->addFrameButton, &QPushButton::clicked, &model, &Model::addFrame);

    // Handles UI to delete frame on right animation bar
    connect(ui->removeFrameButton, &QPushButton::clicked, this, &View::deleteFrameButton);

    // Handles model to remove a frame from the model
    connect(ui->removeFrameButton, &QPushButton::clicked, &model, &Model::removeFrame);

    connect(this, &View::swapFrames, &model, &Model::swapFrames);

    // Now connect the animation button to the model
    connect(ui->mainRunButton, &QPushButton::clicked, &model, &Model::toggleAnimationPlayback);

    connect(ui->popoutButton, &QPushButton::clicked, this, &View::showPreviewWindow);

    connect(ui->gridButton, &QRadioButton::toggled, this, &View::showGrid);

    // Connect the FPS slider to the textbox next to it
    // The lambda simply converts the fpsSlider's integer value to a QString,
    // before the label applies setText
    connect(ui->fpsSlider, &QSlider::valueChanged, ui->fpsNumber,
            [this](int num) { ui->fpsNumber->setText(QString::number(num)); });

    // Connect the FPS slider to the Model's updateFPS slot
    connect(ui->fpsSlider, &QSlider::valueChanged, &model, &Model::updateFPS);

    // Tool Button Connections
    connect(ui->penToolButton, &QPushButton::pressed, &model, &Model::setPenTool);

    connect(ui->penToolButton, &QPushButton::pressed, this, &View::setCursorIconPen);

    connect(ui->eraserToolButton, &QPushButton::pressed, &model, &Model::setEraserTool);

    connect(ui->eraserToolButton, &QPushButton::pressed, this, &View::setCursorIconEraser);

    connect(ui->clearCanvasToolButton, &QPushButton::pressed, &model, &Model::setClearCanvasTool);

    connect(ui->clearCanvasToolButton, &QPushButton::pressed, this, &View::setCursorIconClearCanvas);

    connect(ui->bucketToolButton, &QPushButton::pressed, &model, &Model::setBucketFillTool);

    connect(ui->bucketToolButton, &QPushButton::pressed, this, &View::setCursorIconBucketFill);

    connect(ui->tintButton, &QPushButton::pressed, &model, &Model::setTintTool);

    connect(ui->tintButton, &QPushButton::pressed, this, &View::setCursorIconTint);

    connect(ui->shadeButton, &QPushButton::pressed, &model, &Model::setShadeTool);

    connect(ui->shadeButton, &QPushButton::pressed, this, &View::setCursorIconShade);

    // Sends model information on the location of a pixel pressed on screen, used with all draw tools
    connect(this, &View::setImagePixel, &model, &Model::useCurrentTool);

    // Connect save and load buttons to view's slots, which handle getting the fileName
    connect(ui->actionSave_As, &QAction::triggered, this, &View::getSaveFileName);

    connect(ui->actionOpen, &QAction::triggered, this, &View::getLoadFileName);

    // This is save button, not saveAs
    connect(ui->actionSave, &QAction::triggered, this, &View::processSave);

    // Now connect the save and load signals of the view to the model's slots
    connect(this, &View::saveToFile, &model, &Model::saveToFile);

    connect(this, &View::loadfromFile, &model, &Model::loadFromFile);

    // Connect the color picker button to this View
    connect(ui->displayColorButton, &QPushButton::pressed, this, &View::onChooseColorButtonPressed);

    // Allow the View to update the Model's color
    connect(this, &View::updateModelColor, &model, &Model::updateStoredColor);

    // This MUST be a unique connection, otherwise bad things happen
    // when trying to add a frame when the animation is empty
    connect(ui->addFrameButton, &QPushButton::clicked, this, &View::createNewButton, Qt::UniqueConnection);

    // Connect model's error sender signal and view's slot
    connect(&model, &Model::sendErrorMessage, this, &View::displayError);

    // Connect new menu button to the View's slot
    connect(ui->actionNew, &QAction::triggered, this, &View::processNewAnimation);

    // Now connect the emitted new animation signal to the model
    connect(this, &View::getNewAnimation, &model, &Model::createNewAnimation);

    // Connect the Menu Bar's undo action to the model
    connect(ui->actionUndo, &QAction::triggered, &model, &Model::undoAction);

    // Connect the Menu Bar's redo action to the model
    connect(ui->actionRedo, &QAction::triggered, &model, &Model::redoAction);

    // Allow the model to completely refresh the right animation bar
    connect(&model, &Model::bulkUpdateAnimation, this, &View::bulkRefreshFrames);

    // Connect model's successful Load to view
    connect(&model, &Model::successfulLoad, this, &View::successfulLoad);

    // Connect help menu button to slot displaying it
    connect(ui->actionHelp, &QAction::triggered, this, &View::showHelpMenu);

    emit changeWorkingFrame(0); // Request the starting frame
    showGrid(false); // start with default no grid
}


///
/// \brief Destructor for view
///
View::~View()
{
    delete ui;
}


///
/// \brief View::updateCanvas   Slot setting the graphicsDrawView's image to the currentWorkingImage
/// \param newWorkingImage      New image to set canvas to
/// \param currentIndex         What the index of that image is in the animation
///
void View::updateCanvas(const QImage& newWorkingImage, const int currentIndex)
{
    ui->canvasGraphicsView->drawImage(newWorkingImage);
    setButtonImage(newWorkingImage, currentIndex);
}


///
/// \brief Creates a new framebutton for the right animation bar
///
void View::createNewButton()
{
    FrameButton newButton;
    connect(newButton.getUpButton(), &QPushButton::clicked, this, &View::moveFrameUp);

    connect(newButton.getDownButton(), &QPushButton::clicked, this, &View::moveFrameDown);

    connect(newButton.getCenterButton(), &QPushButton::clicked, this, &View::switchToClickedFrame);

    ui->minimizedFramesLayout->addLayout(newButton.getLayout());

    frameButtons.push_back(newButton);
}


///
/// \brief Slot attached to new framebuttons in animation bar to swap locations up
///
void View::moveFrameUp()
{
    // This is the current button that will be moved up
    QPushButton* imageFrameToMove =
        qobject_cast<QPushButton*>(qobject_cast<QPushButton*>(sender())->nextInFocusChain());

    // The FrameButtons are a class, but we need to scan just the central buttons for equality
    // Therefore, this transform takes every FrameButton from frameButtons, and just creates a vector
    // with only the center buttons in order, and this is stored in centralButtons.
    QVector<QPushButton*> centralButtons;
    std::transform(frameButtons.cbegin(), frameButtons.cend(), std::back_inserter(centralButtons),
                   [](const FrameButton& val) { return val.getCenterButton(); });
    int moveImageIndex = centralButtons.indexOf(imageFrameToMove);

    if (moveImageIndex == 0)
        return;

    int destinationIndex = moveImageIndex - 1;

    emit swapFrames(moveImageIndex, destinationIndex);
}


///
/// \brief Slot attached to new framebuttons in animation bar to swap locations down
///
void View::moveFrameDown()
{
    // This is the current button that will be moved cown
    QPushButton* imageFrameToMove =
        qobject_cast<QPushButton*>(qobject_cast<QPushButton*>(sender())->previousInFocusChain());

    // The FrameButtons are a class, but we need to scan just the central buttons for equality
    // Therefore, this transform takes every FrameButton from frameButtons, and just creates a vector
    // with only the center buttons in order, and this is stored in centralButtons.
    QVector<QPushButton*> centralButtons;
    std::transform(frameButtons.cbegin(), frameButtons.cend(), std::back_inserter(centralButtons),
                   [](const FrameButton& val) { return val.getCenterButton(); });

    int moveImageIndex = centralButtons.indexOf(imageFrameToMove);

    if (moveImageIndex == centralButtons.size() - 1)
        return;

    int destinationIndex = moveImageIndex + 1;

    emit swapFrames(moveImageIndex, destinationIndex);
}


///
/// \brief Sets a framebutton's image
/// \param image to use in the frame
/// \param index in the animation to set
///
void View::setButtonImage(const QImage& image, int index)
{

    // Check if not a valid index, or if the image is an empty image, which should not result in anything happening
    if (index < 0 || image.height() == 0 || image.width() == 0)
        return;

    if (frameButtons.size() == 0)
    {
        // This is disconnected when there are no frames,
        // So we need to re-connect when adding the first frame
        // This MUST be a unique connection, otherwise bad things happen
        // when trying to add a frame when the animation is empty
        connect(ui->addFrameButton, &QPushButton::clicked, this, &View::createNewButton, Qt::UniqueConnection);
    }

    if (frameButtons.size() <= index)
        createNewButton();

    frameButtons[index].setIcon(image);
}


///
/// \brief View::getToolPos     Gets the position of a user's mouse on the canvas, and emits the signal to the model to draw
/// \param pos                  Mouse's position in pixels
/// \param mousePressed         If the mouse was pressed
///
void View::getToolPos(const QPoint& pos, bool mousePressed)
{
    emit setImagePixel(pos, mousePressed);
    updateCurrentPos(pos);
}

///
/// \brief View::updateCurrentPos
/// \param  New mouse position
/// This method uses the position of the mouse when its clicked
/// to update the bottom info bar with information about where the mouse is,
/// as well as updating what color is currently being used by the user to draw the sprites.
///
void View::updateCurrentPos(const QPoint& pos)
{
    const int xPos = pos.x();
    const int yPos = pos.y();
    const QPoint mousePos(xPos, yPos);

    // Evaluate the current image being drawn on, and grab the colors being used.
    const QImage* image = ui->canvasGraphicsView->getImage();
    const QColor currentColor = image->pixelColor(mousePos);

    ui->bottomInfoLabel->setText("X: " + QString::number(xPos) + " Y: " + QString::number(yPos) + " Red: " + QString::number(currentColor.red())
                                 + " Blue: " + QString::number(currentColor.blue()) + " Green: " + QString::number(currentColor.green()) + " Alpha: "
                                 + QString::number(currentColor.alpha()));
}


///
/// \brief View::getSaveFileName    Opens file dialog to get fileName to save to
///
void View::getSaveFileName()
{
    // Save file dialog can not use static method, as we want a default .ssp suffix
    QFileDialog saveFileDialog(this, "Save Sprite Sheet Project", "", "Sprite Sheet Project (*.ssp);;All Files (*)");

    saveFileDialog.setAcceptMode(QFileDialog::AcceptSave);
    saveFileDialog.setDefaultSuffix(".ssp");
    saveFileDialog.setFileMode(QFileDialog::AnyFile);

    if (!saveFileDialog.exec())
        return;

    const QStringList selectedFiles = saveFileDialog.selectedFiles();

    if (selectedFiles.isEmpty() || selectedFiles.size() > 1)
        return;

    const QString fileName = selectedFiles.constFirst();

    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    // Attempt to open file in WriteOnly
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, "Unable to open file", file.errorString());
        return;
    }

    emit saveToFile(file);
    lastSavedFileName = fileName;
    updateWindowTitle(fileName);
}


///
/// \brief View::getLoadFileName    Opens file dialog to get fileName to load from
///
void View::getLoadFileName()
{
    const QString fileName = QFileDialog::getOpenFileName(this, "Open Sprite Sheet Project", "",
                                                          "Sprite Sheet Project (*.ssp);;All Files (*)");

    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    // Attempt to open file in ReadOnly
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, "Unable to open file", file.errorString());
        return;
    }

    emit loadfromFile(file);
}


///
/// \brief View::onChooseColorButtonPressed
///                     Allows the user to update their currently selected color.
///                     (this is triggered by the chooseColorButton)
///
void View::onChooseColorButtonPressed()
{
    // Display the color picker dialogue, and recieve the returned color
    QColor color = QColorDialog::getColor(Qt::white, this);

    // Display the new color to the user
    QString style = "QPushButton {background-color: " + color.name() + " ;}";
    ui->displayColorButton->setStyleSheet(style);

    // Update the color in the model
    emit updateModelColor(color);
}


///
/// \brief Displays errors from the model
///
void View::displayError(const QString& errorMessage)
{
    QMessageBox::information(this, "An error has occurred", errorMessage);
}


///
/// \brief Gets user input for new animation, then requests it from model
///
void View::processNewAnimation()
{
    // Ok variable is set to true if user presses Ok on the dialog, and false otherwise
    bool ok = false;
    const int width =
        QInputDialog::getInt(this, "Create a new window", "Enter width for new Sprite", 0, 1, 512, 1, &ok);
    if (!ok)
        return;
    const int height =
        QInputDialog::getInt(this, "Create a new window", "Enter height for new Sprite", 0, 1, 512, 1, &ok);
    if (!ok)
        return;

    frameButtons.clear();
    emit getNewAnimation(width, height);
    lastSavedFileName = "";
    updateWindowTitle("");
}


///
/// \brief View::switchToFrame
///                     Allows the user to switch directly to the frame
///                     being clicked on in the right scroll area
///
void View::switchToClickedFrame()
{
    auto button = qobject_cast<QPushButton*>(sender());
    // The FrameButtons are a class, but we need to scan just the central buttons for equality
    // Therefore, this transform takes every FrameButton from frameButtons, and just creates a vector
    // with only the center buttons in order, and this is stored in centralButtons.
    QVector<QPushButton*> centralButtons;
    std::transform(frameButtons.cbegin(), frameButtons.cend(), std::back_inserter(centralButtons),
                   [](const FrameButton& val) { return val.getCenterButton(); });

    emit getCurrentFrame(centralButtons.indexOf(button));
}


///
/// \brief Shows the preview window with the animation.
///
void View::showPreviewWindow()
{
    preview.setModal(true);
    preview.exec();
}

///
/// \brief  Method that communicates with the canvas
///         graphics view to toggle on or off a grid
/// \param  Whether to toggle on or off
///
void View::showGrid(bool toggled)
{
    auto gridScene = new QGraphicsScene(ui->canvasGraphicsView);
    gridScene->setSceneRect(ui->canvasGraphicsView->getImage()->rect());
    gridScene->addPixmap(QPixmap::fromImage(*ui->canvasGraphicsView->getImage()));

    if (toggled)
    {
        for(int x = 0; x <= gridScene->width() - 1; x++)
            gridScene->addLine(x, 0, x, gridScene->width(), QPen(Qt::black, 0, Qt::DashLine, Qt::RoundCap));

        for(int y = 0; y <= gridScene->height(); y++)
            gridScene->addLine(0, y, gridScene->height(), y, QPen(Qt::black, 0, Qt::DashLine, Qt::RoundCap));
        ui->canvasGraphicsView->setGrid(toggled);
    }
    else if(!toggled)
    {
        // These two for loops are used to draw the grid lines across each pixel's location within the image.
        for(int x = 0; x <= gridScene->width() - 1; x++)
            gridScene->addLine(x, 0, x, gridScene->width(), QPen(Qt::transparent, 0, Qt::DashLine, Qt::RoundCap));

        for(int y = 0; y <= gridScene->height(); y++)
            gridScene->addLine(0, y, gridScene->height(), y, QPen(Qt::transparent, 0, Qt::DashLine, Qt::RoundCap));

        ui->canvasGraphicsView->setGrid(toggled);
    }

    ui->canvasGraphicsView->setScene(gridScene);
    ui->canvasGraphicsView->fitInView(gridScene->sceneRect(), Qt::AspectRatioMode::KeepAspectRatio);
}


///
/// \brief View::deleteFrameButton  Method called when remove frame button is pressed
///
void View::deleteFrameButton()
{
    if (!frameButtons.empty())
        frameButtons.pop_back();

    // If empty, we need to disable the addFrameButton directly adding a new frame,
    // As this causes 2 frames to be added (model sends a signal for this when animation is empty)
    if (frameButtons.empty())
    {
        disconnect(ui->addFrameButton, &QPushButton::clicked, this, &View::createNewButton);
    }
}


///
/// \brief View::bulkRefreshFrames  Updates all the displayed frames in the right animation bar
/// \param newFrames                The new frames to display
///
void View::bulkRefreshFrames(const QVector<QImage> newFrames)
{
    // Add/delete buttons to match the number of new frames
    while (frameButtons.count() > newFrames.count())
        deleteFrameButton();
    while (frameButtons.count() < newFrames.count())
        createNewButton();

    // Update the displayed images on all buttons
    for (int i = 0; i < newFrames.count(); i++)
        setButtonImage(newFrames[i], i);
}


///
/// \brief View::successfulLoad     Slot that processes when the model has successfully loaded an animation.
/// \param animationIsEmpty         Check if the animation contains any frames or not
/// \param fileName                 Name of the file load
///
void View::successfulLoad(bool animationIsEmpty, const QString fileName)
{
    frameButtons.clear();

    // If empty, we need to disable the addFrameButton directly adding a new frame,
    // As this causes 2 frames to be added (model sends a signal for this when animation is empty)
    if (animationIsEmpty)
        disconnect(ui->addFrameButton, &QPushButton::clicked, this, &View::createNewButton);

    lastSavedFileName = fileName;
    updateWindowTitle(fileName);
}


///
/// \brief View::processSave    Slot that processes the save button press, not save as
///
void View::processSave()
{
    if (lastSavedFileName.isEmpty())
    {
        getSaveFileName();
        return;
    }

    QFile file(lastSavedFileName);
    // Attempt to open file in WriteOnly
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, "Unable to open file", file.errorString());
        return;
    }

    emit saveToFile(file);
}


///
/// \brief View::updateWindowTitle  Updates window title with a fileName, if empty, just sets it as SpriteEditor
/// \param fileName                 Name of the file to be saved with
///
void View::updateWindowTitle(const QString& fileName)
{
    if (fileName.isEmpty())
        setWindowTitle("Sprite Editor");
    else
        setWindowTitle("Sprite Editor - " + fileName.split("/").last()); // Gets fileName after last slash in filePath
}


///
/// \brief View::showHelpMenu   Shows help menu
///
void View::showHelpMenu()
{
    const QString helpText = "This program allows you to edit sprites!\n\n"
                             "===BASIC FUNCTIONALITY===\n"
                             "There are 6 main tools available on the left side, these are:\n"
                             "\t1. Pen tool (p)\n"
                             "\t2. Eraser tool (e)\n"
                             "\t3. Clear image\n"
                             "\t4. Bucket fill (b)\n"
                             "\t5. Tint (t)\n"
                             "\t6. Shade (s)\n"
                             "These tools all allow you to manipulate pixels in the canvas in some way. "
                             "You can choose the color by clicking on the box underneath the words \"Current Color.\"\n"
                             "Animation playback can be toggled by pressing the \"Run Animation\" button on the bottom bar."
                             "The FPS can be adjusted with a slider from 1-30.\n"
                             "Some tools have hotkeys, which can be seen by hovering over the icon or looking above.\n\n"
                             "You can add or remove a frame to/from the end of the animation by clicking the +/- icons in the bottom right. "
                             "The pop window out button is to the right of these buttons, which opens a new window with the animation. "
                             "The arrow buttons in the bottom right move forward and backwards between frames. You can also click on a frame to edit it. "
                             "You can save, load, or create a new image from the File menu.\n\n"
                             "===BONUS FEATURES===\n\n"
                             "1. Frames can be re-ordered by pressing the move up/down buttons to swap frames.\n"
                             "2. You can undo/redo actions from the edit menu or using shortcuts.\n"
                             "3. You can toggle gridlines in the bottom left corner.";

    QMessageBox::information(this, "Help Menu", helpText);
}


///
/// \brief View::setCursorIconPen   Sets the mouse cursor icon to the pen tool icon
///
void View::setCursorIconPen()
{
    QCursor penCursor = QCursor(QPixmap(":/images/pen_icon.png"));
    ui->canvasGraphicsView->setCursor(penCursor);
}


///
/// \brief View::setCursorIconEraser    Sets the mouse cursor icon to the eraser tool icon
///
void View::setCursorIconEraser()
{
    QCursor penCursor = QCursor(QPixmap(":/images/eraser_icon.png"));
    ui->canvasGraphicsView->setCursor(penCursor);
}


///
/// \brief View::setCursorIconClearCanvas   Sets the mouse cursor icon to the clear canvas tool icon
///
void View::setCursorIconClearCanvas()
{
    QCursor penCursor = QCursor(QPixmap(":/images/clear_icon.png"));
    ui->canvasGraphicsView->setCursor(penCursor);
}


///
/// \brief View::setCursorIconBucketFill    Sets the mouse cursor icon to the bucket fill tool icon
///
void View::setCursorIconBucketFill()
{
    QCursor penCursor = QCursor(QPixmap(":/images/bucket_fill_icon.png"));
    ui->canvasGraphicsView->setCursor(penCursor);
}


///
/// \brief View::setCursorIconTint      Sets the mouse cursor icon to the tint tool icon
///
void View::setCursorIconTint()
{
    QCursor penCursor = QCursor(QPixmap(":/images/tint_icon.png"));
    ui->canvasGraphicsView->setCursor(penCursor);
}


///
/// \brief View::setCursorIconShade     Sets the mouse cursor icon to the shade tool icon
///
void View::setCursorIconShade()
{
    QCursor penCursor = QCursor(QPixmap(":/images/shade_icon.png"));
    ui->canvasGraphicsView->setCursor(penCursor);
}
