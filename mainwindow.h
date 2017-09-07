#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //初始化控件
    void initControl();


private:
    QLineEdit *lineEditTrainNumber;  //车次
    QComboBox *comboBoxTrainType;    //分类
    QLineEdit *lineEditStartStation; //起始站
    QLineEdit *lineEditEndStation;   //终点站
    QDateEdit *dateEditStartTime;    //发车时间
    QDateEdit *dateEditEndTime;      //到站时间
    QLineEdit *lineEditHardSeat;     //硬座
    QLineEdit *lineEditSleepSeat;    //卧铺
    QLineEdit *lineEditSeatMoney;    //票价
    QPushButton * insertButton;      //录入信息
};

#endif // MAINWINDOW_H
