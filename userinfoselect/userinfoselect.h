#ifndef USERINFOSELECT_H
#define USERINFOSELECT_H

#include <QWidget>

namespace Ui {
class userinfoselect;
}

class UserInfoSelect : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfoSelect(QWidget *parent = 0);
    ~UserInfoSelect();

private:
    Ui::userinfoselect *ui;
};

#endif // USERINFOSELECT_H
