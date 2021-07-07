#include "mainwindow.h"

#include <QApplication>
#include<databasehandler.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DatabaseHandler dbh;
    dbh.setAPIkey("AIzaSyAoB27uJgJKRfy9l_DewZvTUkVJDeGH5mY");
    w.show();
    return a.exec();
}
