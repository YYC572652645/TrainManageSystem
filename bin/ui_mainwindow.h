/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTrainInfoSelect;
    QAction *actionTrainInfoInsert;
    QAction *actionUserInfoInsert;
    QAction *actionUserInfoSelect;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidgetInsert;
    QLineEdit *lineEdit;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(833, 630);
        actionTrainInfoSelect = new QAction(MainWindow);
        actionTrainInfoSelect->setObjectName(QStringLiteral("actionTrainInfoSelect"));
        actionTrainInfoSelect->setCheckable(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/trainSelect.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionTrainInfoSelect->setIcon(icon);
        actionTrainInfoInsert = new QAction(MainWindow);
        actionTrainInfoInsert->setObjectName(QStringLiteral("actionTrainInfoInsert"));
        actionTrainInfoInsert->setIcon(icon);
        actionUserInfoInsert = new QAction(MainWindow);
        actionUserInfoInsert->setObjectName(QStringLiteral("actionUserInfoInsert"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/user.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUserInfoInsert->setIcon(icon1);
        actionUserInfoSelect = new QAction(MainWindow);
        actionUserInfoSelect->setObjectName(QStringLiteral("actionUserInfoSelect"));
        actionUserInfoSelect->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidgetInsert = new QTableWidget(centralWidget);
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

        verticalLayout->addWidget(tableWidgetInsert);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(0, 0));

        verticalLayout->addWidget(lineEdit);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(lineEdit, tableWidgetInsert);

        toolBar->addAction(actionTrainInfoInsert);
        toolBar->addAction(actionTrainInfoSelect);
        toolBar->addAction(actionUserInfoInsert);
        toolBar->addAction(actionUserInfoSelect);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionTrainInfoSelect->setText(QApplication::translate("MainWindow", "\345\210\227\350\275\246\344\277\241\346\201\257\346\237\245\350\257\242", 0));
#ifndef QT_NO_TOOLTIP
        actionTrainInfoSelect->setToolTip(QApplication::translate("MainWindow", "\345\210\227\350\275\246\344\277\241\346\201\257\346\237\245\350\257\242", 0));
#endif // QT_NO_TOOLTIP
        actionTrainInfoInsert->setText(QApplication::translate("MainWindow", "\345\210\227\350\275\246\344\277\241\346\201\257\345\275\225\345\205\245", 0));
#ifndef QT_NO_TOOLTIP
        actionTrainInfoInsert->setToolTip(QApplication::translate("MainWindow", "\345\210\227\350\275\246\344\277\241\346\201\257\345\275\225\345\205\245", 0));
#endif // QT_NO_TOOLTIP
        actionUserInfoInsert->setText(QApplication::translate("MainWindow", "\350\256\242\345\215\225\344\277\241\346\201\257\345\275\225\345\205\245", 0));
#ifndef QT_NO_TOOLTIP
        actionUserInfoInsert->setToolTip(QApplication::translate("MainWindow", "\350\256\242\345\215\225\344\277\241\346\201\257\345\275\225\345\205\245", 0));
#endif // QT_NO_TOOLTIP
        actionUserInfoSelect->setText(QApplication::translate("MainWindow", "\350\256\242\345\215\225\344\277\241\346\201\257\346\237\245\350\257\242", 0));
#ifndef QT_NO_TOOLTIP
        actionUserInfoSelect->setToolTip(QApplication::translate("MainWindow", "\350\256\242\345\215\225\344\277\241\346\201\257\346\237\245\350\257\242", 0));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem = tableWidgetInsert->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetInsert->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetInsert->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetInsert->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetInsert->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetInsert->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetInsert->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetInsert->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetInsert->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetInsert->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
