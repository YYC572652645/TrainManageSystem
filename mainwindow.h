#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>

class TrainInfoSelect;
class UserInfoInsert;
class UserInfoSelect;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void insertData(); //插入数据槽函数

    void on_actionTrainInfoSelect_triggered();

    void on_actionTrainInfoInsert_triggered();

private slots:
    void on_actionUserInfoInsert_triggered();

    void on_actionUserInfoSelect_triggered();

private:
    Ui::MainWindow *ui;


    void initControl();   //初始化控件

    void initData();      //初始化数据

private:
    QLineEdit *lineEditTrainNumber;     //车次
    QComboBox *comboBoxTrainType;       //分类
    QLineEdit *lineEditStartStation;    //起始站
    QLineEdit *lineEditEndStation;      //终点站
    QDateEdit *dateEditStartTime;       //发车时间
    QDateEdit *dateEditEndTime;         //到站时间
    QLineEdit *lineEditHardSeat;        //硬座
    QLineEdit *lineEditSleepSeat;       //卧铺
    QLineEdit *lineEditSeatMoney;       //票价
    QPushButton * insertButton;         //录入信息

    TrainInfoSelect * trainInfoSelect;  //列车信息查询
    UserInfoInsert * userInfoInsert;    //用户信息录入
    UserInfoSelect * userInfoSelect;    //用户信息查询
};

#endif // MAINWINDOW_H
