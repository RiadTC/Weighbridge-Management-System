#include "Setup/Init.h"
#include <QtMessageHandler>
#include <QHeaderView>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QString>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QStringList>
#include <QCompleter>
#include <QList>
#include <QDebug>
#include <QCoreApplication>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Setup/Customers.h"
#include "Setup/Items.h"

// InitServer opens a connection with the server
// the parameters should be set as server information when the
// system is installed



QDateTime parse(QString dt)
{
    QString d,t;
    QStringList a, b;
    QTime Time;
    QDate Date;
    QDateTime date;


    a = dt.split(" ");
    d = a.at(0);
    t = a.at(1);
    a = d.split("/");
    Date.setDate(a.at(2).toInt(), a.at(1).toInt(), a.at(0).toInt());
    a = t.split(":");
    Time.setHMS(a.at(0).toInt(), a.at(1).toInt(), 0);
    date.setDate(Date);
    date.setTime(Time);
    return date;
}

QSqlDatabase InitServer (void)
{
    QMessageBox msgBox;
    QSqlDatabase db;
    QFile file("./Server.txt");
    QString ServerRec;
    QStringList ServerAttributes;

 //  Get server connection data from server.txt if found.
     if (file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
         ServerRec = file.readLine();
         ServerRec.remove("\n");
         if (ServerRec.length()) // line is not empty
         {   ServerAttributes = ServerRec.split(";");
             db = QSqlDatabase::addDatabase("QMYSQL", "Connection1");
             db.setHostName(ServerAttributes.at(1));
             db.setPort(ServerAttributes.at(2).toInt());
             db.setDatabaseName(ServerAttributes.at(0));
             db.setUserName(ServerAttributes.at(3));
             db.setPassword(ServerAttributes.at(4));
             bool ok = db.open();
             if (!ok)
             {   msgBox.setText("Could not connect to the database. Please review your connection settings.");
                 msgBox.exec();
             }
         }
         file.close();
     }
    else // Need to define server.txt from the file menu
     {    msgBox.setText("Could not connect to the database. Please review your server settings.");
          msgBox.exec();
     }
   return db;
}

// Create the default price list which is the basis for all lists
void MainWindow::InitPriceList(void)
{
    QSqlTableModel *Table;
    QSqlQuery Query(db);
    QSqlRecord Record;
    int ListID;

    Query.prepare("Select * from Lists where (ListName = 'Default')");
    if (Query.exec())
    {   // check if list is empty
        if (!Query.next())
        {   // Create Default List
            Query.prepare("INSERT INTO Lists (ListName) VALUES ('Default')");
            Query.exec();
            ListID = Query.lastInsertId().toInt();
            Query.prepare("SELECT * FROM Item WHERE (Sale = true)");
            Query.exec();
            // create price list for Default List
            Table = new QSqlTableModel(0, db);
            Table->setTable("PriceList");
            Table->select();
            Record = Table->record();
            while ((Query.next()))
            {
                Record.setValue("ListID", ListID);
                Record.setValue("Item", Query.value("ItemID").toInt());
                Record.setValue("Price", 0);
                Table->insertRecord(-1, Record);
            }
        }
    }
}


