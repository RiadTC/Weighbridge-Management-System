#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Setup/Init.h"
#include "Setup/Operators.h"
#include "Setup/Customers.h"
#include "Other/WeightBill.h"
#include "Other/mydelegate.h"
#include "Other/mystringdelegate.h"
#include "Other/mysearchmodel.h"
#include "Other/miscfunc.h"

#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QFile>
#include <QSqlError>
#include <QDateTime>
#include <QCompleter>
#include <QFileDialog>
#include <QDateTime>
#include <QList>
#include <QSortFilterProxyModel>
#include <QWhatsThis>

#include "ui_noticedialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int i;

    // Initialize Current operator to empty
    CurOperator.id = -1;

    // Initialize Current ticket to empty
    CurTicket = new Ticket;
    CurTicket->id = -1;
    CurTicket->Empty = 0;
    CurTicket->Factor = 1.0;

    // Initialize Current item to empty
    CurItem = new Item;
    CurItem->id = -1;

    // Initialize Current customer to empty
    CurCustomer = new Customer;
    CurCustomer->id = -1;

    // Initialize serial port
    serial = new QSerialPort(this);


    // Initialize user interface
    ui->setupUi(this);
    ui->tabWidget->setEnabled(false);
    ui->menuSetup->setEnabled(false);
    ui->menuFile->setEnabled(true);
    ui->menuImport->setEnabled(false);
    ui->menuReports->setEnabled(false);

    // Initializations for the Weigh tab
    ButtonSet = new QButtonGroup(this);
    ButtonSet->addButton(ui->rb0,1);
    ButtonSet->addButton(ui->rb1,2);
    ButtonSet->addButton(ui->rb2,3);
    ButtonSet->addButton(ui->rb3,4);
    ButtonSet->addButton(ui->rb4,5);
    ButtonSet->addButton(ui->rb5,6);
    ButtonSet->addButton(ui->rb6,7);
    ButtonSet->addButton(ui->rb7,8);
    ButtonSet->addButton(ui->rb8,9);
    ButtonSet->addButton(ui->rb9,10);

    //Initializations for the Search tab
    ui->deStartTime->setDisplayFormat("dd.MM.yyyy HH:mm");
    ui->deStartTime->setDate(QDate::currentDate());
    ui->deStartTime->setTime(QTime::fromString(QString("00:00")));
    ui->deEndTime->setDisplayFormat("dd.MM.yyyy HH:mm");
    ui->deEndTime->setDate(QDate::currentDate());
    ui->deEndTime->setTime(QTime::fromString(QString("23:59")));

    // Hide Reports Tabs
    ui->tabWidget->tabBar()->tabButton(0, QTabBar::RightSide)->resize(0, 0);
    ui->tabWidget->tabBar()->tabButton(1, QTabBar::RightSide)->resize(0, 0);
    for (i=0; i<15; i++) ReportTab[i] = ui->tabWidget->widget(i+2);
    for (i=0; i<15; i++) ui->tabWidget->removeTab(2);

    //ui->gbButtons->setStyleSheet("::title {color:black; font-size: bold}, background-color: rgb(170,170, 127)");

    ui->cbOther->setInsertPolicy(QComboBox::InsertAlphabetically);

    createStatusBar();
    startTimer(1000) ;

    ui->tabWidget->setCurrentIndex(0); // Always show first tab

}

MainWindow::~MainWindow()
{
    delete serial;
    delete ui;
}

void MainWindow::createStatusBar()
{

    DateLabel = new QLabel;
    DateLabel->setAlignment(Qt::AlignRight);
    DateLabel->setStyleSheet("font-size: 11pt;font-weight: bold; color : black; background-color: rgb(170,170, 127)");
    statusBar()->addPermanentWidget(DateLabel);

}


void MainWindow::timerEvent(QTimerEvent * event)
{
    DateLabel->setText(QDateTime::currentDateTime().toString("  dddd MMM dd, yyyy hh:mm  "));
   // statusBar()->showMessage(QDateTime::currentDateTime().toString("MMM dd, yyyy hh:mm:ss"),0);
}


void MainWindow::ResetButtons ()
{
    if (ButtonSet->checkedButton())
    {   ButtonSet->setExclusive(false);
        ButtonSet->checkedButton()->setChecked(false);
        ButtonSet->setExclusive(true);
        ResetButtonsBackground();
        ui->gbButtons->repaint();
    }
}

