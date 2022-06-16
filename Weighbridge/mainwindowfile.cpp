#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_ServerDialog.h"
#include "ui_noticedialog.h"
#include "Setup/Init.h"
#include "Other/mydelegate.h"
#include "Other/LoginDialog.h"
#include "ui_ProgressDialog.h"
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QFileDialog>
#include <QProcess>
#include <QStringList>
#include <QDialog>

void MainWindow::on_actionLogin_triggered()
{
    // Show Login form
    DialogLogin DL(db,0);
    int i=0;
    QSqlTableModel *Table;
    QMessageBox Warning;

    //Check if the database connection is open before trying to login
    if (!db.isOpen())
    {   // Database connection should be established before trying to login
        Warning.setText("Database connection should be open before trying to login");
        Warning.setStandardButtons(QMessageBox::Ok);
        Warning.exec();
        return;
    }
    // If a database connection is already established proceed with the login process
    if (ui->actionLogin->text() == "&Login")
    {   // if Login is pressed then show the login dialog.
        DL.exec();
        if (DL.correctPass) // if the operatorname and password are correct, proceed with the login
        {   CurOperator.id = DL.User.id;
            CurOperator.Name = DL.User.Name;
            ui->actionLogin->setText("Logout");
            ui->menuBar->setEnabled(true);
            ui->tabWidget->setEnabled(true);
            if (CurOperator.Name == "Admin")  ui->menuSetup->setEnabled(true);
            ui->menuImport->setEnabled(true);
            ui->menuReports->setEnabled(true);
            openSerialPort();
            InitData();
            ui->leVehicule->setFocus();
            ui->leCustomer->setCompleter(CustCompleter);
            ui->leCustomer1->setCompleter(CustCompleter);
            ui->leMaterial->setCompleter(ItemCompleter);
            ui->leVehicule->setCompleter(VehiculeCompleter);
            ui->leVehicule1->setCompleter(VehiculeCompleter);
            ui->leDriver->setCompleter(DriverCompleter);
            ui->leDriver1->setCompleter((DriverCompleter));
            ui->leTransporter->setCompleter(TransporterCompleter);
            ui->leTransporter1->setCompleter(TransporterCompleter);
            while (i < ItemCompleter->model()->rowCount())
            {  switch (i)
                {
                    case 0: ui->rb0->setText(ItemCompleter->model()->index(i,1).data().toString()); break;
                    case 1: ui->rb1->setText(ItemCompleter->model()->index(i,1).data().toString()); break;
                    case 2: ui->rb2->setText(ItemCompleter->model()->index(i,1).data().toString()); break;
                    case 3: ui->rb3->setText(ItemCompleter->model()->index(i,1).data().toString()); break;
                    case 4: ui->rb4->setText(ItemCompleter->model()->index(i,1).data().toString()); break;
                    case 5: ui->rb5->setText(ItemCompleter->model()->index(i,1).data().toString()); break;
                    case 6: ui->rb6->setText(ItemCompleter->model()->index(i,1).data().toString()); break;
                    case 7: ui->rb7->setText(ItemCompleter->model()->index(i,1).data().toString()); break;
                    case 8: ui->rb8->setText(ItemCompleter->model()->index(i,1).data().toString()); break;
                    //case 9: ui->leOther->setText(ItemCompleter->model()->index(i,1).data().toString()); break;
                }
                i++;
            }
            while (i < 10)
            {  switch (i)
                {
                    case 0: ui->rb0->hide(); break;
                    case 1: ui->rb1->hide(); break;
                    case 2: ui->rb2->hide(); break;
                    case 3: ui->rb3->hide(); break;
                    case 4: ui->rb4->hide(); break;
                    case 5: ui->rb5->hide(); break;
                    case 6: ui->rb6->hide(); break;
                    case 7: ui->rb7->hide(); break;
                    case 8: ui->rb8->hide(); break;
                    case 9: ui->rb9->hide(); ui->cbOther->hide(); break;
                }
                i++;
            }
        ResetButtons();
        ItemCompleter->model()->sort(1, Qt::AscendingOrder);
        Table = new QSqlTableModel(0, db);
        Table->setTable("InProcess");
        Table->select();
        ui->tvTicket->setModel(Table);
        ui->tvTicket->setItemDelegateForColumn(7,new MyDelegate(this) );
        ui->tvTicket->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tvTicket->hideColumn(0);
        ui->tvTicket->horizontalHeader()->setSectionsMovable(true);
        ui->tvTicket->setAlternatingRowColors(true);
        ui->tvTicket->horizontalHeader()->setStyleSheet("font-size: 11pt;font-weight: bold;background-color: rgb(255, 210, 0)");
        //ui->tvTicket->setStyleSheet("alternate-background-color: lightyellow;background-color: lightgray;");
        for (int c = 0; c < ui->tvTicket->horizontalHeader()->count(); ++c)
           {
               ui->tvTicket->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
           }
        }
        DL.close();
    }
    else
    {   // Logout is pressed.
        // Quitting the application. Show a warning message. If confirmed, proceed.
        Warning.setText("Are you sure you want to quit?");
        Warning.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel );
        Warning.setDefaultButton(QMessageBox::Cancel);
        if ( Warning.exec() == QMessageBox::Ok) QApplication::quit();
    }
}


