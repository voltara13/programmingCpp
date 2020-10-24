/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelMin;
    QLineEdit *lineEditMin;
    QLabel *labelMax;
    QLineEdit *lineEditMax;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelCount;
    QSpinBox *spinBox;
    QPushButton *pushButtonOk;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonClose;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(415, 228);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelMin = new QLabel(centralwidget);
        labelMin->setObjectName(QString::fromUtf8("labelMin"));

        verticalLayout_2->addWidget(labelMin);

        lineEditMin = new QLineEdit(centralwidget);
        lineEditMin->setObjectName(QString::fromUtf8("lineEditMin"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditMin->sizePolicy().hasHeightForWidth());
        lineEditMin->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEditMin);

        labelMax = new QLabel(centralwidget);
        labelMax->setObjectName(QString::fromUtf8("labelMax"));

        verticalLayout_2->addWidget(labelMax);

        lineEditMax = new QLineEdit(centralwidget);
        lineEditMax->setObjectName(QString::fromUtf8("lineEditMax"));
        sizePolicy.setHeightForWidth(lineEditMax->sizePolicy().hasHeightForWidth());
        lineEditMax->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEditMax);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelCount = new QLabel(centralwidget);
        labelCount->setObjectName(QString::fromUtf8("labelCount"));

        verticalLayout->addWidget(labelCount);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(spinBox);


        horizontalLayout->addLayout(verticalLayout);

        pushButtonOk = new QPushButton(centralwidget);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));
        sizePolicy.setHeightForWidth(pushButtonOk->sizePolicy().hasHeightForWidth());
        pushButtonOk->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButtonOk);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButtonClose = new QPushButton(centralwidget);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));
        sizePolicy.setHeightForWidth(pushButtonClose->sizePolicy().hasHeightForWidth());
        pushButtonClose->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pushButtonClose);


        horizontalLayout_2->addLayout(verticalLayout_2);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(plainTextEdit);

        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(lineEditMin, lineEditMax);
        QWidget::setTabOrder(lineEditMax, spinBox);
        QWidget::setTabOrder(spinBox, pushButtonOk);
        QWidget::setTabOrder(pushButtonOk, pushButtonClose);
        QWidget::setTabOrder(pushButtonClose, plainTextEdit);

        retranslateUi(MainWindow);
        QObject::connect(pushButtonClose, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(pushButtonOk, SIGNAL(clicked()), MainWindow, SLOT(generate()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelMin->setText(QCoreApplication::translate("MainWindow", "Minimum", nullptr));
        lineEditMin->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelMax->setText(QCoreApplication::translate("MainWindow", "Maximum", nullptr));
        lineEditMax->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        labelCount->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        pushButtonOk->setText(QCoreApplication::translate("MainWindow", "Ok", nullptr));
        pushButtonClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
