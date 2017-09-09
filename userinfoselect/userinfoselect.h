#ifndef USERINFOSELECT_H
#define USERINFOSELECT_H

#include <QWidget>
#include <QMovie>
#include <QMenu>
#include <QTimer>
#include <QContextMenuEvent>
#include "traindata/database.h"

namespace Ui {
class userinfoselect;
}

class UserInfoSelect : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfoSelect(QWidget *parent = 0);
    ~UserInfoSelect();

    void initControl();             //初始化控件
    void createActions();           //创建菜单
    void dataSelect(int type);      //查询数据


private slots:
    void updateMovie();                                     //更新gif
    void updateData();                                      //更新数据
    void dataDelete();                                      //删除数据
    void on_pushButtonRefresh_clicked();                    //刷新
    void on_tableWidget_clicked(const QModelIndex &index);  //表格点击
    void on_pushButtonFind_clicked();                       //查询数据

private:
    Ui::userinfoselect *ui;
    void contextMenuEvent(QContextMenuEvent *event);
    QTimer *timer;
    QMovie * movie;
    QMenu *menu;                  //菜单
    QAction *update;              //更改
    QAction *del;                 //删除
    QAction *refresh;             //刷新
    int rowCount;                 //获取当前选中行
    UserInfo userInfo;            //存取选中数据
};

#endif // USERINFOSELECT_H
