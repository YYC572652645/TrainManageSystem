#ifndef TRAININFOSELECT_H
#define TRAININFOSELECT_H

#include <QWidget>
#include <QTimer>
#include <QMovie>
#include <QMenu>
#include <QContextMenuEvent>

namespace Ui {
class traininfoselect;
}

class TrainInfoSelect : public QWidget
{
    Q_OBJECT

public:
    explicit TrainInfoSelect(QWidget *parent = 0);
    ~TrainInfoSelect();
    void initControl();
    void createActions();
    void dataSelect();

private slots:
    void updateMovie();
    void on_pushButtonRefresh_clicked();

private:
    Ui::traininfoselect *ui;
    void contextMenuEvent(QContextMenuEvent *event);
    QTimer *timer;
    QMovie * movie;
    QMenu *menu;                  //菜单
    QAction *update;              //更改
    QAction *del;                 //删除
    QAction *refresh;             //刷新
};

#endif // TRAININFOSELECT_H
