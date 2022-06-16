#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QtSerialPort>
#include <QCompleter>
#include <QButtonGroup>
#include <QSqlDatabase>
#include <QLabel>

#include "Setup/Operators.h"
#include "Setup/Items.h"
#include "Setup/Customers.h"
#include "lib/include/lrreportengine.h"
#include "lib/include/lrcallbackdatasourceintf.h"

typedef struct weighbill
{
    int id, OperatorID, CustomerID, ItemID;
    QString Vehicule, Driver, Transporter, Remark;
    QDateTime TimeIn, TimeOut;
    double Empty, Full, Factor;

} Ticket;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Operator CurOperator;
    Ticket *CurTicket;
    Item *CurItem;
    Customer *CurCustomer;
    bool addMode;
    QLabel *DateLabel;
    QWidget *ReportTab[15];
    QStringList *VehiculeList, *DriverList, *TransporterList;
    QCompleter *CustCompleter, *VehiculeCompleter, *ItemCompleter, *DriverCompleter, *TransporterCompleter;


public:

    QSqlDatabase db;
    QButtonGroup *ButtonSet;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void timerEvent(QTimerEvent *event);

private slots:

    int  getItemId(QString ItemDesc, int *Pos);
    int  getItem(QString ItemDesc);
    void getItem(Item *ItemRec, int row);
    int  getImportedItemId(QString ItemDesc);
    int  getCustomerId(QString CusName);
    void getCustomer(Customer *Cust, int row);
    void InitData();
    void InitPriceList();
    void openSerialPort();
    void readData();
    void ResetButtons();
    void ResetButtonsBackground();
    void SetButton(int i, QString Label);
    void ClearScreen();
    void PrintTicket();
    void on_actionLogin_triggered();
    void on_actionOperators_triggered();
    void on_actionCustomersImport_triggered();
    void on_actionCustomers_triggered();
    void on_actionTransactionsImport_triggered();
    void on_actionExit_triggered();
    void on_actionSerial_Port_triggered();
    void on_actionItems_triggered();
    void on_leDriver_returnPressed();
    void on_leVehicule_returnPressed();
    void on_leCustomer_returnPressed();
    void on_leTransporter_returnPressed();
    void on_rb0_clicked();
    void on_rb1_clicked();
    void on_rb2_clicked();
    void on_rb3_clicked();
    void on_rb4_clicked();
    void on_rb5_clicked();
    void on_rb6_clicked();
    void on_rb7_clicked();
    void on_rb8_clicked();
    void on_rb9_clicked();
    void on_cbOther_currentTextChanged(const QString &arg1);
    void on_pbWeigh_clicked();
    void on_tvTicket_doubleClicked(const QModelIndex &index);
    void on_pbSearch_clicked();
    void on_pbExport_clicked();
    void on_actionDaily_Report_triggered();
    void on_tvResult_doubleClicked(const QModelIndex &index);
    void on_pbClear_clicked();
    void on_pbPrint_clicked();
    void on_deDate_dateChanged(const QDate &date);
    void on_tabWidget_tabCloseRequested(int index);
    void on_pbQuery_clicked();
    void on_actionLifting_Report_triggered();
    void on_pbPrintCL_clicked();
    void on_actionLifting_By_Item_triggered();
    void on_pbQueryCLI_clicked();
    void on_pbPrintCLI_clicked();
    void on_pbClearTransaction_clicked();
    void on_actionPrice_Lists_triggered();
    void on_actionTrans_By_Date_triggered();
    void on_pbQueryTBD_clicked();
    void on_actionTransporter_By_Material_triggered();
    void on_pbQueryTDI_clicked();
    void on_pbPrintTBD_clicked();
    void on_pbPrintTicket_clicked();
    void on_pbPrintTDI_clicked();
    void on_pbAddItem_clicked();
    void on_pbModifyItem_clicked();
    void updateItemRow(int, QSqlRecord&);
    void on_pbDeleteItem_clicked();
    void on_tvLists_clicked(const QModelIndex &index);
    void on_pbAddPriceList_clicked();
    void updateListRow(QModelIndex,QModelIndex);
    void on_pbDeletePriceList_clicked();
    void on_tvPriceList_doubleClicked(const QModelIndex &index);
    void on_pbAddCustomer_clicked();
    void on_pbDeleteCustomer_clicked();
    void sortByHeader(int Column);
    void on_pbModifyCustomer_clicked();
    void modifyCustomer(int row, Customer *NewData);
    void on_actionLifting_By_Customer_Summary_triggered();
    void on_pbQueryCLS_clicked();
    void on_pbPrintCLS_clicked();
    void on_pbQuerySR_clicked();
    void on_pbPrintSR_clicked();
    void createStatusBar();
    void on_actionItem_By_Date_Detailed_triggered();
    void on_pbQueryILD_clicked();
    void on_pbPrintILD_clicked();
    void on_actionItem_By_Date_Summary_triggered();
    void on_pbQueryIS_clicked();
    void on_pbPrintIS_clicked();
    void on_actionAbout_triggered();
    void on_actionContents_triggered();
    void on_actionServer_triggered();
    void on_actionSalesDetailed_triggered();
    void on_actionSalesSummary_triggered();
    void on_pbQuerySRS_clicked();
    void on_pbPrintSRS_clicked();
    void on_tvItems_clicked(const QModelIndex &index);
    void on_tvCustomers_clicked(const QModelIndex &index);
    void on_actionBackup_triggered();
    void on_tvOperators_clicked(const QModelIndex &index);
    void on_pbAddOperator_clicked();
    int getOperator(QString OpName);
    void on_pbDeleteOperator_clicked();
    void on_pbModifyOperator_clicked();
    void on_actionRestore_triggered();
    void on_actionReport_Designer_triggered();
    void on_actionWhatisThis_triggered();



private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    int StreamLen;
    QString Indicator, Delimiter;

};

#endif // MAINWINDOW_H
