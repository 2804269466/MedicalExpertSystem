#ifndef EXPERTUI_H
#define EXPERTUI_H

#include <QDialog>

namespace Ui {
class ExpertUI;
}

class ExpertUI : public QDialog
{
    Q_OBJECT

public:
    explicit ExpertUI(QWidget *parent = 0);
    ~ExpertUI();

private slots:
    void on_expert_return_clicked();

    void on_button_file_1_clicked();

    void on_button_file_2_clicked();

    void on_button_file_3_clicked();

    void on_button_file_4_clicked();

    void on_button_file_5_clicked();

    void on_file_save_clicked();

private:
    Ui::ExpertUI *ui;
};

#endif // EXPERTUI_H
