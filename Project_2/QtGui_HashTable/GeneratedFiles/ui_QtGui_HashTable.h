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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGui_HashTableClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_editItem;
    QLabel *label_editItem;
    QLineEdit *lineEdit_editItem_key;
    QLineEdit *lineEdit_editItem_value;
    QPushButton *pushButton_editItem_save;
    QPushButton *pushButton_editItem_remove;
    QTableView *tableView;
    QWidget *widget;
    QVBoxLayout *verticalLayout_controls;
    QVBoxLayout *verticalLayout_addKey;
    QLabel *label_addItem;
    QLineEdit *lineEdit_addItem_key;
    QLineEdit *lineEdit_addItem_value;
    QPushButton *pushButton_addItem;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_findItem;
    QLabel *label_findItem;
    QLineEdit *lineEdit_findItem;
    QPushButton *pushButton_findKey;
    QLabel *label_findItem_count;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_clear;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_getTop;
    QLabel *label_getTop;
    QLineEdit *lineEdit_getTop;
    QPushButton *pushButton_getTop;

    void setupUi(QMainWindow *QtGui_HashTableClass)
    {
        if (QtGui_HashTableClass->objectName().isEmpty())
            QtGui_HashTableClass->setObjectName(QStringLiteral("QtGui_HashTableClass"));
        QtGui_HashTableClass->resize(431, 514);
        QtGui_HashTableClass->setMinimumSize(QSize(431, 514));
        centralWidget = new QWidget(QtGui_HashTableClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 380, 137, 125));
        verticalLayout_editItem = new QVBoxLayout(layoutWidget);
        verticalLayout_editItem->setSpacing(6);
        verticalLayout_editItem->setContentsMargins(11, 11, 11, 11);
        verticalLayout_editItem->setObjectName(QStringLiteral("verticalLayout_editItem"));
        verticalLayout_editItem->setContentsMargins(0, 0, 0, 0);
        label_editItem = new QLabel(layoutWidget);
        label_editItem->setObjectName(QStringLiteral("label_editItem"));
        label_editItem->setAlignment(Qt::AlignCenter);

        verticalLayout_editItem->addWidget(label_editItem);

        lineEdit_editItem_key = new QLineEdit(layoutWidget);
        lineEdit_editItem_key->setObjectName(QStringLiteral("lineEdit_editItem_key"));

        verticalLayout_editItem->addWidget(lineEdit_editItem_key);

        lineEdit_editItem_value = new QLineEdit(layoutWidget);
        lineEdit_editItem_value->setObjectName(QStringLiteral("lineEdit_editItem_value"));

        verticalLayout_editItem->addWidget(lineEdit_editItem_value);

        pushButton_editItem_save = new QPushButton(layoutWidget);
        pushButton_editItem_save->setObjectName(QStringLiteral("pushButton_editItem_save"));

        verticalLayout_editItem->addWidget(pushButton_editItem_save);

        pushButton_editItem_remove = new QPushButton(layoutWidget);
        pushButton_editItem_remove->setObjectName(QStringLiteral("pushButton_editItem_remove"));

        verticalLayout_editItem->addWidget(pushButton_editItem_remove);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(160, 10, 256, 192));
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableView->setSortingEnabled(true);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 137, 367));
        verticalLayout_controls = new QVBoxLayout(widget);
        verticalLayout_controls->setSpacing(6);
        verticalLayout_controls->setContentsMargins(11, 11, 11, 11);
        verticalLayout_controls->setObjectName(QStringLiteral("verticalLayout_controls"));
        verticalLayout_controls->setContentsMargins(0, 0, 0, 0);
        verticalLayout_addKey = new QVBoxLayout();
        verticalLayout_addKey->setSpacing(6);
        verticalLayout_addKey->setObjectName(QStringLiteral("verticalLayout_addKey"));
        label_addItem = new QLabel(widget);
        label_addItem->setObjectName(QStringLiteral("label_addItem"));
        label_addItem->setAlignment(Qt::AlignCenter);

        verticalLayout_addKey->addWidget(label_addItem);

        lineEdit_addItem_key = new QLineEdit(widget);
        lineEdit_addItem_key->setObjectName(QStringLiteral("lineEdit_addItem_key"));

        verticalLayout_addKey->addWidget(lineEdit_addItem_key);

        lineEdit_addItem_value = new QLineEdit(widget);
        lineEdit_addItem_value->setObjectName(QStringLiteral("lineEdit_addItem_value"));

        verticalLayout_addKey->addWidget(lineEdit_addItem_value);

        pushButton_addItem = new QPushButton(widget);
        pushButton_addItem->setObjectName(QStringLiteral("pushButton_addItem"));

        verticalLayout_addKey->addWidget(pushButton_addItem);


        verticalLayout_controls->addLayout(verticalLayout_addKey);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_controls->addItem(verticalSpacer);

        verticalLayout_findItem = new QVBoxLayout();
        verticalLayout_findItem->setSpacing(6);
        verticalLayout_findItem->setObjectName(QStringLiteral("verticalLayout_findItem"));
        label_findItem = new QLabel(widget);
        label_findItem->setObjectName(QStringLiteral("label_findItem"));
        label_findItem->setAlignment(Qt::AlignCenter);

        verticalLayout_findItem->addWidget(label_findItem);

        lineEdit_findItem = new QLineEdit(widget);
        lineEdit_findItem->setObjectName(QStringLiteral("lineEdit_findItem"));

        verticalLayout_findItem->addWidget(lineEdit_findItem);

        pushButton_findKey = new QPushButton(widget);
        pushButton_findKey->setObjectName(QStringLiteral("pushButton_findKey"));

        verticalLayout_findItem->addWidget(pushButton_findKey);

        label_findItem_count = new QLabel(widget);
        label_findItem_count->setObjectName(QStringLiteral("label_findItem_count"));

        verticalLayout_findItem->addWidget(label_findItem_count);


        verticalLayout_controls->addLayout(verticalLayout_findItem);

        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_controls->addItem(verticalSpacer_2);

        pushButton_clear = new QPushButton(widget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));

        verticalLayout_controls->addWidget(pushButton_clear);

        verticalSpacer_3 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_controls->addItem(verticalSpacer_3);

        verticalLayout_getTop = new QVBoxLayout();
        verticalLayout_getTop->setSpacing(6);
        verticalLayout_getTop->setObjectName(QStringLiteral("verticalLayout_getTop"));
        label_getTop = new QLabel(widget);
        label_getTop->setObjectName(QStringLiteral("label_getTop"));
        label_getTop->setAlignment(Qt::AlignCenter);

        verticalLayout_getTop->addWidget(label_getTop);

        lineEdit_getTop = new QLineEdit(widget);
        lineEdit_getTop->setObjectName(QStringLiteral("lineEdit_getTop"));

        verticalLayout_getTop->addWidget(lineEdit_getTop);

        pushButton_getTop = new QPushButton(widget);
        pushButton_getTop->setObjectName(QStringLiteral("pushButton_getTop"));

        verticalLayout_getTop->addWidget(pushButton_getTop);


        verticalLayout_controls->addLayout(verticalLayout_getTop);

        QtGui_HashTableClass->setCentralWidget(centralWidget);
        label_addItem->raise();
        lineEdit_addItem_key->raise();
        lineEdit_addItem_value->raise();
        pushButton_addItem->raise();
        layoutWidget->raise();
        label_findItem_count->raise();
        pushButton_findKey->raise();
        pushButton_clear->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        label_findItem->raise();
        tableView->raise();

        retranslateUi(QtGui_HashTableClass);

        QMetaObject::connectSlotsByName(QtGui_HashTableClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGui_HashTableClass)
    {
        QtGui_HashTableClass->setWindowTitle(QApplication::translate("QtGui_HashTableClass", "QtGui_HashTable", Q_NULLPTR));
        label_editItem->setText(QApplication::translate("QtGui_HashTableClass", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260", Q_NULLPTR));
        lineEdit_editItem_key->setInputMask(QString());
        lineEdit_editItem_key->setPlaceholderText(QApplication::translate("QtGui_HashTableClass", "\320\232\320\273\321\216\321\207", Q_NULLPTR));
        lineEdit_editItem_value->setInputMask(QString());
        lineEdit_editItem_value->setPlaceholderText(QApplication::translate("QtGui_HashTableClass", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        pushButton_editItem_save->setText(QApplication::translate("QtGui_HashTableClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        pushButton_editItem_remove->setText(QApplication::translate("QtGui_HashTableClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        label_addItem->setText(QApplication::translate("QtGui_HashTableClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\273\321\216\321\207", Q_NULLPTR));
        lineEdit_addItem_key->setInputMask(QString());
        lineEdit_addItem_key->setPlaceholderText(QApplication::translate("QtGui_HashTableClass", "\320\232\320\273\321\216\321\207", Q_NULLPTR));
        lineEdit_addItem_value->setInputMask(QString());
        lineEdit_addItem_value->setPlaceholderText(QApplication::translate("QtGui_HashTableClass", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        pushButton_addItem->setText(QApplication::translate("QtGui_HashTableClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        label_findItem->setText(QApplication::translate("QtGui_HashTableClass", "\320\237\320\276\320\270\321\201\320\272 \320\272\320\273\321\216\321\207\320\260", Q_NULLPTR));
        lineEdit_findItem->setInputMask(QString());
        lineEdit_findItem->setPlaceholderText(QApplication::translate("QtGui_HashTableClass", "\320\232\320\273\321\216\321\207", Q_NULLPTR));
        pushButton_findKey->setText(QApplication::translate("QtGui_HashTableClass", "\320\237\320\276\320\270\321\201\320\272", Q_NULLPTR));
        label_findItem_count->setText(QApplication::translate("QtGui_HashTableClass", "\320\235\320\265 \320\275\320\260\320\271\320\264\320\265\320\275\320\276", Q_NULLPTR));
        pushButton_clear->setText(QApplication::translate("QtGui_HashTableClass", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", Q_NULLPTR));
        label_getTop->setText(QApplication::translate("QtGui_HashTableClass", "\320\242\320\236\320\237 \320\267\320\260\320\277\320\270\321\201\320\265\320\271", Q_NULLPTR));
        lineEdit_getTop->setInputMask(QString());
        lineEdit_getTop->setPlaceholderText(QApplication::translate("QtGui_HashTableClass", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        pushButton_getTop->setText(QApplication::translate("QtGui_HashTableClass", "\320\237\320\276\320\270\321\201\320\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtGui_HashTableClass: public Ui_QtGui_HashTableClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUI_HASHTABLE_H