void MainWindow::ResetButtonsBackground ()
{
    ui->rb0->setStyleSheet( "color: black; background-color: rgb(170, 170, 127);");
    ui->rb1->setStyleSheet( "color: black; background-color: rgb(170, 170, 127);");
    ui->rb2->setStyleSheet( "color: black; background-color: rgb(170, 170, 127);");
    ui->rb3->setStyleSheet( "color: black; background-color: rgb(170, 170, 127);");
    ui->rb4->setStyleSheet( "color: black; background-color: rgb(170, 170, 127);");
    ui->rb5->setStyleSheet( "color: black; background-color: rgb(170, 170, 127);");
    ui->rb6->setStyleSheet( "color: black; background-color: rgb(170, 170, 127);");
    ui->rb7->setStyleSheet( "color: black; background-color: rgb(170, 170, 127);");
    ui->rb8->setStyleSheet( "color: black; background-color: rgb(170, 170, 127);");
    ui->rb9->setStyleSheet( "color: black; background-color: rgb(170, 170, 127);");
    ui->cbOther->setStyleSheet( "color: black; background-color: rgb(170, 170, 127);");
}

void MainWindow::SetButton(int i, QString Label)
{
    switch (i-1)
    {
        case 0: ui->rb0->show(); ui->rb0->setText(Label); break;
        case 1: ui->rb1->show(); ui->rb1->setText(Label); break;
        case 2: ui->rb2->show(); ui->rb2->setText(Label); break;
        case 3: ui->rb3->show(); ui->rb3->setText(Label); break;
        case 4: ui->rb4->show(); ui->rb4->setText(Label); break;
        case 5: ui->rb5->show(); ui->rb5->setText(Label); break;
        case 6: ui->rb6->show(); ui->rb6->setText(Label); break;
        case 7: ui->rb7->show(); ui->rb7->setText(Label); break;
        case 8: ui->rb8->show(); ui->rb8->setText(Label); break;
        case 9: ui->rb9->show(); ui->cbOther->show(); ui->cbOther->addItem(Label); break;
    }
    if (i > 9) ui->cbOther->addItem(Label);
}


void MainWindow::readData()
{
    QByteArray data;
    char *s1;
    float w;
    int i;
    static int Count = 0;
    static QString s2;

    data = serial->readAll();
    s1 = data.data();
    if ((Count) && (*s1 != Delimiter.at(0)))
    {   s2[StreamLen-Count] = QChar(*s1);
        Count ++;
        if (Count > StreamLen)
        {
            Count = 0;
            w = s2.toDouble();
            w = (w - CurTicket->Empty) * CurTicket->Factor;
            i = w;
            i = (i/10)*10;
            ui->lcdNumber->display(i);
        }
    }
    if  (*s1 == Delimiter.at(0)) { Count=1; s2.clear(); }
 }



void MainWindow::ClearScreen()
{
    CurTicket->Factor= 1;
    CurTicket->Empty = 0;
    ui->leDriver->clear();
    ui->leCustomer->clear();
    ui->leTransporter->clear();
    ui->leVehicule->clear();
    ui->leVehicule->setFocus();
    ui->leRemark->clear();
    ResetButtons();
}


void MainWindow::on_leVehicule_returnPressed()
{
    QMessageBox msgBox;
    int Index;

    if (!ui->leVehicule->text().isEmpty())
    {   ui->leVehicule->setText(ui->leVehicule->text().toUpper());
        Index = VehiculeList->indexOf(ui->leVehicule->text(),0) ;
        if (Index < 0)
        {   msgBox.setText("The entered vehicule number is not in the database.");
            msgBox.setInformativeText("Do you want to save it?");
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
            msgBox.setDefaultButton(QMessageBox::Discard);
            msgBox.setModal(true);
            ui->leVehicule->blockSignals(true);
            if (msgBox.exec() == QMessageBox::Save)
            {   VehiculeList->append(ui->leVehicule->text());
                delete VehiculeCompleter;
                VehiculeCompleter = new QCompleter(*VehiculeList);
                VehiculeCompleter->setCompletionMode(QCompleter::PopupCompletion);
                VehiculeCompleter->setCaseSensitivity(Qt::CaseInsensitive);
                ui->leVehicule->setCompleter(VehiculeCompleter);
                ui->leVehicule1->setCompleter(VehiculeCompleter);
            }
            else { ui->leVehicule->clear();  ui->leVehicule->setFocus();}
            ui->leVehicule->blockSignals(false);
        }
    }
}

