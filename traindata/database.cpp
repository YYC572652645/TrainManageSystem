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

QList<UserInfo> DataBase::getUserData() const
{
    return userData;
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
    if(db.isOpen())  db.close();

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

/***************************查询列车数据***********************/
int DataBase::selectTrainData(int type,QString data)
{
    trainData.clear();
    int count = 0;

    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str;

    if(type == GLOBALDEF::SELECTALL)
    {
        str = "select * from traininfo;";
    }
    else
    {
        str = "select * from traininfo where trainnumber like '%" + data +"%'";
    }


    bool success = query.exec(str);  //执行sql语句

    if(!success)  return GLOBALDEF::ERROR;


    while(query.next())        //挨个遍历数据
    {
        TrainInfo trainInfo;

        trainInfo.trainNumber       = query.value(GLOBALDEF::TRAINNUMMBER).toString();
        trainInfo.trainType         = query.value(GLOBALDEF::TRAINTYPE).toString();
        trainInfo.startStation      = query.value(GLOBALDEF::STARTSTATION).toString();
        trainInfo.endStation        = query.value(GLOBALDEF::ENDSTATION).toString();
        trainInfo.startTime         = query.value(GLOBALDEF::STARTTIME).toString();
        trainInfo.endTime           = query.value(GLOBALDEF::ENDTIME).toString();
        trainInfo.sleeperSeatNumber = query.value(GLOBALDEF::SLEEPERSEATNUMBER).toString();
        trainInfo.hardSeadNumber    = query.value(GLOBALDEF::HARDSEADNUMBER).toString();
        trainInfo.seatMoney         = query.value(GLOBALDEF::SEATMONEY).toString();

        trainData.append(trainInfo);

        count ++;
    }

    db.close();

    return count;
}

/***************************更改列车数据***********************/
bool DataBase::updateTrainData(TrainInfo &trainInfo)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("update traininfo set ");

    str += "traintype = '"         + trainInfo.trainType          + "',";

    str += "startstation = '"      + trainInfo.startStation       + "'," ;

    str += "endstation = '"        + trainInfo.endStation         + "',";

    str += "starttime = '"         + trainInfo.startTime          + "',";

    str += "endtime = '"           + trainInfo.endTime            + "',";

    str += "sleeperseatnumber = '" + trainInfo.sleeperSeatNumber  + "',";

    str += "hardseadnumber = '"    + trainInfo.hardSeadNumber     + "',";

    str += "seatmoney = '"         + trainInfo.seatMoney          + "' ";

    str += "where trainnumber = '" + trainInfo.trainNumber        + "';";

    bool success = query.exec(str);  //执行sql语句

    db.close();

    return success;
}

/***************************删除列车数据***********************/
bool DataBase::deleteTrainData(QString trainNumber)
{
    if(trainNumber.isEmpty()) return false;

    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("delete from traininfo where trainnumber = '") + trainNumber + "';";

    bool success = query.exec(str);

    db.close();

    return success;
}

/***************************插入用户数据***********************/
bool DataBase::insertUserData(UserInfo & userInfo)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("insert into userinfo values('");

    str += userInfo.idCardNumber  + "','" + userInfo.trainNumber   + "','";

    str += userInfo.dataTime      + "','" + userInfo.seatMoney     + "','";

    str += userInfo.seatNumber    + "','" + userInfo.totalMoney    + "');";


    qDebug()<<str;

    bool success = query.exec(str);  //执行sql语句

    db.close();

    return success;
}

/***************************查询列车数据***********************/
int DataBase::selectUserData(int type, QString data)
{
    userData.clear();
    int count = 0;

    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str;

    if(type == GLOBALDEF::SELECTALL)
    {
        str = "select * from userinfo;";
    }
    else
    {
        str = "select * from userinfo where idcardnumber like '%" + data +"%'";
    }

    bool success = query.exec(str);  //执行sql语句

    if(!success)  return GLOBALDEF::ERROR;


    while(query.next())        //挨个遍历数据
    {
        UserInfo userInfo;

        userInfo.idCardNumber  = query.value(GLOBALDEF::IDCARDNUMBER).toString();
        userInfo.trainNumber   = query.value(GLOBALDEF::USERTRAINNUMBER).toString();
        userInfo.dataTime      = query.value(GLOBALDEF::DATETIME).toString();
        userInfo.seatMoney     = query.value(GLOBALDEF::USERSEATMONEY).toString();
        userInfo.seatNumber    = query.value(GLOBALDEF::SEATNUMBER).toString();
        userInfo.totalMoney    = query.value(GLOBALDEF::TOTALMONEY).toString();

        userData.append(userInfo);

        count ++;
    }

    db.close();

    return count;
}

/***************************更改列车数据***********************/
bool DataBase::updateUserData(UserInfo & userInfo)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("update userinfo set ");

    str += "trainnumber = '"        + userInfo.trainNumber    + "',";

    str += "datatime = '"           + userInfo.dataTime       + "'," ;

    str += "seatmoney = '"          + userInfo.seatMoney      + "',";

    str += "seatnumber = '"         + userInfo.seatNumber     + "',";

    str += "totalmoney = '"         + userInfo.totalMoney     + "' ";

    str += "where idcardnumber = '" + userInfo.idCardNumber   + "';";

    bool success = query.exec(str);  //执行sql语句

    db.close();

    return success;
}

/***************************删除列车数据***********************/
bool DataBase::deleteUserData(QString idCardNumber)
{
    if(idCardNumber.isEmpty()) return false;

    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("delete from userinfo where idcardnumber = '") + idCardNumber + "';";

    bool success = query.exec(str);

    db.close();

    return success;
}