void MainWindow::on_actionCustomersImport_triggered()
{
    QSqlTableModel *CustomersTable;
    QSqlRecord Record;
    QString Name, fileName;
    QFile File;
    int index;
    QMessageBox ErrMsg;

    // Open Customers Table
    CustomersTable = static_cast <QSqlTableModel *> (CustCompleter->model());
    // Add additional customer records to the end of list.
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Image Files (*.csv"));
    File.setFileName(fileName);
    if (File.open(QIODevice::ReadOnly | QIODevice::Text))
    {    while (!File.atEnd())
        {   Name = File.readLine();
            Name.remove('\n');
            if (Name.length())
            {   index = getCustomerId(Name);
                if (index < 0)
                {   Record = CustomersTable->record();
                    Record.setValue("Name", Name);
                    Record.setValue("Active", true);
                    Record.setValue("Factor", 1);
                    Record.setValue("AccountNo", 0);
                    Record.setValue("PriceList", 0);
                    if (!CustomersTable->insertRecord(-1, Record))
                    {
                        ErrMsg.setText(CustomersTable->lastError().text());
                        ErrMsg.exec();
                        return;
                    }
                }

           }
        }
    }
    if (File.error())
    {
        ErrMsg.setText(File.errorString());
        ErrMsg.exec();
    }
    File.close();
    CustomersTable->submitAll();
    CustomersTable->select();
    CustCompleter->setModel(CustomersTable);
    CustCompleter->setCompletionColumn(1);
    CustCompleter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    CustCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    CustCompleter->model()->sort(1, Qt::AscendingOrder);

}


void MainWindow::on_actionTransactionsImport_triggered()
{
    QSqlTableModel *TicketTable, *OperatorTable, *ItemsTable, *CustomersTable;
    QSqlRecord Record;
    QStringList TransAttributes, OperatorList;
    QString Transaction, Description, fileName;
    QFile File;
    int i, index, ItemID, CustomerID, OperatorID, counter ;
    QDateTime timeIn, timeOut;
    QMessageBox Warning;
    QFrame *ProgressDialog;
    Ui::ProgDialog PD;
    float f, RecordCount;


    // Open and read Operator Table into a list
    OperatorTable = new QSqlTableModel(0, db);
    OperatorTable->setTable("Operator");
    OperatorTable->select();
    i=0;
    while (i < OperatorTable->rowCount())
    {   Record = OperatorTable->record(i);
        Description = Record.value("Name").toString();
        OperatorList.append(Description);
        i++;
    }
    i = 0;
    ItemsTable = static_cast <QSqlTableModel *> (ItemCompleter->model());
    CustomersTable = static_cast <QSqlTableModel *> (CustCompleter->model());
    // Open Ticket Table
    TicketTable = new QSqlTableModel(0, db);
    TicketTable->setTable("Ticket");
    TicketTable->select();
   // Add additional customer records to the end of list.
    fileName = QFileDialog::getOpenFileName(this,tr("Open File"), "/home", tr("Image Files (*.csv"));
    File.setFileName(fileName);
    if (File.open(QIODevice::ReadOnly | QIODevice::Text))
    {   //Compute Total Size of transactions.
        RecordCount = File.size()/100; i=0;
        ProgressDialog = new QFrame;
        PD.setupUi(ProgressDialog);
        PD.progressBar->setValue(0);
        ProgressDialog->show();
        while (!File.atEnd())
        {   Transaction = File.readLine();
            Transaction.remove("\n");
            if (Transaction.length()) // line is not empty
            {   TransAttributes = Transaction.split(",");
                Description = TransAttributes.at(1);
                OperatorID = OperatorList.indexOf(TransAttributes.at(7),0); // needs work
                if (OperatorID >= 0)
                {   index = getImportedItemId(Description) ;
                    if (index < 0)
                    {   Warning.setText("Item "+ Description + " is not in the database. Would you like to add it?");
                        Warning.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel );
                        Warning.setDefaultButton(QMessageBox::Cancel);
                        if ( Warning.exec() == QMessageBox::Ok)
                        {   Record = ItemsTable->record();
                            Record.setValue("ShortDesc", Description);
                            Record.setValue("LongDesc", Description);
                            Record.setValue("Sale", true);
                            if (ItemsTable->insertRecord(-1, Record))
                            {   ItemsTable->submitAll();
                                ItemID = ItemsTable->query().lastInsertId().toInt();
                                ItemsTable->select();
                                ItemCompleter->setModel(ItemsTable);
                                ItemCompleter->setCompletionColumn(1);
                                ItemCompleter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
                                ItemCompleter->setCaseSensitivity(Qt::CaseInsensitive);
                                ItemCompleter->model()->sort(1, Qt::AscendingOrder);
                            }
                            else
                            {
                                Warning.setText(ItemsTable->lastError().text());
                                Warning.exec();
                            }
                        }
                        // else abort operation
                    }
                    else ItemID = index;
                    index = getCustomerId(TransAttributes.at(2));
                    if (index < 0)
                    {   Warning.setText("Customer "+ TransAttributes.at(2) + " is not in the database. Would you like to add it?");
                        Warning.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel );
                        Warning.setDefaultButton(QMessageBox::Cancel);
                        if ( Warning.exec() == QMessageBox::Ok)
                        {   Record = CustomersTable->record();
                            Record.setValue("Name", TransAttributes.at(2) );
                            Record.setValue("Active", true);
                            Record.setValue("Factor", 1);
                            Record.setValue("AccountNo", 0);
                            Record.setValue("PriceList", 0);
                            if (CustomersTable->insertRecord(-1, Record))
                            {   CustomersTable->submitAll();
                                CustomerID = CustomersTable->query().lastInsertId().toInt();
                                CustomersTable->select();
                                CustCompleter->setModel(CustomersTable);
                                CustCompleter->setCompletionColumn(1);
                                CustCompleter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
                                CustCompleter->setCaseSensitivity(Qt::CaseInsensitive);
                                CustCompleter->model()->sort(1, Qt::AscendingOrder);
                            }
                            else
                            {
                                Warning.setText(CustomersTable->lastError().text());
                                Warning.exec();
                            }
                        }
                    }
                    else CustomerID = index;
                    Record = TicketTable->record();
                    Record.setValue("ItemID", ItemID);
                    Record.setValue("CustomerID", CustomerID);
                    Record.setValue("OperatorID", OperatorID);
                    Record.setValue("Vehicule", TransAttributes.at(0));
                    Record.setValue("Empty", TransAttributes.at(4).toInt());
                    Record.setValue("Full", TransAttributes.at(3).toInt());
                    Record.setValue("Netweight", TransAttributes.at(3).toInt()-TransAttributes.at(4).toInt());
                    Description = TransAttributes.at(5);
                    timeOut = parse(Description);
                    Record.setValue("TimeOut", timeOut);
                    Description = TransAttributes.at(6);
                    timeIn = parse(Description);
                    Record.setValue("TimeIn", timeIn);
                    Record.setValue("Transporter", TransAttributes.at(8));
                    Record.setValue("Driver", TransAttributes.at(9));
                    counter =  TransAttributes.size() ;
                    if (TransAttributes.size() == 11) Record.setValue("Remark", TransAttributes.at(10));
                    if (!TicketTable->insertRecord(-1,Record))
                    {
                        Warning.setText("Error in inserting imported transaction. Record " + QString::number(i));
                        Warning.exec();
                    }
                    else
                    {   i++;
                        f = ( i/RecordCount) * 100;
                        PD.progressBar->setValue(f);
                        QCoreApplication::processEvents();
                    }
               }
           }
       }
       ProgressDialog->close();
    }
    if (File.error())
    {
        Warning.setText(File.errorString());
        Warning.exec();
    }
    File.close();
    Warning.setText(QString::number(i) +" transactions has been imported successfully.");
    Warning.setStandardButtons(QMessageBox::Ok);
    Warning.exec();

}


