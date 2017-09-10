#ifndef TRAININFOSELECT_H
#define TRAININFOSELECT_H

#include <QWidget>
#include <QTimer>
#include <QMovie>
#include <QMenu>
#include <QContextMenuEvent>
#include "traindata/database.h"
#include <QPaintEvent>
#include <QPainter>

namespace Ui {
class traininfoselect;
}

class TrainInfoSelect : public QWidget
{
    Q_OBJECT

public:
    explicit TrainInfoSelect(QWidget *parent = 0);
    ~TrainInfoSelect();
    void initControl();             //初始化控件
    void createActions();           //创建菜单
    void dataSelect(int type);      //查询数据
    void setFirstSliderValue(float value);

    void setSecondSliderValue(float value);

private slots:
    void updateMovie();                                     //更新gif
    void updateData();                                      //更新数据
    void dataDelete();                                      //删除数据
    void on_pushButtonRefresh_clicked();                    //刷新
    void on_tableWidget_clicked(const QModelIndex &index);  //表格点击
    void on_pushButtonFind_clicked();                       //查询数据

private:
    Ui::traininfoselect *ui;
    void contextMenuEvent(QContextMenuEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
    void paintImage(QWidget * widget, float sliderValue, QString text);
    QTimer *timer;
    QMovie * movie;
    QMenu *menu;                  //菜单
    QAction *update;              //更改
    QAction *del;                 //删除
    QAction *refresh;             //刷新
    int rowCount;                 //获取当前选中行
    int index;
    TrainInfo trainInfo;
    float firstSliderValue;
    float secondSliderValue;
};

#endif // TRAININFOSELECT_H
