#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Setup/Init.h"
#include "Setup/Customers.h"
#include "Setup/Items.h"
#include "Other/mydelegate.h"
#include "Other/mystringdelegate.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QList>
#include <QMessageBox>

//#include <QTextStream>
//QTextStream cout(stdout);

void MainWindow::PrintTicket(void)
{
    LimeReport::ReportEngine *report;

    report = new LimeReport::ReportEngine(this);
    report->dataManager()->clearUserVariables();
    report->dataManager()->setReportVariable("CurrentTime", QDateTime::currentDateTime().toString());
    report->dataManager()->setReportVariable("CustomerName", CurCustomer->Name);
    report->dataManager()->setReportVariable("Transporter", CurTicket->Transporter);
    report->dataManager()->setReportVariable("Vehicule", CurTicket->Vehicule);
    report->dataManager()->setReportVariable("Driver", CurTicket->Driver);
    report->dataManager()->setReportVariable("Empty", CurTicket->Empty);
    report->dataManager()->setReportVariable("Full", CurTicket->Full);
    report->dataManager()->setReportVariable("Material", CurItem->ShortDesc);
    report->dataManager()->setReportVariable("Weight", CurTicket->Full-CurTicket->Empty);
    report->dataManager()->setReportVariable("TimeIn", CurTicket->TimeIn.toString("ddd MMM dd, yyyy / HH:mm"));
    report->dataManager()->setReportVariable("TimeOut", CurTicket->TimeOut.toString("ddd MMM dd, yyyy / HH:mm"));
    report->dataManager()->setReportVariable("Operator", CurOperator.Name);
    report->loadFromFile(QCoreApplication::applicationDirPath() + "/Reports/weighbill.lrxml");
    report->previewReport();



}

void MainWindow::on_actionDaily_Report_triggered()
{
    ui->tabWidget->addTab(ReportTab[4], "Daily Report");
    ui->tabWidget->setCurrentWidget(ReportTab[4]);
    ui->deDate->setDate(QDate::currentDate());
    ui->tvReport->setModel(NULL);
}  
    
void MainWindow::on_deDate_dateChanged(const QDate &date)
{
    QSqlQueryModel  *Model;
    QSqlQuery Query(db);
    QString Expression;
    QMessageBox Warning;
        
    Expression.append("SELECT OperatorID, Name, ShortDesc, Vehicule, Driver, Transporter, TimeIn, TimeOut, Empty, Full, Netweight, Remark FROM Ticket  ");
    Expression.append("JOIN Item ON Ticket.ItemID = Item.ItemID ");
    Expression.append("JOIN Customer ON Ticket.CustomerID = Customer.CustomerID ");
    Expression.append(" WHERE ( DATE(Ticket.TimeOut) = :Val1)");
    Expression.append(" ORDER BY Name, ShortDesc");
    Query.prepare(Expression);
    Query.bindValue(":Val1", date);
    if (!Query.exec())
    {
        Warning.setText(Query.lastError().text());
        Warning.exec();
    }
    Model = new QSqlQueryModel(0);
    Model->setQuery(Query);
    Model->setHeaderData(2, Qt::Horizontal, "Material", 0);
    Model->setHeaderData(1, Qt::Horizontal, "Customer", 0);
    Model->setHeaderData(10, Qt::Horizontal, "Net", 0);
    if (Model->lastError().isValid())
    {
        Warning.setText(Model->lastError().text());
        Warning.exec();
    }
    ui->tvReport->setModel(Model);
    ui->tvReport->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tvReport->hideColumn(0);
    ui->tvReport->resizeColumnsToContents();
    ui->tvReport->horizontalHeader()->setSectionResizeMode(5,QHeaderView::Stretch);
    ui->tvReport->horizontalHeader()->setSectionResizeMode(6,QHeaderView::Stretch);
    ui->tvReport->setAlternatingRowColors(true);
    ui->tvReport->setStyleSheet("font-size: 11pt;alternate-background-color: lightblue;background-color: lightyellow;");
    ui->tvReport->horizontalHeader()->setStyleSheet("font-size: 11pt;font-weight: bold;background-color: rgb(255,210, 0)");
    ui->tvReport->setItemDelegateForColumn(6, new MyStringDelegate(this) );
    ui->tvReport->setItemDelegateForColumn(7, new MyStringDelegate(this) );
    ui->tvReport->setItemDelegateForColumn(8, new MyDelegate(this) );
    ui->tvReport->setItemDelegateForColumn(9, new MyDelegate(this) );
    ui->tvReport->setItemDelegateForColumn(10, new MyDelegate(this) );
}

void MainWindow::on_pbPrint_clicked()
{
    LimeReport::ReportEngine *report;    
    

    report = new LimeReport::ReportEngine(this);
    report->dataManager()->clearUserVariables();
    report->dataManager()->setReportVariable("ReportDate",  ui->deDate->date());
    report->dataManager()->addModel("dailytickets", ui->tvReport->model(), true);
    report->loadFromFile(QCoreApplication::applicationDirPath() + "/Reports/daily.lrxml");
    report->previewReport();

}


