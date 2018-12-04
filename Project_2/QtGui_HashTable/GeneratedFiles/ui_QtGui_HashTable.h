/********************************************************************************
** Form generated from reading UI file 'QtGui_HashTable.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUI_HASHTABLE_H
#define UI_QTGUI_HASHTABLE_H

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

class Ui_QtGui_HashTableClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGui_HashTableClass)
    {
        if (QtGui_HashTableClass->objectName().isEmpty())
            QtGui_HashTableClass->setObjectName(QStringLiteral("QtGui_HashTableClass"));
        QtGui_HashTableClass->resize(600, 400);
        menuBar = new QMenuBar(QtGui_HashTableClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtGui_HashTableClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGui_HashTableClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGui_HashTableClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtGui_HashTableClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtGui_HashTableClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtGui_HashTableClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGui_HashTableClass->setStatusBar(statusBar);

        retranslateUi(QtGui_HashTableClass);

        QMetaObject::connectSlotsByName(QtGui_HashTableClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGui_HashTableClass)
    {
        QtGui_HashTableClass->setWindowTitle(QApplication::translate("QtGui_HashTableClass", "QtGui_HashTable", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtGui_HashTableClass: public Ui_QtGui_HashTableClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUI_HASHTABLE_H
