#ifndef QREADINI_H
#define QREADINI_H
#include<QSettings>

//获取配置文件内容宏定义
#define DATACONFIG  QReadIni::getInstance()->getIniConfig()

typedef struct IniConfig
{
    QString ip;                        //IP地址
    QString port;                      //端口
    QString dataBaseVersion;           //数据库版本
    QString dataBaseName;              //数据库名称
    QString userName;                  //用户名
    QString passWord;                  //密码
}IniConfig;


class QReadIni
{
public:
    static QReadIni * getInstance();    //静态函数

    void readIni();                     //读取数据库配置文件

    const IniConfig &getIniConfig();    //获取读取信息

private:
    QReadIni();                         //构造函数

    IniConfig iniConfig;                //结构题对象

    static QReadIni * instance;         //静态对象用于单例模式
};

#endif // QREADINI_H
