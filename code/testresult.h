#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <QDialog>


namespace Ui {
class TestResult;
}

class TestResult : public QDialog
{
    Q_OBJECT

public:
    explicit TestResult(QWidget *parent = 0);
    ~TestResult();
    void flash();

private slots:


private:
    Ui::TestResult *ui;
};

#endif // TESTRESULT_H