void MainWindow::on_leCustomer_returnPressed()
{
    QMessageBox msgBox;

    if (!ui->leCustomer->text().isEmpty())
    {
        if (getCustomerId(ui->leCustomer->text()) < 0)
        {
            msgBox.setText("This customer is not in the database.\n\nUse Setup->Customers to add it.");
            msgBox.setStandardButtons(QMessageBox::Close);
            msgBox.setModal(true);
            msgBox.exec();
            ui->leCustomer->blockSignals(true);
            ui->leCustomer->clear();
            ui->leCustomer->setFocus();
            ui->leCustomer->blockSignals(false);
        }
    }
}

void MainWindow::on_leTransporter_returnPressed()
{
    QMessageBox msgBox;
    int Index;

    if (!ui->leTransporter->text().isEmpty())
    {   Index = TransporterList->indexOf(ui->leTransporter->text(),0) ;
        if (Index < 0)
        {   msgBox.setText("The entered transporter name is not in the database.");
            msgBox.setInformativeText("Do you want to save it?");
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
            msgBox.setDefaultButton(QMessageBox::Discard);
            msgBox.setModal(true);
            Index = msgBox.exec();
            ui->leTransporter->blockSignals(true);
            if (Index == QMessageBox::Save)
            {   TransporterList->append(ui->leTransporter->text());
                delete TransporterCompleter;
                TransporterCompleter = new QCompleter(*TransporterList);
                TransporterCompleter->setCompletionMode(QCompleter::PopupCompletion);
                TransporterCompleter->setCaseSensitivity(Qt::CaseInsensitive);
                ui->leTransporter->setCompleter(TransporterCompleter);
                ui->leTransporter1->setCompleter(TransporterCompleter);
            }
            else { ui->leTransporter->clear(); ui->leTransporter->setFocus();}
            ui->leTransporter->blockSignals(false);
         }
    }

}


void MainWindow::on_leDriver_returnPressed()
{
    QMessageBox msgBox;
    int Index;

    if (!ui->leDriver->text().isEmpty())
    {   Index = DriverList->indexOf(ui->leDriver->text(),0) ;
        if (Index < 0)
        {   msgBox.setText("The entered driver name is not in the database.");
            msgBox.setInformativeText("Do you want to save it?");
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
            msgBox.setDefaultButton(QMessageBox::Discard);
            msgBox.setModal(true);
            Index = msgBox.exec();
            ui->leDriver->blockSignals(true);
            if (Index == QMessageBox::Save)
            {   DriverList->append(ui->leDriver->text());
                delete DriverCompleter;
                DriverCompleter = new QCompleter(*DriverList);
                DriverCompleter->setCompletionMode(QCompleter::PopupCompletion);
                DriverCompleter->setCaseSensitivity(Qt::CaseInsensitive);
                ui->leDriver->setCompleter(DriverCompleter);
                ui->leDriver1->setCompleter(DriverCompleter);
            }
            else { ui->leDriver->clear(); ui->leDriver->setFocus();}
            ui->leDriver->blockSignals(false);
         }     
     }

}


void MainWindow::on_rb0_clicked()
{
    QString ItemDesc;

    ResetButtons();
    ui->rb0->setChecked(true);
    ui->rb0->setStyleSheet("background-color: rgb(255,210, 0)");
/*    ItemDesc = ui->rb0->text();
    ItemDesc.remove('&');
    getItem(ItemDesc);*/
    CurItem->id = ItemCompleter->model()->index(0,0).data().toInt();
    CurItem->ShortDesc = ItemCompleter->model()->index(0,1).data().toString();
    CurItem->LongDesc = ItemCompleter->model()->index(0,2).data().toString();
}

void MainWindow::on_rb1_clicked()
{
    ResetButtons();
    ui->rb1->setChecked(true);
    ui->rb1->setStyleSheet("background-color: rgb(255,210, 0)");
    CurItem->id = ItemCompleter->model()->index(1,0).data().toInt();
    CurItem->ShortDesc = ItemCompleter->model()->index(1,1).data().toString();
    CurItem->LongDesc = ItemCompleter->model()->index(1,2).data().toString();
}

void MainWindow::on_rb2_clicked()
{
    ResetButtons();
    ui->rb2->setChecked(true);
    ui->rb2->setStyleSheet("background-color: rgb(255,210, 0)");
    CurItem->id = ItemCompleter->model()->index(2,0).data().toInt();
    CurItem->ShortDesc = ItemCompleter->model()->index(2,1).data().toString();
    CurItem->LongDesc = ItemCompleter->model()->index(2,2).data().toString();
}

