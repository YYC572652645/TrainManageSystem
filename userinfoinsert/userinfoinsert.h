#ifndef USERINFOINSERT_H
#define USERINFOINSERT_H

#include <QWidget>

namespace Ui {
class userinfoinsert;
}

class UserInfoInsert : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfoInsert(QWidget *parent = 0);
    ~UserInfoInsert();

private:
    Ui::userinfoinsert *ui;
};

#endif // USERINFOINSERT_H
