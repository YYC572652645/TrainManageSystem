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
        traininfoselect->resize(736, 300);
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
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
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
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("traininfoselect", "\350\275\246\346\254\241", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("traininfoselect", "\345\210\206\347\261\273", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("traininfoselect", "\350\265\267\347\202\271\347\253\231", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("traininfoselect", "\347\273\210\347\202\271\347\253\231", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("traininfoselect", "\345\217\221\350\275\246\346\227\266\351\227\264", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("traininfoselect", "\345\210\260\347\253\231\346\227\266\351\227\264", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("traininfoselect", "\347\241\254\345\272\247\345\272\247\344\275\215", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("traininfoselect", "\345\215\247\351\223\272\345\272\247\344\275\215", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("traininfoselect", "\347\245\250\344\273\267", 0));
    } // retranslateUi

};

namespace Ui {
    class traininfoselect: public Ui_traininfoselect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAININFOSELECT_H