void MainWindow::on_rb3_clicked()
{
    ResetButtons();
    ui->rb3->setChecked(true);
    ui->rb3->setStyleSheet("background-color: rgb(255,210, 0)");
    CurItem->id = ItemCompleter->model()->index(3,0).data().toInt();
    CurItem->ShortDesc = ItemCompleter->model()->index(3,1).data().toString();
    CurItem->LongDesc = ItemCompleter->model()->index(3,2).data().toString();
}

void MainWindow::on_rb4_clicked()
{
    ResetButtons();
    ui->rb4->setChecked(true);
    ui->rb4->setStyleSheet("background-color: rgb(255,210, 0)");
    CurItem->id = ItemCompleter->model()->index(4,0).data().toInt();
    CurItem->ShortDesc = ItemCompleter->model()->index(4,1).data().toString();
    CurItem->LongDesc = ItemCompleter->model()->index(4,2).data().toString();
}

void MainWindow::on_rb5_clicked()
{
    ResetButtons();
    ui->rb5->setChecked(true);
    ui->rb5->setStyleSheet("background-color: rgb(255,210, 0)");
    CurItem->id = ItemCompleter->model()->index(5,0).data().toInt();
    CurItem->ShortDesc = ItemCompleter->model()->index(5,1).data().toString();
    CurItem->LongDesc = ItemCompleter->model()->index(5,2).data().toString();
}

void MainWindow::on_rb6_clicked()
{
    ResetButtons();
    ui->rb6->setChecked(true);
    ui->rb6->setStyleSheet("background-color: rgb(255,210, 0)");
    CurItem->id = ItemCompleter->model()->index(6,0).data().toInt();
    CurItem->ShortDesc = ItemCompleter->model()->index(6,1).data().toString();
    CurItem->LongDesc = ItemCompleter->model()->index(6,2).data().toString();
}

void MainWindow::on_rb7_clicked()
{
    ResetButtons();
    ui->rb7->setChecked(true);
    ui->rb7->setStyleSheet("background-color: rgb(255,210, 0)");
    CurItem->id = ItemCompleter->model()->index(7,0).data().toInt();
    CurItem->ShortDesc = ItemCompleter->model()->index(7,1).data().toString();
    CurItem->LongDesc = ItemCompleter->model()->index(7,2).data().toString();
}

void MainWindow::on_rb8_clicked()
{
    ResetButtons();
    ui->rb8->setChecked(true);
    ui->rb8->setStyleSheet("background-color: rgb(255,210, 0)");
    CurItem->id = ItemCompleter->model()->index(8,0).data().toInt();
    CurItem->ShortDesc = ItemCompleter->model()->index(8,1).data().toString();
    CurItem->LongDesc = ItemCompleter->model()->index(8,2).data().toString();
}

void MainWindow::on_rb9_clicked()
{
    int rowcount, index = 0;

    if (!ui->cbOther->currentText().isEmpty())  ResetButtons();
    else
    {   rowcount = ItemCompleter->model()->rowCount();
        while ((ItemCompleter->model()->index(index,1).data().toString() != ui->cbOther->currentText()) && (index < rowcount)) index++;
        if (index < rowcount)
        {   CurItem->id = ItemCompleter->model()->index(index,0).data().toInt();
            CurItem->ShortDesc = ItemCompleter->model()->index(index,1).data().toString();
            CurItem->LongDesc = ItemCompleter->model()->index(index,2).data().toString();
            ResetButtons();
            ui->rb9->setStyleSheet("background-color: rgb(255,210, 0)");
            ui->rb9->setChecked(true);
            ui->cbOther->setStyleSheet("background-color: rgb(255,210, 0)");
        }
    }
}

void MainWindow::on_cbOther_currentTextChanged(const QString &arg1)
{
    int rowcount, index = 0;

    rowcount = ItemCompleter->model()->rowCount();
    while ((ItemCompleter->model()->index(index,1).data().toString() != ui->cbOther->currentText()) && (index < rowcount)) index++;
    if (index < rowcount)
    {   CurItem->id = ItemCompleter->model()->index(index,0).data().toInt();
        CurItem->ShortDesc = ItemCompleter->model()->index(index,1).data().toString();
        CurItem->LongDesc = ItemCompleter->model()->index(index,2).data().toString();
        ResetButtons();
        ui->rb9->setStyleSheet( "background-color: rgb(255,210, 0)");
        ui->rb9->setChecked(true);
        ui->cbOther->setStyleSheet( "background-color: rgb(255,210, 0)");
    }
}

