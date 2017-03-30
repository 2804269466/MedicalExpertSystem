#include "testresult.h"
#include "ui_testresult.h"
#include "expertsystem.h"
#include <QDebug>

TestResult::TestResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestResult)
{
    ui->setupUi(this);


}

TestResult::~TestResult()
{
    delete ui;
}

void TestResult::flash(){
    ui->test_result->setText("");
    ui_map_output();
    user_interface();
    view_result();
    priority_queue<UIRes> get_queue = ui_res_map();
    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;
    while(!get_queue.empty()){
        UIRes get_head = get_queue.top();

        cout << get_head.sdiseasename << "  " << get_head.possibility << endl;
        if(get_head.possibility == 0){
            if(flag1 == false){
                string temp_1_s = "很有可能:";
                QString temp_1_qs = QString::fromStdString(temp_1_s);
                ui->test_result->setText(ui->test_result->text() + "\n" + temp_1_qs);
                flag1 = true;
            }

            ui->test_result->setText(ui->test_result->text() + "\n" +  "   " + QString::fromStdWString(str2wstr(get_head.sdiseasename)));

        }
        else if(get_head.possibility == 1){
            if(flag2 == false){
                string temp_2_s = "可能:";
                QString temp_2_qs = QString::fromStdString((temp_2_s));
                ui->test_result->setText(ui->test_result->text() + "\n" + temp_2_qs);
                flag2 = true;
            }
            ui->test_result->setText(ui->test_result->text() + "\n" +  "   " + QString::fromStdWString(str2wstr(get_head.sdiseasename)));

        }
        else{
            if(flag3 == false){
                string temp_3_s = "极小可能:";
                QString temp_3_qs = QString::fromStdString((temp_3_s));
                ui->test_result->setText(ui->test_result->text() + "\n" + temp_3_qs);
                flag3 = true;
            }
            ui->test_result->setText(ui->test_result->text() + "\n" +  "   " + QString::fromStdWString(str2wstr(get_head.sdiseasename)));

        }
        get_queue.pop();
    }

    QString get_final = ui->test_result->text();
    int len_final = get_final.length();
    if(get_final.length() <= 1){
        string temp_4_s = "证据不足";
        QString temp_4_qs = QString::fromStdString(temp_4_s);
        ui->test_result->setText(ui->test_result->text() + "\n" + temp_4_qs);
    }

    reset_environment();
}
