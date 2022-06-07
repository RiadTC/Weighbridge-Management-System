#include "Customers.h"
#include "ui_Customers.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QStringList>
#include <QString>
#include <QListView>
#include <QSqlError>
#include <QMessageBox>
#include <QList>
#include "Setup/CustomerDialog.h"


Customers::Customers(QSqlDatabase db, QAbstractItemModel *Model, QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Customers)
{

    ui->setupUi(this);
    mydb = db;
    ui->lvCustomers->setModel(Model);
    ui->lvCustomers->setModelColumn(1);

}


Customers::~Customers()
{
    delete ui;
}

// returns the row number of the customer Name in the view model, -1 if not found
int Customers::getCustomer(QString Name)
{
    int i=0;

    while ((i < ui->lvCustomers->model()->rowCount()) && (ui->lvCustomers->model()->index(i,1).data().toString()!= Name))i++;
    if (i >= ui->lvCustomers->model()->rowCount()) return -1;
    else return i;

}


// returns the customer's data at row index of the view model
void MainWindow::getCustomer(Customer *Cust, int row)
{

    Cust->id = ui->tvCustomers->model()->index(row,0).data().toInt();
    Cust->Name = ui->tvCustomers->model()->index(row,1).data().toString();
    Cust->Active = ui->tvCustomers->model()->index(row,5).data().toBool();
    Cust->Factor = ui->tvCustomers->model()->index(row,6).data().toDouble();

}


int MainWindow::getCustomerId(QString CustName)
{
    int RowCount, CurRow =0;
    QString s;

    if (!CustName.isEmpty())
    {   RowCount = CustCompleter->model()->rowCount();
         s = CustCompleter->model()->index(CurRow,1).data().toString();
        while ( (s != CustName)  && (CurRow < RowCount))
        {   CurRow++;
            s = CustCompleter->model()->index(CurRow,1).data().toString();
        }
        if (CurRow < RowCount)
        {
            CurCustomer->id = CustCompleter->model()->index(CurRow,0).data().toInt();
            CurCustomer->Name = CustCompleter->model()->index(CurRow,1).data().toString();
            CurCustomer->Factor = CustCompleter->model()->index(CurRow,6).data().toDouble();
            return CurCustomer->id;
        }
    }
    return -1;
}


void MainWindow::modifyCustomer(int row, Customer *NewData)
{
    QModelIndex index;

    index = ui->tvCustomers->model()->index(row,1);
    ui->tvCustomers->model()->setData(index, NewData->Name);
    index = ui->tvCustomers->model()->index(row,2);
    ui->tvCustomers->model()->setData(index, NewData->FullName);
    index = ui->tvCustomers->model()->index(row,3);
    ui->tvCustomers->model()->setData(index, NewData->Phone1);
    index = ui->tvCustomers->model()->index(row,4);
    ui->tvCustomers->model()->setData(index, NewData->Phone2);
    index = ui->tvCustomers->model()->index(row,5);
    ui->tvCustomers->model()->setData(index, NewData->Active);
    index = ui->tvCustomers->model()->index(row,6);
    ui->tvCustomers->model()->setData(index, NewData->Factor);
    index = ui->tvCustomers->model()->index(row,7);
    ui->tvCustomers->model()->setData(index, NewData->Account);
}

bool Customers::AddCustomer(Customer *Cust, int *Index)
{
    QSqlQuery Query(mydb);
    QSqlError Err;
    QMessageBox Msg;


    if (!Cust->Name.isEmpty())
    {
       Query.prepare("INSERT INTO Customer (Name, Phone1, Phone2, Active, Factor) "
                       "VALUES (:Name, :Phone1, :Phone2, :Active, :Factor)");
       Query.bindValue(":Name", Cust->Name);
       Query.bindValue(":Phone1", Cust->Phone1);
       Query.bindValue(":Phone2", Cust->Phone2);
       Query.bindValue(":Active", Cust->Active);
       Query.bindValue(":Factor", 1);
       if (!Query.exec())
       { qDebug("Record was not inserted");
         Err = Query.lastError();
         return false;
       }
      else
       {  if (Index != NULL) *Index = Query.lastInsertId().toInt();
          return 1;
       }
    }
}

void MainWindow::on_pbModifyCustomer_clicked()
{
    QSqlTableModel *Table;
    QSqlRecord CustRec;
    QSqlQuery Query(db);
    QSqlError Err;
    QMessageBox Warning;
    CustomerDialog *ModifyDialog;
    Customer OldCustomer, *NewCustomer;
    int index, i;

    index = ui->tvCustomers->currentIndex().row();
    getCustomer(&OldCustomer, index);
    ModifyDialog = new CustomerDialog( OldCustomer, this);
    if (ModifyDialog->exec())  // Ok was pressed
    {   NewCustomer = ModifyDialog->Custmer;
        if (OldCustomer.Name == NewCustomer->Name) // Name Description was not modified
        {  // Update other Fields
            Query.prepare("UPDATE Customer SET Phone1 = :Phone1, Phone2 = :Phone2, Active = :Active  "
                                     "WHERE (CustomerID= :CustomerID)");
            Query.bindValue(":CustomerID", NewCustomer->id);
            Query.bindValue(":Phone1", NewCustomer->Phone1);
            Query.bindValue(":Phone2", NewCustomer->Phone2);
            Query.bindValue(":Active", NewCustomer->Active);
            if (!Query.exec()) qDebug("Record could not be modified");
            else modifyCustomer(index, NewCustomer);
        }
        else
        {   i = getCustomerId(NewCustomer->Name);
            if (i<0) // Change of Customer name to a new one
            {   Table = new QSqlTableModel(0, db);
                Table->setTable("Customer");
                Table->select();
                Query.prepare("UPDATE Customer SET Name = :Name,  Phone1 = :Phone1, Phone2 = :Phone2, Active = :Active "
                                         "WHERE (CustomerID= :CustomerID)");
                Query.bindValue(":CustomerID", NewCustomer->id);
                Query.bindValue(":Name", NewCustomer->Name);
                Query.bindValue(":Phone1", NewCustomer->Phone1);
                Query.bindValue(":Phone2", NewCustomer->Phone2);
                            Query.bindValue(":Active", NewCustomer->Active);
                if (!Query.exec()) qDebug("Record could not be modified");
                else modifyCustomer(index, NewCustomer);
            }
            else // Replace item by another
            {
               Warning.setText("Are you sure you want to replace "+ OldCustomer.Name
                             + " by " +CurCustomer->Name + "?");
               Warning.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel );
               Warning.setDefaultButton(QMessageBox::Cancel);
               if ( Warning.exec() == QMessageBox::Yes)
               {  Table = new QSqlTableModel(0, db);
                  Table->setTable("Ticket");
                  Table->select();
                  Query.prepare("UPDATE Ticket SET CustomerID = :NewCustID WHERE (CustomerID = :OldCustID)");
                  Query.bindValue(":NewCustID", CurCustomer->id);
                  Query.bindValue(":OldCustID", OldCustomer.id);
                  if (!Query.exec()) qDebug("Record was not modified");
               }
            }
       }
    }
}


