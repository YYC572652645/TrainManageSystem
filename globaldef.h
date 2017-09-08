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
const static QString UNUSED       = "1";                          //不用使用密码登录
const static QString PRINTFLAGE   = "1";                          //已经打印
const static QString SUCCESSIMAGE = ":/image/image/ok.png";       //成功图片
const static QString FAILIMAGE    = ":/image/image/fail.png";     //失败图片
const static QString PRINTICON    = ":/image/image/print.jpg";    //打印图片
const static QString REFRESHICON  = ":/image/image/refresh.png";  //刷新图片
const static QString DELETEICON   = ":/image/image/critical.png"; //删除图片
const static QString SYSTEMINFO   = "系统提示";                    //系统提示
const static int     REFRESHTIME  = 3500;                         //刷新时间


enum DATATYPE
{
    TYPEINSERT,
    TYPEUPDATE,
};

}


#endif // GLOBALDEF_H
