/********************************************************************************
** Form generated from reading UI file 'userinfoinsert.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOINSERT_H
#define UI_USERINFOINSERT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userinfoinsert
{
public:
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidgetInsert;

    void setupUi(QWidget *userinfoinsert)
    {
        if (userinfoinsert->objectName().isEmpty())
            userinfoinsert->setObjectName(QStringLiteral("userinfoinsert"));
        userinfoinsert->resize(874, 499);
        verticalLayout_2 = new QVBoxLayout(userinfoinsert);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableWidgetInsert = new QTableWidget(userinfoinsert);
        if (tableWidgetInsert->columnCount() < 6)
            tableWidgetInsert->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetInsert->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetInsert->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetInsert->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetInsert->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetInsert->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetInsert->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidgetInsert->rowCount() < 4)
            tableWidgetInsert->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetInsert->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetInsert->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetInsert->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetInsert->setVerticalHeaderItem(3, __qtablewidgetitem9);
        tableWidgetInsert->setObjectName(QStringLiteral("tableWidgetInsert"));

        verticalLayout_2->addWidget(tableWidgetInsert);


        retranslateUi(userinfoinsert);

        QMetaObject::connectSlotsByName(userinfoinsert);
    } // setupUi

    void retranslateUi(QWidget *userinfoinsert)
    {
        userinfoinsert->setWindowTitle(QApplication::translate("userinfoinsert", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetInsert->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("userinfoinsert", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetInsert->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("userinfoinsert", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetInsert->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("userinfoinsert", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetInsert->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("userinfoinsert", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetInsert->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("userinfoinsert", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetInsert->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("userinfoinsert", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetInsert->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("userinfoinsert", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetInsert->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("userinfoinsert", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetInsert->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("userinfoinsert", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetInsert->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("userinfoinsert", "\346\226\260\345\273\272\350\241\214", 0));
    } // retranslateUi

};

namespace Ui {
    class userinfoinsert: public Ui_userinfoinsert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOINSERT_H
