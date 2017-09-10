#ifndef USERINFOINSERT_H
#define USERINFOINSERT_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>

namespace Ui {
class userinfoinsert;
}

class UserInfoInsert : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfoInsert(QWidget *parent = 0);
    ~UserInfoInsert();

    void initControl();

private slots:
    void insertData();
    void seatMoneyChange(int value);
    void seatNumberChange(int value);

private:
    Ui::userinfoinsert *ui;

    QLineEdit *lineEditIDCardNumber;    //身份证号
    QLineEdit *lineEditTrainNumber;     //车次
    QDateEdit *dateEditDateTime;        //时间
    QComboBox *comboBoxSeatType;        //座位类型
    QSpinBox  *spinBoxSeatMoney;        //票价
    QSpinBox  *spinBoxSeatNumber;       //票数
    QLineEdit *lineEditTotalMoney;      //总价钱

    QPushButton * insertButton;         //录入信息
};

#endif // USERINFOINSERT_H
