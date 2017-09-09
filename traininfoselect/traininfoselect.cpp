#include "traininfoselect.h"
#include "ui_traininfoselect.h"
#include "globaldef.h"
#include <QVBoxLayout>
#include <QDebug>

TrainInfoSelect::TrainInfoSelect(QWidget *parent) :
    QWidget(parent),rowCount(0),
    ui(new Ui::traininfoselect)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    movie = new QMovie(":/image/image/refresh.gif");

    connect(timer, SIGNAL(timeout()), this, SLOT(updateMovie()));

    this->initControl();

    dataSelect(GLOBALDEF::SELECTALL);
}

TrainInfoSelect::~TrainInfoSelect()
{
    delete ui;
}

/*******************   更新gif    ***********************/
void TrainInfoSelect::updateMovie()
{
    movie->stop();
    timer->stop();
}

/*******************   更新数据       ***********************/
void TrainInfoSelect::updateData()
{
    DATABASE->updateTrainData(trainInfo);
}

/*******************   刷新数据       ***********************/
void TrainInfoSelect::on_pushButtonRefresh_clicked()
{
    ui->labelMovie->setMovie(movie);
    movie->start();

    dataSelect(GLOBALDEF::SELECTALL);

    timer->start(GLOBALDEF::REFRESHTIME);
}


/*******************   初始化控件    ***********************/
void TrainInfoSelect::initControl()
{
    //设置单行选中
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);

    //纵向隐藏序号
    QHeaderView *headerView=ui->tableWidget->horizontalHeader();
    headerView=ui->tableWidget->verticalHeader();
    headerView->setHidden(true);

    //设置表头点击禁止塌陷
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);

    //设置点击表头排序
    ui->tableWidget->setSortingEnabled(true);

    //设置根据内容调整列宽
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    //创建菜单
    this->createActions();
}

/*******************   创建菜单    ***********************/
void TrainInfoSelect::createActions()
{
    menu    = new QMenu(this);
    update   = new QAction(QIcon(GLOBALDEF::UPDATEICON),  "更新", this);
    refresh = new QAction(QIcon(GLOBALDEF::REFRESHICON),  "刷新" , this);
    del     = new QAction(QIcon(GLOBALDEF::DELETEICON) ,  "删除", this);

    connect(update,  SIGNAL(triggered(bool)), this,SLOT(updateData()));
    connect(refresh, SIGNAL(triggered(bool)), this,SLOT(on_pushButtonRefresh_clicked()));
    connect(del,     SIGNAL(triggered(bool)), this,SLOT(dataDelete()));
}

void TrainInfoSelect::dataSelect(int type)
{
    int dataCount = DATABASE->selectTrainData(type, ui->lineEdit->text()); //查询出的数据条数

    if(dataCount == GLOBALDEF::ERROR) return;

    ui->tableWidget->setRowCount(dataCount);          //设置表格行数

    for(int i = 0; i < DATABASE->getTrainData().size(); i ++)
    {
        ui->tableWidget->setItem(i, GLOBALDEF::TRAINNUMMBER,      DATA(DATABASE->getTrainData().at(i).trainNumber));
        ui->tableWidget->setItem(i, GLOBALDEF::TRAINTYPE,         DATA(DATABASE->getTrainData().at(i).trainType));
        ui->tableWidget->setItem(i, GLOBALDEF::STARTSTATION,      DATA(DATABASE->getTrainData().at(i).startStation));
        ui->tableWidget->setItem(i, GLOBALDEF::ENDSTATION,        DATA(DATABASE->getTrainData().at(i).endStation));
        ui->tableWidget->setItem(i, GLOBALDEF::STARTTIME,         DATA(DATABASE->getTrainData().at(i).startTime));
        ui->tableWidget->setItem(i, GLOBALDEF::ENDTIME,           DATA(DATABASE->getTrainData().at(i).endTime));
        ui->tableWidget->setItem(i, GLOBALDEF::SLEEPERSEATNUMBER, DATA(DATABASE->getTrainData().at(i).sleeperSeatNumber));
        ui->tableWidget->setItem(i, GLOBALDEF::HARDSEADNUMBER,    DATA(DATABASE->getTrainData().at(i).hardSeadNumber));
        ui->tableWidget->setItem(i, GLOBALDEF::SEATMONEY,         DATA(DATABASE->getTrainData().at(i).seatMoney));
    }

    //滑动至最后一行
    ui->tableWidget->scrollToBottom();

    //设置第一行为当前选中行
    if(dataCount != 0)
    {
        ui->tableWidget->selectRow(dataCount - 1);
        ui->tableWidget->setFocus();
    }
}

/**************************          删除数据      ***************************/
void TrainInfoSelect::dataDelete()
{
    DATABASE->deleteTrainData(trainInfo.trainNumber);

    dataSelect(GLOBALDEF::SELECTALL);
}

/**************************          显示菜单      ***************************/
void TrainInfoSelect::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();

    menu->addAction(update);
    menu->addAction(refresh);
    menu->addAction(del);

    menu->exec(QCursor::pos());

    event->accept();
}

/**************************          表格点击事件      ***************************/
void TrainInfoSelect::on_tableWidget_clicked(const QModelIndex &index)
{
    rowCount = index.row();

    for(int i = 0; i < GLOBALDEF::TRAININFOMAX; i ++)
    {
        QTableWidgetItem * item = ui->tableWidget->item(index.row(), i);
        switch(i)
        {
        case GLOBALDEF::TRAINNUMMBER:      trainInfo.trainNumber       = item->text(); break;
        case GLOBALDEF::TRAINTYPE:         trainInfo.trainType         = item->text(); break;
        case GLOBALDEF::STARTSTATION:      trainInfo.startStation      = item->text(); break;
        case GLOBALDEF::ENDSTATION:        trainInfo.endStation        = item->text(); break;
        case GLOBALDEF::STARTTIME:         trainInfo.startTime         = item->text(); break;
        case GLOBALDEF::ENDTIME:           trainInfo.endTime           = item->text(); break;
        case GLOBALDEF::SLEEPERSEATNUMBER: trainInfo.sleeperSeatNumber = item->text(); break;
        case GLOBALDEF::HARDSEADNUMBER:    trainInfo.hardSeadNumber    = item->text(); break;
        case GLOBALDEF::SEATMONEY:         trainInfo.seatMoney         = item->text(); break;
        }
    }
}

/**************************          查询数据      ***************************/
void TrainInfoSelect::on_pushButtonFind_clicked()
{
    dataSelect(GLOBALDEF::SELECTLIKE);
}
