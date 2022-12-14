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
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "chessboardview.h"
#include "lcdclock.h"

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_9;
    QFormLayout *formLayout;
    QStackedWidget *allPagesStackedWidget;
    QWidget *titlePage;
    QGridLayout *gridLayout_2;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *playButtonTitle;
    QPushButton *rulesButtonTitle;
    QPushButton *helpMenuButtonTitle;
    QPushButton *leaderboardButton;
    QPushButton *quitButtonTitle;
    QSpacerItem *verticalSpacer_3;
    QWidget *levelSelectorPage;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer;
    QLabel *titleLabel_2;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout_2;
    QLabel *beginnerLabel;
    QScrollArea *beginnerScrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *levelOneEasyButton;
    QPushButton *levelTwoEasyButton;
    QPushButton *levelThreeEasyButton;
    QPushButton *levelFourEasyButton;
    QLabel *normalLabel;
    QScrollArea *normalScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QPushButton *levelFourMediumButton;
    QPushButton *levelTwoMediumButton;
    QPushButton *levelThreeMediumButton;
    QPushButton *levelOneMediumButton;
    QLabel *hardLabel;
    QScrollArea *hardScrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QPushButton *levelFourHardButton;
    QPushButton *levelOneHardButton;
    QPushButton *levelThreeHardButton;
    QPushButton *levelTwoHardButton;
    QWidget *chessPage;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *puzzleNumberLabel;
    QLabel *puzzleNameLabel;
    QLabel *puzzleDifficultyLabel;
    QSpacerItem *verticalSpacer_2;
    QLabel *turnLabel;
    QLabel *label;
    LCDClock *puzzleTimer;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *hintButton;
    QPushButton *rulesButton;
    QPushButton *retryButton;
    QPushButton *quitButton;
    QLabel *label_5;
    ChessBoardView *chessBoardView;
    QWidget *leaderboardPage;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_11;
    QPushButton *leaderboardBackButton;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_12;
    QLabel *leaderboardTitle;
    QListWidget *leaderboardListWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName("View");
        View->resize(800, 752);
        View->setMaximumSize(QSize(800, 752));
        centralwidget = new QWidget(View);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_9 = new QVBoxLayout(centralwidget);
        verticalLayout_9->setObjectName("verticalLayout_9");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        allPagesStackedWidget = new QStackedWidget(centralwidget);
        allPagesStackedWidget->setObjectName("allPagesStackedWidget");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable Small Semilig")});
        allPagesStackedWidget->setFont(font);
        titlePage = new QWidget();
        titlePage->setObjectName("titlePage");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titlePage->sizePolicy().hasHeightForWidth());
        titlePage->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(titlePage);
        gridLayout_2->setObjectName("gridLayout_2");
        titleLabel = new QLabel(titlePage);
        titleLabel->setObjectName("titleLabel");
        sizePolicy.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Book Antiqua")});
        font1.setPointSize(50);
        titleLabel->setFont(font1);
        titleLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(titleLabel, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        playButtonTitle = new QPushButton(titlePage);
        playButtonTitle->setObjectName("playButtonTitle");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Book Antiqua")});
        playButtonTitle->setFont(font2);

        verticalLayout_2->addWidget(playButtonTitle);

        rulesButtonTitle = new QPushButton(titlePage);
        rulesButtonTitle->setObjectName("rulesButtonTitle");
        rulesButtonTitle->setFont(font2);

        verticalLayout_2->addWidget(rulesButtonTitle);

        helpMenuButtonTitle = new QPushButton(titlePage);
        helpMenuButtonTitle->setObjectName("helpMenuButtonTitle");
        helpMenuButtonTitle->setFont(font2);

        verticalLayout_2->addWidget(helpMenuButtonTitle);

        leaderboardButton = new QPushButton(titlePage);
        leaderboardButton->setObjectName("leaderboardButton");
        leaderboardButton->setFont(font2);

        verticalLayout_2->addWidget(leaderboardButton);

        quitButtonTitle = new QPushButton(titlePage);
        quitButtonTitle->setObjectName("quitButtonTitle");
        quitButtonTitle->setFont(font2);

        verticalLayout_2->addWidget(quitButtonTitle);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer_3);


        gridLayout_2->addLayout(verticalLayout_2, 1, 1, 1, 1);

        allPagesStackedWidget->addWidget(titlePage);
        levelSelectorPage = new QWidget();
        levelSelectorPage->setObjectName("levelSelectorPage");
        sizePolicy.setHeightForWidth(levelSelectorPage->sizePolicy().hasHeightForWidth());
        levelSelectorPage->setSizePolicy(sizePolicy);
        levelSelectorPage->setMinimumSize(QSize(776, 677));
        verticalLayout_4 = new QVBoxLayout(levelSelectorPage);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        backButton = new QPushButton(levelSelectorPage);
        backButton->setObjectName("backButton");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Book Antiqua")});
        font3.setBold(true);
        backButton->setFont(font3);

        horizontalLayout_2->addWidget(backButton);

        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        titleLabel_2 = new QLabel(levelSelectorPage);
        titleLabel_2->setObjectName("titleLabel_2");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Book Antiqua")});
        font4.setPointSize(30);
        titleLabel_2->setFont(font4);

        horizontalLayout_2->addWidget(titleLabel_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        beginnerLabel = new QLabel(levelSelectorPage);
        beginnerLabel->setObjectName("beginnerLabel");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Book Antiqua")});
        font5.setPointSize(20);
        beginnerLabel->setFont(font5);
        beginnerLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, beginnerLabel);

        beginnerScrollArea = new QScrollArea(levelSelectorPage);
        beginnerScrollArea->setObjectName("beginnerScrollArea");
        beginnerScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 98, 28));
        levelOneEasyButton = new QPushButton(scrollAreaWidgetContents);
        levelOneEasyButton->setObjectName("levelOneEasyButton");
        levelOneEasyButton->setGeometry(QRect(10, 30, 111, 111));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Imprint MT Shadow")});
        font6.setPointSize(17);
        levelOneEasyButton->setFont(font6);
        levelTwoEasyButton = new QPushButton(scrollAreaWidgetContents);
        levelTwoEasyButton->setObjectName("levelTwoEasyButton");
        levelTwoEasyButton->setGeometry(QRect(140, 30, 111, 111));
        levelTwoEasyButton->setFont(font6);
        levelThreeEasyButton = new QPushButton(scrollAreaWidgetContents);
        levelThreeEasyButton->setObjectName("levelThreeEasyButton");
        levelThreeEasyButton->setGeometry(QRect(270, 30, 111, 111));
        levelThreeEasyButton->setFont(font6);
        levelFourEasyButton = new QPushButton(scrollAreaWidgetContents);
        levelFourEasyButton->setObjectName("levelFourEasyButton");
        levelFourEasyButton->setGeometry(QRect(400, 30, 111, 111));
        levelFourEasyButton->setFont(font6);
        beginnerScrollArea->setWidget(scrollAreaWidgetContents);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, beginnerScrollArea);

        normalLabel = new QLabel(levelSelectorPage);
        normalLabel->setObjectName("normalLabel");
        normalLabel->setFont(font5);
        normalLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, normalLabel);

        normalScrollArea = new QScrollArea(levelSelectorPage);
        normalScrollArea->setObjectName("normalScrollArea");
        normalScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 98, 28));
        levelFourMediumButton = new QPushButton(scrollAreaWidgetContents_2);
        levelFourMediumButton->setObjectName("levelFourMediumButton");
        levelFourMediumButton->setGeometry(QRect(400, 30, 111, 111));
        levelFourMediumButton->setFont(font6);
        levelTwoMediumButton = new QPushButton(scrollAreaWidgetContents_2);
        levelTwoMediumButton->setObjectName("levelTwoMediumButton");
        levelTwoMediumButton->setGeometry(QRect(140, 30, 111, 111));
        levelTwoMediumButton->setFont(font6);
        levelThreeMediumButton = new QPushButton(scrollAreaWidgetContents_2);
        levelThreeMediumButton->setObjectName("levelThreeMediumButton");
        levelThreeMediumButton->setGeometry(QRect(270, 30, 111, 111));
        levelThreeMediumButton->setFont(font6);
        levelOneMediumButton = new QPushButton(scrollAreaWidgetContents_2);
        levelOneMediumButton->setObjectName("levelOneMediumButton");
        levelOneMediumButton->setGeometry(QRect(10, 30, 111, 111));
        levelOneMediumButton->setFont(font6);
        normalScrollArea->setWidget(scrollAreaWidgetContents_2);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, normalScrollArea);

        hardLabel = new QLabel(levelSelectorPage);
        hardLabel->setObjectName("hardLabel");
        hardLabel->setFont(font5);
        hardLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, hardLabel);

        hardScrollArea = new QScrollArea(levelSelectorPage);
        hardScrollArea->setObjectName("hardScrollArea");
        hardScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 98, 28));
        levelFourHardButton = new QPushButton(scrollAreaWidgetContents_3);
        levelFourHardButton->setObjectName("levelFourHardButton");
        levelFourHardButton->setGeometry(QRect(400, 30, 111, 111));
        levelFourHardButton->setFont(font6);
        levelOneHardButton = new QPushButton(scrollAreaWidgetContents_3);
        levelOneHardButton->setObjectName("levelOneHardButton");
        levelOneHardButton->setGeometry(QRect(10, 30, 111, 111));
        levelOneHardButton->setFont(font6);
        levelThreeHardButton = new QPushButton(scrollAreaWidgetContents_3);
        levelThreeHardButton->setObjectName("levelThreeHardButton");
        levelThreeHardButton->setGeometry(QRect(270, 30, 111, 111));
        levelThreeHardButton->setFont(font6);
        levelTwoHardButton = new QPushButton(scrollAreaWidgetContents_3);
        levelTwoHardButton->setObjectName("levelTwoHardButton");
        levelTwoHardButton->setGeometry(QRect(140, 30, 111, 111));
        levelTwoHardButton->setFont(font6);
        hardScrollArea->setWidget(scrollAreaWidgetContents_3);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, hardScrollArea);


        verticalLayout_3->addLayout(formLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        allPagesStackedWidget->addWidget(levelSelectorPage);
        chessPage = new QWidget();
        chessPage->setObjectName("chessPage");
        sizePolicy.setHeightForWidth(chessPage->sizePolicy().hasHeightForWidth());
        chessPage->setSizePolicy(sizePolicy);
        widget = new QWidget(chessPage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(435, 0, 343, 527));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(250, 0));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        puzzleNumberLabel = new QLabel(widget);
        puzzleNumberLabel->setObjectName("puzzleNumberLabel");
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Book Antiqua")});
        font7.setPointSize(32);
        puzzleNumberLabel->setFont(font7);

        horizontalLayout_3->addWidget(puzzleNumberLabel);


        verticalLayout->addLayout(horizontalLayout_3);

        puzzleNameLabel = new QLabel(widget);
        puzzleNameLabel->setObjectName("puzzleNameLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(puzzleNameLabel->sizePolicy().hasHeightForWidth());
        puzzleNameLabel->setSizePolicy(sizePolicy2);
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Book Antiqua")});
        font8.setPointSize(10);
        font8.setBold(true);
        puzzleNameLabel->setFont(font8);

        verticalLayout->addWidget(puzzleNameLabel);

        puzzleDifficultyLabel = new QLabel(widget);
        puzzleDifficultyLabel->setObjectName("puzzleDifficultyLabel");
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Book Antiqua")});
        font9.setPointSize(10);
        puzzleDifficultyLabel->setFont(font9);

        verticalLayout->addWidget(puzzleDifficultyLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        turnLabel = new QLabel(widget);
        turnLabel->setObjectName("turnLabel");
        turnLabel->setFont(font7);
        turnLabel->setStyleSheet(QString::fromUtf8("QLabel { color : green; }"));
        turnLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(turnLabel);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setFont(font2);

        verticalLayout->addWidget(label);

        puzzleTimer = new LCDClock(widget);
        puzzleTimer->setObjectName("puzzleTimer");
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(puzzleTimer->sizePolicy().hasHeightForWidth());
        puzzleTimer->setSizePolicy(sizePolicy3);
        puzzleTimer->setMinimumSize(QSize(0, 100));
        puzzleTimer->setSmallDecimalPoint(false);
        puzzleTimer->setMode(QLCDNumber::Dec);
        puzzleTimer->setSegmentStyle(QLCDNumber::Filled);
        puzzleTimer->setProperty("value", QVariant(10.000000000000000));

        verticalLayout->addWidget(puzzleTimer);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        hintButton = new QPushButton(widget_2);
        hintButton->setObjectName("hintButton");
        hintButton->setFont(font2);

        gridLayout->addWidget(hintButton, 1, 0, 1, 1);

        rulesButton = new QPushButton(widget_2);
        rulesButton->setObjectName("rulesButton");
        rulesButton->setFont(font2);

        gridLayout->addWidget(rulesButton, 2, 0, 1, 1);

        retryButton = new QPushButton(widget_2);
        retryButton->setObjectName("retryButton");
        retryButton->setFont(font2);

        gridLayout->addWidget(retryButton, 1, 1, 1, 1);

        quitButton = new QPushButton(widget_2);
        quitButton->setObjectName("quitButton");
        quitButton->setFont(font2);

        gridLayout->addWidget(quitButton, 2, 1, 1, 1);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName("label_5");
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Book Antiqua")});
        font10.setPointSize(13);
        label_5->setFont(font10);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_2);

        chessBoardView = new ChessBoardView(chessPage);
        chessBoardView->setObjectName("chessBoardView");
        chessBoardView->setGeometry(QRect(0, 0, 428, 527));
        allPagesStackedWidget->addWidget(chessPage);
        leaderboardPage = new QWidget();
        leaderboardPage->setObjectName("leaderboardPage");
        horizontalLayout_4 = new QHBoxLayout(leaderboardPage);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        leaderboardBackButton = new QPushButton(leaderboardPage);
        leaderboardBackButton->setObjectName("leaderboardBackButton");
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(leaderboardBackButton->sizePolicy().hasHeightForWidth());
        leaderboardBackButton->setSizePolicy(sizePolicy4);
        leaderboardBackButton->setFont(font3);

        verticalLayout_11->addWidget(leaderboardBackButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_4);


        horizontalLayout_4->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        leaderboardTitle = new QLabel(leaderboardPage);
        leaderboardTitle->setObjectName("leaderboardTitle");
        leaderboardTitle->setFont(font4);

        verticalLayout_12->addWidget(leaderboardTitle);

        leaderboardListWidget = new QListWidget(leaderboardPage);
        leaderboardListWidget->setObjectName("leaderboardListWidget");
        sizePolicy.setHeightForWidth(leaderboardListWidget->sizePolicy().hasHeightForWidth());
        leaderboardListWidget->setSizePolicy(sizePolicy);
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Book Antiqua")});
        font11.setPointSize(18);
        font11.setStyleStrategy(QFont::PreferDefault);
        leaderboardListWidget->setFont(font11);
        leaderboardListWidget->setFrameShape(QFrame::NoFrame);
        leaderboardListWidget->setFrameShadow(QFrame::Plain);

        verticalLayout_12->addWidget(leaderboardListWidget);


        horizontalLayout_4->addLayout(verticalLayout_12);

        allPagesStackedWidget->addWidget(leaderboardPage);

        formLayout->setWidget(0, QFormLayout::SpanningRole, allPagesStackedWidget);


        verticalLayout_9->addLayout(formLayout);

        View->setCentralWidget(centralwidget);
        menubar = new QMenuBar(View);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        View->setMenuBar(menubar);
        statusbar = new QStatusBar(View);
        statusbar->setObjectName("statusbar");
        View->setStatusBar(statusbar);

        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QCoreApplication::translate("View", "View", nullptr));
        titleLabel->setText(QCoreApplication::translate("View", "AKPSE-ieces", nullptr));
        playButtonTitle->setText(QCoreApplication::translate("View", "Play", nullptr));
        rulesButtonTitle->setText(QCoreApplication::translate("View", "Rules", nullptr));
        helpMenuButtonTitle->setText(QCoreApplication::translate("View", "Help Menu", nullptr));
        leaderboardButton->setText(QCoreApplication::translate("View", "Leaderboards", nullptr));
        quitButtonTitle->setText(QCoreApplication::translate("View", "Quit", nullptr));
        backButton->setText(QCoreApplication::translate("View", "Back", nullptr));
        titleLabel_2->setText(QCoreApplication::translate("View", "AKPSE-ieces", nullptr));
        beginnerLabel->setText(QCoreApplication::translate("View", "Easy", nullptr));
        levelOneEasyButton->setText(QCoreApplication::translate("View", "Level 1", nullptr));
        levelTwoEasyButton->setText(QCoreApplication::translate("View", "Level 2", nullptr));
        levelThreeEasyButton->setText(QCoreApplication::translate("View", "Level 3", nullptr));
        levelFourEasyButton->setText(QCoreApplication::translate("View", "Level 4", nullptr));
        normalLabel->setText(QCoreApplication::translate("View", "Medium", nullptr));
        levelFourMediumButton->setText(QCoreApplication::translate("View", "Level 4", nullptr));
        levelTwoMediumButton->setText(QCoreApplication::translate("View", "Level 2", nullptr));
        levelThreeMediumButton->setText(QCoreApplication::translate("View", "Level 3", nullptr));
        levelOneMediumButton->setText(QCoreApplication::translate("View", "Level 1", nullptr));
        hardLabel->setText(QCoreApplication::translate("View", "Hard", nullptr));
        levelFourHardButton->setText(QCoreApplication::translate("View", "Level 4", nullptr));
        levelOneHardButton->setText(QCoreApplication::translate("View", "Level 1", nullptr));
        levelThreeHardButton->setText(QCoreApplication::translate("View", "Level 3", nullptr));
        levelTwoHardButton->setText(QCoreApplication::translate("View", "Level 2", nullptr));
        puzzleNumberLabel->setText(QCoreApplication::translate("View", "Puzzle #", nullptr));
        puzzleNameLabel->setText(QCoreApplication::translate("View", "Name:", nullptr));
        puzzleDifficultyLabel->setText(QCoreApplication::translate("View", "Difficulty:", nullptr));
        turnLabel->setText(QCoreApplication::translate("View", "Player Turn", nullptr));
        label->setText(QCoreApplication::translate("View", "Time Elapsed:", nullptr));
        hintButton->setText(QCoreApplication::translate("View", "Hints", nullptr));
        rulesButton->setText(QCoreApplication::translate("View", "Rules", nullptr));
        retryButton->setText(QCoreApplication::translate("View", "Retry", nullptr));
        quitButton->setText(QCoreApplication::translate("View", "Quit", nullptr));
        label_5->setText(QCoreApplication::translate("View", "Menu:", nullptr));
        leaderboardBackButton->setText(QCoreApplication::translate("View", "Back", nullptr));
        leaderboardTitle->setText(QCoreApplication::translate("View", "LEADERBOARDS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
