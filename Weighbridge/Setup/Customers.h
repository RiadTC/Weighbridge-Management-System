#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <QAbstractItemModel>
#include <QDockWidget>
#include <QSqlDatabase>
#include <QSqlRecord>

typedef struct
{   QString Name, FullName, Phone1, Phone2, Account;
    bool Active;
    int id;
    double Factor;
} Customer;


namespace Ui {
class Customers;
}

class Customers : public QDockWidget
{
    Q_OBJECT

public:
//    Customer Cust;
    explicit Customers(QSqlDatabase db, QAbstractItemModel *Model, QWidget *parent = 0);
    ~Customers();

   bool AddCustomer ( Customer *Cust, int *Index);

private slots:
 
    int getCustomer(QString Name);
//    void modifyCustomer(int Index, Customer *NewData);
//    void on_pbAddCustomer_clicked();
//    void on_pbModCustomer_clicked();
//    void on_pbDelCustomer_clicked();
    void on_pbClose_clicked();



private:
    Ui::Customers *ui;
    QSqlDatabase mydb;
};

#endif // CUSTOMERS_H
