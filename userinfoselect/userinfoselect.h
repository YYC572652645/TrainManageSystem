#ifndef USERINFOSELECT_H
#define USERINFOSELECT_H

#include <QWidget>
#include <QMovie>
#include <QMenu>
#include <QTimer>
#include <QContextMenuEvent>

namespace Ui {
class userinfoselect;
}

class UserInfoSelect : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfoSelect(QWidget *parent = 0);
    ~UserInfoSelect();

      void createActions();

      void initControl();

private slots:
    void updateMovie();
    void on_pushButtonRefresh_clicked();

private:
    Ui::userinfoselect *ui;

    void contextMenuEvent(QContextMenuEvent *event);
    QTimer  *timer;
    QMovie  *movie;
    QMenu   *menu;                //菜单
    QAction *update;              //更改
    QAction *del;                 //删除
    QAction *refresh;             //刷新
};

#endif // USERINFOSELECT_H