void MainWindow::on_actionExit_triggered()
{
    QMessageBox Warning;

// Quitting the application. Show a warning message. If confirmed proceed.

    Warning.setText("Are you sure you want to quit?");
    Warning.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel );
    Warning.setDefaultButton(QMessageBox::Cancel);
    if ( Warning.exec() == QMessageBox::Ok) QApplication::quit();

}

void MainWindow::on_actionServer_triggered()
{
    Ui::ServerDialog PD;
    QDialog *ServerDialog;
    QString ServerRec;
    QFile file("./Server.txt");
    QMessageBox msg;
    QStringList ServerAttributes;

    ServerDialog = new QDialog;
    PD.setupUi(ServerDialog);
    // If a server.txt file already exists, load the data into the server definition dialog
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ServerRec = file.readLine();
        ServerRec.remove("\n");
        if (ServerRec.length()) // line is not empty
        {   ServerAttributes = ServerRec.split(";");
            PD.leHost->setText(ServerAttributes.at(1));
            PD.lePort->setText(ServerAttributes.at(2));
            PD.leDatabase->setText(ServerAttributes.at(0));
            PD.leUserN->setText(ServerAttributes.at(3));
            PD.lePassw->setText(ServerAttributes.at(4));
        }
        file.close();
    }
    ServerRec.clear();
    ServerDialog->show();
    if (ServerDialog->exec() == QDialog::Accepted)
    {   ServerRec.append(PD.leDatabase->text() +";");
        ServerRec.append(PD.leHost->text()+";");
        ServerRec.append(PD.lePort->text()+";");
        ServerRec.append(PD.leUserN->text()+";");
        ServerRec.append(PD.lePassw->text());
        if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
        {   // Parameters are case sensitive
            msg.setText(file.errorString());
            msg.setStandardButtons(QMessageBox::Ok);
            msg.exec();
        }
        else
        {   file.write(ServerRec.toUtf8());
            file.close();
            // Reinitialize database connection
            QString connection;
            connection = db.connectionName();
            db = QSqlDatabase();
            db.removeDatabase(connection);
            db = InitServer();
        }
    }
    else ServerDialog->close();
}