void MainWindow::on_pbWeigh_clicked()
{
    QMessageBox msgBox;
    int MinWeigh = 100, Weight;
    QSqlTableModel *Table1, *Table2;
    QSqlQuery Query(db);

    if (!ui->leVehicule->text().isEmpty()) // Vehicule must not be empty
      if (!ui->leCustomer->text().isEmpty())  // Customer must not be empty
          if (!ui->leDriver->text().isEmpty())    // Driver must not be empty
              if (CurItem->id > -1)  // Item must be checked
                 if (qAbs(ui->lcdNumber->intValue()) > MinWeigh)   // Measured weight must be higher than minimun value
                    {   // Save the record
                        Table1 = new QSqlTableModel(0, db);
                        Table1->setTable("InProcess");
                        Table1->select();
                        Table2 = new QSqlTableModel(0, db);
                        Table2->setTable("Ticket");
                        Table2->select();
                        if (CurTicket->Empty == 0)  // First Weigh
                        {   CurTicket->Vehicule = ui->leVehicule->text();
                            CurTicket->CustomerID = CurCustomer->id;
                            CurTicket->Driver = ui->leDriver->text();
                            CurTicket->Transporter = ui->leTransporter->text();
                            CurTicket->ItemID = CurItem->id;
                            CurTicket->Empty = ui->lcdNumber->intValue();
                            CurTicket->OperatorID = CurOperator.id;
                            CurTicket->TimeIn = QDateTime::currentDateTime();
                            CurTicket->Remark = ui->leRemark->text();
                            // Save record in InProcess Table
                            if (!InsertRecord(Table1, CurTicket, CurItem->ShortDesc, CurCustomer->Name,0))
                            {
                                msgBox.setText(Table1->lastError().text());
                                msgBox.exec();
                            }
                            else
                            {   //move record to unfinished list
                                Table1->select();
                                ui->tvTicket->setModel(Table1);
                                for (int c = 0; c < ui->tvTicket->horizontalHeader()->count(); ++c)
                                   {
                                       ui->tvTicket->horizontalHeader()->setSectionResizeMode( c, QHeaderView::Stretch);
                                   }
                                // clear the screen
                                ClearScreen();
                            }
                        }
                        else
                        {   Weight = ui->lcdNumber->intValue();
                            CurTicket->Full = Weight+CurTicket->Empty;
                            if (CurTicket->Full < CurTicket->Empty)
                            {   Weight = CurTicket->Full;
                                CurTicket->Full = CurTicket->Empty;
                                CurTicket->Empty = Weight;
                            }
                            CurTicket->TimeOut = QDateTime::currentDateTime();
                            CurTicket->Vehicule = ui->leVehicule->text();
                            CurTicket->CustomerID = CurCustomer->id;
                            CurTicket->Driver = ui->leDriver->text();
                            CurTicket->Transporter = ui->leTransporter->text();
                            CurTicket->ItemID = CurItem->id;
                            CurTicket->OperatorID = CurOperator.id;
                            CurTicket->Remark = ui->leRemark->text();
                            // save record in Ticket Table and delete from InProcess
                            if (!InsertRecord(Table2, CurTicket, CurItem->ShortDesc, CurCustomer->Name, 1))
                            {
                                msgBox.setText(Table2->lastError().text());
                                msgBox.exec();
                            }
                            else
                            {   //UpdateTransationBalance(CurTicket, db);
                                Query.prepare("DELETE FROM InProcess WHERE TimeIn = ? ");
                                Query.addBindValue(CurTicket->TimeIn);
                                if (!Query.exec())
                                {
                                    msgBox.setText(Query.lastError().text());
                                    msgBox.exec();
                                }
                                Table1->select();
                                ui->tvTicket->setModel(Table1);
                                for (int c = 0; c < ui->tvTicket->horizontalHeader()->count(); ++c)
                                   {
                                       ui->tvTicket->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
                                   }
                                msgBox.setText("Do you want to print the ticket?");
                                msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Discard);
                                msgBox.setDefaultButton(QMessageBox::Discard);
                                msgBox.setModal(true);
                                if (msgBox.exec() == QMessageBox::Ok) PrintTicket();
                               ClearScreen();
                            }
                        }
                    }
                 else
                 {  msgBox.setText("Weight is too low");
                    msgBox.setDefaultButton(QMessageBox::Discard);
                    msgBox.setModal(true);
                    msgBox.exec();
                 }
              else
                {   msgBox.setText("Item must not be empty.");
                    msgBox.setDefaultButton(QMessageBox::Discard);
                    msgBox.setModal(true);
                    msgBox.exec();
                 }
            else
              {  msgBox.setText("Driver name must not be empty.");
                 msgBox.setDefaultButton(QMessageBox::Discard);
                 msgBox.setModal(true);
                 msgBox.exec();
                 ui->leDriver->setFocus();
              }
       else
        {   msgBox.setText("Customer name must not be empty.");
            msgBox.setDefaultButton(QMessageBox::Discard);
            msgBox.setModal(true);
            msgBox.exec();
            ui->leCustomer->setFocus();
        }
    else
    {   msgBox.setText("Vehicule number must not be empty.");
        msgBox.setDefaultButton(QMessageBox::Discard);
        msgBox.setModal(true);
        msgBox.exec();
        ui->leVehicule->setFocus();
    }
}



