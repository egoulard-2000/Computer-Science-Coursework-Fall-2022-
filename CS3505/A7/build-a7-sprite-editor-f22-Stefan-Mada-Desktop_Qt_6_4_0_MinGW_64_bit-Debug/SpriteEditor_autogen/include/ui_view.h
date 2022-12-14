/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "graphicsdrawview.h"

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionEnable_Gridlines;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionHelp;
    QWidget *windowLayout;
    QHBoxLayout *horizontalLayout_2;
    QWidget *leftColumnLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *toolsLabel;
    QWidget *toolLayout;
    QGridLayout *gridLayout_3;
    QToolButton *penToolButton;
    QToolButton *bucketToolButton;
    QToolButton *clearCanvasToolButton;
    QToolButton *eraserToolButton;
    QPushButton *tintButton;
    QPushButton *shadeButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *colorsLabel;
    QPushButton *displayColorButton;
    QSpacerItem *verticalSpacer;
    QRadioButton *gridButton;
    QVBoxLayout *canvasLayout;
    GraphicsDrawView *canvasGraphicsView;
    QHBoxLayout *bottomLayout;
    QLabel *bottomInfoLabel;
    QPushButton *mainRunButton;
    QWidget *rightColumnLayout;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *frameScrollArea;
    QWidget *frameScrollLayout;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *minimizedFramesLayout;
    QWidget *fpsLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *fpsSliderLayout;
    QLabel *fpsLabel;
    QLabel *fpsNumber;
    QSlider *fpsSlider;
    QHBoxLayout *frameButtonLayout;
    QPushButton *removeFrameButton;
    QPushButton *addFrameButton;
    QPushButton *popoutButton;
    QHBoxLayout *tempFrameTraverseLayout;
    QPushButton *tempPrevFrameButton;
    QPushButton *tempNextFrameButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName("View");
        View->resize(836, 600);
        View->setTabShape(QTabWidget::Rounded);
        actionNew = new QAction(View);
        actionNew->setObjectName("actionNew");
        actionOpen = new QAction(View);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(View);
        actionSave->setObjectName("actionSave");
        actionSave_As = new QAction(View);
        actionSave_As->setObjectName("actionSave_As");
        actionEnable_Gridlines = new QAction(View);
        actionEnable_Gridlines->setObjectName("actionEnable_Gridlines");
        actionEnable_Gridlines->setCheckable(true);
        actionEnable_Gridlines->setChecked(true);
        actionUndo = new QAction(View);
        actionUndo->setObjectName("actionUndo");
        actionRedo = new QAction(View);
        actionRedo->setObjectName("actionRedo");
        actionHelp = new QAction(View);
        actionHelp->setObjectName("actionHelp");
        windowLayout = new QWidget(View);
        windowLayout->setObjectName("windowLayout");
        horizontalLayout_2 = new QHBoxLayout(windowLayout);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        leftColumnLayout = new QWidget(windowLayout);
        leftColumnLayout->setObjectName("leftColumnLayout");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftColumnLayout->sizePolicy().hasHeightForWidth());
        leftColumnLayout->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(leftColumnLayout);
        verticalLayout_2->setObjectName("verticalLayout_2");
        toolsLabel = new QLabel(leftColumnLayout);
        toolsLabel->setObjectName("toolsLabel");

        verticalLayout_2->addWidget(toolsLabel);

        toolLayout = new QWidget(leftColumnLayout);
        toolLayout->setObjectName("toolLayout");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolLayout->sizePolicy().hasHeightForWidth());
        toolLayout->setSizePolicy(sizePolicy1);
        toolLayout->setMinimumSize(QSize(100, 100));
        gridLayout_3 = new QGridLayout(toolLayout);
        gridLayout_3->setObjectName("gridLayout_3");
        penToolButton = new QToolButton(toolLayout);
        penToolButton->setObjectName("penToolButton");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(penToolButton->sizePolicy().hasHeightForWidth());
        penToolButton->setSizePolicy(sizePolicy2);
        penToolButton->setCursor(QCursor(Qt::PointingHandCursor));
        penToolButton->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/images/pen_icon_full.png)"));

        gridLayout_3->addWidget(penToolButton, 0, 0, 1, 1);

        bucketToolButton = new QToolButton(toolLayout);
        bucketToolButton->setObjectName("bucketToolButton");
        sizePolicy2.setHeightForWidth(bucketToolButton->sizePolicy().hasHeightForWidth());
        bucketToolButton->setSizePolicy(sizePolicy2);
        bucketToolButton->setCursor(QCursor(Qt::PointingHandCursor));
        bucketToolButton->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/images/bucket_fill_icon_full.png)"));

        gridLayout_3->addWidget(bucketToolButton, 1, 1, 1, 1);

        clearCanvasToolButton = new QToolButton(toolLayout);
        clearCanvasToolButton->setObjectName("clearCanvasToolButton");
        sizePolicy2.setHeightForWidth(clearCanvasToolButton->sizePolicy().hasHeightForWidth());
        clearCanvasToolButton->setSizePolicy(sizePolicy2);
        clearCanvasToolButton->setCursor(QCursor(Qt::PointingHandCursor));
        clearCanvasToolButton->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/images/clear_icon_full.png)"));

        gridLayout_3->addWidget(clearCanvasToolButton, 1, 0, 1, 1);

        eraserToolButton = new QToolButton(toolLayout);
        eraserToolButton->setObjectName("eraserToolButton");
        sizePolicy2.setHeightForWidth(eraserToolButton->sizePolicy().hasHeightForWidth());
        eraserToolButton->setSizePolicy(sizePolicy2);
        eraserToolButton->setCursor(QCursor(Qt::PointingHandCursor));
        eraserToolButton->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/images/eraser_icon_full.png)"));

        gridLayout_3->addWidget(eraserToolButton, 0, 1, 1, 1);


        verticalLayout_2->addWidget(toolLayout);

        tintButton = new QPushButton(leftColumnLayout);
        tintButton->setObjectName("tintButton");
        tintButton->setCursor(QCursor(Qt::PointingHandCursor));
        tintButton->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/images/tint_icon_full.png)"));

        verticalLayout_2->addWidget(tintButton);

        shadeButton = new QPushButton(leftColumnLayout);
        shadeButton->setObjectName("shadeButton");
        shadeButton->setCursor(QCursor(Qt::PointingHandCursor));
        shadeButton->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/images/shade_icon_full.png)"));

        verticalLayout_2->addWidget(shadeButton);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        colorsLabel = new QLabel(leftColumnLayout);
        colorsLabel->setObjectName("colorsLabel");
        colorsLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(colorsLabel);

        displayColorButton = new QPushButton(leftColumnLayout);
        displayColorButton->setObjectName("displayColorButton");
        displayColorButton->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(displayColorButton->sizePolicy().hasHeightForWidth());
        displayColorButton->setSizePolicy(sizePolicy3);
        displayColorButton->setMinimumSize(QSize(80, 80));
        displayColorButton->setCursor(QCursor(Qt::PointingHandCursor));
        displayColorButton->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgb(0, 0, 0);}"));

        verticalLayout_2->addWidget(displayColorButton);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        gridButton = new QRadioButton(leftColumnLayout);
        gridButton->setObjectName("gridButton");
        gridButton->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(gridButton);


        horizontalLayout_2->addWidget(leftColumnLayout);

        canvasLayout = new QVBoxLayout();
        canvasLayout->setObjectName("canvasLayout");
        canvasGraphicsView = new GraphicsDrawView(windowLayout);
        canvasGraphicsView->setObjectName("canvasGraphicsView");
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(canvasGraphicsView->sizePolicy().hasHeightForWidth());
        canvasGraphicsView->setSizePolicy(sizePolicy4);

        canvasLayout->addWidget(canvasGraphicsView);

        bottomLayout = new QHBoxLayout();
        bottomLayout->setObjectName("bottomLayout");
        bottomInfoLabel = new QLabel(windowLayout);
        bottomInfoLabel->setObjectName("bottomInfoLabel");
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(bottomInfoLabel->sizePolicy().hasHeightForWidth());
        bottomInfoLabel->setSizePolicy(sizePolicy5);

        bottomLayout->addWidget(bottomInfoLabel);

        mainRunButton = new QPushButton(windowLayout);
        mainRunButton->setObjectName("mainRunButton");
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(mainRunButton->sizePolicy().hasHeightForWidth());
        mainRunButton->setSizePolicy(sizePolicy6);
        mainRunButton->setCursor(QCursor(Qt::PointingHandCursor));

        bottomLayout->addWidget(mainRunButton);


        canvasLayout->addLayout(bottomLayout);


        horizontalLayout_2->addLayout(canvasLayout);

        rightColumnLayout = new QWidget(windowLayout);
        rightColumnLayout->setObjectName("rightColumnLayout");
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(rightColumnLayout->sizePolicy().hasHeightForWidth());
        rightColumnLayout->setSizePolicy(sizePolicy7);
        rightColumnLayout->setMinimumSize(QSize(150, 0));
        verticalLayout_3 = new QVBoxLayout(rightColumnLayout);
        verticalLayout_3->setObjectName("verticalLayout_3");
        frameScrollArea = new QScrollArea(rightColumnLayout);
        frameScrollArea->setObjectName("frameScrollArea");
        frameScrollArea->setWidgetResizable(true);
        frameScrollLayout = new QWidget();
        frameScrollLayout->setObjectName("frameScrollLayout");
        frameScrollLayout->setGeometry(QRect(0, 0, 136, 457));
        sizePolicy2.setHeightForWidth(frameScrollLayout->sizePolicy().hasHeightForWidth());
        frameScrollLayout->setSizePolicy(sizePolicy2);
        frameScrollLayout->setMinimumSize(QSize(0, 0));
        verticalLayout_5 = new QVBoxLayout(frameScrollLayout);
        verticalLayout_5->setSpacing(40);
        verticalLayout_5->setObjectName("verticalLayout_5");
        minimizedFramesLayout = new QVBoxLayout();
        minimizedFramesLayout->setObjectName("minimizedFramesLayout");

        verticalLayout_5->addLayout(minimizedFramesLayout);

        frameScrollArea->setWidget(frameScrollLayout);

        verticalLayout_3->addWidget(frameScrollArea);

        fpsLayout = new QWidget(rightColumnLayout);
        fpsLayout->setObjectName("fpsLayout");
        QSizePolicy sizePolicy8(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(fpsLayout->sizePolicy().hasHeightForWidth());
        fpsLayout->setSizePolicy(sizePolicy8);
        fpsLayout->setMinimumSize(QSize(0, 0));
        verticalLayout_4 = new QVBoxLayout(fpsLayout);
        verticalLayout_4->setObjectName("verticalLayout_4");
        fpsSliderLayout = new QHBoxLayout();
        fpsSliderLayout->setObjectName("fpsSliderLayout");
        fpsLabel = new QLabel(fpsLayout);
        fpsLabel->setObjectName("fpsLabel");

        fpsSliderLayout->addWidget(fpsLabel);

        fpsNumber = new QLabel(fpsLayout);
        fpsNumber->setObjectName("fpsNumber");

        fpsSliderLayout->addWidget(fpsNumber);

        fpsSlider = new QSlider(fpsLayout);
        fpsSlider->setObjectName("fpsSlider");
        fpsSlider->setMinimum(1);
        fpsSlider->setMaximum(30);
        fpsSlider->setOrientation(Qt::Horizontal);

        fpsSliderLayout->addWidget(fpsSlider);


        verticalLayout_4->addLayout(fpsSliderLayout);

        frameButtonLayout = new QHBoxLayout();
        frameButtonLayout->setSpacing(10);
        frameButtonLayout->setObjectName("frameButtonLayout");
        removeFrameButton = new QPushButton(fpsLayout);
        removeFrameButton->setObjectName("removeFrameButton");
        sizePolicy5.setHeightForWidth(removeFrameButton->sizePolicy().hasHeightForWidth());
        removeFrameButton->setSizePolicy(sizePolicy5);
        removeFrameButton->setMinimumSize(QSize(0, 0));
        removeFrameButton->setCursor(QCursor(Qt::PointingHandCursor));

        frameButtonLayout->addWidget(removeFrameButton);

        addFrameButton = new QPushButton(fpsLayout);
        addFrameButton->setObjectName("addFrameButton");
        sizePolicy5.setHeightForWidth(addFrameButton->sizePolicy().hasHeightForWidth());
        addFrameButton->setSizePolicy(sizePolicy5);
        addFrameButton->setMinimumSize(QSize(0, 0));
        addFrameButton->setCursor(QCursor(Qt::PointingHandCursor));

        frameButtonLayout->addWidget(addFrameButton);

        popoutButton = new QPushButton(fpsLayout);
        popoutButton->setObjectName("popoutButton");
        sizePolicy5.setHeightForWidth(popoutButton->sizePolicy().hasHeightForWidth());
        popoutButton->setSizePolicy(sizePolicy5);
        popoutButton->setMinimumSize(QSize(0, 0));
        popoutButton->setCursor(QCursor(Qt::PointingHandCursor));
        popoutButton->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/images/mini-player-icon.png)"));

        frameButtonLayout->addWidget(popoutButton);


        verticalLayout_4->addLayout(frameButtonLayout);


        verticalLayout_3->addWidget(fpsLayout);

        tempFrameTraverseLayout = new QHBoxLayout();
        tempFrameTraverseLayout->setObjectName("tempFrameTraverseLayout");
        tempPrevFrameButton = new QPushButton(rightColumnLayout);
        tempPrevFrameButton->setObjectName("tempPrevFrameButton");
        sizePolicy1.setHeightForWidth(tempPrevFrameButton->sizePolicy().hasHeightForWidth());
        tempPrevFrameButton->setSizePolicy(sizePolicy1);
        tempPrevFrameButton->setMinimumSize(QSize(10, 0));
        tempPrevFrameButton->setMaximumSize(QSize(20, 16777215));
        tempPrevFrameButton->setCursor(QCursor(Qt::PointingHandCursor));

        tempFrameTraverseLayout->addWidget(tempPrevFrameButton);

        tempNextFrameButton = new QPushButton(rightColumnLayout);
        tempNextFrameButton->setObjectName("tempNextFrameButton");
        sizePolicy5.setHeightForWidth(tempNextFrameButton->sizePolicy().hasHeightForWidth());
        tempNextFrameButton->setSizePolicy(sizePolicy5);
        tempNextFrameButton->setMinimumSize(QSize(10, 0));
        tempNextFrameButton->setMaximumSize(QSize(20, 16777215));
        tempNextFrameButton->setCursor(QCursor(Qt::PointingHandCursor));

        tempFrameTraverseLayout->addWidget(tempNextFrameButton);


        verticalLayout_3->addLayout(tempFrameTraverseLayout);


        horizontalLayout_2->addWidget(rightColumnLayout);

        View->setCentralWidget(windowLayout);
        menubar = new QMenuBar(View);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 836, 17));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        View->setMenuBar(menubar);
        statusbar = new QStatusBar(View);
        statusbar->setObjectName("statusbar");
        View->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuHelp->addAction(actionHelp);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);

        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QCoreApplication::translate("View", "Sprite Editor", nullptr));
        actionNew->setText(QCoreApplication::translate("View", "New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("View", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("View", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("View", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("View", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("View", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_As->setText(QCoreApplication::translate("View", "Save As...", nullptr));
        actionEnable_Gridlines->setText(QCoreApplication::translate("View", "Enable Gridlines", nullptr));
        actionUndo->setText(QCoreApplication::translate("View", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("View", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("View", "Redo", nullptr));
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("View", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionHelp->setText(QCoreApplication::translate("View", "Open Help Menu", nullptr));
#if QT_CONFIG(shortcut)
        actionHelp->setShortcut(QCoreApplication::translate("View", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        toolsLabel->setText(QCoreApplication::translate("View", "Tools", nullptr));
#if QT_CONFIG(tooltip)
        penToolButton->setToolTip(QCoreApplication::translate("View", "Pen tool (p)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        penToolButton->setStatusTip(QCoreApplication::translate("View", "Pen tool (p)", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        penToolButton->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        penToolButton->setText(QCoreApplication::translate("View", "P", nullptr));
#if QT_CONFIG(shortcut)
        penToolButton->setShortcut(QCoreApplication::translate("View", "P", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        bucketToolButton->setToolTip(QCoreApplication::translate("View", "Bucket fill (b)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        bucketToolButton->setStatusTip(QCoreApplication::translate("View", "Bucket fill (b)", nullptr));
#endif // QT_CONFIG(statustip)
        bucketToolButton->setText(QCoreApplication::translate("View", "BU", nullptr));
#if QT_CONFIG(shortcut)
        bucketToolButton->setShortcut(QCoreApplication::translate("View", "B", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        clearCanvasToolButton->setToolTip(QCoreApplication::translate("View", "Clear Image", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        clearCanvasToolButton->setStatusTip(QCoreApplication::translate("View", "Clear Image", nullptr));
#endif // QT_CONFIG(statustip)
        clearCanvasToolButton->setText(QCoreApplication::translate("View", "ED", nullptr));
#if QT_CONFIG(shortcut)
        clearCanvasToolButton->setShortcut(QCoreApplication::translate("View", "D", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        eraserToolButton->setToolTip(QCoreApplication::translate("View", "Eraser tool (e)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        eraserToolButton->setStatusTip(QCoreApplication::translate("View", "Eraser tool (e)", nullptr));
#endif // QT_CONFIG(statustip)
        eraserToolButton->setText(QCoreApplication::translate("View", "E", nullptr));
#if QT_CONFIG(shortcut)
        eraserToolButton->setShortcut(QCoreApplication::translate("View", "E", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        tintButton->setToolTip(QCoreApplication::translate("View", "Tin tool (t)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        tintButton->setStatusTip(QCoreApplication::translate("View", "Tint tool (t)", nullptr));
#endif // QT_CONFIG(statustip)
        tintButton->setText(QCoreApplication::translate("View", "Tint Pen", nullptr));
#if QT_CONFIG(shortcut)
        tintButton->setShortcut(QCoreApplication::translate("View", "T", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        shadeButton->setToolTip(QCoreApplication::translate("View", "Shade tool (s)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        shadeButton->setStatusTip(QCoreApplication::translate("View", "Shade tool (s)", nullptr));
#endif // QT_CONFIG(statustip)
        shadeButton->setText(QCoreApplication::translate("View", "Shade Pen", nullptr));
#if QT_CONFIG(shortcut)
        shadeButton->setShortcut(QCoreApplication::translate("View", "S", nullptr));
#endif // QT_CONFIG(shortcut)
        colorsLabel->setText(QCoreApplication::translate("View", "Current Color", nullptr));
        displayColorButton->setText(QString());
        gridButton->setText(QCoreApplication::translate("View", "Toggle Grid", nullptr));
        bottomInfoLabel->setText(QString());
        mainRunButton->setText(QCoreApplication::translate("View", "Run Animation", nullptr));
#if QT_CONFIG(shortcut)
        mainRunButton->setShortcut(QCoreApplication::translate("View", "Space", nullptr));
#endif // QT_CONFIG(shortcut)
        fpsLabel->setText(QCoreApplication::translate("View", "FPS:", nullptr));
        fpsNumber->setText(QCoreApplication::translate("View", "1", nullptr));
        removeFrameButton->setText(QCoreApplication::translate("View", "-", nullptr));
#if QT_CONFIG(shortcut)
        removeFrameButton->setShortcut(QCoreApplication::translate("View", "-", nullptr));
#endif // QT_CONFIG(shortcut)
        addFrameButton->setText(QCoreApplication::translate("View", "+", nullptr));
#if QT_CONFIG(shortcut)
        addFrameButton->setShortcut(QCoreApplication::translate("View", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        popoutButton->setText(QString());
#if QT_CONFIG(shortcut)
        popoutButton->setShortcut(QCoreApplication::translate("View", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        tempPrevFrameButton->setText(QCoreApplication::translate("View", "<", nullptr));
#if QT_CONFIG(shortcut)
        tempPrevFrameButton->setShortcut(QCoreApplication::translate("View", "Left", nullptr));
#endif // QT_CONFIG(shortcut)
        tempNextFrameButton->setText(QCoreApplication::translate("View", ">", nullptr));
#if QT_CONFIG(shortcut)
        tempNextFrameButton->setShortcut(QCoreApplication::translate("View", "Right", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFile->setTitle(QCoreApplication::translate("View", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("View", "Help", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("View", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
