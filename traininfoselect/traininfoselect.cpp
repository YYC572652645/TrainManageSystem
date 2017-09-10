#include "traininfoselect.h"
#include "ui_traininfoselect.h"
#include "globaldef.h"
#include <QVBoxLayout>
#include <QDebug>

TrainInfoSelect::TrainInfoSelect(QWidget *parent) :
    QWidget(parent),rowCount(0),firstSliderValue(0),secondSliderValue(0),
    ui(new Ui::traininfoselect)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    movie = new QMovie(":/image/image/refresh.gif");

    connect(timer, SIGNAL(timeout()), this, SLOT(updateMovie()));

    this->initControl();

    dataSelect(GLOBALDEF::SELECTALL);

    ui->widget->installEventFilter(this);      //注册监视对象
    ui->widgetSecond->installEventFilter(this);//注册监视对象

    ui->widget->hide();
    ui->widgetSecond->hide();
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

        int totalnumber  =  DATABASE->getTrainData().at(i).totalSleeperSeatNumber.toInt() - DATABASE->getTrainData().at(i).sleeperSeatNumber.toInt();
        totalnumber     +=  DATABASE->getTrainData().at(i).totalHardSeadNumber.toInt() - DATABASE->getTrainData().at(i).hardSeadNumber.toInt();

        ui->tableWidget->setItem(i, 9, DATA(QString::number(totalnumber * DATABASE->getTrainData().at(i).seatMoney.toInt())));
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

    for (int i = 0; i < DATABASE->getTrainData().size(); i ++)
    {
        if(trainInfo.trainNumber == DATABASE->getTrainData().at(i).trainNumber
                &&trainInfo.startTime == DATABASE->getTrainData().at(i).startTime
                && trainInfo.endTime == DATABASE->getTrainData().at(i).endTime)
        {
            float hardNumber = trainInfo.hardSeadNumber.toFloat();
            float totalHardNumber = DATABASE->getTrainData().at(i).totalHardSeadNumber.toFloat();

            if(totalHardNumber != 0)
            {
                float persent =  (totalHardNumber - hardNumber) / totalHardNumber;

                this->setFirstSliderValue(persent);
            }

            float sleepNumber = trainInfo.sleeperSeatNumber.toFloat();
            float totalSleepNumber = DATABASE->getTrainData().at(i).totalSleeperSeatNumber.toFloat();

            if(totalSleepNumber != 0)
            {
                float persent = (totalSleepNumber - sleepNumber) / totalSleepNumber;

                this->setSecondSliderValue(persent);
            }

            ui->widget->show();
            ui->widgetSecond->show();
            ui->widget->update();
            ui->widgetSecond->update();
        }
    }
}

/**************************          查询数据      ***************************/
void TrainInfoSelect::on_pushButtonFind_clicked()
{
    dataSelect(GLOBALDEF::SELECTLIKE);
}

/************************    画图事件         **************************************/
void TrainInfoSelect::paintImage(QWidget * widget, float sliderValue, QString text)
{
    if(NULL == widget) return;

    QPainter painter(widget);

    float sliderMaxValue = widget->height() * 0.9;
    float sliderHigh  = -widget->height() * 0.8;  //进度条高度
    const int sliderWidth = 60;                   //进度条宽度

    //将坐标系的该点变成原点坐标
    painter.translate(widget->width() * 0.3, sliderMaxValue);

    //设置画笔为红色
    QPen pen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);

    //画下面直线
    painter.drawLine(0, 0, sliderWidth, 0);

    //画左边直线
    painter.drawLine(0, 0, 0, sliderHigh);

    //画右边直线
    painter.drawLine(sliderWidth, 0, sliderWidth, sliderHigh);

    //画上面直线线
    painter.drawLine(0, sliderHigh, sliderWidth, sliderHigh);

    //画进度值
    painter.drawText(sliderWidth - 40, sliderHigh - 10,tr("%%1").arg(sliderValue * 100));
    painter.drawText(-10, 30,text);


    //将矩形填充为白色
    QPolygon polyGon;
    polyGon<<QPoint(sliderWidth, 0);
    polyGon<<QPoint(sliderWidth, sliderHigh);
    polyGon<<QPoint(0, sliderHigh);
    polyGon<<QPoint(0, 0);
    painter.setBrush(Qt::white);
    painter.drawConvexPolygon(polyGon);

    //设置渐变
    QLinearGradient linerGradient = QLinearGradient(0, 0, 0, sliderHigh);
    linerGradient.setColorAt(0.0, Qt::cyan);
    linerGradient.setColorAt(0.3, Qt::green);
    linerGradient.setColorAt(0.7, Qt::yellow);
    linerGradient.setColorAt(1.0, Qt::red);

    QBrush brush(linerGradient);
    painter.setBrush(brush);

    painter.drawRect(0, 0, sliderWidth, sliderHigh * sliderValue);

    painter.end();
}

void TrainInfoSelect::setSecondSliderValue(float value)
{
    secondSliderValue = value;
}

void TrainInfoSelect::setFirstSliderValue(float value)
{
    firstSliderValue = value;
}

bool TrainInfoSelect::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->widget && event->type()==QEvent::Paint)
    {
        paintImage(ui->widget, firstSliderValue, "硬座上座率");
    }
    if(watched == ui->widgetSecond && event->type()==QEvent::Paint)
    {
        paintImage(ui->widgetSecond, secondSliderValue, "卧铺上座率");
    }

    return QWidget::eventFilter(watched,event);
}