void MainWindow::on_tvTicket_doubleClicked(const QModelIndex &index)
{
    int row, Position;

    row = index.row();
    // Fill selected ticket values into CurTicket
    CurTicket->OperatorID = CurOperator.id;
    CurTicket->CustomerID = getCustomerId(ui->tvTicket->model()->index(row,1).data().toString());
    CurTicket->ItemID = getItemId(ui->tvTicket->model()->index(row,2).data().toString(), &Position);
    CurTicket->Vehicule = ui->tvTicket->model()->index(row,3).data().toString();
    CurTicket->Driver = ui->tvTicket->model()->index(row,4).data().toString();
    CurTicket->Transporter = ui->tvTicket->model()->index(row,5).data().toString();
    CurTicket->TimeIn = ui->tvTicket->model()->index(row,6).data().toDateTime();
    CurTicket->Empty = ui->tvTicket->model()->index(row,7).data().toInt();
    CurTicket->Remark = ui->tvTicket->model()->index(row,8).data().toString();
    CurTicket->Factor = CurCustomer->Factor;
    ResetButtonsBackground();
    ui->leVehicule->setText(CurTicket->Vehicule);
    ui->leCustomer->setText(CurCustomer->Name);
    ui->leDriver->setText(CurTicket->Driver);
    ui->leTransporter->setText(CurTicket->Transporter);
    ui->leRemark->setText(CurTicket->Remark);
    if (Position >= 9)
    {   ui->cbOther->setCurrentIndex(ui->cbOther->findText(CurItem->ShortDesc));
        ui->rb9->setChecked(true);
        ui->cbOther->setStyleSheet("background-color: rgb(255,210, 0)");
    }
    else
    {  ButtonSet->button(Position+1)->setChecked(true);
       ButtonSet->button(Position+1)->setStyleSheet("background-color: rgb(255,210, 0)");
    }
}


