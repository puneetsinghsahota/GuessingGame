/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication2.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION2_H
#define UI_QTGUIAPPLICATION2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication2Class
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *guesstheNuymber;
    QLineEdit *guessedNumberTextBox;
    QGroupBox *groupBox_3;
    QLabel *commentsLabel;
    QPushButton *GoButton;
    QGraphicsView *graphicsViewMore;
    QGroupBox *displayGroupBox;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *QtGuiApplication2Class)
    {
        if (QtGuiApplication2Class->objectName().isEmpty())
            QtGuiApplication2Class->setObjectName(QStringLiteral("QtGuiApplication2Class"));
        QtGuiApplication2Class->resize(655, 635);
        centralWidget = new QWidget(QtGuiApplication2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 511, 61));
        guesstheNuymber = new QLabel(groupBox);
        guesstheNuymber->setObjectName(QStringLiteral("guesstheNuymber"));
        guesstheNuymber->setGeometry(QRect(20, 20, 111, 20));
        guessedNumberTextBox = new QLineEdit(groupBox);
        guessedNumberTextBox->setObjectName(QStringLiteral("guessedNumberTextBox"));
        guessedNumberTextBox->setGeometry(QRect(160, 20, 31, 20));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 60, 511, 61));
        commentsLabel = new QLabel(groupBox_3);
        commentsLabel->setObjectName(QStringLiteral("commentsLabel"));
        commentsLabel->setGeometry(QRect(280, 10, 231, 41));
        GoButton = new QPushButton(groupBox_3);
        GoButton->setObjectName(QStringLiteral("GoButton"));
        GoButton->setGeometry(QRect(10, 20, 41, 31));
        graphicsViewMore = new QGraphicsView(centralWidget);
        graphicsViewMore->setObjectName(QStringLiteral("graphicsViewMore"));
        graphicsViewMore->setGeometry(QRect(530, 0, 121, 121));
        displayGroupBox = new QGroupBox(centralWidget);
        displayGroupBox->setObjectName(QStringLiteral("displayGroupBox"));
        displayGroupBox->setGeometry(QRect(9, 119, 641, 501));
        QtGuiApplication2Class->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(QtGuiApplication2Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGuiApplication2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(QtGuiApplication2Class);

        QMetaObject::connectSlotsByName(QtGuiApplication2Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication2Class)
    {
        QtGuiApplication2Class->setWindowTitle(QApplication::translate("QtGuiApplication2Class", "QtGuiApplication2", nullptr));
        groupBox->setTitle(QApplication::translate("QtGuiApplication2Class", "Guess It !!", nullptr));
        guesstheNuymber->setText(QApplication::translate("QtGuiApplication2Class", "Guess The Number : ", nullptr));
        groupBox_3->setTitle(QApplication::translate("QtGuiApplication2Class", "Result", nullptr));
        commentsLabel->setText(QApplication::translate("QtGuiApplication2Class", "Comments : ", nullptr));
        GoButton->setText(QApplication::translate("QtGuiApplication2Class", "GO >", nullptr));
        displayGroupBox->setTitle(QApplication::translate("QtGuiApplication2Class", "Display Guesses", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication2Class: public Ui_QtGuiApplication2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION2_H