void MainWindow::on_actionSalesDetailed_triggered()
{
    ui->tabWidget->addTab(ReportTab[10], "Sales Report Detailed");
    ui->tabWidget->setCurrentWidget(ReportTab[10]);
    ui->deFromSR->setDate(QDate::currentDate());
    ui->deToSR->setDate(QDate::currentDate());
    ui->tvSalesRep->setModel(NULL);

}


void MainWindow::on_pbQuerySR_clicked()
{
    QSqlQueryModel  *Model;
    QSqlQuery Query(db);
    QString Expression;
    QMessageBox Warning;

    Expression.append("SELECT OperatorID, Name, ShortDesc, Vehicule, Driver, Transporter, TimeIn, TimeOut, Empty, Full, Netweight, Remark FROM Ticket  ");
    Expression.append("JOIN Item ON Ticket.ItemID = Item.ItemID ");
    Expression.append("JOIN Customer ON Ticket.CustomerID = Customer.CustomerID ");
    Expression.append(" WHERE ( DATE(Ticket.TimeOut) BETWEEN  :Val1 AND :Val2) AND (Item.Sale = TRUE)");
    Expression.append(" ORDER BY Name, TimeOut");
    Query.prepare(Expression);
    Query.bindValue(":Val1", ui->deFromSR->date());
    Query.bindValue(":Val2", ui->deToSR->date());
    if (!Query.exec())
    {
        Warning.setText(Query.lastError().text());
        Warning.exec();
    }
    Model = new QSqlQueryModel(0);
    Model->setQuery(Query);
    Model->setHeaderData(2, Qt::Horizontal, "Material", 0);
    Model->setHeaderData(1, Qt::Horizontal, "Customer", 0);
    Model->setHeaderData(10, Qt::Horizontal, "Net", 0);
    if (Model->lastError().isValid())
    {
        Warning.setText(Model->lastError().text());
        Warning.exec();
    }
    ui->tvSalesRep->setModel(Model);
    ui->tvSalesRep->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tvSalesRep->hideColumn(0);
    ui->tvSalesRep->resizeColumnsToContents();
    ui->tvSalesRep->horizontalHeader()->setSectionResizeMode(5,QHeaderView::Stretch);
    ui->tvSalesRep->horizontalHeader()->setSectionResizeMode(6,QHeaderView::Stretch);
    ui->tvSalesRep->setAlternatingRowColors(true);
    ui->tvSalesRep->setStyleSheet("font-size: 11pt;alternate-background-color: lightblue;background-color: lightyellow;");
    ui->tvSalesRep->horizontalHeader()->setStyleSheet("font-size: 11pt;font-weight: bold;background-color: rgb(255,210, 0)");
    ui->tvSalesRep->setItemDelegateForColumn(6, new MyStringDelegate(this) );
    ui->tvSalesRep->setItemDelegateForColumn(7, new MyStringDelegate(this) );
    ui->tvSalesRep->setItemDelegateForColumn(8, new MyDelegate(this) );
    ui->tvSalesRep->setItemDelegateForColumn(9, new MyDelegate(this) );
    ui->tvSalesRep->setItemDelegateForColumn(10, new MyDelegate(this) );
}



void MainWindow::on_pbPrintSR_clicked()
{
    LimeReport::ReportEngine *report;

    report = new LimeReport::ReportEngine(this);
    report->dataManager()->clearUserVariables();
    report->dataManager()->setReportVariable("ReportDate1",  ui->deFromSR->date());
    report->dataManager()->setReportVariable("ReportDate2",  ui->deToSR->date());
    report->dataManager()->addModel("dailytickets", ui->tvSalesRep->model(), true);
    report->loadFromFile(QCoreApplication::applicationDirPath() + "/Reports/sales.lrxml");
    report->previewReport();
}


void MainWindow::on_actionSalesSummary_triggered()
{
    ui->tabWidget->addTab(ReportTab[14], "Sales Report Summary");
    ui->tabWidget->setCurrentWidget(ReportTab[14]);
    ui->deFromSRS->setDate(QDate::currentDate());
    ui->deToSRS->setDate(QDate::currentDate());
    ui->tvSalesRepSum->setModel(NULL);
}


