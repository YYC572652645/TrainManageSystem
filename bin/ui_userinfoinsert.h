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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userinfoinsert
{
public:

    void setupUi(QWidget *userinfoinsert)
    {
        if (userinfoinsert->objectName().isEmpty())
            userinfoinsert->setObjectName(QStringLiteral("userinfoinsert"));
        userinfoinsert->resize(400, 300);

        retranslateUi(userinfoinsert);

        QMetaObject::connectSlotsByName(userinfoinsert);
    } // setupUi

    void retranslateUi(QWidget *userinfoinsert)
    {
        userinfoinsert->setWindowTitle(QApplication::translate("userinfoinsert", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class userinfoinsert: public Ui_userinfoinsert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOINSERT_H
