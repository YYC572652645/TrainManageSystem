/********************************************************************************
** Form generated from reading UI file 'traininfoselect.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAININFOSELECT_H
#define UI_TRAININFOSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_traininfoselect
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButtonFind;
    QLabel *labelMovie;
    QPushButton *pushButtonRefresh;
    QTableWidget *tableWidget;

    void setupUi(QWidget *traininfoselect)
    {
        if (traininfoselect->objectName().isEmpty())
            traininfoselect->setObjectName(QStringLiteral("traininfoselect"));
        traininfoselect->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(traininfoselect);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(traininfoselect);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButtonFind = new QPushButton(traininfoselect);
        pushButtonFind->setObjectName(QStringLiteral("pushButtonFind"));
        pushButtonFind->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/serch.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonFind->setIcon(icon);

        horizontalLayout->addWidget(pushButtonFind);

        labelMovie = new QLabel(traininfoselect);
        labelMovie->setObjectName(QStringLiteral("labelMovie"));
        labelMovie->setPixmap(QPixmap(QString::fromUtf8(":/image/image/refresh.png")));

        horizontalLayout->addWidget(labelMovie);

        pushButtonRefresh = new QPushButton(traininfoselect);
        pushButtonRefresh->setObjectName(QStringLiteral("pushButtonRefresh"));
        pushButtonRefresh->setMinimumSize(QSize(40, 0));
        pushButtonRefresh->setMaximumSize(QSize(40, 16777215));
        pushButtonRefresh->setStyleSheet(QLatin1String("QPushButton:hover\n"
"{\n"
"    color:skyblue;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"background-color:transparent;\n"
"}"));

        horizontalLayout->addWidget(pushButtonRefresh);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(traininfoselect);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(traininfoselect);

        QMetaObject::connectSlotsByName(traininfoselect);
    } // setupUi

    void retranslateUi(QWidget *traininfoselect)
    {
        traininfoselect->setWindowTitle(QApplication::translate("traininfoselect", "Form", 0));
        pushButtonFind->setText(QApplication::translate("traininfoselect", "    \346\237\245\346\211\276", 0));
        labelMovie->setText(QString());
        pushButtonRefresh->setText(QApplication::translate("traininfoselect", "\345\210\267\346\226\260", 0));
    } // retranslateUi

};

namespace Ui {
    class traininfoselect: public Ui_traininfoselect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAININFOSELECT_H
