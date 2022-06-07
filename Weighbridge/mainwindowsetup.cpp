#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Setup/SettingsDialog.h"
#include "Setup/PriceList.h"

#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QMessageBox>


void MainWindow::on_actionOperators_triggered()
{
    QSqlQueryModel *Model;
    QSqlQuery Query(db);
    QMessageBox Warning;
    QString Key;

    // Initialize Tab
    ui->tabWidget->addTab(ReportTab[0], "Operators List");
    ui->tabWidget->setCurrentWidget(ReportTab[0]);
    // Open and read Operators Table into a list
    Model = new QSqlQueryModel (0);
    Key = "729308A8E815F6A46EB3A8AE6D5463CA7B64A0E2E11BC26A68106FC7697E727E37011";
    Query.prepare("SELECT OperatorID, Name, AES_DECRYPT(Password, :Key) FROM Operator");
    Query.bindValue(":Key", Key);
    if (!Query.exec())
    {
        Warning.setText(Query.lastError().text());
        Warning.exec();
    }
    else
    {
        Model->setQuery(Query);
        ui->tvOperators->setModel(Model);
        ui->tvOperators->model()->setHeaderData(1, Qt::Horizontal, "Operator Name", 0);
        ui->tvOperators->model()->setHeaderData(2, Qt::Horizontal, "Password", 0);
        ui->tvOperators->hideColumn(0);
        ui->tvOperators->hideColumn(2);
        ui->tvOperators->resizeColumnsToContents();
        ui->tvOperators->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
        ui->tvOperators->setAlternatingRowColors(true);
        ui->tvOperators->setSortingEnabled(true);
    }

}


void MainWindow::on_actionCustomers_triggered()
{
    QSqlTableModel *CustTable;

    // Initialize Tab
    ui->tabWidget->addTab(ReportTab[1], "Customers List");
    ui->tabWidget->setCurrentWidget(ReportTab[1]);
    ui->tvCustomers->setModel(CustCompleter->model());
    ui->tvCustomers->model()->setHeaderData(1, Qt::Horizontal, "Name", 0);
    //ui->tvCustomers->model()->setHeaderData(2, Qt::Horizontal, "Full Name", 0);
    for (int i=0; i<10; i++) ui->tvCustomers->hideColumn(i);
    ui->tvCustomers->showColumn(1);
    ui->tvCustomers->resizeColumnsToContents();
    ui->tvCustomers->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tvCustomers->setAlternatingRowColors(true);
    ui->tvCustomers->setSortingEnabled(true);
    CustTable = static_cast <QSqlTableModel *> (ItemCompleter->model());
    CustTable->setEditStrategy(QSqlTableModel::OnFieldChange);
    //connect(CustTable, SIGNAL(beforeUpdate(int,QSqlRecord&)), this, SLOT(updateCustRow(int,QSqlRecord&)));

}


void MainWindow::on_actionItems_triggered()
{
    QSqlTableModel *ItemsTable;

    // Initialize Tab
    ui->tabWidget->addTab(ReportTab[2], "Items List");
    ui->tabWidget->setCurrentWidget(ReportTab[2]);
    ui->leShortDesc->clear();
    ui->leLongDesc->clear();
    ui->lDate->clear();
    ui->lQuantity->clear();
    ui->lCustomer->clear();
    ui->lVehicule->clear();
    ui->lcurM->clear();
    ui->lcurW->clear();
    ui->lcurY->clear();
    ui->tvItems->setModel(ItemCompleter->model());
    ui->tvItems->model()->setHeaderData(1, Qt::Horizontal, "Short Description", 0);
    ui->tvItems->model()->setHeaderData(2, Qt::Horizontal, "Long Description", 0);
    ui->tvItems->hideColumn(0);
    ui->tvItems->resizeColumnsToContents();
    ui->tvItems->setAlternatingRowColors(true);
    ui->tvItems->setSortingEnabled(true);
    ItemsTable = static_cast <QSqlTableModel *> (ItemCompleter->model());
    ItemsTable->setEditStrategy(QSqlTableModel::OnFieldChange);
    connect(ItemsTable, SIGNAL(beforeUpdate(int,QSqlRecord&)), this, SLOT(updateItemRow(int,QSqlRecord&)));

}


void MainWindow::openSerialPort()
{
    QSqlTableModel *PortTable;
    QSqlRecord PortRec;

    //Initialize Port's Table then Check if user is in database.
    PortTable = new QSqlTableModel(0, db);
    PortTable->setTable("Port");
    PortTable->select();
    PortRec = PortTable->record(0);

    serial->setPortName(PortRec.value("Name").toString());
    serial->setBaudRate(static_cast<QSerialPort::BaudRate>(PortRec.value("Baudrate").toInt()));
    serial->setDataBits(static_cast<QSerialPort::DataBits>(PortRec.value("Databits").toInt()));
    serial->setParity( static_cast<QSerialPort::Parity>(PortRec.value("Parity").toInt()));
    serial->setStopBits(static_cast<QSerialPort::StopBits>(PortRec.value("Stopbits").toInt()));
    serial->setFlowControl(static_cast<QSerialPort::FlowControl>(PortRec.value("Flowcontrol").toInt()));

    StreamLen = PortRec.value("StreamLen").toInt();
    Delimiter = PortRec.value("Delimiter").toString();
    Indicator = PortRec.value("Indicator").toString();

    if (!serial->open(QIODevice::ReadWrite)) QMessageBox::critical(this, tr("Error"), serial->errorString());
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    //connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(readData(QString)));

}

void MainWindow::on_actionSerial_Port_triggered()
{
    SettingsDialog PortSetting(db, this);

    PortSetting.exec();
    openSerialPort();
}

void MainWindow::on_actionPrice_Lists_triggered()
{
    QSqlTableModel *ListsTable;

    // Initialize Tab
    ui->tabWidget->addTab(ReportTab[3], "Price Lists");
    ui->tabWidget->setCurrentWidget(ReportTab[3]);
    ListsTable = new QSqlTableModel (0, db);
    ListsTable->setTable("Lists");
    ListsTable->select();
    ListsTable->setEditStrategy(QSqlTableModel::OnFieldChange);

    ui->tvLists->setModel(ListsTable);
    ui->tvLists->model()->setHeaderData(1, Qt::Horizontal, "List Name", 0);
    ui->tvLists->hideColumn(0);
    ui->tvLists->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tvLists->setAlternatingRowColors(true);
    ui->tvLists->setSortingEnabled(true);
    ui->tvLists->sortByColumn(1, Qt::AscendingOrder);

    connect(ui->tvLists->model(), SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(updateListRow(QModelIndex,QModelIndex)));
}





