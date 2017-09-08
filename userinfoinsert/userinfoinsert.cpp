#include "userinfoinsert.h"
#include "ui_userinfoinsert.h"

UserInfoInsert::UserInfoInsert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userinfoinsert)
{
    ui->setupUi(this);
}

UserInfoInsert::~UserInfoInsert()
{
    delete ui;
}