void Customers::on_pbClose_clicked()
{
    this->close();
}



void MainWindow::on_pbAddCustomer_clicked()
{
    CustomerDialog *NewCustDialog;
    QSqlTableModel *Table;
    QSqlRecord Record;

    NewCustDialog = new CustomerDialog(CustCompleter->model() ,this);
    NewCustDialog->exec();
    if (!NewCustDialog->Custmer->Name.isEmpty())
    {   // Add Customer in the model/view
        Table = static_cast <QSqlTableModel *> (CustCompleter->model());
        Record = Table->record();
        Record.setValue("Name", NewCustDialog->Custmer->Name);
        Record.setValue("FullName", NewCustDialog->Custmer->Name);
        Record.setValue("Phone1", NewCustDialog->Custmer->Phone1);
        Record.setValue("Phone2", NewCustDialog->Custmer->Phone2);
        Record.setValue("Active", NewCustDialog->Custmer->Active);
        Record.setValue("AccountNo", NewCustDialog->Custmer->Account);
        Record.setValue("Factor", 1);
        if (Table->insertRecord(-1, Record))
        {   Table->submitAll();
            ui->tvCustomers->model()->sort(1, Qt::AscendingOrder);
            Table = new QSqlTableModel(0,db);
            Table->setTable("Accounts");
            Table->select();
            Record = Table->record();
            Record.setValue("AccountNo", NewCustDialog->Custmer->Account);
            Record.setValue("Balance", NewCustDialog->Bal);
            Table->insertRecord(-1, Record);
        }
        else qDebug() << Table->lastError();
    }
}


void MainWindow::on_pbDeleteCustomer_clicked()
{
    QSqlTableModel *Table;
    QSqlQuery Query(db);
    QSqlError Err;
    Customer CustomerToDelete;
    QMessageBox Warning;
    QModelIndex index;

    index = ui->tvCustomers->currentIndex();
    if (index.isValid())
    {   getCustomer(&CustomerToDelete, index.row());
        Warning.setText("Are you sure you want to delete "+ CustomerToDelete.Name + "?");
        Warning.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel );
        Warning.setDefaultButton(QMessageBox::Cancel);
        if ( Warning.exec() == QMessageBox::Yes)
        {   // Check if the customer is used in transactions
            Table = new QSqlTableModel(0, db);
            Table->setTable("Ticket");
            Table->select();
            Query.prepare("SELECT * FROM Ticket WHERE (CustomerID = :CustID)");
            Query.bindValue(":CustID", CustomerToDelete.id);
            if (!Query.exec()) qDebug("Error in Query");
            else if (Query.size()<=0)
            {   // Check if the customer is used in transactions
                Table = new QSqlTableModel(0, db);
                Table->setTable("InProcess");
                Table->select();
                Query.prepare("SELECT * FROM InProcess WHERE (Customer = :Name)");
                Query.bindValue(":Name", CustomerToDelete.Name);
                if (!Query.exec()) qDebug("Error in Query");
                else if (Query.size()<=0)
                {   // Customer can be deleted
                     Query.prepare("DELETE FROM Customer WHERE (CustomerID = :CustID)");
                     Query.bindValue(":CustID", CustomerToDelete.id);
                     if (!Query.exec()) qDebug("Record was not deleted");
                     else
                     {   //CustCompleter->model()->removeRow(index.row());
                         ui->tvCustomers->model()->removeRow(index.row());
                         ui->tvCustomers->model()->submit();
                         ui->tvCustomers->model()->sort(1, Qt::AscendingOrder);

                     }
                }
                else
                {   Warning.setText( CustomerToDelete.Name + " is used in some transactions and cannot be deleted.");
                    Warning.setStandardButtons(QMessageBox::Ok );
                    Warning.exec();
                }
            }
            else
            {   Warning.setText( CustomerToDelete.Name+ " is used in some transactions and cannot be deleted.");
                Warning.setStandardButtons(QMessageBox::Ok );
                Warning.exec();
            }
        }
    }
}



void MainWindow::on_tvCustomers_clicked(const QModelIndex &index)
{
    int row, CustomerID;


    row = index.row();
    CustomerID =  ui->tvCustomers->model()->data(ui->tvCustomers->model()->index(row,0)).toInt();
    ui->leName->setText(ui->tvCustomers->model()->data(ui->tvCustomers->model()->index(row,1)).toString());

}
