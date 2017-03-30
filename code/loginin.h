#ifndef LOGININ_H
#define LOGININ_H

#include <QMainWindow>
#include "userui.h"
#include "expertui.h"

namespace Ui {
class Loginin;
}

class Loginin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Loginin(QWidget *parent = 0);
    ~Loginin();

private slots:
    void on_Loginin_iconSizeChanged(const QSize &iconSize);

    void on_login_close_clicked();

    void on_login_user_clicked();

    void on_login_user_img_clicked();

    void on_login_expert_clicked();

    void on_login_expert_img_clicked();

private:
    Ui::Loginin *ui;

    UserUI userui;
    ExpertUI expertui;
};

#endif // LOGININ_H
