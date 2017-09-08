#include "userinfoselect.h"
#include "ui_userinfoselect.h"
#include "globaldef.h"


UserInfoSelect::UserInfoSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userinfoselect)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    movie = new QMovie(":/image/image/refresh.gif");

    connect(timer, SIGNAL(timeout()), this, SLOT(updateMovie()));

    this->initControl();
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
/*******************   刷新数据       ***********************/
void UserInfoSelect::on_pushButtonRefresh_clicked()
{
    ui->labelMovie->setMovie(movie);
    movie->start();


    timer->start(3500);
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

    //创建菜单
    this->createActions();
}

/*******************   创建菜单    ***********************/
void UserInfoSelect::createActions()
{
    menu    = new QMenu(this);
    update   = new QAction(QIcon(GLOBALDEF::PRINTICON),  "更新", this);
    refresh = new QAction(QIcon(GLOBALDEF::REFRESHICON), "刷新", this);
    del     = new QAction(QIcon(GLOBALDEF::DELETEICON),  "删除", this);

    //connect(update,  SIGNAL(triggered(bool)), this,SLOT(on_actionPrintLabel_triggered()));
    //connect(refresh, SIGNAL(triggered(bool)), this,SLOT(on_pushButtonRefresh_clicked()));
    //connect(del,     SIGNAL(triggered(bool)), this,SLOT(on_actionDeleteInfo_triggered()));
}


/**************************显示菜单***************************/
void UserInfoSelect::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();

    menu->addAction(update);
    menu->addAction(refresh);
    menu->addAction(del);

    menu->exec(QCursor::pos());

    event->accept();
}
