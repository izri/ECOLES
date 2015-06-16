/** \mainpage Management of a restaurant made easy.
    This software can manage the client of a resturant.
    Stats are done automatically and the database of customer don't
    need any manual operations on it.
*/
#include <iostream>
#include <string>
#include <QApplication>
#include "startwindow.h"
#include "src/customer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;
    w.setModal(true);
    w.exec();

    exit(42);
    return a.exec();
}
