#include "loginin.h"
#include <QApplication>
#include <QTextCodec>
#include <qtextcodec.h>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Loginin w;
    w.show();

    return a.exec();
}
