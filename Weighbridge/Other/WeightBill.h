#ifndef WEIGHTBILL_H
#define WEIGHTBILL_H

#include <QDialog>

#include "mainwindow.h"

namespace Ui {
class WeightBill;
}

class WeightBill : public QDialog
{
    Q_OBJECT

public:
//    explicit WeightBill(QWidget *parent = 0);
    explicit WeightBill(QSqlDatabase db, QString Customer, QString Material, QString Transporter, QString Vehicule, Ticket *OldWeigh,
                        QCompleter *CustCompleter, QCompleter *ItemCompleterLong, QCompleter *TransporterCompleter, QCompleter  *VehiculeCompleter,
                        QWidget *parent);
    ~WeightBill();

private slots:

    int  getItemId(QString ItemDesc);
    int  getCustomerId(QString Name);
    void on_buttonBox_accepted();

private:
    Ticket *OldTicket;
    Ui::WeightBill *ui;
    QSqlDatabase mydb;
};

#endif // WEIGHTBILL_H