void MainWindow::on_pbQuerySRS_clicked()
{
    QSqlQueryModel  *Model;
    QSqlQuery Query(db);
    QString Expression;
    QMessageBox Warning;

    Expression.append("SELECT Name, ShortDesc,  sum(Netweight) FROM Ticket ");
    Expression.append("JOIN Item ON Ticket.ItemID = Item.ItemID ");
    Expression.append("JOIN Customer ON Ticket.CustomerID = Customer.CustomerID ");
    Expression.append("WHERE ( DATE(TimeOut) between :Val1 and :Val2)  AND (Item.Sale = TRUE)");
    Expression.append(" GROUP by Name, ShortDesc ");
    Query.prepare(Expression);
    Query.bindValue(":Val1", ui->deFromSRS->date());
    Query.bindValue(":Val2", ui->deToSRS->date());
    if (!Query.exec())
    {
        Warning.setText(Query.lastError().text());
        Warning.exec();
    }
    Model = new QSqlQueryModel(0);
    Model->setQuery(Query);
    Model->setHeaderData(0, Qt::Horizontal, "Customer", 0);
    Model->setHeaderData(1, Qt::Horizontal, "Material", 0);
    Model->setHeaderData(2, Qt::Horizontal, "NetWeight", 0);
    if (Model->lastError().isValid())
    {
        Warning.setText(Model->lastError().text());
        Warning.exec();
    }
   ui->tvSalesRepSum->setModel(Model);
   ui->tvSalesRepSum->setEditTriggers(QAbstractItemView::NoEditTriggers);
   ui->tvSalesRepSum->setAlternatingRowColors(true);
   ui->tvSalesRepSum->setStyleSheet("font-size: 11pt;alternate-background-color: lightblue;background-color: lightyellow;");
   ui->tvSalesRepSum->horizontalHeader()->setStyleSheet("font-size: 11pt;font-weight: bold;background-color: rgb(255,210, 0)");
   ui->tvSalesRepSum->setItemDelegateForColumn(2, new MyDelegate(this) );
   for (int c = 0; c < ui->tvSalesRepSum->horizontalHeader()->count(); ++c)
      ui->tvSalesRepSum->horizontalHeader()->setSectionResizeMode( c, QHeaderView::ResizeToContents);
}


void MainWindow::on_pbPrintSRS_clicked()
{
    LimeReport::ReportEngine *report;

    report = new LimeReport::ReportEngine(this);
    report->dataManager()->clearUserVariables();
    report->dataManager()->setReportVariable("ReportDate1",  ui->deFromSRS->date());
    report->dataManager()->setReportVariable("ReportDate2",  ui->deToSRS->date());
    report->dataManager()->addModel("dailytickets", ui->tvSalesRepSum->model(), true);
    report->loadFromFile(QCoreApplication::applicationDirPath() + "/Reports/salessum.lrxml");
    report->previewReport();
}


void MainWindow::on_actionLifting_Report_triggered()
{  // Initialize Tab
    ui->tabWidget->addTab(ReportTab[5], "Customer's Lifting Report");
    ui->tabWidget->setCurrentWidget(ReportTab[5]);
    ui->deFrom->setDate(QDate::currentDate());
    ui->deTo->setDate(QDate::currentDate());
    ui->leCustomerLR->setCompleter(CustCompleter);
    ui->leCustomerLR->clear();
    ui->tvCustLifting->setModel(NULL);

}

void MainWindow::on_pbQuery_clicked()
{
    QSqlQueryModel  *Model;
    QSqlQuery Query(db);
    QString Expression;
    QMessageBox Warning;
    int Index;

    if (!ui->leCustomerLR->text().isEmpty())
    {   Index = getCustomerId(ui->leCustomerLR->text());
        if (Index >=0)
        { // Prepare Query
            Expression.append("SELECT Vehicule, ShortDesc, Driver, Transporter, TimeIn, TimeOut, Empty, Full, Netweight FROM Ticket ");
            Expression.append("JOIN Item ON Ticket.ItemID = Item.ItemID ");
            Expression.append("JOIN Customer ON Ticket.CustomerID = Customer.CustomerID ");
            Expression.append("WHERE ( (Ticket.CustomerID = :Val1 and  ( DATE(TimeOut) between :Val2 and :Val3) )) ");
            Expression.append(" ORDER by ShortDesc, TimeOut");
            Query.prepare(Expression);
            Query.bindValue(":Val1", Index);
            Query.bindValue(":Val2", ui->deFrom->date());
            Query.bindValue(":Val3", ui->deTo->date());
            if (!Query.exec())
            {
                Warning.setText(Query.lastError().text());
                Warning.exec();
            }
            Model = new QSqlQueryModel(0);
            Model->setQuery(Query);
            Model->setHeaderData(1, Qt::Horizontal, "Material", 0);
            Model->setHeaderData(8, Qt::Horizontal, "NetWeight", 0);
            if (Model->lastError().isValid())
            {
                Warning.setText(Model->lastError().text());
                Warning.exec();
            }
           ui->tvCustLifting->setModel(Model);
           ui->tvCustLifting->setEditTriggers(QAbstractItemView::NoEditTriggers);
           ui->tvCustLifting->setAlternatingRowColors(true);
           ui->tvCustLifting->setStyleSheet("font-size: 11pt;alternate-background-color: lightblue;background-color: lightyellow;");
           ui->tvCustLifting->horizontalHeader()->setStyleSheet("font-size: 11pt;font-weight: bold;background-color: rgb(255,210, 0)");
           ui->tvCustLifting->setItemDelegateForColumn(4, new MyStringDelegate(this) );
           ui->tvCustLifting->setItemDelegateForColumn(5, new MyStringDelegate(this) );
           ui->tvCustLifting->setItemDelegateForColumn(6, new MyDelegate(this) );
           ui->tvCustLifting->setItemDelegateForColumn(7, new MyDelegate(this) );
           ui->tvCustLifting->setItemDelegateForColumn(8, new MyDelegate(this) );
           for (int c = 0; c < ui->tvCustLifting->horizontalHeader()->count(); ++c)
              ui->tvCustLifting->horizontalHeader()->setSectionResizeMode( c, QHeaderView::Stretch);
        }
    }
}

