#ifndef CUSTOMERDIALOG_H
#define CUSTOMERDIALOG_H

#include "Setup/Customers.h"
#include <QDialog>

namespace Ui {
class CustomerDialog;
}

class CustomerDialog : public QDialog
{
    Q_OBJECT

public:
     Customer *Custmer;
     bool InsertMode;
     float Bal;
     explicit CustomerDialog(Customer Cust, QWidget *parent = 0);
     explicit CustomerDialog(QAbstractItemModel *Model, QWidget *parent = 0);
    ~CustomerDialog();

private slots:

     int getCustomer(QString Name);
     void on_leName_editingFinished();
     void on_buttonBox_accepted();


private:
    Ui::CustomerDialog *ui;
    QAbstractItemModel *CustomerModel;
};

#endif // CUSTOMERDIALOG_H
