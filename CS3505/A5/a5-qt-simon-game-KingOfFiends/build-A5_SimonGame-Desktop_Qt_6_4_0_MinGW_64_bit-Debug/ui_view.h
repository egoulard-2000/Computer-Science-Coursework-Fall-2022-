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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QWidget *centralwidget;
    QPushButton *StartButton;
    QPushButton *BlueButton;
    QPushButton *RedButton;
    QLabel *ProgressLabel;
    QProgressBar *ProgressBar;
    QLabel *LoseLabel;
    QLabel *HighScoreLabel;
    QLabel *HighScoreVar;
    QLabel *InstructionLabel;
    QLabel *ControlLabelRed;
    QLabel *ControlLabelBlue;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName("View");
        View->resize(800, 600);
        centralwidget = new QWidget(View);
        centralwidget->setObjectName("centralwidget");
        StartButton = new QPushButton(centralwidget);
        StartButton->setObjectName("StartButton");
        StartButton->setEnabled(true);
        StartButton->setGeometry(QRect(300, 230, 91, 31));
        BlueButton = new QPushButton(centralwidget);
        BlueButton->setObjectName("BlueButton");
        BlueButton->setGeometry(QRect(350, 110, 141, 81));
        RedButton = new QPushButton(centralwidget);
        RedButton->setObjectName("RedButton");
        RedButton->setGeometry(QRect(190, 110, 141, 81));
        ProgressLabel = new QLabel(centralwidget);
        ProgressLabel->setObjectName("ProgressLabel");
        ProgressLabel->setGeometry(QRect(310, 20, 51, 21));
        ProgressBar = new QProgressBar(centralwidget);
        ProgressBar->setObjectName("ProgressBar");
        ProgressBar->setGeometry(QRect(280, 40, 151, 23));
        ProgressBar->setValue(0);
        LoseLabel = new QLabel(centralwidget);
        LoseLabel->setObjectName("LoseLabel");
        LoseLabel->setGeometry(QRect(290, 110, 191, 81));
        QFont font;
        font.setPointSize(24);
        LoseLabel->setFont(font);
        HighScoreLabel = new QLabel(centralwidget);
        HighScoreLabel->setObjectName("HighScoreLabel");
        HighScoreLabel->setGeometry(QRect(40, 20, 141, 31));
        QFont font1;
        font1.setPointSize(15);
        HighScoreLabel->setFont(font1);
        HighScoreVar = new QLabel(centralwidget);
        HighScoreVar->setObjectName("HighScoreVar");
        HighScoreVar->setGeometry(QRect(150, 20, 71, 31));
        HighScoreVar->setFont(font1);
        InstructionLabel = new QLabel(centralwidget);
        InstructionLabel->setObjectName("InstructionLabel");
        InstructionLabel->setGeometry(QRect(490, 280, 171, 71));
        InstructionLabel->setFont(font1);
        ControlLabelRed = new QLabel(centralwidget);
        ControlLabelRed->setObjectName("ControlLabelRed");
        ControlLabelRed->setGeometry(QRect(510, 310, 141, 61));
        QFont font2;
        font2.setPointSize(10);
        ControlLabelRed->setFont(font2);
        ControlLabelBlue = new QLabel(centralwidget);
        ControlLabelBlue->setObjectName("ControlLabelBlue");
        ControlLabelBlue->setGeometry(QRect(510, 340, 141, 51));
        ControlLabelBlue->setFont(font2);
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
        StartButton->setText(QCoreApplication::translate("View", "Start Game!", nullptr));
        BlueButton->setText(QString());
        RedButton->setText(QString());
        ProgressLabel->setText(QCoreApplication::translate("View", "Progress:", nullptr));
        ProgressBar->setFormat(QCoreApplication::translate("View", "%p%", nullptr));
        LoseLabel->setText(QCoreApplication::translate("View", "You Lose!", nullptr));
        HighScoreLabel->setText(QCoreApplication::translate("View", "High Score: ", nullptr));
        HighScoreVar->setText(QCoreApplication::translate("View", "0", nullptr));
        InstructionLabel->setText(QCoreApplication::translate("View", "Keyboard Controls", nullptr));
        ControlLabelRed->setText(QCoreApplication::translate("View", "R Key: Press Red Button", nullptr));
        ControlLabelBlue->setText(QCoreApplication::translate("View", "B Key: Press Blue Button", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
