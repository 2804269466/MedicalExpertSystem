#include "userui.h"
#include "ui_userui.h"
#include <QDebug>
#include <map>
#include <string.h>
#include <QLabel>
#include "expertsystem.h"

UserUI::UserUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserUI)
{
    ui->setupUi(this);

    system_prepare();
}

UserUI::~UserUI()
{
    delete ui;
}

void UserUI::on_user_return_clicked()
{
    this->close();
    testresult.close();
}

void UserUI::on_user_run_clicked()
{


    ui->user_run->hide();
    testresult.show();
    testresult.flash();
    testresult.exec();

    ui->cf_1_1->setValue(0);
    ui->degree_1_1->setValue(0);
    ui->cf_2_1->setValue(0);
    ui->degree_2_1->setValue(0);
    ui->cf_2_2->setValue(0);
    ui->degree_2_2->setValue(0);
    ui->cf_3_1->setValue(0);
    ui->degree_3_1->setValue(0);
    ui->cf_3_2->setValue(0);
    ui->degree_3_2->setValue(0);
    ui->cf_4_1->setValue(0);
    ui->degree_4_1->setValue(0);
    ui->cf_4_2->setValue(0);
    ui->degree_4_2->setValue(0);
    ui->cf_5_4->setValue(0);
    ui->degree_5_4->setValue(0);
    ui->cf_5_1->setValue(0);
    ui->degree_5_1->setValue(0);
    ui->cf_5_2->setValue(0);
    ui->degree_5_2->setValue(0);
    ui->cf_5_3->setValue(0);
    ui->degree_5_3->setValue(0);
    ui->cf_6_1->setValue(0);
    ui->degree_6_1->setValue(0);
    ui->cf_6_2->setValue(0);
    ui->degree_6_2->setValue(0);
    ui->cf_6_3->setValue(0);
    ui->degree_6_3->setValue(0);
    ui->cf_7_1->setValue(0);
    ui->degree_7_1->setValue(0);
    ui->cf_7_2->setValue(0);
    ui->degree_7_2->setValue(0);
    ui->cf_8_1->setValue(0);
    ui->degree_8_1->setValue(0);
    ui->cf_8_2->setValue(0);
    ui->degree_8_2->setValue(0);
    ui->cf_9_1->setValue(0);
    ui->degree_9_1->setValue(0);
    ui->cf_10_1->setValue(0);
    ui->degree_10_1->setValue(0);
    ui->cf_11_1->setValue(0);
    ui->degree_11_1->setValue(0);
    ui->cf_12_1->setValue(0);
    ui->degree_12_1->setValue(0);
    ui->cf_12_2->setValue(0);
    ui->degree_12_2->setValue(0);
    ui->cf_13_1->setValue(0);
    ui->degree_13_1->setValue(0);
    ui->cf_13_2->setValue(0);
    ui->degree_13_2->setValue(0);
    ui->cf_14_1->setValue(0);
    ui->degree_14_1->setValue(0);
    ui->user_run->show();

}

