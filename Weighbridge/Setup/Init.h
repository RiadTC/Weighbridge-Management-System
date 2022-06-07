#ifndef INIT_H
#define INIT_H

#endif // INIT_H

#include <QString>
#include <QDateTime>
#include <QSqlTableModel>

#include "mainwindow.h"

QDateTime parse (QString d);
QSqlDatabase InitServer(void);
bool InsertRecord(QSqlTableModel *Table, Ticket *Record, QString ItemDesc, QString CusName, bool Finished);
QString ItemDesc (int index);
QString CustName (int index);
