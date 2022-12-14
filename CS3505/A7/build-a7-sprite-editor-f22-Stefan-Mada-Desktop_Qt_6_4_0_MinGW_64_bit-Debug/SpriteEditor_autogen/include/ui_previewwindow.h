/********************************************************************************
** Form generated from reading UI file 'previewwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWWINDOW_H
#define UI_PREVIEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "graphicsdrawview.h"

QT_BEGIN_NAMESPACE

class Ui_PreviewWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    GraphicsDrawView *graphicsView;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *actualSizeCheckbox;

    void setupUi(QDialog *PreviewWindow)
    {
        if (PreviewWindow->objectName().isEmpty())
            PreviewWindow->setObjectName("PreviewWindow");
        PreviewWindow->resize(600, 500);
        verticalLayout_2 = new QVBoxLayout(PreviewWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        graphicsView = new GraphicsDrawView(PreviewWindow);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setLineWidth(1);
        QBrush brush(QColor(0, 0, 0, 0));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::NoBrush);
        graphicsView->setForegroundBrush(brush1);
        graphicsView->setInteractive(true);

        horizontalLayout->addWidget(graphicsView);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        actualSizeCheckbox = new QCheckBox(PreviewWindow);
        actualSizeCheckbox->setObjectName("actualSizeCheckbox");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(actualSizeCheckbox->sizePolicy().hasHeightForWidth());
        actualSizeCheckbox->setSizePolicy(sizePolicy1);
        actualSizeCheckbox->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(actualSizeCheckbox);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(PreviewWindow);

        QMetaObject::connectSlotsByName(PreviewWindow);
    } // setupUi

    void retranslateUi(QDialog *PreviewWindow)
    {
        PreviewWindow->setWindowTitle(QCoreApplication::translate("PreviewWindow", "Dialog", nullptr));
        actualSizeCheckbox->setText(QCoreApplication::translate("PreviewWindow", "Actual Size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PreviewWindow: public Ui_PreviewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWWINDOW_H
