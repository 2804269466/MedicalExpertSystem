#include "expertui.h"
#include "ui_expertui.h"
#include <iostream>
#include <string>
#include <QString>
#include <QFile>
#include <QTextCodec>
#include <QDebug>
#include <QMessageBox>

QString now_focus = "";

ExpertUI::ExpertUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExpertUI)
{
    ui->setupUi(this);
}

ExpertUI::~ExpertUI()
{
    delete ui;
}

void ExpertUI::on_expert_return_clicked()
{
    this->close();
}

void ExpertUI::on_button_file_1_clicked()
{

    ui->filecontext->clear();
    QString res_ = QString::fromStdString("disease_symptom_A.txt");
     now_focus = res_;
    QFile file(res_);
     QTextCodec * code = QTextCodec::codecForName("GBK");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::about(NULL, "About", " <font color='red'>Openfile fail</font>");
        ui->filecontext->setText("unable to open file :" + res_);
        return;
    }

    ui->filecontext->setText("file not exist");

    QTextStream stream(&file);
    stream.setCodec(code);
    while (stream.atEnd() == 0) {
            ui->filecontext->setText(stream.readAll());
     }
     file.close();
}

void ExpertUI::on_button_file_2_clicked()
{
    ui->filecontext->clear();
    QString res_ = QString::fromStdString("disease_symptom_S.txt");
     now_focus = res_;
    QFile file(res_);
     QTextCodec * code = QTextCodec::codecForName("GBK");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::about(NULL, "About", " <font color='red'>Openfile fail</font>");
        ui->filecontext->setText("unable to open file :" + res_);
        return;
    }

    ui->filecontext->setText("file not exist");

    QTextStream stream(&file);
    stream.setCodec(code);
    while (stream.atEnd() == 0) {
            ui->filecontext->setText(stream.readAll());
     }
     file.close();
}

void ExpertUI::on_button_file_3_clicked()
{
    ui->filecontext->clear();
    QString res_ = QString::fromStdString("diseaseID.txt");
     now_focus = res_;
    QFile file(res_);
     QTextCodec * code = QTextCodec::codecForName("GBK");
    if(!file.open(QIODevice::ReadOnly)){
         QMessageBox::about(NULL, "About", " <font color='red'>Openfile fail</font>");
        ui->filecontext->setText("unable to open file :" + res_);
        return;
    }

    ui->filecontext->setText("file not exist");

    QTextStream stream(&file);
    stream.setCodec(code);
    while (stream.atEnd() == 0) {
            ui->filecontext->setText(stream.readAll());
     }
     file.close();
}

void ExpertUI::on_button_file_4_clicked()
{
    ui->filecontext->clear();
    QString res_ = QString::fromStdString("diseaseType.txt");
     now_focus = res_;
    QFile file(res_);
     QTextCodec * code = QTextCodec::codecForName("GBK");
    if(!file.open(QIODevice::ReadOnly)){
         QMessageBox::about(NULL, "About", " <font color='red'>Openfile fail</font>");
        ui->filecontext->setText("unable to open file :" + res_);
        return;
    }

    ui->filecontext->setText("file not exist");

    QTextStream stream(&file);
    stream.setCodec(code);
    while (stream.atEnd() == 0) {
            ui->filecontext->setText(stream.readAll());
    }
     file.close();
}

void ExpertUI::on_button_file_5_clicked()
{
    ui->filecontext->clear();
    QString res_ = QString::fromStdString("symptom.txt");
     now_focus = res_;
    QFile file(res_);
     QTextCodec * code = QTextCodec::codecForName("GBK");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::about(NULL, "About", " <font color='red'>Openfile fail</font>");
        ui->filecontext->setText("unable to open file :" + res_);
        return;
    }

    ui->filecontext->setText("file not exist");

    QTextStream stream(&file);
    stream.setCodec(code);
    while (stream.atEnd() == 0) {
            ui->filecontext->setText(stream.readAll());
    }
    file.close();
}

void ExpertUI::on_file_save_clicked()
{
    QFile writefile(now_focus);
    if(!writefile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::about(NULL, "About", " <font color='red'>Openfile fail</font>");
        return;
    }

    QTextStream txtOutput(&writefile);
    QString content = ui->filecontext->toPlainText();
    txtOutput << content;

    writefile.close();
    QMessageBox::about(NULL, "About", " <font color='green'>Writefile success</font>");
}
