#include "userinfoinsert.h"
#include "ui_userinfoinsert.h"
#include "traindata/database.h"
#include "messagebox/messagedialog.h"
#include "globaldef.h"

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


    /*************************          姓名           ***********************/
    lineEditName = new QLineEdit(this);
    lineEditName->setMinimumHeight(25);
    QWidget *widgetName = new QWidget(this);
    QHBoxLayout *hboxLayoutName = new QHBoxLayout(this);
    hboxLayoutName->addWidget(lineEditName);
    hboxLayoutName->setAlignment(widgetName,Qt::AlignCenter);
    widgetName->setLayout(hboxLayoutName);

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
    dateEditDateTime->setDisplayFormat("yyyy-MM-dd");
    dateEditDateTime->setDateTime(QDateTime::currentDateTime());


    /*************************车类型***********************/
    comboBoxSeatType = new QComboBox(this);
    comboBoxSeatType->setMinimumHeight(25);
    QWidget *widgetSeatType = new QWidget(this);
    QHBoxLayout *hboxLayoutSeatType = new QHBoxLayout(this);
    hboxLayoutSeatType->addWidget(comboBoxSeatType);
    hboxLayoutSeatType->setAlignment(widgetSeatType,Qt::AlignCenter);
    widgetSeatType->setLayout(hboxLayoutSeatType);
    comboBoxSeatType->addItem("硬座");
    comboBoxSeatType->addItem("卧铺");


    /*************************票价***********************/
    spinBoxSeatMoney = new QSpinBox(this);
    spinBoxSeatMoney->setMinimumHeight(25);
    QWidget *widgetSeatMoney = new QWidget(this);
    QHBoxLayout *hboxLayoutSeatMoney = new QHBoxLayout(this);
    hboxLayoutSeatMoney->addWidget(spinBoxSeatMoney);
    hboxLayoutSeatMoney->setAlignment(widgetSeatMoney,Qt::AlignCenter);
    widgetSeatMoney->setLayout(hboxLayoutSeatMoney);
    spinBoxSeatMoney->setMaximum(1000);
    spinBoxSeatMoney->setValue(100);

    /*************************买票数***********************/
    spinBoxSeatNumber = new QSpinBox(this);
    spinBoxSeatNumber->setMinimumHeight(25);
    QWidget *widgetSeatNumber = new QWidget(this);
    QHBoxLayout *hboxLayoutSeatNumber = new QHBoxLayout(this);
    hboxLayoutSeatNumber->addWidget(spinBoxSeatNumber);
    hboxLayoutSeatNumber->setAlignment(widgetSeatNumber,Qt::AlignCenter);
    widgetSeatNumber->setLayout(hboxLayoutSeatNumber);
    spinBoxSeatNumber->setMaximum(1000);
    spinBoxSeatNumber->setValue(1);


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
    ui->tableWidgetInsert->setCellWidget(0, 3, widgetName);
    ui->tableWidgetInsert->setCellWidget(0, 5, widgetTrainNumber);
    ui->tableWidgetInsert->setCellWidget(1, 1, widgetDateTime);
    ui->tableWidgetInsert->setCellWidget(1, 3, widgetSeatType);
    ui->tableWidgetInsert->setCellWidget(1, 5, widgetSeatMoney);
    ui->tableWidgetInsert->setCellWidget(2, 1, widgetSeatNumber);
    ui->tableWidgetInsert->setCellWidget(2, 3, widgetTotalMoney);
    ui->tableWidgetInsert->setCellWidget(3, 5, widgetButton);

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

    QTableWidgetItem *textName = new QTableWidgetItem("姓名：");
    textName->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetInsert->setItem(0, 2, textName);

    QTableWidgetItem *textTrainType = new QTableWidgetItem("车次：");
    textTrainType->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetInsert->setItem(0, 4, textTrainType);

    QTableWidgetItem *textDateTime = new QTableWidgetItem("时间：");
    textDateTime->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetInsert->setItem(1, 0, textDateTime);

    QTableWidgetItem *textSeatType = new QTableWidgetItem("座位类型：");
    textSeatType->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetInsert->setItem(1, 2, textSeatType);

    QTableWidgetItem *textSeatMoney = new QTableWidgetItem("票价：");
    textSeatMoney->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetInsert->setItem(1, 4, textSeatMoney);

    QTableWidgetItem *textSeatNumber = new QTableWidgetItem("票数：");
    textSeatNumber->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetInsert->setItem(2, 0, textSeatNumber);

    QTableWidgetItem *textTotalMoney = new QTableWidgetItem("总价：");
    textTotalMoney->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetInsert->setItem(2, 2, textTotalMoney);

    connect(insertButton,SIGNAL(clicked()), this, SLOT(insertData()));

    lineEditTotalMoney->setEnabled(false);

    connect(spinBoxSeatMoney, SIGNAL(valueChanged(int)), this, SLOT(seatMoneyChange(int)));
    connect(spinBoxSeatNumber, SIGNAL(valueChanged(int)), this, SLOT(seatNumberChange(int)));

    lineEditTotalMoney->setText(QString::number(spinBoxSeatNumber->value() * spinBoxSeatMoney->value()));
}

void UserInfoInsert::insertData()
{
    UserInfo userInfo;

    userInfo.idCardNumber  = lineEditIDCardNumber->text();     //身份证号
    userInfo.name          = lineEditName->text();             //姓名
    userInfo.trainNumber   = lineEditTrainNumber->text();      //车次
    userInfo.dataTime      = dateEditDateTime->text();         //时间
    userInfo.seatType      = comboBoxSeatType->currentText();  //座位类型
    userInfo.seatMoney     = spinBoxSeatMoney->text();         //票价
    userInfo.seatNumber    = spinBoxSeatNumber->text();        //票数
    userInfo.totalMoney    = lineEditTotalMoney->text();       //总价钱

    if(DATABASE->insertUserData(userInfo))
    {
        MESSAGEBOX->setInfo("系统提示", "录入成功", QPixmap(GLOBALDEF::SUCCESSIMAGE), true, this);
    }
    else
    {
        MESSAGEBOX->setInfo("系统提示", "请检查车次和身份证号", QPixmap(GLOBALDEF::FAILIMAGE), true, this);
    }
}

void UserInfoInsert::seatMoneyChange(int value)
{
    lineEditTotalMoney->setText(QString::number(spinBoxSeatNumber->value() * value));
}

void UserInfoInsert::seatNumberChange(int value)
{
    lineEditTotalMoney->setText(QString::number(spinBoxSeatMoney->value() * value));
}
