#include "CustomerDialog.h"
#include "ui_CustomerDialog.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>


CustomerDialog::CustomerDialog(QAbstractItemModel *Model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerDialog)
{
    ui->setupUi(this);
    ui->rbActive->setChecked(true);
    InsertMode = true;
    CustomerModel = Model;
    Custmer = new Customer;
}

CustomerDialog::CustomerDialog( Customer Cust, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerDialog)
{
    ui->setupUi(this);
    ui->leName->setText(Cust.Name);
    ui->leFullName->setText(Cust.FullName);
    ui->lePhone1->setText(Cust.Phone1);
    ui->lePhone2->setText(Cust.Phone2);
    ui->rbActive->setChecked(Cust.Active);
    Custmer = new Customer;
    InsertMode = false;
}

CustomerDialog::~CustomerDialog()
{
    delete ui;
}

// returns the row index of the customer in the table model, -1 if not found
int CustomerDialog::getCustomer(QString Name)
{
    int i=0;

    while (i < CustomerModel->rowCount())
    {   if (!Name.compare(CustomerModel->index(i,1).data().toString(), Qt::CaseInsensitive)) return i;
        i++;
    }
    return -1;

}

void CustomerDialog::on_leName_editingFinished()
{
    QMessageBox Err;

    // Customer name should not be null and must be unique
    if (InsertMode)
        if (!ui->leName->text().isEmpty())
        {  // Check if Customer name is in database.
           if ( getCustomer(ui->leName->text()) >= 0 )
            {   Err.setText("Customer already exists");
                Err.setWindowTitle("Customer");
                Err.exec();
                ui->leName->clear();
                ui->leName->setFocus();
             }
        }
}


void CustomerDialog::on_buttonBox_accepted()
{
    Custmer->Name = ui->leName->text();
    Custmer->FullName = ui->leFullName->text();
    Custmer->Phone1 = ui->lePhone1->text();
    Custmer->Phone2 = ui->lePhone2->text();
    Custmer->Active = ui->rbActive->isChecked();
    Custmer->Account = ui->leAccount->text();
    Custmer->Factor = 1.0;
    Bal = ui->leAccount->text().toFloat();
}
