/********************************************************************************
** Form generated from reading UI file 'QtGu_CookRobot.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGU_COOKROBOT_H
#define UI_QTGU_COOKROBOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGu_CookRobotClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGu_CookRobotClass)
    {
        if (QtGu_CookRobotClass->objectName().isEmpty())
            QtGu_CookRobotClass->setObjectName(QStringLiteral("QtGu_CookRobotClass"));
        QtGu_CookRobotClass->resize(600, 400);
        menuBar = new QMenuBar(QtGu_CookRobotClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtGu_CookRobotClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGu_CookRobotClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGu_CookRobotClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtGu_CookRobotClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtGu_CookRobotClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtGu_CookRobotClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGu_CookRobotClass->setStatusBar(statusBar);

        retranslateUi(QtGu_CookRobotClass);

        QMetaObject::connectSlotsByName(QtGu_CookRobotClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGu_CookRobotClass)
    {
        QtGu_CookRobotClass->setWindowTitle(QApplication::translate("QtGu_CookRobotClass", "QtGu_CookRobot", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtGu_CookRobotClass: public Ui_QtGu_CookRobotClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGU_COOKROBOT_H