void MainWindow::on_pbSearch_clicked()
{
    QSqlQueryModel *Model;
    QSortFilterProxyModel *proxyModel;
    QSqlQuery Query(db);
    QString Expression;
    int index, Position;
    QMessageBox Warning;


    Expression.append("SELECT TicketID, OperatorID, Name, ShortDesc, Vehicule, Driver, Transporter, TimeIn, TimeOut, Empty, Full, Netweight, Remark FROM Ticket  ");
    Expression.append("JOIN Item ON Ticket.ItemID = Item.ItemID ");
    Expression.append("JOIN Customer ON Ticket.CustomerID = Customer.CustomerID ");
    Expression.append(" WHERE ( ");
    if (!ui->leCustomer1->text().isEmpty()) Expression.append("(Ticket.CustomerID =:Val3 ) AND ");
    if (!ui->leVehicule1->text().isEmpty())  Expression.append(" ( Ticket.Vehicule = :Val4 ) AND ");
    if (!ui->leMaterial->text().isEmpty())  Expression.append(" ( Ticket.ItemID = :Val5 ) AND ");
    if (!ui->leDriver1->text().isEmpty())  Expression.append(" ( Ticket.Driver = :Val6 ) AND ");
    if (!ui->leTransporter1->text().isEmpty())  Expression.append(" ( Ticket.Transporter = :Val7 ) AND ");
    Expression.append("  (Ticket.TimeOut BETWEEN :Val1 AND :Val2));");
    Query.prepare(Expression);
    Query.bindValue(":Val1", ui->deStartTime->dateTime());
    Query.bindValue(":Val2", ui->deEndTime->dateTime());
    if (!ui->leCustomer1->text().isEmpty())
    {   index = getCustomerId(ui->leCustomer1->text());
        Query.bindValue(":Val3", index);
    }
    if (!ui->leVehicule1->text().isEmpty()) Query.bindValue(":Val4", ui->leVehicule1->text());
    if (!ui->leMaterial->text().isEmpty())
    {   index = getItemId(ui->leMaterial->text(), &Position);
        Query.bindValue(":Val5", index);
    }
    if (!ui->leDriver1->text().isEmpty()) Query.bindValue(":Val6", ui->leDriver1->text());
    if (!ui->leTransporter1->text().isEmpty()) Query.bindValue(":Val7", ui->leTransporter1->text());
    if (!Query.exec())
    {
        Warning.setText(Query.lastError().text());
        Warning.exec();
    }
    Model = new QSqlQueryModel(0);
    Model->setQuery(Query);
    Model->setHeaderData(3, Qt::Horizontal, "Material", 0);
    Model->setHeaderData(2, Qt::Horizontal, "Customer", 0);
    Model->setHeaderData(11, Qt::Horizontal, "Net Weight", 0);
    if (Model->lastError().isValid())
    {
        Warning.setText(Model->lastError().text());
        Warning.exec();
    }
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(Model );
    ui->tvResult->setModel(proxyModel);
    ui->tvResult->setAlternatingRowColors("alternate-background-color: lightyellow;background-color: lightblue;");
    ui->tvResult->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tvResult->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tvResult->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tvResult->hideColumn(0);
    ui->tvResult->hideColumn(1);
    ui->tvResult->resizeColumnsToContents();
    ui->tvResult->horizontalHeader()->setSectionResizeMode(5,QHeaderView::Stretch);
    ui->tvResult->horizontalHeader()->setSectionResizeMode(6,QHeaderView::Stretch);
    ui->tvResult->horizontalHeader()->setStyleSheet("font-size: 11pt;font-weight: bold;color: black;background-color: rgb(170,170,127)");

    ui->tvResult->setItemDelegateForColumn(7, new MyStringDelegate(this) );
    ui->tvResult->setItemDelegateForColumn(8, new MyStringDelegate(this) );
    ui->tvResult->setItemDelegateForColumn(9, new MyDelegate(this) );
    ui->tvResult->setItemDelegateForColumn(10, new MyDelegate(this) );
    ui->tvResult->setItemDelegateForColumn(11, new MyDelegate(this) );
   //Add Total Line
    int result = 0;
        const int column = 11;
        for (int row = 0; row < Model->rowCount(); ++row) {
            result += Model->data(Model->index(row, column)).toInt();
        }
    // show sum in label
    ui->lresult->setText("Total Weight  " + QString::number(result)+ " Kg");

}

