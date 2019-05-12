#include <QCoreApplication>
#include "QtGrape.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QtGrape instance;

    instance.generate(QString("overwatch"));



    return a.exec();
}