void MainWindow::on_pbPrintCL_clicked()
{
    LimeReport::ReportEngine *report;
    int Index;

    if (!ui->leCustomerLR->text().isEmpty())
    {   Index = getCustomerId(ui->leCustomerLR->text());
        report = new LimeReport::ReportEngine(this);
        report->dataManager()->clearUserVariables();
        report->dataManager()->setReportVariable("CustomerID", Index);
        report->dataManager()->setReportVariable("CustomerName", ui->leCustomerLR->text());
        report->dataManager()->setReportVariable("ReportDate1",  ui->deFrom->date());
        report->dataManager()->setReportVariable("ReportDate2",  ui->deTo->date());
        report->dataManager()->addModel("customerlifting", ui->tvCustLifting->model(), true);
        report->loadFromFile(QCoreApplication::applicationDirPath() + "/Reports/CustomerLifting.lrxml");
        report->previewReport();
    }
}

void MainWindow::on_actionLifting_By_Customer_Summary_triggered()
{
    // Initialize Tab
        ui->tabWidget->addTab(ReportTab[9], "Customer's Lifting Summary Report");
        ui->tabWidget->setCurrentWidget(ReportTab[9]);
        ui->deFromCLS->setDate(QDate::currentDate());
        ui->deToCLS->setDate(QDate::currentDate());
        ui->leCustomerCLS->setCompleter(CustCompleter);
        ui->leCustomerCLS->clear();
        ui->tvCustLiftingSum->setModel(NULL);
}

void MainWindow::on_pbQueryCLS_clicked()
{
    QSqlQueryModel  *Model;
    QSqlQuery Query(db);
    QString Expression;
    QMessageBox Warning;
    int Index;

    if (!ui->leCustomerCLS->text().isEmpty())
    {   Index = getCustomerId(ui->leCustomerCLS->text());
        if (Index >=0)
        { // Prepare Query
            Expression.append("SELECT COALESCE(ShortDesc, 'Total'), sum(Netweight) FROM Ticket ");
            Expression.append("JOIN Item ON Ticket.ItemID = Item.ItemID ");
            Expression.append("JOIN Customer ON Ticket.CustomerID = Customer.CustomerID ");
            Expression.append("WHERE ( (Ticket.CustomerID = :Val1 and  ( DATE(TimeOut) between :Val2 and :Val3) )) ");
            Expression.append(" GROUP by ShortDesc WITH ROLLUP");
            Query.prepare(Expression);
            Query.bindValue(":Val1", Index);
            Query.bindValue(":Val2", ui->deFromCLS->date());
            Query.bindValue(":Val3", ui->deToCLS->date());
            if (!Query.exec())
            {
                Warning.setText(Query.lastError().text());
                Warning.exec();
            }
            Model = new QSqlQueryModel(0);
            Model->setQuery(Query);
            Model->setHeaderData(0, Qt::Horizontal, "Material", 0);
            Model->setHeaderData(1, Qt::Horizontal, "NetWeight", 0);
            if (Model->lastError().isValid())
            {
                Warning.setText(Model->lastError().text());
                Warning.exec();
            }
            ui->tvCustLiftingSum->setModel(Model);
            ui->tvCustLiftingSum->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tvCustLiftingSum->setAlternatingRowColors(true);
            ui->tvCustLiftingSum->setStyleSheet("font-size: 11pt;alternate-background-color: lightblue;background-color: lightyellow;");
            ui->tvCustLiftingSum->horizontalHeader()->setStyleSheet("font-size: 11pt;font-weight: bold;background-color: rgb(255,210, 0)");
            ui->tvCustLiftingSum->setItemDelegateForColumn(1, new MyDelegate(this) );
          // for (int c = 0; c < ui->tvCustLiftingSum->horizontalHeader()->count(); ++c)
          //    ui->tvCustLiftingSum->horizontalHeader()->setSectionResizeMode( c, QHeaderView::Stretch);
        }
    }
}


void MainWindow::on_pbPrintCLS_clicked()
{
    LimeReport::ReportEngine *report;
    int Index;

    if (!ui->leCustomerCLS->text().isEmpty())
    {   Index = getCustomerId(ui->leCustomerCLS->text());
        report = new LimeReport::ReportEngine(this);
        report->dataManager()->clearUserVariables();
        report->dataManager()->setReportVariable("CustomerID", Index);
        report->dataManager()->setReportVariable("CustomerName", ui->leCustomerCLS->text());
        report->dataManager()->setReportVariable("ReportDate1",  ui->deFromCLS->date());
        report->dataManager()->setReportVariable("ReportDate2",  ui->deToCLS->date());
        report->dataManager()->addModel("customerlifting", ui->tvCustLiftingSum->model(), true);
        report->loadFromFile(QCoreApplication::applicationDirPath() + "/Reports/CustomerLiftingSum.lrxml");
        report->previewReport();
    }
}


void MainWindow::on_actionLifting_By_Item_triggered()
{
    // Initialize Tab
       ui->tabWidget->addTab(ReportTab[6], "Customer Lifting By Item Report");
       ui->tabWidget->setCurrentWidget(ReportTab[6]);
       ui->deFromCLI->setDate(QDate::currentDate());
       ui->deToCLI->setDate(QDate::currentDate());
       ui->leCustomerCLI->setCompleter(CustCompleter);
       ui->leCustomerCLI->clear();
       ui->leItemCLI->setCompleter(ItemCompleter);
       ui->leItemCLI->clear();
       ui->tvCustLiftingCLI->setModel(NULL);
}

