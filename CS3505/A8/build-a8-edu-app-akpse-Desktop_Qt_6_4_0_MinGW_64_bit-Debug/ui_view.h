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
    QHBoxLayout *horizontalLayout;
    QStackedWidget *allPagesStackedWidget;
    QWidget *titlePage;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *playButtonTitle;
    QPushButton *rulesButtonTitle;
    QPushButton *helpMenuButtonTitle;
    QPushButton *quitButtonTitle;
    QLabel *titleLabel;
    QWidget *levelSelectorPage;
    QWidget *verticalLayoutWidget_2;
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
    QPushButton *levelOneButton;
    QLabel *normalLabel;
    QScrollArea *normalScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *hardLabel;
    QScrollArea *hardScrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QWidget *chessPage;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *puzzleNumberLabel;
    QPushButton *cogButton;
    QLabel *puzzleNameLabel;
    QLabel *puzzleDifficultyLabel;
    QSpacerItem *verticalSpacer_2;
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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName("View");
        View->resize(800, 752);
        centralwidget = new QWidget(View);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        allPagesStackedWidget = new QStackedWidget(centralwidget);
        allPagesStackedWidget->setObjectName("allPagesStackedWidget");
        titlePage = new QWidget();
        titlePage->setObjectName("titlePage");
        verticalLayoutWidget = new QWidget(titlePage);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(290, 360, 151, 171));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        playButtonTitle = new QPushButton(verticalLayoutWidget);
        playButtonTitle->setObjectName("playButtonTitle");

        verticalLayout_2->addWidget(playButtonTitle);

        rulesButtonTitle = new QPushButton(verticalLayoutWidget);
        rulesButtonTitle->setObjectName("rulesButtonTitle");

        verticalLayout_2->addWidget(rulesButtonTitle);

        helpMenuButtonTitle = new QPushButton(verticalLayoutWidget);
        helpMenuButtonTitle->setObjectName("helpMenuButtonTitle");

        verticalLayout_2->addWidget(helpMenuButtonTitle);

        quitButtonTitle = new QPushButton(verticalLayoutWidget);
        quitButtonTitle->setObjectName("quitButtonTitle");

        verticalLayout_2->addWidget(quitButtonTitle);

        titleLabel = new QLabel(titlePage);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(230, 130, 261, 121));
        QFont font;
        font.setPointSize(50);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);
        allPagesStackedWidget->addWidget(titlePage);
        levelSelectorPage = new QWidget();
        levelSelectorPage->setObjectName("levelSelectorPage");
        verticalLayoutWidget_2 = new QWidget(levelSelectorPage);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(80, 20, 631, 619));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        backButton = new QPushButton(verticalLayoutWidget_2);
        backButton->setObjectName("backButton");

        horizontalLayout_2->addWidget(backButton);

        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        titleLabel_2 = new QLabel(verticalLayoutWidget_2);
        titleLabel_2->setObjectName("titleLabel_2");
        QFont font1;
        font1.setPointSize(30);
        titleLabel_2->setFont(font1);

        horizontalLayout_2->addWidget(titleLabel_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        beginnerLabel = new QLabel(verticalLayoutWidget_2);
        beginnerLabel->setObjectName("beginnerLabel");
        QFont font2;
        font2.setPointSize(20);
        beginnerLabel->setFont(font2);
        beginnerLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, beginnerLabel);

        beginnerScrollArea = new QScrollArea(verticalLayoutWidget_2);
        beginnerScrollArea->setObjectName("beginnerScrollArea");
        beginnerScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 554, 185));
        levelOneButton = new QPushButton(scrollAreaWidgetContents);
        levelOneButton->setObjectName("levelOneButton");
        levelOneButton->setGeometry(QRect(10, 30, 111, 111));
        beginnerScrollArea->setWidget(scrollAreaWidgetContents);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, beginnerScrollArea);

        normalLabel = new QLabel(verticalLayoutWidget_2);
        normalLabel->setObjectName("normalLabel");
        normalLabel->setFont(font2);
        normalLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, normalLabel);

        normalScrollArea = new QScrollArea(verticalLayoutWidget_2);
        normalScrollArea->setObjectName("normalScrollArea");
        normalScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 554, 185));
        normalScrollArea->setWidget(scrollAreaWidgetContents_2);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, normalScrollArea);

        hardLabel = new QLabel(verticalLayoutWidget_2);
        hardLabel->setObjectName("hardLabel");
        hardLabel->setFont(font2);
        hardLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, hardLabel);

        hardScrollArea = new QScrollArea(verticalLayoutWidget_2);
        hardScrollArea->setObjectName("hardScrollArea");
        hardScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 554, 185));
        hardScrollArea->setWidget(scrollAreaWidgetContents_3);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, hardScrollArea);


        verticalLayout_3->addLayout(formLayout_2);

        allPagesStackedWidget->addWidget(levelSelectorPage);
        chessPage = new QWidget();
        chessPage->setObjectName("chessPage");
        widget = new QWidget(chessPage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(435, 0, 343, 527));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(250, 0));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        puzzleNumberLabel = new QLabel(widget);
        puzzleNumberLabel->setObjectName("puzzleNumberLabel");
        QFont font3;
        font3.setPointSize(36);
        puzzleNumberLabel->setFont(font3);

        horizontalLayout_3->addWidget(puzzleNumberLabel);

        cogButton = new QPushButton(widget);
        cogButton->setObjectName("cogButton");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cogButton->sizePolicy().hasHeightForWidth());
        cogButton->setSizePolicy(sizePolicy1);
        cogButton->setMinimumSize(QSize(50, 50));

        horizontalLayout_3->addWidget(cogButton);


        verticalLayout->addLayout(horizontalLayout_3);

        puzzleNameLabel = new QLabel(widget);
        puzzleNameLabel->setObjectName("puzzleNameLabel");

        verticalLayout->addWidget(puzzleNameLabel);

        puzzleDifficultyLabel = new QLabel(widget);
        puzzleDifficultyLabel->setObjectName("puzzleDifficultyLabel");

        verticalLayout->addWidget(puzzleDifficultyLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        puzzleTimer = new LCDClock(widget);
        puzzleTimer->setObjectName("puzzleTimer");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(puzzleTimer->sizePolicy().hasHeightForWidth());
        puzzleTimer->setSizePolicy(sizePolicy2);
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

        gridLayout->addWidget(hintButton, 1, 0, 1, 1);

        rulesButton = new QPushButton(widget_2);
        rulesButton->setObjectName("rulesButton");

        gridLayout->addWidget(rulesButton, 2, 0, 1, 1);

        retryButton = new QPushButton(widget_2);
        retryButton->setObjectName("retryButton");

        gridLayout->addWidget(retryButton, 1, 1, 1, 1);

        quitButton = new QPushButton(widget_2);
        quitButton->setObjectName("quitButton");

        gridLayout->addWidget(quitButton, 2, 1, 1, 1);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_2);

        chessBoardView = new ChessBoardView(chessPage);
        chessBoardView->setObjectName("chessBoardView");
        chessBoardView->setGeometry(QRect(0, 0, 428, 527));
        allPagesStackedWidget->addWidget(chessPage);

        horizontalLayout->addWidget(allPagesStackedWidget);

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
        playButtonTitle->setText(QCoreApplication::translate("View", "Play", nullptr));
        rulesButtonTitle->setText(QCoreApplication::translate("View", "Rules", nullptr));
        helpMenuButtonTitle->setText(QCoreApplication::translate("View", "Help Me(nu)", nullptr));
        quitButtonTitle->setText(QCoreApplication::translate("View", "Quit", nullptr));
        titleLabel->setText(QCoreApplication::translate("View", "Title", nullptr));
        backButton->setText(QCoreApplication::translate("View", "Back", nullptr));
        titleLabel_2->setText(QCoreApplication::translate("View", "Title", nullptr));
        beginnerLabel->setText(QCoreApplication::translate("View", "Simp", nullptr));
        levelOneButton->setText(QCoreApplication::translate("View", "Level 1", nullptr));
        normalLabel->setText(QCoreApplication::translate("View", "Normie", nullptr));
        hardLabel->setText(QCoreApplication::translate("View", "Chad", nullptr));
        puzzleNumberLabel->setText(QCoreApplication::translate("View", "Puzzle #", nullptr));
        cogButton->setText(QCoreApplication::translate("View", "C", nullptr));
        puzzleNameLabel->setText(QCoreApplication::translate("View", "Name", nullptr));
        puzzleDifficultyLabel->setText(QCoreApplication::translate("View", "Difficulty", nullptr));
        label->setText(QCoreApplication::translate("View", "Time Elapsed:", nullptr));
        hintButton->setText(QCoreApplication::translate("View", "Hints", nullptr));
        rulesButton->setText(QCoreApplication::translate("View", "Rules", nullptr));
        retryButton->setText(QCoreApplication::translate("View", "Retry", nullptr));
        quitButton->setText(QCoreApplication::translate("View", "Quit", nullptr));
        label_5->setText(QCoreApplication::translate("View", "Menu:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