void MainWindow::InitData ()
{
    QSqlTableModel *CurTable;
    QSqlRecord TmpRecord;
    QSqlQuery Query (db);
    QSqlError Err;
    QStringList *itlist;
    QString Name;
    int i = 0;
    Item Material;

    addMode = false;
    // Open and read Customers Table into a list
    CurTable = new QSqlTableModel(0, db);
    CurTable->setTable("Customer");
    CurTable->select();
    CurTable->sort(1, Qt::AscendingOrder);
    CustCompleter = new QCompleter(CurTable);
    CustCompleter->setCompletionColumn(1);
    CustCompleter->setCompletionMode(QCompleter::PopupCompletion);
    CustCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    CustCompleter->setFilterMode(Qt::MatchContains);
    // Open and read Items Table into a list
    CurTable = new QSqlTableModel(0, db);
    CurTable->setTable("Item");
    CurTable->select();
    itlist = new QStringList;
    i = 0;
    while (i < CurTable->rowCount())
    {   TmpRecord = CurTable->record(i);
        Material.ShortDesc = TmpRecord.value("ShortDesc").toString();
        if (i>8) itlist->append(Material.ShortDesc);
        i++;
    }
    itlist->sort(Qt::CaseInsensitive);
   // ItemCompleterShort = new QCompleter(*itlist);
   // ItemCompleterShort->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
//    ItemCompleterShort->setCaseSensitivity(Qt::CaseInsensitive);
    //CurTable->sort(1, Qt::AscendingOrder);
    ItemCompleter = new QCompleter(CurTable);
    ItemCompleter->setModel(CurTable);
    ItemCompleter->setCompletionColumn(1);
    ItemCompleter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ItemCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    // Create a list of vehicules
    CurTable = new QSqlTableModel(0, db);
    CurTable->setTable("Ticket");
    CurTable->select();
    VehiculeList = new QStringList;
    DriverList = new QStringList;
    TransporterList = new QStringList;
    Query.prepare("SELECT DISTINCT Vehicule FROM Ticket");
    if (!Query.exec())
    { qDebug("Query Failed");
      Err = Query.lastError();
    }
    else  while (Query.next())
        {   Name = Query.value(0).toString();
            VehiculeList->append(Name);
         }
    VehiculeList->sort(Qt::CaseInsensitive);
    VehiculeCompleter = new QCompleter(*VehiculeList);
    VehiculeCompleter->setCompletionMode(QCompleter::PopupCompletion);
    VehiculeCompleter->setCaseSensitivity(Qt::CaseInsensitive);
 //   VehiculeCompleter->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    // Create list of drivers
    Query.prepare("SELECT DISTINCT Driver FROM Ticket");
    if (!Query.exec())
    { qDebug("Query Failed");
      Err = Query.lastError();
    }
    else  while (Query.next())
    {
        Name = Query.value(0).toString();
        DriverList->append(Name);
    }
    DriverList->sort(Qt::CaseInsensitive);
    DriverCompleter = new QCompleter(*DriverList);
    DriverCompleter->setCompletionMode(QCompleter::PopupCompletion);
    DriverCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    // Create list of Transporters
    Query.prepare("SELECT DISTINCT Transporter FROM Ticket");
    if (!Query.exec())
    {
        qDebug("Query Failed");
        Err = Query.lastError();
    }
    else  while (Query.next())
    {   Name = Query.value(0).toString();
        TransporterList->append(Name);
    }
    TransporterList->sort(Qt::CaseInsensitive);
    TransporterCompleter = new QCompleter(*TransporterList);
    TransporterCompleter->setCompletionMode(QCompleter::PopupCompletion);
    TransporterCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    InitPriceList();

    connect(ui->tvResult->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByHeader(int)));
}

bool InsertRecord (QSqlTableModel *Table, Ticket *Record, QString ItemDesc, QString CusName, bool Finished)
{
    QSqlRecord TmpRecord;

    TmpRecord = Table->record();
    if (Finished)
    {   TmpRecord.setValue("OperatorID", Record->OperatorID);
        TmpRecord.setValue("ItemID", Record->ItemID);
        TmpRecord.setValue("CustomerID", Record->CustomerID);
        TmpRecord.setValue("Full", Record->Full);
        TmpRecord.setValue("TimeOut", Record->TimeOut);
        TmpRecord.setValue("Netweight", Record->Full-Record->Empty);
    }
    else
    {   TmpRecord.setValue("Material",ItemDesc);
        TmpRecord.setValue("Customer", CusName);
    }
    TmpRecord.setValue("Vehicule", Record->Vehicule);
    TmpRecord.setValue("Empty", Record->Empty);
    TmpRecord.setValue("TimeIn", Record->TimeIn);
    TmpRecord.setValue("Transporter", Record->Transporter);
    TmpRecord.setValue("Driver", Record->Driver);
    TmpRecord.setValue("Remark", Record->Remark);
    if (!Table->insertRecord(-1,TmpRecord))
    {  qDebug("Error in inserting record"); return 0; }
    Record->id = Table->query().lastInsertId().toInt();
    return 1;
}

