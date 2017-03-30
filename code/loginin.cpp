#include "loginin.h"
#include "ui_loginin.h"

Loginin::Loginin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Loginin)
{

    ui->setupUi(this);
    Qt::WindowFlags flags;
    flags = Qt::WindowMinimizeButtonHint;
    setWindowFlags(flags); // 设置禁止最大化
    setFixedSize(725,492); // 禁止改变窗口大小。
}

Loginin::~Loginin()
{
    delete ui;
}

void Loginin::on_Loginin_iconSizeChanged(const QSize &iconSize)
{

}

void Loginin::on_login_close_clicked()
{
    this->close();
}

void Loginin::on_login_user_clicked()
{
    this->hide();
    userui.show();
    userui.exec();
    this->show();
}

void Loginin::on_login_user_img_clicked()
{
    this->hide();
    userui.show();
    userui.exec();
    this->show();
}

void Loginin::on_login_expert_clicked()
{
    this->hide();
    expertui.show();
    expertui.exec();
    this->show();
}

void Loginin::on_login_expert_img_clicked()
{
    this->hide();
    expertui.show();
    expertui.exec();
    this->show();
}