void MainWindow::on_pbQueryCLI_clicked()
{
    QSqlQueryModel  *Model;
    QSqlQuery Query(db);
    QString Expression;
    int Index1, Index2;
    QMessageBox Warning;

    if  ((!ui->leCustomerCLI->text().isEmpty()) && (!ui->leItemCLI->text().isEmpty()))
    {   Index1 = getCustomerId(ui->leCustomerCLI->text());
        Index2 = getItem(ui->leItemCLI->text());
        if ((Index1 >=0) & (Index2 >=0))
        { // Prepare Query
            Expression.append("SELECT Vehicule, Driver, Transporter, TimeIn, TimeOut, Empty, Full, Netweight FROM Ticket ");
            Expression.append("JOIN Item ON Ticket.ItemID = Item.ItemID ");
            Expression.append("JOIN Customer ON Ticket.CustomerID = Customer.CustomerID ");
            Expression.append("WHERE ( (Ticket.CustomerID = :Val1) AND (Ticket.ItemID = :Val4) AND ( DATE(TimeOut) between :Val2 and :Val3)) ");
            Expression.append(" ORDER by TimeOut");
            Query.prepare(Expression);
            Query.bindValue(":Val1", Index1);
            Query.bindValue(":Val2", ui->deFromCLI->date());
            Query.bindValue(":Val3", ui->deToCLI->date());
            Query.bindValue(":Val4", Index2);
            if (!Query.exec())
            {
                Warning.setText(Query.lastError().text());
                Warning.exec();
            }
            Model = new QSqlQueryModel(0);
            Model->setQuery(Query);
            Model->setHeaderData(7, Qt::Horizontal, "NetWeight", 0);
            if (Model->lastError().isValid())
            {
                Warning.setText(Model->lastError().text());
                Warning.exec();
            }
            ui->tvCustLiftingCLI->setModel(Model);
            ui->tvCustLiftingCLI->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tvCustLiftingCLI->setAlternatingRowColors(true);
            ui->tvCustLiftingCLI->setStyleSheet("font-size: 11pt;alternate-background-color: lightblue;background-color: lightyellow;");
            ui->tvCustLiftingCLI->setItemDelegateForColumn(3, new MyStringDelegate(this) );
            ui->tvCustLiftingCLI->setItemDelegateForColumn(4, new MyStringDelegate(this) );
            ui->tvCustLiftingCLI->setItemDelegateForColumn(5, new MyDelegate(this) );
            ui->tvCustLiftingCLI->setItemDelegateForColumn(6, new MyDelegate(this) );
            ui->tvCustLiftingCLI->setItemDelegateForColumn(7, new MyDelegate(this) );
            ui->tvCustLiftingCLI->horizontalHeader()->setStyleSheet("font-size: 11pt;font-weight: bold;background-color: rgb(255,210, 0)");
            for (int c = 0; c < ui->tvCustLiftingCLI->horizontalHeader()->count(); ++c)
              ui->tvCustLiftingCLI->horizontalHeader()->setSectionResizeMode( c, QHeaderView::Stretch);
        }
    }
}

void MainWindow::on_pbPrintCLI_clicked()
{
    LimeReport::ReportEngine *report;
    int Index1, Index2;

    if  ((!ui->leCustomerCLI->text().isEmpty()) && (!ui->leItemCLI->text().isEmpty()))
    {   Index1 = getCustomerId(ui->leCustomerCLI->text());
        Index2 = getItem(ui->leItemCLI->text());
         if ( (Index1 >=0) & (Index2 >=0))
        {   report = new LimeReport::ReportEngine(this);
            report->dataManager()->clearUserVariables();
            report->dataManager()->setReportVariable("ItemID", Index2);
            report->dataManager()->setReportVariable("ItemName", ui->leItemCLI->text());
            report->dataManager()->setReportVariable("CustomerID", Index1);
            report->dataManager()->setReportVariable("CustomerName", ui->leCustomerCLI->text());
            report->dataManager()->setReportVariable("ReportDate1",  ui->deFromCLI->date());
            report->dataManager()->setReportVariable("ReportDate2",  ui->deToCLI->date());
            report->dataManager()->addModel("customerlifting", ui->tvCustLiftingCLI->model(), true);
            report->loadFromFile(QCoreApplication::applicationDirPath() + "/Reports/CustomerLiftingItem.lrxml");
            report->previewReport();
        }
    }
}

void MainWindow::on_actionTrans_By_Date_triggered()
{
    // Initialize Tab
       ui->tabWidget->addTab(ReportTab[7], "Transporter's Lifting By Date");
       ui->tabWidget->setCurrentWidget(ReportTab[7]);
       ui->deFromTBD->setDate(QDate::currentDate());
       ui->deToTBD->setDate(QDate::currentDate());
       ui->leTransporterD->setCompleter(TransporterCompleter);
       ui->leTransporterD->clear();
       ui->tvTransLiftD->setModel(NULL);
}