void UserUI::on_cf_1_1_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_1_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_1_1->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_1_1_valueChanged(double arg1)
{
    double get_cf = ui->cf_1_1->value();
    QString get_str_qs = ui->label_1_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_2_1_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_2_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_2_1->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_2_1_valueChanged(double arg1)
{
    double get_cf = ui->cf_2_1->value();
    QString get_str_qs = ui->label_2_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_2_2_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_2_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_2_2->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_2_2_valueChanged(double arg1)
{
    double get_cf = ui->cf_2_2->value();
    QString get_str_qs = ui->label_2_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_3_1_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_3_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_3_1->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_3_1_valueChanged(double arg1)
{
    double get_cf = ui->cf_3_1->value();
    QString get_str_qs = ui->label_3_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_3_2_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_3_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_3_2->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_3_2_valueChanged(double arg1)
{
    double get_cf = ui->cf_3_2->value();
    QString get_str_qs = ui->label_3_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_4_1_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_4_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_4_1->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_4_1_valueChanged(double arg1)
{
    double get_cf = ui->cf_4_1->value();
    QString get_str_qs = ui->label_4_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_4_2_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_4_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_4_2->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_4_2_valueChanged(double arg1)
{
    double get_cf = ui->cf_4_2->value();
    QString get_str_qs = ui->label_4_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_5_1_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_5_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_5_1->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_5_1_valueChanged(double arg1)
{
    double get_cf = ui->degree_5_1->value();
    QString get_str_qs = ui->label_5_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_5_2_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_5_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_5_2->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_5_2_valueChanged(double arg1)
{
    double get_cf = ui->degree_5_2->value();
    QString get_str_qs = ui->label_5_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_5_3_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_5_3->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_5_3->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_5_3_valueChanged(double arg1)
{
    double get_cf = ui->cf_5_3->value();
    QString get_str_qs = ui->label_5_3->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_5_4_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_5_4->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_5_4->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_5_4_valueChanged(double arg1)
{
    double get_cf = ui->cf_5_4->value();
    QString get_str_qs = ui->label_5_4->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_6_1_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_6_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_6_1->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_6_1_valueChanged(double arg1)
{
    double get_cf = ui->cf_6_1->value();
    QString get_str_qs = ui->label_6_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_6_2_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_6_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_6_2->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_6_2_valueChanged(double arg1)
{
    double get_cf = ui->cf_6_2->value();
    QString get_str_qs = ui->label_6_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_6_3_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_6_3->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_6_3->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_6_3_valueChanged(double arg1)
{
    double get_cf = ui->cf_6_3->value();
    QString get_str_qs = ui->label_6_3->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_7_1_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_7_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_7_1->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_7_1_valueChanged(double arg1)
{
    double get_cf = ui->cf_7_1->value();
    QString get_str_qs = ui->label_7_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_7_2_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_7_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_7_2->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_7_2_valueChanged(double arg1)
{
    double get_cf = ui->cf_7_2->value();
    QString get_str_qs = ui->label_7_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_8_1_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_8_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_8_1->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_8_1_valueChanged(double arg1)
{
    double get_cf = ui->cf_8_1->value();
    QString get_str_qs = ui->label_8_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_8_2_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_8_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_8_2->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_8_2_valueChanged(double arg1)
{
    double get_cf = ui->cf_8_2->value();
    QString get_str_qs = ui->label_8_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_9_1_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_9_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_9_1->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_9_1_valueChanged(double arg1)
{
    double get_cf = ui->cf_9_1->value();
    QString get_str_qs = ui->label_9_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_10_1_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_10_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_10_1->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_10_1_valueChanged(double arg1)
{
    double get_cf = ui->cf_10_1->value();
    QString get_str_qs = ui->label_10_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_11_1_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_11_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_11_1->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_11_1_valueChanged(double arg1)
{
    double get_cf = ui->cf_11_1->value();
    QString get_str_qs = ui->label_11_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_12_1_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_12_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_12_1->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_12_1_valueChanged(double arg1)
{
    double get_cf = ui->cf_12_1->value();
    QString get_str_qs = ui->label_12_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_12_2_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_12_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_12_2->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_12_2_valueChanged(double arg1)
{
    double get_cf = ui->cf_12_2->value();
    QString get_str_qs = ui->label_12_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_13_1_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_13_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_13_1->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_13_1_valueChanged(double arg1)
{
    double get_cf = ui->cf_13_1->value();
    QString get_str_qs = ui->label_13_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_13_2_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_13_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_13_2->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_13_2_valueChanged(double arg1)
{
    double get_cf = ui->cf_13_2->value();
    QString get_str_qs = ui->label_13_2->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_cf_14_1_valueChanged(double arg1)
{
    double get_cf = arg1;
    QString get_str_qs = ui->label_14_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = ui->degree_14_1->value();
    ui_map_change(get_str_s, get_cf, get_degree);
}

void UserUI::on_degree_14_1_valueChanged(double arg1)
{
    double get_cf = ui->cf_14_1->value();
    QString get_str_qs = ui->label_14_1->text();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    double get_degree = arg1;
    ui_map_change(get_str_s, get_cf, get_degree);
}
