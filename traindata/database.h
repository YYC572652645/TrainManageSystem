#ifndef DATABASE_H
#define DATABASE_H
#include<QString>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QFile>
#include<QIODevice>
#include<QDebug>

#define DATABASE DataBase::getInstance()

//列车信息
typedef struct TrainInfo
{
    QString trainNumber;
    QString trainType;
    QString startStation;
    QString endStation;
    QString startTime;
    QString endTime;
    QString sleeperSeatNumber;
    QString hardSeadNumber;
    QString seatMoney;
}TrainInfo;


//用户订票信息
typedef struct UserInfo
{
    QString idcardnumber;
    QString trainnumber;
    QString datatime;
    QString seatmoney;
    QString seatnumber;
    QString totalmoney;
}UserInfo;

class DataBase
{
public:

    /************单例模式*************/
    static DataBase * getInstance()
    {
        if(NULL == dataBase)
        {
            dataBase = new DataBase();
        }

        return dataBase;
    }

    /************连接数据库*************/
    bool dataCnn();


    /************插入列车数据*************/
    bool insertTrainData(TrainInfo & trainInfo);


    /************查询数据*************/
    bool selectData();


    /************更改数据*************/
    bool updateData();


    /************删除数据*************/
    bool deleteData();


private:
    DataBase();                //构造函数
    static DataBase *dataBase; //静态对象
    QSqlDatabase db;           //定义数据库对象
};

#endif // DATABASE_H