void MainWindow::on_pbQueryTBD_clicked()
{
    QSqlQueryModel  *Model;
    QSqlQuery Query(db);
    QString Expression;
    QMessageBox Warning;

    if (!ui->leTransporterD->text().isEmpty())
    { // Prepare Query
            Expression.append("SELECT Vehicule, ShortDesc, Driver, TimeIn, TimeOut, Empty, Full, Netweight FROM Ticket ");
            Expression.append("JOIN Item ON Ticket.ItemID = Item.ItemID ");
            Expression.append("JOIN Customer ON Ticket.CustomerID = Customer.CustomerID ");
            Expression.append("WHERE ( (Ticket.Transporter = :Val1 and  ( DATE(TimeOut) between :Val2 and :Val3) )) ");
            Expression.append(" ORDER by TimeOut");
            Query.prepare(Expression);
            Query.bindValue(":Val1", ui->leTransporterD->text());
            Query.bindValue(":Val2", ui->deFromTBD->date());
            Query.bindValue(":Val3", ui->deToTBD->date());
            if (!Query.exec())
            {
                Warning.setText(Query.lastError().text());
                Warning.exec();
            }
            Model = new QSqlQueryModel(0);
            Model->setQuery(Query);
            Model->setHeaderData(1, Qt::Horizontal, "Material", 0);
            Model->setHeaderData(8, Qt::Horizontal, "Net Weight", 0);
            if (Model->lastError().isValid())
            {
                Warning.setText(Model->lastError().text());
                Warning.exec();
            }
            ui->tvTransLiftD->setModel(Model);
            ui->tvTransLiftD->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tvTransLiftD->setAlternatingRowColors(true);
            ui->tvTransLiftD->setStyleSheet("font-size: 11pt;alternate-background-color: lightblue;background-color: lightyellow;");
            ui->tvTransLiftD->horizontalHeader()->setStyleSheet("font-size: 11pt;font-weight: bold;background-color: rgb(255,210, 0)");
            ui->tvTransLiftD->setItemDelegateForColumn(3, new MyStringDelegate(this) );
            ui->tvTransLiftD->setItemDelegateForColumn(4, new MyStringDelegate(this) );
            ui->tvTransLiftD->setItemDelegateForColumn(5, new MyDelegate(this) );
            ui->tvTransLiftD->setItemDelegateForColumn(6, new MyDelegate(this) );
            ui->tvTransLiftD->setItemDelegateForColumn(7, new MyDelegate(this) );
            for (int c = 0; c < ui->tvTransLiftD->horizontalHeader()->count(); ++c)
              ui->tvTransLiftD->horizontalHeader()->setSectionResizeMode( c, QHeaderView::Stretch);
    }
}


void MainWindow::on_pbPrintTBD_clicked()
{
    LimeReport::ReportEngine *report;

    report = new LimeReport::ReportEngine(this);
    report->dataManager()->clearUserVariables();
    report->dataManager()->setReportVariable("Transporter", ui->leTransporterD->text());
    report->dataManager()->setReportVariable("ReportDate1",  ui->deFromTBD->date());
    report->dataManager()->setReportVariable("ReportDate2",  ui->deToTBD->date());
    report->dataManager()->addModel("transporterdetail", ui->tvTransLiftD->model(), true);
    report->loadFromFile(QCoreApplication::applicationDirPath() + "/Reports/TransporterLifting.lrxml");
    report->previewReport();
}


void MainWindow::on_actionTransporter_By_Material_triggered()
{
    // Initialize Tab
       ui->tabWidget->addTab(ReportTab[8], "Transporter's Lifting By Item");
       ui->tabWidget->setCurrentWidget(ReportTab[8]);
       ui->deFromTDI->setDate(QDate::currentDate());
       ui->deToTDI->setDate(QDate::currentDate());
       ui->leTransporterTDI->setCompleter(TransporterCompleter);
       ui->leTransporterTDI->clear();
       ui->leTransporterTDI->setFocus();
       ui->leItemTDI->setCompleter(ItemCompleter);
       ui->leItemTDI->clear();
       ui->tvTransLiftingTDI->setModel(NULL);
}


