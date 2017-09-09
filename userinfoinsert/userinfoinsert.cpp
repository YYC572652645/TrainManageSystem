#include "userinfoinsert.h"
#include "ui_userinfoinsert.h"
#include "traindata/database.h"

UserInfoInsert::UserInfoInsert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userinfoinsert)
{
    ui->setupUi(this);

    this->initControl();
}

UserInfoInsert::~UserInfoInsert()
{
    delete ui;
}


void UserInfoInsert::initControl()
{
    /*************************          身份证号           ***********************/
    lineEditIDCardNumber = new QLineEdit(this);
    lineEditIDCardNumber->setMinimumHeight(25);
    QWidget *widgetIDCardNumber = new QWidget(this);
    QHBoxLayout *hboxLayoutIDCardNumber = new QHBoxLayout(this);
    hboxLayoutIDCardNumber->addWidget(lineEditIDCardNumber);
    hboxLayoutIDCardNumber->setAlignment(widgetIDCardNumber,Qt::AlignCenter);
    widgetIDCardNumber->setLayout(hboxLayoutIDCardNumber);

    /*************************          车次           ***********************/
    lineEditTrainNumber = new QLineEdit(this);
    lineEditTrainNumber->setMinimumHeight(25);
    QWidget *widgetTrainNumber = new QWidget(this);
    QHBoxLayout *hboxLayoutTrainNumber = new QHBoxLayout(this);
    hboxLayoutTrainNumber->addWidget(lineEditTrainNumber);
    hboxLayoutTrainNumber->setAlignment(widgetTrainNumber,Qt::AlignCenter);
    widgetTrainNumber->setLayout(hboxLayoutTrainNumber);


    /*************************          乘车时间        ***********************/
    dateEditDateTime = new QDateEdit(this);
    dateEditDateTime->setMinimumHeight(25);
    QWidget *widgetDateTime = new QWidget(this);
    QHBoxLayout *hboxLayoutDateTime = new QHBoxLayout(this);
    hboxLayoutDateTime->addWidget(dateEditDateTime);
    hboxLayoutDateTime->setAlignment(widgetDateTime,Qt::AlignCenter);
    widgetDateTime->setLayout(hboxLayoutDateTime);


    /*************************票价***********************/
    lineEditSeatMoney = new QLineEdit(this);
    lineEditSeatMoney->setMinimumHeight(25);
    QWidget *widgetSeatMoney = new QWidget(this);
    QHBoxLayout *hboxLayoutSeatMoney = new QHBoxLayout(this);
    hboxLayoutSeatMoney->addWidget(lineEditSeatMoney);
    hboxLayoutSeatMoney->setAlignment(widgetSeatMoney,Qt::AlignCenter);
    widgetSeatMoney->setLayout(hboxLayoutSeatMoney);


    /*************************买票数***********************/
    lineEditSeatNumber = new QLineEdit(this);
    lineEditSeatNumber->setMinimumHeight(25);
    QWidget *widgetSeatNumber = new QWidget(this);
    QHBoxLayout *hboxLayoutSeatNumber = new QHBoxLayout(this);
    hboxLayoutSeatNumber->addWidget(lineEditSeatNumber);
    hboxLayoutSeatNumber->setAlignment(widgetSeatNumber,Qt::AlignCenter);
    widgetSeatNumber->setLayout(hboxLayoutSeatNumber);


    /*************************总价钱***********************/
    lineEditTotalMoney = new QLineEdit(this);
    lineEditTotalMoney->setMinimumHeight(25);
    QWidget *widgetTotalMoney = new QWidget(this);
    QHBoxLayout *hboxLayoutTotalMoney = new QHBoxLayout(this);
    hboxLayoutTotalMoney->addWidget(lineEditTotalMoney);
    hboxLayoutTotalMoney->setAlignment(widgetTotalMoney,Qt::AlignCenter);
    widgetTotalMoney->setLayout(hboxLayoutTotalMoney);

    /*************************录入数据信息***********************/
    insertButton=new QPushButton(this);
    QWidget *widgetButton = new QWidget(this);
    QHBoxLayout *hboxLayoutButton = new QHBoxLayout(this);
    hboxLayoutButton->addWidget(insertButton);
    hboxLayoutButton->setAlignment(widgetButton,Qt::AlignCenter);
    widgetButton->setLayout(hboxLayoutButton);
    insertButton->setText("信息录入");

    QFont font("宋体", 14, QFont::Bold, true);
    insertButton->setFont(font);
    insertButton->setIcon(QIcon(":/image/image/indexedDB.png"));
    insertButton->setIconSize(QSize(25, 25));
    insertButton->setMinimumHeight(50);

    //添加控件
    ui->tableWidgetInsert->setCellWidget(0, 1, widgetIDCardNumber);
    ui->tableWidgetInsert->setCellWidget(0, 3, widgetTrainNumber);
    ui->tableWidgetInsert->setCellWidget(0, 5, widgetDateTime);
    ui->tableWidgetInsert->setCellWidget(1, 1, widgetSeatMoney);
    ui->tableWidgetInsert->setCellWidget(1, 3, widgetSeatNumber);
    ui->tableWidgetInsert->setCellWidget(1, 5, widgetTotalMoney);
    ui->tableWidgetInsert->setCellWidget(2, 5, widgetButton);

    //把表头上面去掉
    ui->tableWidgetInsert->horizontalHeader()->setVisible(false);
    ui->tableWidgetInsert->verticalHeader()->setVisible(false);

    //设置列表控件等宽显示
    QHeaderView *headerView=ui->tableWidgetInsert->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    //设置列表控件等高显示
    QHeaderView *leftHeaderView=ui->tableWidgetInsert->verticalHeader();
    leftHeaderView->setSectionResizeMode(QHeaderView::Stretch);

    //设置不能选择
    ui->tableWidgetInsert->setSelectionMode(QAbstractItemView::NoSelection);

    //设置无边框
    ui->tableWidgetInsert->setFrameShape(QFrame::NoFrame);

    //设置为不可编辑
    ui->tableWidgetInsert->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QTableWidgetItem *textTrainNumber = new QTableWidgetItem("身份证号：");
    textTrainNumber->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetInsert->setItem(0, 0, textTrainNumber);

    QTableWidgetItem *textTrainType = new QTableWidgetItem("车次：");
    textTrainType->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetInsert->setItem(0, 2, textTrainType);

    QTableWidgetItem *textDateTime = new QTableWidgetItem("时间：");
    textDateTime->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetInsert->setItem(0, 4, textDateTime);

    QTableWidgetItem *textSeatMoney = new QTableWidgetItem("票价：");
    textSeatMoney->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetInsert->setItem(1, 0, textSeatMoney);

    QTableWidgetItem *textSeatNumber = new QTableWidgetItem("票数：");
    textSeatNumber->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetInsert->setItem(1, 2, textSeatNumber);

    QTableWidgetItem *textTotalMoney = new QTableWidgetItem("总价：");
    textTotalMoney->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetInsert->setItem(1, 4, textTotalMoney);

    connect(insertButton,SIGNAL(clicked()), this, SLOT(insertData()));
}

void UserInfoInsert::insertData()
{
    UserInfo userInfo;

    userInfo.idCardNumber  = lineEditIDCardNumber->text(); //身份证号
    userInfo.trainNumber   = lineEditTrainNumber->text();  //车次
    userInfo.dataTime      = dateEditDateTime->text();     //时间
    userInfo.seatMoney     = lineEditSeatMoney->text();    //票价
    userInfo.seatNumber    = lineEditSeatNumber->text();   //票数
    userInfo.totalMoney    = lineEditTotalMoney->text();   //总价钱

    DATABASE->insertUserData(userInfo);
}
