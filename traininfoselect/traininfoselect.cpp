#include "traininfoselect.h"
#include "ui_traininfoselect.h"
#include "traindata/database.h"
#include "globaldef.h"
#include <QVBoxLayout>

TrainInfoSelect::TrainInfoSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::traininfoselect)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    movie = new QMovie(":/image/image/refresh.gif");

    connect(timer, SIGNAL(timeout()), this, SLOT(updateMovie()));
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
/*******************   刷新数据       ***********************/
void TrainInfoSelect::on_pushButtonRefresh_clicked()
{
    ui->labelMovie->setMovie(movie);
    movie->start();

    int dataCount = dataCount = DATABASE->selectTrainData();  //查询出的数据条数

    if(dataCount == GLOBALDEF::ERROR) return;

    ui->tableWidget->setRowCount(dataCount);    //设置表格行数

    for(int i = 0; i < dataCount; i ++)
    {
        ui->tableWidget->setItem(i, 0, DATA(DATABASE->getTrainData().at(i).trainNumber));
        ui->tableWidget->setItem(i, 1, DATA(DATABASE->getTrainData().at(i).trainType));
        ui->tableWidget->setItem(i, 2, DATA(DATABASE->getTrainData().at(i).startStation));
        ui->tableWidget->setItem(i, 3, DATA(DATABASE->getTrainData().at(i).endStation));
        ui->tableWidget->setItem(i, 4, DATA(DATABASE->getTrainData().at(i).startTime));
        ui->tableWidget->setItem(i, 5, DATA(DATABASE->getTrainData().at(i).endTime));
        ui->tableWidget->setItem(i, 6, DATA(DATABASE->getTrainData().at(i).sleeperSeatNumber));
        ui->tableWidget->setItem(i, 7, DATA(DATABASE->getTrainData().at(i).hardSeadNumber));
        ui->tableWidget->setItem(i, 8, DATA(DATABASE->getTrainData().at(i).seatMoney));
    }

    //滑动至最后一行
    ui->tableWidget->scrollToBottom();

    //设置第一行为当前选中行
    if(dataCount != 0)
    {
        ui->tableWidget->selectRow(dataCount - 1);
        ui->tableWidget->setFocus();
    }

    timer->start(3500);
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

    //设置为不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget->setStyleSheet("QTableView QHeaderView::section {background-color:#EAE9EE}");

    //设置表头点击禁止塌陷
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);

    //设置点击表头排序
    ui->tableWidget->setSortingEnabled(true);

    //设置根据内容调整列宽
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);

    //创建菜单
    this->createActions();
}

/*******************   创建菜单    ***********************/
void TrainInfoSelect::createActions()
{
    menu    = new QMenu(this);
    update   = new QAction(QIcon(GLOBALDEF::PRINTICON),   "打印", this);
    refresh = new QAction(QIcon(GLOBALDEF::REFRESHICON), "刷新", this);
    del     = new QAction(QIcon(GLOBALDEF::DELETEICON),  "删除", this);

    connect(update,   SIGNAL(triggered(bool)), this,SLOT(on_actionPrintLabel_triggered()));
    connect(refresh, SIGNAL(triggered(bool)), this,SLOT(on_pushButtonRefresh_clicked()));
    connect(del,     SIGNAL(triggered(bool)), this,SLOT(on_actionDeleteInfo_triggered()));
}
