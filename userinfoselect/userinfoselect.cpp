#include "userinfoselect.h"
#include "ui_userinfoselect.h"

UserInfoSelect::UserInfoSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userinfoselect)
{
    ui->setupUi(this);
}

UserInfoSelect::~UserInfoSelect()
{
    delete ui;
}
