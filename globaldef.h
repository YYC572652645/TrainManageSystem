#ifndef GLOBALDEF_H
#define GLOBALDEF_H
#include <QFile>
#include <QString>

#define  DATA(str)   new QTableWidgetItem(str)

#define SETCENTRALWIDGET(widget)               \
{                                              \
    if(this->centralWidget())                  \
    {                                          \
        this->centralWidget()->setParent(NULL);\
    }                                          \
    this->setCentralWidget(widget);            \
}

#define SAFEDELETE(pointer) \
{                           \
    if(pointer)             \
    {                       \
        delete pointer;     \
    }                       \
    pointer = NULL;         \
}

#define LOADQSS(filePath)                                 \
{                                                         \
    QFile qssFile(filePath);                              \
    qssFile.open(QFile::ReadOnly);                        \
    if(qssFile.isOpen())                                  \
    {                                                     \
        QString strQss=QLatin1String(qssFile.readAll());  \
        qApp->setStyleSheet(strQss);                      \
        qssFile.close();                                  \
    }                                                     \
}

namespace GLOBALDEF
{
const static int     ERROR        = -1;                           //数据库查询失败
const static QString SUCCESSIMAGE = ":/image/image/ok.png";       //成功图片
const static QString FAILIMAGE    = ":/image/image/fail.png";     //失败图片
const static QString UPDATEICON   = ":/image/image/update.jpg";   //更新图片
const static QString REFRESHICON  = ":/image/image/refresh.png";  //刷新图片
const static QString DELETEICON   = ":/image/image/critical.png"; //删除图片
const static int     REFRESHTIME  = 3500;                         //刷新时间


//列车信息表对应枚举
enum TRAININFO
{
    TRAINNUMMBER,
    TRAINTYPE,
    STARTSTATION,
    ENDSTATION,
    STARTTIME,
    ENDTIME,
    SLEEPERSEATNUMBER,
    HARDSEADNUMBER,
    SEATMONEY,
    TOTALSLEEPERSEATNUMBER,
    TOTALHARDSEADNUMBER,
    TRAININFOMAX,
};

//用户信息表对应枚举
enum USERINFO
{
    IDCARDNUMBER,
    USERNAME,
    USERTRAINNUMBER,
    DATETIME,
    SEATTYPE,
    USERSEATMONEY,
    SEATNUMBER,
    TOTALMONEY,
    USERINFOMAX,
};

//查询类型
enum SELECTYPE
{
    SELECTALL,
    SELECTLIKE,
    SELECTWHERE,
};

}


#endif // GLOBALDEF_H
