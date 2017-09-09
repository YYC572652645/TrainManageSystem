#include "userinfoselect.h"
#include "ui_userinfoselect.h"
#include "globaldef.h"


UserInfoSelect::UserInfoSelect(QWidget *parent) :
    QWidget(parent),rowCount(0),
    ui(new Ui::userinfoselect)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    movie = new QMovie(":/image/image/refresh.gif");

    connect(timer, SIGNAL(timeout()), this, SLOT(updateMovie()));

    this->initControl();

    dataSelect(GLOBALDEF::SELECTALL);
}

UserInfoSelect::~UserInfoSelect()
{
    delete ui;
}

/*******************   更新gif    ***********************/
void UserInfoSelect::updateMovie()
{
    movie->stop();
    timer->stop();
}

/*******************   更新数据       ***********************/
void UserInfoSelect::updateData()
{
    DATABASE->updateUserData(userInfo);
}

/*******************   刷新数据       ***********************/
void UserInfoSelect::on_pushButtonRefresh_clicked()
{
    ui->labelMovie->setMovie(movie);
    movie->start();

    dataSelect(GLOBALDEF::SELECTALL);

    timer->start(GLOBALDEF::REFRESHTIME);
}

/*******************   初始化控件    ***********************/
void UserInfoSelect::initControl()
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
void UserInfoSelect::createActions()
{
    menu    = new QMenu(this);
    update  = new QAction(QIcon(GLOBALDEF::UPDATEICON),  "更新", this);
    refresh = new QAction(QIcon(GLOBALDEF::REFRESHICON),  "刷新" , this);
    del     = new QAction(QIcon(GLOBALDEF::DELETEICON) ,  "删除", this);

    connect(update,  SIGNAL(triggered(bool)), this,SLOT(updateData()));
    connect(refresh, SIGNAL(triggered(bool)), this,SLOT(on_pushButtonRefresh_clicked()));
    connect(del,     SIGNAL(triggered(bool)), this,SLOT(dataDelete()));
}

void UserInfoSelect::dataSelect(int type)
{
    int dataCount = DATABASE->selectUserData(type, ui->lineEdit->text()); //查询出的数据条数

    if(dataCount == GLOBALDEF::ERROR) return;

    ui->tableWidget->setRowCount(dataCount);          //设置表格行数

    for(int i = 0; i < DATABASE->getUserData().size(); i ++)
    {
        ui->tableWidget->setItem(i, GLOBALDEF::IDCARDNUMBER,      DATA(DATABASE->getUserData().at(i).idCardNumber));
        ui->tableWidget->setItem(i, GLOBALDEF::USERTRAINNUMBER,   DATA(DATABASE->getUserData().at(i).trainNumber));
        ui->tableWidget->setItem(i, GLOBALDEF::DATETIME,          DATA(DATABASE->getUserData().at(i).dataTime));
        ui->tableWidget->setItem(i, GLOBALDEF::USERSEATMONEY,     DATA(DATABASE->getUserData().at(i).seatMoney));
        ui->tableWidget->setItem(i, GLOBALDEF::SEATNUMBER,        DATA(DATABASE->getUserData().at(i).seatNumber));
        ui->tableWidget->setItem(i, GLOBALDEF::TOTALMONEY,        DATA(DATABASE->getUserData().at(i).totalMoney));
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
void UserInfoSelect::dataDelete()
{
    DATABASE->deleteUserData(userInfo.idCardNumber);

    dataSelect(GLOBALDEF::SELECTALL);
}

/**************************          显示菜单      ***************************/
void UserInfoSelect::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();

    menu->addAction(update);
    menu->addAction(refresh);
    menu->addAction(del);

    menu->exec(QCursor::pos());

    event->accept();
}

/**************************          表格点击事件      ***************************/
void UserInfoSelect::on_tableWidget_clicked(const QModelIndex &index)
{
    rowCount = index.row();

    for(int i = 0; i < GLOBALDEF::USERINFOMAX; i ++)
    {
        //用户信息表对应枚举
        QTableWidgetItem * item = ui->tableWidget->item(index.row(), i);
        switch(i)
        {
        case GLOBALDEF::IDCARDNUMBER:      userInfo.idCardNumber  = item->text(); break;
        case GLOBALDEF::USERTRAINNUMBER:   userInfo.trainNumber   = item->text(); break;
        case GLOBALDEF::DATETIME:          userInfo.dataTime      = item->text(); break;
        case GLOBALDEF::USERSEATMONEY:     userInfo.seatMoney     = item->text(); break;
        case GLOBALDEF::SEATNUMBER:        userInfo.seatNumber    = item->text(); break;
        case GLOBALDEF::TOTALMONEY:        userInfo.totalMoney    = item->text(); break;
        }
    }
}

/**************************          查询数据      ***************************/
void UserInfoSelect::on_pushButtonFind_clicked()
{
    dataSelect(GLOBALDEF::SELECTLIKE);
}