void MainWindow::on_pbQueryTDI_clicked()
{
    QSqlQueryModel  *Model;
    QSqlQuery Query(db);
    QString Expression;
    QMessageBox Warning;
    int Index1;

    if (!ui->leItemTDI->text().isEmpty())
    {   Index1 = getItem(ui->leItemTDI->text());
        if ((Index1 >=0) & (!ui->leTransporterTDI->text().isEmpty()))
        { // Prepare Query
            Expression.append("SELECT Name, Vehicule, Driver, TimeIn, TimeOut, Empty, Full, Netweight FROM Ticket ");
            Expression.append("JOIN Item ON Ticket.ItemID = Item.ItemID ");
            Expression.append("JOIN Customer ON Ticket.CustomerID = Customer.CustomerID ");
            Expression.append("WHERE ( (Ticket.Transporter = :Val1) AND (Ticket.ItemID = :Val4) AND ( DATE(TimeOut) between :Val2 and :Val3)) ");
            Expression.append(" ORDER by Name, TimeOut");
            Query.prepare(Expression);
            Query.bindValue(":Val1", ui->leTransporterTDI->text());
            Query.bindValue(":Val2", ui->deFromTDI->date());
            Query.bindValue(":Val3", ui->deToTDI->date());
            Query.bindValue(":Val4", Index1);
            if (!Query.exec())
            {
                Warning.setText(Query.lastError().text());
                Warning.exec();
            }
            Model = new QSqlQueryModel(0);
            Model->setQuery(Query);
            Model->setHeaderData(0, Qt::Horizontal, "Customer", 0);
            Model->setHeaderData(7, Qt::Horizontal, "NetWeight", 0);
            if (Model->lastError().isValid())
            {
                Warning.setText(Model->lastError().text());
                Warning.exec();
            }
            ui->tvTransLiftingTDI->setModel(Model);
            ui->tvTransLiftingTDI->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tvTransLiftingTDI->setAlternatingRowColors(true);
            ui->tvTransLiftingTDI->setStyleSheet("font-size: 11pt;alternate-background-color: lightblue;background-color: lightyellow;");
            ui->tvTransLiftingTDI->horizontalHeader()->setStyleSheet("font-size: 11pt;font-weight: bold;background-color: rgb(255,210, 0)");
            ui->tvTransLiftingTDI->setItemDelegateForColumn(3, new MyStringDelegate(this) );
            ui->tvTransLiftingTDI->setItemDelegateForColumn(4, new MyStringDelegate(this) );
            ui->tvTransLiftingTDI->setItemDelegateForColumn(5, new MyDelegate(this) );
            ui->tvTransLiftingTDI->setItemDelegateForColumn(6, new MyDelegate(this) );
            ui->tvTransLiftingTDI->setItemDelegateForColumn(7, new MyDelegate(this) );
            for (int c = 0; c < ui->tvTransLiftingTDI->horizontalHeader()->count(); ++c)
              ui->tvTransLiftingTDI->horizontalHeader()->setSectionResizeMode( c, QHeaderView::Stretch);
        }
    }
}


void MainWindow::on_pbPrintTDI_clicked()
{
    LimeReport::ReportEngine *report;

    report = new LimeReport::ReportEngine(this);
    report->dataManager()->clearUserVariables();
    report->dataManager()->setReportVariable("Transporter", ui->leTransporterTDI->text());
    report->dataManager()->setReportVariable("ReportDate1",  ui->deFromTDI->date());
    report->dataManager()->setReportVariable("ReportDate2",  ui->deToTDI->date());
    report->dataManager()->setReportVariable("Material",  ui->leItemTDI->text());
    report->dataManager()->setReportVariable("MaterialID",  getItem(ui->leItemTDI->text()));
    report->dataManager()->addModel("transporterdetail", ui->tvTransLiftingTDI->model(), true);
    report->loadFromFile(QCoreApplication::applicationDirPath() + "/Reports/TransporterLiftingItem.lrxml");
    report->previewReport();
}



void MainWindow::on_actionItem_By_Date_Detailed_triggered()
{
    // Initialize Tab
       ui->tabWidget->addTab(ReportTab[11], "Lifting By Item Detail");
       ui->tabWidget->setCurrentWidget(ReportTab[11]);
       ui->deFromILD->setDate(QDate::currentDate());
       ui->deToILD->setDate(QDate::currentDate());
       ui->leItemILD->setCompleter(ItemCompleter);
       ui->leItemILD->clear();
       ui->tvItemLiftD->setModel(NULL);
}



void MainWindow::on_pbQueryILD_clicked()
{
    QSqlQueryModel  *Model;
    QSqlQuery Query(db);
    QString Expression;
    QMessageBox Warning;
    int Index1;

    if (!ui->leItemILD->text().isEmpty())
    {   Index1 = getItem(ui->leItemILD->text());
        Expression.append("SELECT  ShortDesc, Name, Vehicule, Driver, TimeIn, TimeOut, Empty, Full, Netweight FROM Ticket ");
        Expression.append("JOIN Item ON Ticket.ItemID = Item.ItemID ");
        Expression.append("JOIN Customer ON Ticket.CustomerID = Customer.CustomerID ");
        Expression.append("WHERE ( (DATE(TimeOut) between :Val1 and :Val2) AND (Ticket.ItemID = :Val3))");
        Expression.append("ORDER by Name, TimeOut");
        Query.prepare(Expression);
        Query.bindValue(":Val1", ui->deFromILD->date());
        Query.bindValue(":Val2", ui->deToILD->date());
        Query.bindValue(":Val3", Index1);
        if (!Query.exec())
        {
            Warning.setText(Query.lastError().text());
            Warning.exec();
        }
        Model = new QSqlQueryModel(0);
        Model->setQuery(Query);
        Model->setHeaderData(0, Qt::Horizontal, "Material", 0);
        Model->setHeaderData(1, Qt::Horizontal, "Customer", 0);
        Model->setHeaderData(8, Qt::Horizontal, "NetWeight", 0);
        if (Model->lastError().isValid())
        {
            Warning.setText(Model->lastError().text());
            Warning.exec();
        }
        ui->tvItemLiftD->setModel(Model);
        ui->tvItemLiftD->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tvItemLiftD->setAlternatingRowColors(true);
        ui->tvItemLiftD->setStyleSheet("font-size: 11pt;alternate-background-color: lightblue;background-color: lightyellow;");
        ui->tvItemLiftD->horizontalHeader()->setStyleSheet("font-size: 11pt;font-weight: bold;background-color: rgb(255,210, 0)");
        ui->tvItemLiftD->setItemDelegateForColumn(4, new MyStringDelegate(this) );
        ui->tvItemLiftD->setItemDelegateForColumn(5, new MyStringDelegate(this) );
        ui->tvItemLiftD->setItemDelegateForColumn(6, new MyDelegate(this) );
        ui->tvItemLiftD->setItemDelegateForColumn(7, new MyDelegate(this) );
        ui->tvItemLiftD->setItemDelegateForColumn(8, new MyDelegate(this) );
        for (int c = 0; c < ui->tvItemLiftD->horizontalHeader()->count(); ++c)
              ui->tvItemLiftD->horizontalHeader()->setSectionResizeMode( c, QHeaderView::Stretch);
    }
}


