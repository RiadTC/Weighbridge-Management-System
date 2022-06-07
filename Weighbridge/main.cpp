#include "mainwindow.h"
#include "Setup/Init.h"
#include <QApplication>
#include "iostream"
#include "QtSql/QSqlDatabase"
#include <QMessageBox>
#include <QStringList>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QCompleter>


int main(int argc, char *argv[])
{

    QCoreApplication::addLibraryPath("./");
    QCoreApplication::addLibraryPath("./lib");
    QCoreApplication::addLibraryPath("./plugins");
    QApplication a(argc, argv);
    MainWindow w;

    w.db = InitServer();
    w.show();
    return a.exec();

}
