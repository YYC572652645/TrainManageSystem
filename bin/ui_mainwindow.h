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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(618, 527);
        actionTrainInfoSelect = new QAction(MainWindow);
        actionTrainInfoSelect->setObjectName(QStringLiteral("actionTrainInfoSelect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/trainSelect.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionTrainInfoSelect->setIcon(icon);
        actionTrainInfoInsert = new QAction(MainWindow);
        actionTrainInfoInsert->setObjectName(QStringLiteral("actionTrainInfoInsert"));
        actionTrainInfoInsert->setIcon(icon);
        actionUserInfoInsert = new QAction(MainWindow);
        actionUserInfoInsert->setObjectName(QStringLiteral("actionUserInfoInsert"));
        actionUserInfoSelect = new QAction(MainWindow);
        actionUserInfoSelect->setObjectName(QStringLiteral("actionUserInfoSelect"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 618, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionTrainInfoInsert);
        mainToolBar->addAction(actionTrainInfoSelect);
        mainToolBar->addAction(actionUserInfoInsert);
        mainToolBar->addAction(actionUserInfoSelect);

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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