void MainWindow::on_actionBackup_triggered()
{
    QProcess *backup;
    QStringList args, ServerAttributes;
    QString ServerRec, fileName;
    QFile file("./Server.txt");
    QMessageBox msg;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       ServerRec = file.readLine();
       ServerRec.remove("\n");
       if (ServerRec.length()) ServerAttributes = ServerRec.split(";");
    }
    file.close();
    fileName = QFileDialog::getSaveFileName(this,tr("Save File"), "/home", tr("Image Files (*.sql)"));
    file.setFileName(fileName);
    args.append("-u"+ ServerAttributes.at(3));
    args.append("-p"+ ServerAttributes.at(4));
    args.append("-r"+ fileName);
    args.append(ServerAttributes.at(0));
    backup = new QProcess(this);
    backup->start("mysqldump", args);
    backup->waitForFinished();
    QString output(backup->readAllStandardOutput());
    file.close();
    QString err(backup->readAllStandardError());
    if (err.isEmpty())
    {
        msg.setText("Backup was completed successfully.");
        msg.exec();
    }
    else
    {
        msg.setText("Backup was not successfull.\n\n" +err);
        msg.exec();
    }
    backup->close();

}


void MainWindow::on_actionRestore_triggered()
{
    QProcess *restore;
    QStringList args, ServerAttributes;
    QString ServerRec, fileName, Database, ProcessArg;
    QFile file("./Server.txt");
    QMessageBox msg;
    Ui::NoticeDialog DP;
    QDialog *displayForm;


    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       ServerRec = file.readLine();
       ServerRec.remove("\n");
       if (ServerRec.length()) ServerAttributes = ServerRec.split(";");
    }
    file.close();
    if (ServerAttributes.size())
    {
        args.append("-u"+ ServerAttributes.at(3));
        args.append("-p"+ ServerAttributes.at(4));
        // Open the sql backup file
        fileName = QFileDialog::getOpenFileName(this,tr("Open File"), "/home", tr("Image Files (*.sql)"));
        if (!fileName.isEmpty())
        {
            file.setFileName(fileName);
            Database = ServerAttributes.at(0);
            restore = new QProcess(this);
            restore->start("mysql", args);
            ProcessArg = "DROP DATABASE IF EXISTS " + Database + ";\n";
            restore->write(ProcessArg.toUtf8().constData());
            ProcessArg = "CREATE DATABASE " + Database + ";\n";
            restore->write(ProcessArg.toUtf8().constData());
            ProcessArg = "USE " + Database + ";\n";
            restore->write(ProcessArg.toUtf8().constData());
            ProcessArg = "SOURCE "+ fileName + ";\n";
            restore->write(ProcessArg.toUtf8().constData());
            restore->write("quit\n");
            displayForm = new QDialog;
            DP.setupUi(displayForm);
            DP.label->setText("Kindly wait as the database is being restored.");
            displayForm->show();
            restore->waitForFinished();
            displayForm->close();
            QString output(restore->readAllStandardError());
            if (output.isEmpty())
            {
                msg.setText("Database was restored successfully.");
                msg.exec();
                // Reinitialize database connection
                QString connection;
                connection = db.connectionName();
                db = QSqlDatabase();
                db.removeDatabase(connection);
                db = InitServer();
            }
            else
            {   // Display the error
                msg.setText(output);
                msg.exec();
            }
            restore->close();
        }
    }
    else
    {
        msg.setText("Server attributes are not correct or file is corrupted\n"
                    "Please adjust server attributes first.");
        msg.exec();
    }
    
}
