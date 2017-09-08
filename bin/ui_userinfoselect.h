/********************************************************************************
** Form generated from reading UI file 'userinfoselect.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOSELECT_H
#define UI_USERINFOSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userinfoselect
{
public:

    void setupUi(QWidget *userinfoselect)
    {
        if (userinfoselect->objectName().isEmpty())
            userinfoselect->setObjectName(QStringLiteral("userinfoselect"));
        userinfoselect->resize(400, 300);

        retranslateUi(userinfoselect);

        QMetaObject::connectSlotsByName(userinfoselect);
    } // setupUi

    void retranslateUi(QWidget *userinfoselect)
    {
        userinfoselect->setWindowTitle(QApplication::translate("userinfoselect", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class userinfoselect: public Ui_userinfoselect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOSELECT_H
