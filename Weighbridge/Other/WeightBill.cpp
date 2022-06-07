#include "WeightBill.h"
#include "ui_WeightBill.h"
#include "Setup/Init.h"
#include "Setup/Customers.h"
#include "Setup/Items.h"
#include "mainwindow.h"

#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>

//extern QSqlDatabase db;
//extern QStringList *CustomerList, *VehiculeList, *TransporterList, *ItemList, *DriverList;
//extern QCompleter *CustCompleter, *VehiculeCompleter,  *ItemCompleterLong, *DriverCompleter, *TransporterCompleter;

/*WeightBill::WeightBill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WeightBill)
{
    ui->setupUi(this);
}*/

WeightBill::WeightBill(QSqlDatabase db, QString Customer, QString Material, QString Transporter, QString Vehicule,
                       Ticket *OldWeigh, QCompleter *CustCompleter, QCompleter *ItemCompleterLong,
                       QCompleter *TransporterCompleter, QCompleter  *VehiculeCompleter , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WeightBill)
{
    ui->setupUi(this);
    ui->leCustomerTM->setText(Customer);
    ui->leCustomerTM->setCompleter(CustCompleter);
    ui->leMaterialTM->setText(Material);
    ui->leMaterialTM->setCompleter(ItemCompleterLong);
    ui->leTransporterTM->setText(Transporter);
    ui->leTransporterTM->setCompleter(TransporterCompleter);
    ui->leVehiculeTM->setText(Vehicule);
    ui->leVehiculeTM->setCompleter(VehiculeCompleter);
    OldTicket = OldWeigh;
    mydb = db;
}

WeightBill::~WeightBill()
{
    delete ui;
}

// getItemId returns the id of item with short description ItemDesc
// in addition to the row number in the items table
int WeightBill::getItemId(QString ItemDesc)
{
    int RowCount, CurRow = 0;

    if (!ItemDesc.isEmpty())
    {   RowCount = ui->leMaterialTM->completer()->model()->rowCount();
        while ((ItemDesc.compare(ui->leMaterialTM->completer()->model()->index(CurRow,1).data().toString() , Qt::CaseInsensitive) !=0) && (CurRow < RowCount)) CurRow++;
        if (CurRow < RowCount) return ui->leMaterialTM->completer()->model()->index(CurRow,0).data().toInt();;
    }
    return -1;
}

// returns the row number of the customer Name in the view model, -1 if not found
int WeightBill::getCustomerId(QString Name)
{
    int i=0;

    while ((i < ui->leCustomerTM->completer()->model()->rowCount()) &&
           (ui->leCustomerTM->completer()->model()->index(i,1).data().toString()!= Name))i++;
    if (i >= ui->leCustomerTM->completer()->model()->rowCount()) return -1;
    else return ui->leCustomerTM->completer()->model()->index(i,0).data().toInt();

}

void WeightBill::on_buttonBox_accepted()
{
    QMessageBox Warning;
    QSqlTableModel *Table;
    QSqlRecord Record;
    QSqlQuery Query(mydb);
    QDateTime dt;


    Warning.setText("Are you sure you want to modify this transaction ?");
    Warning.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel );
    Warning.setDefaultButton(QMessageBox::Cancel);
    if ( Warning.exec() == QMessageBox::Yes)
    {  // Check if data is complete
        if ((!ui->leCustomerTM->text().isEmpty()) && (!ui->leMaterialTM->text().isEmpty()) && (!ui->leVehiculeTM->text().isEmpty()))
        {    // Insert Old Ticket Values in Table log
            Table = new QSqlTableModel(0, mydb);
            Table->setTable("Log");
            Table->select();
            Record = Table->record();
            Record.setValue("Action", "Update");
            Record.setValue("CustomerID", OldTicket->CustomerID);
            Record.setValue("ItemID",OldTicket->ItemID);
            Record.setValue("Vehicule",OldTicket->Vehicule);
            Record.setValue("Transporter",OldTicket->Transporter);
            Record.setValue("TicketID", OldTicket->id);
            if (!Table->insertRecord(-1,Record))  qDebug("Error in inserting record");
            else
            {   Table = new QSqlTableModel(0, mydb);
                Table->setTable("Ticket");
                Table->select();
                // Update Ticket in Ticket Table
                Query.prepare("UPDATE Ticket SET CustomerID = :NewCustID , ItemID = :NewItemID,  "
                                        "Transporter = :NewTransporter, Vehicule = :NewVehicule "
                                        "WHERE (TicketID = :TicketNo)");
                Query.bindValue(":NewCustID", getCustomerId(ui->leCustomerTM->text()));
                Query.bindValue(":NewItemID", getItemId(ui->leMaterialTM->text()));
                Query.bindValue(":NewTransporter", ui->leTransporterTM->text());
                Query.bindValue(":NewVehicule", ui->leVehiculeTM->text());
                Query.bindValue(":TicketNo", OldTicket->id);
                if (!Query.exec()) qDebug("Record was not modified");
            }
        }
    }
}
