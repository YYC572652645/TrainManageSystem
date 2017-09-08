#include "database.h"
#include "qreadini.h"
#include <QDebug>
#include "globaldef.h"

DataBase *DataBase::dataBase = NULL;

/***************************构造函数***********************/
DataBase::DataBase()
{   
    if(!dataCnn())
    {
        qDebug()<<"连接失败";
    }
}

QList<TrainInfo> DataBase::getTrainData() const
{
    return trainData;
}

/***************************连接数据库*********************/
bool DataBase::dataCnn()
{
    //是否为默认连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase(DATACONFIG.dataBaseVersion);         //设置数据库类型
    }

    db.setHostName(DATACONFIG.ip);                                        //设置数据库主机名
    db.setPort(DATACONFIG.port.toInt());                                  //设置端口
    db.setDatabaseName(DATACONFIG.dataBaseName);                          //设置数据库名
    db.setUserName(DATACONFIG.userName);                                  //设置用户名
    db.setPassword(DATACONFIG.passWord);                                  //设置密码
    //如果数据库处于打开状态，则关闭
    if(db.isOpen())
    {
        db.close();
    }
    return db.open();
}

/***************************插入列车数据***********************/
bool DataBase::insertTrainData(TrainInfo &trainInfo)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("insert into traininfo values('");

    str += trainInfo.trainNumber       + "','" + trainInfo.trainType      + "','";

    str += trainInfo.startStation      + "','" + trainInfo.endStation     + "','";

    str += trainInfo.startTime         + "','" + trainInfo.endTime        + "','";

    str += trainInfo.sleeperSeatNumber + "','" + trainInfo.hardSeadNumber + "','";

    str += trainInfo.seatMoney + "');";

    qDebug()<<str;

    bool success = query.exec(str);  //执行sql语句

    db.close();

    return success;
}

/***************************查询数据***********************/
bool DataBase::selectTrainData()
{
    trainData.clear();
    int Count = 0;
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str = QString("select * from traininfo;");
    bool success = query.exec(Str);  //执行sql语句
    if(!success)  return GLOBALDEF::ERROR;


    while(query.next())        //挨个遍历数据
    {
        TrainInfo trainInfo;

        trainInfo.trainNumber       = query.value(0).toString();
        trainInfo.trainType         = query.value(1).toString();
        trainInfo.startStation      = query.value(2).toString();
        trainInfo.endStation        = query.value(3).toString();
        trainInfo.startTime         = query.value(4).toString();
        trainInfo.endTime           = query.value(5).toString();
        trainInfo.sleeperSeatNumber = query.value(6).toString();
        trainInfo.hardSeadNumber    = query.value(7).toString();
        trainInfo.seatMoney         = query.value(8).toString();

        trainData.append(trainInfo);
        Count ++;
    }

    db.close();

    return Count > 0 ? true : false;
}

/***************************更改数据***********************/
bool DataBase::updateData()
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str = QString("update  table set('','');");
    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

/***************************删除数据***********************/
bool DataBase::deleteData()
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str = QString("delete from table where ;");
    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