void MainWindow::on_pbPrintILD_clicked()
{
    LimeReport::ReportEngine *report;

    report = new LimeReport::ReportEngine(this);
    report->dataManager()->clearUserVariables();
    report->dataManager()->setReportVariable("ReportDate1",  ui->deFromILD->date());
    report->dataManager()->setReportVariable("ReportDate2",  ui->deToILD->date());
    report->dataManager()->addModel("Itemdetail", ui->tvItemLiftD->model(), true);
    report->loadFromFile(QCoreApplication::applicationDirPath() + "/Reports/Itemliftingdetail.lrxml");
    report->previewReport();

}


void MainWindow::on_actionItem_By_Date_Summary_triggered()
{
    // Initialize Tab
       ui->tabWidget->addTab(ReportTab[12], "Lifting By Item Summary");
       ui->tabWidget->setCurrentWidget(ReportTab[12]);
       ui->deFromIS->setDate(QDate::currentDate());
       ui->deToIS->setDate(QDate::currentDate());
       ui->tvItemLiftIS->setModel(NULL);
}


void MainWindow::on_pbQueryIS_clicked()
{
    QSqlQueryModel  *Model;
    QSqlQuery Query(db);
    QString Expression;
    QMessageBox Warning;

     // Prepare Query
     Expression.append("SELECT  COALESCE(ShortDesc, 'Total'),  sum(Netweight) FROM Ticket ");
     Expression.append("JOIN Item ON Ticket.ItemID = Item.ItemID ");
     if (ui->rbSales->isChecked()) Expression.append("WHERE ( (DATE(TimeOut) between :Val1 and :Val2)  AND (Item.Sale = :Val3))");
     else Expression.append("WHERE (DATE(TimeOut) between :Val1 and :Val2)  ");
     Expression.append(" GROUP by ShortDesc WITH ROLLUP");
     Query.prepare(Expression);
     Query.bindValue(":Val1", ui->deFromIS->date());
     Query.bindValue(":Val2", ui->deToIS->date());
     Query.bindValue(":Val3",ui->rbSales->isChecked());
     if (!Query.exec())
     {
         Warning.setText(Query.lastError().text());
         Warning.exec();
     }
     Model = new QSqlQueryModel(0);
     Model->setQuery(Query);
     Model->setHeaderData(0, Qt::Horizontal, "Material", 0);
     Model->setHeaderData(1, Qt::Horizontal, "NetWeight", 0);
     if (Model->lastError().isValid())
     {
         Warning.setText(Model->lastError().text());
         Warning.exec();
     }
     ui->tvItemLiftIS->setModel(Model);
     ui->tvItemLiftIS->setEditTriggers(QAbstractItemView::NoEditTriggers);
     ui->tvItemLiftIS->setAlternatingRowColors(true);
     ui->tvItemLiftIS->setStyleSheet("font-size: 11pt;alternate-background-color: lightblue;background-color: lightyellow;");
     ui->tvItemLiftIS->horizontalHeader()->setStyleSheet("font-size: 11pt;font-weight: bold;background-color: rgb(255,210, 0)");
     ui->tvItemLiftIS->setItemDelegateForColumn(1, new MyDelegate(this) );
}




void MainWindow::on_pbPrintIS_clicked()
{

    LimeReport::ReportEngine *report;

    report = new LimeReport::ReportEngine(this);
    report->dataManager()->clearUserVariables();
    report->dataManager()->setReportVariable("ReportDate1",  ui->deFromIS->date());
    report->dataManager()->setReportVariable("ReportDate2",  ui->deToIS->date());
    report->dataManager()->addModel("Itemlifting", ui->tvItemLiftIS->model(), true);
    report->loadFromFile(QCoreApplication::applicationDirPath() + "/Reports/ItemLiftingSum.lrxml");
    report->previewReport();

}



void MainWindow::on_actionReport_Designer_triggered()
{
    QProcess *backup;

    backup = new QProcess(this);
    backup->start(QCoreApplication::applicationDirPath() + "/LRDesigner");

}
