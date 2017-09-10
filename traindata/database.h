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
    QString totalSleeperSeatNumber;
    QString totalHardSeadNumber;
}TrainInfo;


//用户订票信息
typedef struct UserInfo
{
    QString idCardNumber;
    QString trainNumber;
    QString dataTime;
    QString seatType;
    QString seatMoney;
    QString seatNumber;
    QString totalMoney;
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


    /************查询列车数据*************/
    int selectTrainData(int type, QString data = NULL);


    /************更改列车数据*************/
    bool updateTrainData(TrainInfo &trainInfo);


    /************删除列车数据*************/
    bool deleteTrainData(QString trainNumber);


    /************插入用户数据*************/
    bool insertUserData(UserInfo & userInfo);


    /************查询用户数据*************/
    int selectUserData(int type, QString data = NULL);


    /************更改用户数据*************/
    bool updateUserData(UserInfo & userInfo);


    /************删除用户数据*************/
    bool deleteUserData(QString idCardNumber);


    QList<TrainInfo> getTrainData() const;

    QList<UserInfo> getUserData() const;

private:
    DataBase();                     //构造函数
    static DataBase *dataBase;      //静态对象
    QSqlDatabase db;                //定义数据库对象

    QList<TrainInfo> trainData;     //用于存储查询出来的列车数据
    QList<UserInfo> userData;       //用于存储查询出来的用户数据
};

#endif // DATABASE_H