void MainWindow::on_pbExport_clicked()
{
    // [Collect model data to QString]
    QString textData, fileName ;
    int rows, columns, i;
    QFile File;

    rows = ui->tvResult->model()->rowCount();
    columns = ui->tvResult->model()->columnCount();
    for (i=2; i< columns; i++)
    {  textData += ui->tvResult->model()->headerData(i,Qt::Horizontal).toString();
       textData += ", ";
    }
    textData += "\n";
    for ( i = 0; i < rows; i++)
    {  // scan columns
        for (int j = 2; j < columns; j++)
        {   textData += ui->tvResult->model()->data(ui->tvResult->model()->index(i,j)).toString();
             textData += "," ;     // for .csv file format
        }
        textData += "\n";             // (optional: for new line segmentation)
    }
    // [Save to file] (header file <QFile> needed)
    // .csv
    fileName = QFileDialog::getSaveFileName(this, tr("Open File"), "/home", tr("Image Files (*.csv"));
    File.setFileName(fileName + ".csv");
    if (File.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {  QTextStream out(&File);
        out << textData;
        File.close();
    }
}

void MainWindow::on_pbClearTransaction_clicked()
{
    ClearScreen();
    CurTicket->Empty = 0;
    CurTicket->Factor = 1;
}

void MainWindow::on_tvResult_doubleClicked(const QModelIndex &index)
{
    WeightBill *w;
    int row, Position;

    row = index.row();
    CurTicket->id = ui->tvResult->model()->data(ui->tvResult->model()->index(row,0)).toInt();
    CurTicket->OperatorID = ui->tvResult->model()->data(ui->tvResult->model()->index(row,1)).toInt();
    CurTicket->CustomerID = getCustomerId(ui->tvResult->model()->data(ui->tvResult->model()->index(row,2)).toString());
    CurTicket->ItemID = getItemId(ui->tvResult->model()->data(ui->tvResult->model()->index(row,3)).toString(), &Position);
    CurTicket->Vehicule = ui->tvResult->model()->data(ui->tvResult->model()->index(row,4)).toString();
    CurTicket->Driver = ui->tvResult->model()->data(ui->tvResult->model()->index(row,5)).toString();
    CurTicket->Transporter = ui->tvResult->model()->data(ui->tvResult->model()->index(row,6)).toString();
    CurTicket->TimeIn = ui->tvResult->model()->data(ui->tvResult->model()->index(row,7)).toDateTime();
    CurTicket->TimeOut = ui->tvResult->model()->data(ui->tvResult->model()->index(row,8)).toDateTime();
    CurTicket->Empty = ui->tvResult->model()->data(ui->tvResult->model()->index(row,9)).toInt();
    CurTicket->Full = ui->tvResult->model()->data(ui->tvResult->model()->index(row,10)).toInt();
    w = new WeightBill (db, ui->tvResult->model()->data(ui->tvResult->model()->index(row,2)).toString(),
                        ui->tvResult->model()->data(ui->tvResult->model()->index(row,3)).toString(),
                        CurTicket->Transporter, CurTicket->Vehicule, CurTicket, CustCompleter, ItemCompleter,
                        TransporterCompleter, VehiculeCompleter,this);
    w->show();
    CurTicket->Empty = 0;
}

void MainWindow::on_pbClear_clicked()
{
    QSqlQueryModel *Model;

    Model = new QSqlQueryModel(0);
    ui->tvResult->setModel(Model);
    ui->leCustomer1->clear();
    ui->leMaterial->clear();
    ui->leDriver1->clear();
    ui->leTransporter1->clear();
    ui->leVehicule1->clear();
    ui->deStartTime->setDate(QDate::currentDate());
    ui->deStartTime->setTime(QTime::fromString(QString("00:00")));
    ui->deEndTime->setDate(QDate::currentDate());
    ui->deEndTime->setTime(QTime::fromString(QString("23:59")));
    ui->lresult->clear();
}

void MainWindow::on_pbPrintTicket_clicked()
{
    QModelIndexList indexlist;
    int row, Position;

    if (ui->tvResult->model() != NULL)
    {   indexlist = ui->tvResult->selectionModel()->selectedIndexes();
        if (indexlist.count() > 0)
        {   row = indexlist[0].row();
            CurTicket->OperatorID = ui->tvResult->model()->data(ui->tvResult->model()->index(row,1)).toInt();
            CurTicket->CustomerID = getCustomerId(ui->tvResult->model()->data(ui->tvResult->model()->index(row,2)).toString());
            CurTicket->ItemID = getItemId(ui->tvResult->model()->data(ui->tvResult->model()->index(row,3)).toString(), &Position);
            CurTicket->Vehicule = ui->tvResult->model()->data(ui->tvResult->model()->index(row,4)).toString();
            CurTicket->Driver = ui->tvResult->model()->data(ui->tvResult->model()->index(row,5)).toString();
            CurTicket->Transporter = ui->tvResult->model()->data(ui->tvResult->model()->index(row,6)).toString();
            CurTicket->TimeIn = ui->tvResult->model()->data(ui->tvResult->model()->index(row,7)).toDateTime();
            CurTicket->TimeOut = ui->tvResult->model()->data(ui->tvResult->model()->index(row,8)).toDateTime();
            CurTicket->Empty = ui->tvResult->model()->data(ui->tvResult->model()->index(row,9)).toInt();
            CurTicket->Full = ui->tvResult->model()->data(ui->tvResult->model()->index(row,10)).toInt();
            PrintTicket();
            CurTicket->Empty = 0;
        }
    }
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if (index >1 ) ui->tabWidget->removeTab(index);
}

void MainWindow::sortByHeader(int Column)
{
    ui->tvResult->sortByColumn(Column, Qt::AscendingOrder);
    //ui->tvResult->repaint();
}





void MainWindow::on_actionWhatisThis_triggered()
{
    //QAction *W;

    //W = QWhatsThis::createAction(this);
    QWhatsThis::enterWhatsThisMode();

}




