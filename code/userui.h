#ifndef USERUI_H
#define USERUI_H

#include <QDialog>
#include "testresult.h"

namespace Ui {
class UserUI;
}

class UserUI : public QDialog
{
    Q_OBJECT

public:
    explicit UserUI(QWidget *parent = 0);
    ~UserUI();

private slots:
    void on_user_return_clicked();

    void on_user_run_clicked();

    void on_cf_1_1_valueChanged(double arg1);

    void on_degree_1_1_valueChanged(double arg1);

    void on_cf_2_1_valueChanged(double arg1);

    void on_degree_2_1_valueChanged(double arg1);

    void on_cf_2_2_valueChanged(double arg1);

    void on_degree_2_2_valueChanged(double arg1);

    void on_cf_3_1_valueChanged(double arg1);

    void on_degree_3_1_valueChanged(double arg1);

    void on_cf_3_2_valueChanged(double arg1);

    void on_degree_3_2_valueChanged(double arg1);

    void on_cf_4_1_valueChanged(double arg1);

    void on_degree_4_1_valueChanged(double arg1);

    void on_cf_4_2_valueChanged(double arg1);

    void on_degree_4_2_valueChanged(double arg1);

    void on_cf_5_1_valueChanged(double arg1);

    void on_degree_5_1_valueChanged(double arg1);

    void on_cf_5_2_valueChanged(double arg1);

    void on_degree_5_2_valueChanged(double arg1);

    void on_cf_5_3_valueChanged(double arg1);

    void on_degree_5_3_valueChanged(double arg1);

    void on_cf_5_4_valueChanged(double arg1);

    void on_degree_5_4_valueChanged(double arg1);

    void on_cf_6_1_valueChanged(double arg1);

    void on_degree_6_1_valueChanged(double arg1);

    void on_cf_6_2_valueChanged(double arg1);

    void on_degree_6_2_valueChanged(double arg1);

    void on_cf_6_3_valueChanged(double arg1);

    void on_degree_6_3_valueChanged(double arg1);

    void on_cf_7_1_valueChanged(double arg1);

    void on_degree_7_1_valueChanged(double arg1);

    void on_cf_7_2_valueChanged(double arg1);

    void on_degree_7_2_valueChanged(double arg1);

    void on_cf_8_1_valueChanged(double arg1);

    void on_degree_8_1_valueChanged(double arg1);

    void on_cf_8_2_valueChanged(double arg1);

    void on_degree_8_2_valueChanged(double arg1);

    void on_cf_9_1_valueChanged(double arg1);

    void on_degree_9_1_valueChanged(double arg1);

    void on_cf_10_1_valueChanged(double arg1);

    void on_degree_10_1_valueChanged(double arg1);

    void on_cf_11_1_valueChanged(double arg1);

    void on_degree_11_1_valueChanged(double arg1);

    void on_cf_12_1_valueChanged(double arg1);

    void on_degree_12_1_valueChanged(double arg1);

    void on_cf_12_2_valueChanged(double arg1);

    void on_degree_12_2_valueChanged(double arg1);

    void on_cf_13_1_valueChanged(double arg1);

    void on_degree_13_1_valueChanged(double arg1);

    void on_cf_13_2_valueChanged(double arg1);

    void on_degree_13_2_valueChanged(double arg1);

    void on_cf_14_1_valueChanged(double arg1);

    void on_degree_14_1_valueChanged(double arg1);

private:
    Ui::UserUI *ui;
    TestResult testresult;
};

#endif // USERUI_H
