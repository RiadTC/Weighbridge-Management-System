/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Other/lineedit.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLogin;
    QAction *actionOperators;
    QAction *actionCustomersImport;
    QAction *actionTransactionsImport;
    QAction *actionExit;
    QAction *actionSerial_Port;
    QAction *actionCustomers;
    QAction *actionItems;
    QAction *actionDaily_Report;
    QAction *actionLifting_Report;
    QAction *actionLifting_By_Item;
    QAction *actionPrice_Lists;
    QAction *actionTrans_By_Date;
    QAction *actionBy_Customer;
    QAction *actionTransporter_By_Material;
    QAction *actionLifting_By_Customer_Summary;
    QAction *actionItem_By_Date_Detailed;
    QAction *actionItem_By_Date_Summary;
    QAction *actionContents;
    QAction *actionIndex;
    QAction *actionAbout;
    QAction *actionServer;
    QAction *actionSales_Report_Summary;
    QAction *actionSalesDetailed;
    QAction *actionSalesSummary;
    QAction *actionBackup;
    QAction *actionRestore;
    QAction *actionReport_Designer;
    QAction *actionWhatisThis;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *Weightab;
    QGridLayout *gridLayout_4;
    QSplitter *splitter;
    QFrame *line;
    QTableView *tvTicket;
    QFrame *frame_2;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    LineEdit *leVehicule;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    LineEdit *leCustomer;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    LineEdit *leTransporter;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    LineEdit *leDriver;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_13;
    LineEdit *leRemark;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *gbButtons;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout;
    QRadioButton *rb0;
    QRadioButton *rb1;
    QRadioButton *rb2;
    QRadioButton *rb3;
    QRadioButton *rb4;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rb5;
    QRadioButton *rb6;
    QRadioButton *rb7;
    QRadioButton *rb8;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rb9;
    QComboBox *cbOther;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_4;
    QLCDNumber *lcdNumber;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pbWeigh;
    QPushButton *pbClearTransaction;
    QWidget *SearchTab;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_14;
    QLabel *label_5;
    QDateTimeEdit *deStartTime;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QDateTimeEdit *deEndTime;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbSearch;
    QPushButton *pbClear;
    QPushButton *pbExport;
    QPushButton *pbPrintTicket;
    QTableView *tvResult;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLineEdit *leCustomer1;
    QLabel *label_11;
    QLineEdit *leMaterial;
    QLabel *label_7;
    QLineEdit *leVehicule1;
    QLabel *label_9;
    QLineEdit *leTransporter1;
    QLabel *label_10;
    QLineEdit *leDriver1;
    QLabel *lresult;
    QWidget *OperatorsTab;
    QGridLayout *gridLayout_13;
    QHBoxLayout *horizontalLayout_43;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pbAddOperator;
    QPushButton *pbModifyOperator;
    QPushButton *pbDeleteOperator;
    QHBoxLayout *horizontalLayout_18;
    QTableView *tvOperators;
    QFrame *frame_13;
    QWidget *CustomersTab;
    QGridLayout *gridLayout_16;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pbAddCustomer;
    QPushButton *pbModifyCustomer;
    QPushButton *pbDeleteCustomer;
    QPushButton *pbPrintCustomers;
    QHBoxLayout *horizontalLayout_38;
    QTableView *tvCustomers;
    QFrame *frame_3;
    QGridLayout *gridLayout_32;
    QFrame *frCustomer;
    QGridLayout *gridLayout_31;
    QHBoxLayout *horizontalLayout_39;
    QLabel *label_43;
    QLineEdit *leName;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_40;
    QLabel *label_52;
    QLineEdit *lePhone1;
    QLabel *label_53;
    QLineEdit *lePhone2;
    QSpacerItem *horizontalSpacer_26;
    QHBoxLayout *horizontalLayout_41;
    QLabel *label_54;
    QLineEdit *leFullName;
    QSpacerItem *horizontalSpacer_23;
    QHBoxLayout *horizontalLayout_42;
    QLabel *label_55;
    QLineEdit *leEmail;
    QSpacerItem *horizontalSpacer_24;
    QFrame *frame_12;
    QWidget *ItemsTab;
    QGridLayout *gridLayout_35;
    QHBoxLayout *horizontalLayout_22;
    QTableView *tvItems;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame3;
    QGridLayout *gridLayout_33;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_45;
    QLabel *label_60;
    QLineEdit *leShortDesc;
    QSpacerItem *horizontalSpacer_25;
    QHBoxLayout *horizontalLayout_44;
    QLabel *label_59;
    QLineEdit *leLongDesc;
    QSpacerItem *horizontalSpacer_27;
    QRadioButton *rbSale;
    QFrame *frame3_2;
    QSplitter *splitter_3;
    QLabel *label_57;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_46;
    QLabel *label_58;
    QLabel *lDate;
    QHBoxLayout *horizontalLayout_47;
    QLabel *label_61;
    QLabel *lQuantity;
    QHBoxLayout *horizontalLayout_48;
    QLabel *label_62;
    QLabel *lCustomer;
    QHBoxLayout *horizontalLayout_49;
    QLabel *label_63;
    QLabel *lVehicule;
    QLabel *label_64;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_51;
    QLabel *label_65;
    QLabel *lcurW;
    QHBoxLayout *horizontalLayout_52;
    QLabel *label_66;
    QLabel *lcurM;
    QHBoxLayout *horizontalLayout_53;
    QLabel *label_67;
    QLabel *lcurY;
    QCommandLinkButton *commandLinkButton;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pbAddItem;
    QPushButton *pbModifyItem;
    QPushButton *pbDeleteItem;
    QPushButton *pbPrintItems;
    QWidget *PriceListTab;
    QGridLayout *gridLayout_17;
    QHBoxLayout *horizontalLayout_20;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pbAddPriceList;
    QPushButton *pbModifyPriceList;
    QPushButton *pbDeletePriceList;
    QPushButton *pbPrintPriceList;
    QHBoxLayout *horizontalLayout_21;
    QTableView *tvLists;
    QTableView *tvPriceList;
    QWidget *ReportTab1;
    QGridLayout *gridLayout_5;
    QFrame *frame;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_12;
    QDateEdit *deDate;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pbPrint;
    QTableView *tvReport;
    QWidget *ReportTab2;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_4;
    QGridLayout *gridLayout_14;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_28;
    QLineEdit *leCustomerLR;
    QLabel *label_29;
    QDateEdit *deFrom;
    QLabel *label_30;
    QDateEdit *deTo;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *pbQuery;
    QPushButton *pbPrintCL;
    QTableView *tvCustLifting;
    QWidget *ReportTab3;
    QGridLayout *gridLayout_11;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_34;
    QLineEdit *leCustomerCLI;
    QLabel *label_25;
    QLineEdit *leItemCLI;
    QLabel *label_35;
    QDateEdit *deFromCLI;
    QLabel *label_36;
    QDateEdit *deToCLI;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pbQueryCLI;
    QPushButton *pbPrintCLI;
    QTableView *tvCustLiftingCLI;
    QWidget *ReportTab4;
    QGridLayout *gridLayout_9;
    QFrame *frame_5;
    QGridLayout *gridLayout_15;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_31;
    QLineEdit *leTransporterD;
    QLabel *label_32;
    QDateEdit *deFromTBD;
    QLabel *label_33;
    QDateEdit *deToTBD;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *pbQueryTBD;
    QPushButton *pbPrintTBD;
    QTableView *tvTransLiftD;
    QWidget *ReportTab5;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_37;
    QLineEdit *leTransporterTDI;
    QLabel *label_26;
    QLineEdit *leItemTDI;
    QLabel *label_38;
    QDateEdit *deFromTDI;
    QLabel *label_39;
    QDateEdit *deToTDI;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pbQueryTDI;
    QPushButton *pbPrintTDI;
    QTableView *tvTransLiftingTDI;
    QWidget *ReportTab6;
    QGridLayout *gridLayout_19;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_6;
    QGridLayout *gridLayout_18;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_40;
    QLineEdit *leCustomerCLS;
    QLabel *label_41;
    QDateEdit *deFromCLS;
    QLabel *label_42;
    QDateEdit *deToCLS;
    QSpacerItem *horizontalSpacer_18;
    QPushButton *pbQueryCLS;
    QPushButton *pbPrintCLS;
    QTableView *tvCustLiftingSum;
    QWidget *SalesReport;
    QGridLayout *gridLayout_22;
    QGridLayout *gridLayout_21;
    QFrame *frame_7;
    QGridLayout *gridLayout_20;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_44;
    QDateEdit *deFromSR;
    QLabel *label_45;
    QDateEdit *deToSR;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *pbQuerySR;
    QPushButton *pbPrintSR;
    QTableView *tvSalesRep;
    QWidget *ItemsDetailTab;
    QGridLayout *gridLayout_26;
    QFrame *frame_9;
    QGridLayout *gridLayout_25;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_15;
    QLineEdit *leItemILD;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_49;
    QDateEdit *deFromILD;
    QLabel *label_50;
    QDateEdit *deToILD;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *pbQueryILD;
    QPushButton *pbPrintILD;
    QTableView *tvItemLiftD;
    QWidget *ItemsSummaryTab;
    QGridLayout *gridLayout_24;
    QFrame *frame_8;
    QGridLayout *gridLayout_23;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_46;
    QDateEdit *deFromIS;
    QLabel *label_47;
    QDateEdit *deToIS;
    QRadioButton *rbSales;
    QSpacerItem *horizontalSpacer_20;
    QPushButton *pbQueryIS;
    QPushButton *pbPrintIS;
    QTableView *tvItemLiftIS;
    QWidget *HelpTab;
    QGridLayout *gridLayout_27;
    QSplitter *splitter_2;
    QTabWidget *twHelp;
    QWidget *ContentsTab;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *IndexTab;
    QWidget *tab;
    QGridLayout *gridLayout_30;
    QGridLayout *gridLayout_28;
    QFrame *frame_10;
    QGridLayout *gridLayout_29;
    QHBoxLayout *horizontalLayout_34;
    QLabel *label_48;
    QDateEdit *deFromSRS;
    QLabel *label_51;
    QDateEdit *deToSRS;
    QSpacerItem *horizontalSpacer_22;
    QPushButton *pbQuerySRS;
    QPushButton *pbPrintSRS;
    QTableView *tvSalesRepSum;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuImport;
    QMenu *menuSetup;
    QMenu *menuReports;
    QMenu *menuCustomers;
    QMenu *menuTransporter;
    QMenu *menuItems;
    QMenu *menuSales_Report;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1162, 706);
        QFont font;
        font.setPointSize(11);
        MainWindow->setFont(font);
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionLogin->setEnabled(true);
        actionOperators = new QAction(MainWindow);
        actionOperators->setObjectName(QString::fromUtf8("actionOperators"));
        actionCustomersImport = new QAction(MainWindow);
        actionCustomersImport->setObjectName(QString::fromUtf8("actionCustomersImport"));
        actionTransactionsImport = new QAction(MainWindow);
        actionTransactionsImport->setObjectName(QString::fromUtf8("actionTransactionsImport"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSerial_Port = new QAction(MainWindow);
        actionSerial_Port->setObjectName(QString::fromUtf8("actionSerial_Port"));
        actionCustomers = new QAction(MainWindow);
        actionCustomers->setObjectName(QString::fromUtf8("actionCustomers"));
        actionItems = new QAction(MainWindow);
        actionItems->setObjectName(QString::fromUtf8("actionItems"));
        actionDaily_Report = new QAction(MainWindow);
        actionDaily_Report->setObjectName(QString::fromUtf8("actionDaily_Report"));
        actionLifting_Report = new QAction(MainWindow);
        actionLifting_Report->setObjectName(QString::fromUtf8("actionLifting_Report"));
        actionLifting_By_Item = new QAction(MainWindow);
        actionLifting_By_Item->setObjectName(QString::fromUtf8("actionLifting_By_Item"));
        actionPrice_Lists = new QAction(MainWindow);
        actionPrice_Lists->setObjectName(QString::fromUtf8("actionPrice_Lists"));
        actionTrans_By_Date = new QAction(MainWindow);
        actionTrans_By_Date->setObjectName(QString::fromUtf8("actionTrans_By_Date"));
        actionBy_Customer = new QAction(MainWindow);
        actionBy_Customer->setObjectName(QString::fromUtf8("actionBy_Customer"));
        actionTransporter_By_Material = new QAction(MainWindow);
        actionTransporter_By_Material->setObjectName(QString::fromUtf8("actionTransporter_By_Material"));
        actionLifting_By_Customer_Summary = new QAction(MainWindow);
        actionLifting_By_Customer_Summary->setObjectName(QString::fromUtf8("actionLifting_By_Customer_Summary"));
        actionItem_By_Date_Detailed = new QAction(MainWindow);
        actionItem_By_Date_Detailed->setObjectName(QString::fromUtf8("actionItem_By_Date_Detailed"));
        actionItem_By_Date_Summary = new QAction(MainWindow);
        actionItem_By_Date_Summary->setObjectName(QString::fromUtf8("actionItem_By_Date_Summary"));
        actionContents = new QAction(MainWindow);
        actionContents->setObjectName(QString::fromUtf8("actionContents"));
        actionIndex = new QAction(MainWindow);
        actionIndex->setObjectName(QString::fromUtf8("actionIndex"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionServer = new QAction(MainWindow);
        actionServer->setObjectName(QString::fromUtf8("actionServer"));
        actionSales_Report_Summary = new QAction(MainWindow);
        actionSales_Report_Summary->setObjectName(QString::fromUtf8("actionSales_Report_Summary"));
        actionSalesDetailed = new QAction(MainWindow);
        actionSalesDetailed->setObjectName(QString::fromUtf8("actionSalesDetailed"));
        actionSalesSummary = new QAction(MainWindow);
        actionSalesSummary->setObjectName(QString::fromUtf8("actionSalesSummary"));
        actionBackup = new QAction(MainWindow);
        actionBackup->setObjectName(QString::fromUtf8("actionBackup"));
        actionRestore = new QAction(MainWindow);
        actionRestore->setObjectName(QString::fromUtf8("actionRestore"));
        actionReport_Designer = new QAction(MainWindow);
        actionReport_Designer->setObjectName(QString::fromUtf8("actionReport_Designer"));
        actionWhatisThis = new QAction(MainWindow);
        actionWhatisThis->setObjectName(QString::fromUtf8("actionWhatisThis"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(false);
        Weightab = new QWidget();
        Weightab->setObjectName(QString::fromUtf8("Weightab"));
        Weightab->setFont(font);
        gridLayout_4 = new QGridLayout(Weightab);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        splitter = new QSplitter(Weightab);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        line = new QFrame(splitter);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 10));
        line->setMaximumSize(QSize(16777215, 14));
        line->setLineWidth(15);
        line->setMidLineWidth(5);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        splitter->addWidget(line);
        tvTicket = new QTableView(splitter);
        tvTicket->setObjectName(QString::fromUtf8("tvTicket"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tvTicket->sizePolicy().hasHeightForWidth());
        tvTicket->setSizePolicy(sizePolicy);
        tvTicket->setFrameShadow(QFrame::Sunken);
        tvTicket->setAlternatingRowColors(true);
        tvTicket->setSelectionMode(QAbstractItemView::SingleSelection);
        tvTicket->setSelectionBehavior(QAbstractItemView::SelectRows);
        splitter->addWidget(tvTicket);

        gridLayout_4->addWidget(splitter, 1, 0, 1, 1);

        frame_2 = new QFrame(Weightab);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 230));
        frame_2->setMaximumSize(QSize(16777215, 230));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_2);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(88, 40));

        horizontalLayout_2->addWidget(label_2);

        leVehicule = new LineEdit(frame_2);
        leVehicule->setObjectName(QString::fromUtf8("leVehicule"));

        horizontalLayout_2->addWidget(leVehicule);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(88, 40));

        horizontalLayout_7->addWidget(label);

        leCustomer = new LineEdit(frame_2);
        leCustomer->setObjectName(QString::fromUtf8("leCustomer"));

        horizontalLayout_7->addWidget(leCustomer);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(88, 40));
        label_3->setContextMenuPolicy(Qt::NoContextMenu);

        horizontalLayout_8->addWidget(label_3);

        leTransporter = new LineEdit(frame_2);
        leTransporter->setObjectName(QString::fromUtf8("leTransporter"));

        horizontalLayout_8->addWidget(leTransporter);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(88, 40));

        horizontalLayout_9->addWidget(label_4);

        leDriver = new LineEdit(frame_2);
        leDriver->setObjectName(QString::fromUtf8("leDriver"));

        horizontalLayout_9->addWidget(leDriver);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_13 = new QLabel(frame_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(87, 40));
        label_13->setContextMenuPolicy(Qt::NoContextMenu);

        horizontalLayout_11->addWidget(label_13);

        leRemark = new LineEdit(frame_2);
        leRemark->setObjectName(QString::fromUtf8("leRemark"));
        leRemark->setMinimumSize(QSize(210, 0));

        horizontalLayout_11->addWidget(leRemark);


        verticalLayout_3->addLayout(horizontalLayout_11);


        horizontalLayout_14->addLayout(verticalLayout_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_5);

        gbButtons = new QGroupBox(frame_2);
        gbButtons->setObjectName(QString::fromUtf8("gbButtons"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gbButtons->sizePolicy().hasHeightForWidth());
        gbButtons->setSizePolicy(sizePolicy1);
        gbButtons->setMinimumSize(QSize(300, 200));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        gbButtons->setFont(font1);
        gbButtons->setAutoFillBackground(false);
        gbButtons->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));
        gridLayout = new QGridLayout(gbButtons);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rb0 = new QRadioButton(gbButtons);
        rb0->setObjectName(QString::fromUtf8("rb0"));
        rb0->setFont(font);

        verticalLayout->addWidget(rb0);

        rb1 = new QRadioButton(gbButtons);
        rb1->setObjectName(QString::fromUtf8("rb1"));
        rb1->setFont(font);
        rb1->setAutoFillBackground(false);
        rb1->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(rb1);

        rb2 = new QRadioButton(gbButtons);
        rb2->setObjectName(QString::fromUtf8("rb2"));
        rb2->setFont(font);

        verticalLayout->addWidget(rb2);

        rb3 = new QRadioButton(gbButtons);
        rb3->setObjectName(QString::fromUtf8("rb3"));
        rb3->setFont(font);

        verticalLayout->addWidget(rb3);

        rb4 = new QRadioButton(gbButtons);
        rb4->setObjectName(QString::fromUtf8("rb4"));
        rb4->setFont(font);

        verticalLayout->addWidget(rb4);


        horizontalLayout_12->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        rb5 = new QRadioButton(gbButtons);
        rb5->setObjectName(QString::fromUtf8("rb5"));
        rb5->setFont(font);

        verticalLayout_2->addWidget(rb5);

        rb6 = new QRadioButton(gbButtons);
        rb6->setObjectName(QString::fromUtf8("rb6"));
        rb6->setFont(font);

        verticalLayout_2->addWidget(rb6);

        rb7 = new QRadioButton(gbButtons);
        rb7->setObjectName(QString::fromUtf8("rb7"));
        rb7->setFont(font);

        verticalLayout_2->addWidget(rb7);

        rb8 = new QRadioButton(gbButtons);
        rb8->setObjectName(QString::fromUtf8("rb8"));
        rb8->setFont(font);

        verticalLayout_2->addWidget(rb8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        rb9 = new QRadioButton(gbButtons);
        rb9->setObjectName(QString::fromUtf8("rb9"));
        sizePolicy1.setHeightForWidth(rb9->sizePolicy().hasHeightForWidth());
        rb9->setSizePolicy(sizePolicy1);
        rb9->setMaximumSize(QSize(20, 20));
        rb9->setFont(font);

        horizontalLayout_3->addWidget(rb9);

        cbOther = new QComboBox(gbButtons);
        cbOther->setObjectName(QString::fromUtf8("cbOther"));
        cbOther->setFont(font);
        cbOther->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_3->addWidget(cbOther);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_12->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_12, 0, 0, 1, 1);


        horizontalLayout_14->addWidget(gbButtons);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lcdNumber = new QLCDNumber(frame_2);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setEnabled(true);
        sizePolicy1.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy1);
        lcdNumber->setMinimumSize(QSize(300, 120));
        lcdNumber->setLayoutDirection(Qt::RightToLeft);
        lcdNumber->setAutoFillBackground(false);
        lcdNumber->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color:rgb(255, 0, 0);\n"
"\n"
""));
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setLineWidth(1);
        lcdNumber->setMidLineWidth(0);
        lcdNumber->setDigitCount(6);
        lcdNumber->setMode(QLCDNumber::Dec);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(888888.000000000000000));
        lcdNumber->setProperty("intValue", QVariant(888888));

        verticalLayout_4->addWidget(lcdNumber);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pbWeigh = new QPushButton(frame_2);
        pbWeigh->setObjectName(QString::fromUtf8("pbWeigh"));
        sizePolicy1.setHeightForWidth(pbWeigh->sizePolicy().hasHeightForWidth());
        pbWeigh->setSizePolicy(sizePolicy1);
        pbWeigh->setMinimumSize(QSize(100, 60));
        pbWeigh->setAutoDefault(false);
        pbWeigh->setFlat(false);

        horizontalLayout_10->addWidget(pbWeigh);

        pbClearTransaction = new QPushButton(frame_2);
        pbClearTransaction->setObjectName(QString::fromUtf8("pbClearTransaction"));
        sizePolicy1.setHeightForWidth(pbClearTransaction->sizePolicy().hasHeightForWidth());
        pbClearTransaction->setSizePolicy(sizePolicy1);
        pbClearTransaction->setMinimumSize(QSize(110, 60));
        pbClearTransaction->setAutoDefault(false);
        pbClearTransaction->setFlat(false);

        horizontalLayout_10->addWidget(pbClearTransaction);


        verticalLayout_4->addLayout(horizontalLayout_10);


        horizontalLayout_14->addLayout(verticalLayout_4);


        gridLayout_8->addLayout(horizontalLayout_14, 0, 0, 1, 1);


        gridLayout_4->addWidget(frame_2, 0, 0, 1, 1);

        tabWidget->addTab(Weightab, QString());
        SearchTab = new QWidget();
        SearchTab->setObjectName(QString::fromUtf8("SearchTab"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(SearchTab->sizePolicy().hasHeightForWidth());
        SearchTab->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(SearchTab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_14 = new QLabel(SearchTab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_14->setFont(font2);

        horizontalLayout_4->addWidget(label_14);

        label_5 = new QLabel(SearchTab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        deStartTime = new QDateTimeEdit(SearchTab);
        deStartTime->setObjectName(QString::fromUtf8("deStartTime"));
        sizePolicy1.setHeightForWidth(deStartTime->sizePolicy().hasHeightForWidth());
        deStartTime->setSizePolicy(sizePolicy1);
        deStartTime->setMinimumSize(QSize(180, 0));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setWeight(50);
        deStartTime->setFont(font3);
        deStartTime->setMouseTracking(false);
        deStartTime->setDateTime(QDateTime(QDate(2016, 9, 1), QTime(0, 0, 0)));
        deStartTime->setMinimumDateTime(QDateTime(QDate(2012, 9, 1), QTime(0, 0, 0)));
        deStartTime->setMinimumDate(QDate(2012, 9, 1));
        deStartTime->setCurrentSection(QDateTimeEdit::MonthSection);
        deStartTime->setCalendarPopup(true);

        horizontalLayout_4->addWidget(deStartTime);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalSpacer = new QSpacerItem(34, 33, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(SearchTab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        deEndTime = new QDateTimeEdit(SearchTab);
        deEndTime->setObjectName(QString::fromUtf8("deEndTime"));
        deEndTime->setMinimumSize(QSize(180, 0));
        deEndTime->setDateTime(QDateTime(QDate(2016, 9, 1), QTime(0, 0, 0)));
        deEndTime->setMinimumDate(QDate(2012, 9, 1));
        deEndTime->setCalendarPopup(true);

        horizontalLayout_5->addWidget(deEndTime);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        pbSearch = new QPushButton(SearchTab);
        pbSearch->setObjectName(QString::fromUtf8("pbSearch"));

        horizontalLayout_6->addWidget(pbSearch);

        pbClear = new QPushButton(SearchTab);
        pbClear->setObjectName(QString::fromUtf8("pbClear"));

        horizontalLayout_6->addWidget(pbClear);

        pbExport = new QPushButton(SearchTab);
        pbExport->setObjectName(QString::fromUtf8("pbExport"));

        horizontalLayout_6->addWidget(pbExport);

        pbPrintTicket = new QPushButton(SearchTab);
        pbPrintTicket->setObjectName(QString::fromUtf8("pbPrintTicket"));

        horizontalLayout_6->addWidget(pbPrintTicket);


        gridLayout_3->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        tvResult = new QTableView(SearchTab);
        tvResult->setObjectName(QString::fromUtf8("tvResult"));
        tvResult->setAlternatingRowColors(true);
        tvResult->setSelectionMode(QAbstractItemView::MultiSelection);

        gridLayout_3->addWidget(tvResult, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_8 = new QLabel(SearchTab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        leCustomer1 = new QLineEdit(SearchTab);
        leCustomer1->setObjectName(QString::fromUtf8("leCustomer1"));

        horizontalLayout->addWidget(leCustomer1);

        label_11 = new QLabel(SearchTab);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout->addWidget(label_11);

        leMaterial = new QLineEdit(SearchTab);
        leMaterial->setObjectName(QString::fromUtf8("leMaterial"));

        horizontalLayout->addWidget(leMaterial);

        label_7 = new QLabel(SearchTab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);

        leVehicule1 = new QLineEdit(SearchTab);
        leVehicule1->setObjectName(QString::fromUtf8("leVehicule1"));

        horizontalLayout->addWidget(leVehicule1);

        label_9 = new QLabel(SearchTab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setContextMenuPolicy(Qt::NoContextMenu);

        horizontalLayout->addWidget(label_9);

        leTransporter1 = new QLineEdit(SearchTab);
        leTransporter1->setObjectName(QString::fromUtf8("leTransporter1"));

        horizontalLayout->addWidget(leTransporter1);

        label_10 = new QLabel(SearchTab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout->addWidget(label_10);

        leDriver1 = new QLineEdit(SearchTab);
        leDriver1->setObjectName(QString::fromUtf8("leDriver1"));

        horizontalLayout->addWidget(leDriver1);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);

        lresult = new QLabel(SearchTab);
        lresult->setObjectName(QString::fromUtf8("lresult"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(127, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(63, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 127, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 170, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush8(QColor(0, 0, 0, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush10(QColor(0, 0, 0, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        lresult->setPalette(palette);
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        lresult->setFont(font4);
        lresult->setAutoFillBackground(true);
        lresult->setFrameShape(QFrame::Box);
        lresult->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(lresult, 3, 0, 1, 1);

        tabWidget->addTab(SearchTab, QString());
        OperatorsTab = new QWidget();
        OperatorsTab->setObjectName(QString::fromUtf8("OperatorsTab"));
        gridLayout_13 = new QGridLayout(OperatorsTab);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setSpacing(6);
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        horizontalSpacer_11 = new QSpacerItem(244, 33, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_43->addItem(horizontalSpacer_11);

        pbAddOperator = new QPushButton(OperatorsTab);
        pbAddOperator->setObjectName(QString::fromUtf8("pbAddOperator"));

        horizontalLayout_43->addWidget(pbAddOperator);

        pbModifyOperator = new QPushButton(OperatorsTab);
        pbModifyOperator->setObjectName(QString::fromUtf8("pbModifyOperator"));

        horizontalLayout_43->addWidget(pbModifyOperator);

        pbDeleteOperator = new QPushButton(OperatorsTab);
        pbDeleteOperator->setObjectName(QString::fromUtf8("pbDeleteOperator"));

        horizontalLayout_43->addWidget(pbDeleteOperator);


        gridLayout_13->addLayout(horizontalLayout_43, 0, 0, 1, 1);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        tvOperators = new QTableView(OperatorsTab);
        tvOperators->setObjectName(QString::fromUtf8("tvOperators"));
        tvOperators->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_18->addWidget(tvOperators);

        frame_13 = new QFrame(OperatorsTab);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);

        horizontalLayout_18->addWidget(frame_13);


        gridLayout_13->addLayout(horizontalLayout_18, 1, 0, 1, 1);

        tabWidget->addTab(OperatorsTab, QString());
        CustomersTab = new QWidget();
        CustomersTab->setObjectName(QString::fromUtf8("CustomersTab"));
        gridLayout_16 = new QGridLayout(CustomersTab);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalSpacer_12 = new QSpacerItem(237, 33, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_12);

        pbAddCustomer = new QPushButton(CustomersTab);
        pbAddCustomer->setObjectName(QString::fromUtf8("pbAddCustomer"));

        horizontalLayout_19->addWidget(pbAddCustomer);

        pbModifyCustomer = new QPushButton(CustomersTab);
        pbModifyCustomer->setObjectName(QString::fromUtf8("pbModifyCustomer"));

        horizontalLayout_19->addWidget(pbModifyCustomer);

        pbDeleteCustomer = new QPushButton(CustomersTab);
        pbDeleteCustomer->setObjectName(QString::fromUtf8("pbDeleteCustomer"));

        horizontalLayout_19->addWidget(pbDeleteCustomer);

        pbPrintCustomers = new QPushButton(CustomersTab);
        pbPrintCustomers->setObjectName(QString::fromUtf8("pbPrintCustomers"));
        pbPrintCustomers->setEnabled(false);

        horizontalLayout_19->addWidget(pbPrintCustomers);


        gridLayout_16->addLayout(horizontalLayout_19, 0, 0, 1, 1);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setSpacing(6);
        horizontalLayout_38->setObjectName(QString::fromUtf8("horizontalLayout_38"));
        tvCustomers = new QTableView(CustomersTab);
        tvCustomers->setObjectName(QString::fromUtf8("tvCustomers"));
        tvCustomers->setMaximumSize(QSize(350, 16777215));

        horizontalLayout_38->addWidget(tvCustomers);

        frame_3 = new QFrame(CustomersTab);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_32 = new QGridLayout(frame_3);
        gridLayout_32->setSpacing(6);
        gridLayout_32->setContentsMargins(11, 11, 11, 11);
        gridLayout_32->setObjectName(QString::fromUtf8("gridLayout_32"));
        frCustomer = new QFrame(frame_3);
        frCustomer->setObjectName(QString::fromUtf8("frCustomer"));
        frCustomer->setEnabled(false);
        frCustomer->setFrameShape(QFrame::StyledPanel);
        frCustomer->setFrameShadow(QFrame::Raised);
        gridLayout_31 = new QGridLayout(frCustomer);
        gridLayout_31->setSpacing(6);
        gridLayout_31->setContentsMargins(11, 11, 11, 11);
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setSpacing(6);
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        label_43 = new QLabel(frCustomer);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setMinimumSize(QSize(100, 0));
        QFont font5;
        font5.setPointSize(12);
        label_43->setFont(font5);

        horizontalLayout_39->addWidget(label_43);

        leName = new QLineEdit(frCustomer);
        leName->setObjectName(QString::fromUtf8("leName"));
        leName->setMaximumSize(QSize(250, 16777215));
        leName->setFont(font5);

        horizontalLayout_39->addWidget(leName);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_39->addItem(horizontalSpacer_15);


        gridLayout_31->addLayout(horizontalLayout_39, 0, 0, 1, 2);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setSpacing(6);
        horizontalLayout_40->setObjectName(QString::fromUtf8("horizontalLayout_40"));
        label_52 = new QLabel(frCustomer);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setMinimumSize(QSize(100, 0));
        label_52->setFont(font5);

        horizontalLayout_40->addWidget(label_52);

        lePhone1 = new QLineEdit(frCustomer);
        lePhone1->setObjectName(QString::fromUtf8("lePhone1"));
        lePhone1->setMinimumSize(QSize(100, 0));
        lePhone1->setMaximumSize(QSize(250, 16777215));
        lePhone1->setFont(font5);

        horizontalLayout_40->addWidget(lePhone1);

        label_53 = new QLabel(frCustomer);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setMinimumSize(QSize(100, 0));
        label_53->setFont(font5);
        label_53->setAlignment(Qt::AlignCenter);

        horizontalLayout_40->addWidget(label_53);

        lePhone2 = new QLineEdit(frCustomer);
        lePhone2->setObjectName(QString::fromUtf8("lePhone2"));
        lePhone2->setMinimumSize(QSize(100, 0));
        lePhone2->setMaximumSize(QSize(250, 16777215));
        lePhone2->setFont(font5);

        horizontalLayout_40->addWidget(lePhone2);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_40->addItem(horizontalSpacer_26);


        gridLayout_31->addLayout(horizontalLayout_40, 2, 0, 1, 2);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setSpacing(6);
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        label_54 = new QLabel(frCustomer);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setMinimumSize(QSize(100, 0));
        label_54->setFont(font5);

        horizontalLayout_41->addWidget(label_54);

        leFullName = new QLineEdit(frCustomer);
        leFullName->setObjectName(QString::fromUtf8("leFullName"));
        leFullName->setMinimumSize(QSize(300, 0));
        leFullName->setMaximumSize(QSize(350, 16777215));
        leFullName->setFont(font5);

        horizontalLayout_41->addWidget(leFullName);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_41->addItem(horizontalSpacer_23);


        gridLayout_31->addLayout(horizontalLayout_41, 1, 0, 1, 2);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setSpacing(6);
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        label_55 = new QLabel(frCustomer);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setMinimumSize(QSize(100, 0));
        label_55->setFont(font5);

        horizontalLayout_42->addWidget(label_55);

        leEmail = new QLineEdit(frCustomer);
        leEmail->setObjectName(QString::fromUtf8("leEmail"));
        leEmail->setMinimumSize(QSize(120, 0));
        leEmail->setMaximumSize(QSize(400, 16777215));
        leEmail->setFont(font5);

        horizontalLayout_42->addWidget(leEmail);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_42->addItem(horizontalSpacer_24);


        gridLayout_31->addLayout(horizontalLayout_42, 3, 0, 1, 2);


        gridLayout_32->addWidget(frCustomer, 0, 0, 1, 1);

        frame_12 = new QFrame(frame_3);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);

        gridLayout_32->addWidget(frame_12, 1, 0, 1, 1);


        horizontalLayout_38->addWidget(frame_3);


        gridLayout_16->addLayout(horizontalLayout_38, 1, 0, 1, 1);

        tabWidget->addTab(CustomersTab, QString());
        ItemsTab = new QWidget();
        ItemsTab->setObjectName(QString::fromUtf8("ItemsTab"));
        gridLayout_35 = new QGridLayout(ItemsTab);
        gridLayout_35->setSpacing(6);
        gridLayout_35->setContentsMargins(11, 11, 11, 11);
        gridLayout_35->setObjectName(QString::fromUtf8("gridLayout_35"));
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        tvItems = new QTableView(ItemsTab);
        tvItems->setObjectName(QString::fromUtf8("tvItems"));
        tvItems->setMaximumSize(QSize(500, 16777215));

        horizontalLayout_22->addWidget(tvItems);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        frame3 = new QFrame(ItemsTab);
        frame3->setObjectName(QString::fromUtf8("frame3"));
        frame3->setMaximumSize(QSize(16777215, 200));
        frame3->setFrameShape(QFrame::Box);
        frame3->setFrameShadow(QFrame::Plain);
        frame3->setLineWidth(5);
        gridLayout_33 = new QGridLayout(frame3);
        gridLayout_33->setSpacing(6);
        gridLayout_33->setContentsMargins(11, 11, 11, 11);
        gridLayout_33->setObjectName(QString::fromUtf8("gridLayout_33"));
        label_16 = new QLabel(frame3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        QFont font6;
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setWeight(75);
        label_16->setFont(font6);

        gridLayout_33->addWidget(label_16, 0, 0, 1, 1);

        horizontalLayout_45 = new QHBoxLayout();
        horizontalLayout_45->setSpacing(6);
        horizontalLayout_45->setObjectName(QString::fromUtf8("horizontalLayout_45"));
        label_60 = new QLabel(frame3);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setMinimumSize(QSize(150, 0));
        label_60->setFont(font5);

        horizontalLayout_45->addWidget(label_60);

        leShortDesc = new QLineEdit(frame3);
        leShortDesc->setObjectName(QString::fromUtf8("leShortDesc"));
        leShortDesc->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(leShortDesc->sizePolicy().hasHeightForWidth());
        leShortDesc->setSizePolicy(sizePolicy3);
        leShortDesc->setMaximumSize(QSize(200, 16777215));
        leShortDesc->setReadOnly(true);

        horizontalLayout_45->addWidget(leShortDesc);

        horizontalSpacer_25 = new QSpacerItem(44, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_45->addItem(horizontalSpacer_25);


        gridLayout_33->addLayout(horizontalLayout_45, 1, 0, 1, 1);

        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setSpacing(6);
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        label_59 = new QLabel(frame3);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setMinimumSize(QSize(150, 0));
        label_59->setFont(font5);

        horizontalLayout_44->addWidget(label_59);

        leLongDesc = new QLineEdit(frame3);
        leLongDesc->setObjectName(QString::fromUtf8("leLongDesc"));
        leLongDesc->setMinimumSize(QSize(300, 0));
        leLongDesc->setReadOnly(true);

        horizontalLayout_44->addWidget(leLongDesc);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_44->addItem(horizontalSpacer_27);


        gridLayout_33->addLayout(horizontalLayout_44, 2, 0, 1, 1);

        rbSale = new QRadioButton(frame3);
        rbSale->setObjectName(QString::fromUtf8("rbSale"));
        rbSale->setEnabled(true);
        rbSale->setFont(font5);
        rbSale->setCheckable(true);

        gridLayout_33->addWidget(rbSale, 3, 0, 1, 1);


        verticalLayout_7->addWidget(frame3);

        frame3_2 = new QFrame(ItemsTab);
        frame3_2->setObjectName(QString::fromUtf8("frame3_2"));
        frame3_2->setFrameShape(QFrame::Box);
        frame3_2->setFrameShadow(QFrame::Plain);
        frame3_2->setLineWidth(5);
        splitter_3 = new QSplitter(frame3_2);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setGeometry(QRect(11, 11, 284, 300));
        splitter_3->setOrientation(Qt::Vertical);
        label_57 = new QLabel(splitter_3);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setMinimumSize(QSize(0, 40));
        label_57->setMaximumSize(QSize(16777215, 40));
        label_57->setFont(font4);
        splitter_3->addWidget(label_57);
        layoutWidget = new QWidget(splitter_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_8 = new QVBoxLayout(layoutWidget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setSpacing(6);
        horizontalLayout_46->setObjectName(QString::fromUtf8("horizontalLayout_46"));
        label_58 = new QLabel(layoutWidget);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setMinimumSize(QSize(0, 20));
        label_58->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_46->addWidget(label_58);

        lDate = new QLabel(layoutWidget);
        lDate->setObjectName(QString::fromUtf8("lDate"));
        lDate->setMinimumSize(QSize(200, 20));
        lDate->setMaximumSize(QSize(16777215, 20));
        lDate->setFrameShape(QFrame::StyledPanel);

        horizontalLayout_46->addWidget(lDate);


        verticalLayout_8->addLayout(horizontalLayout_46);

        horizontalLayout_47 = new QHBoxLayout();
        horizontalLayout_47->setSpacing(6);
        horizontalLayout_47->setObjectName(QString::fromUtf8("horizontalLayout_47"));
        label_61 = new QLabel(layoutWidget);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setMinimumSize(QSize(0, 20));
        label_61->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_47->addWidget(label_61);

        lQuantity = new QLabel(layoutWidget);
        lQuantity->setObjectName(QString::fromUtf8("lQuantity"));
        lQuantity->setMinimumSize(QSize(200, 20));
        lQuantity->setMaximumSize(QSize(16777215, 20));
        lQuantity->setFrameShape(QFrame::StyledPanel);

        horizontalLayout_47->addWidget(lQuantity);


        verticalLayout_8->addLayout(horizontalLayout_47);

        horizontalLayout_48 = new QHBoxLayout();
        horizontalLayout_48->setSpacing(6);
        horizontalLayout_48->setObjectName(QString::fromUtf8("horizontalLayout_48"));
        label_62 = new QLabel(layoutWidget);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setMinimumSize(QSize(0, 20));
        label_62->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_48->addWidget(label_62);

        lCustomer = new QLabel(layoutWidget);
        lCustomer->setObjectName(QString::fromUtf8("lCustomer"));
        lCustomer->setMinimumSize(QSize(200, 20));
        lCustomer->setMaximumSize(QSize(16777215, 20));
        lCustomer->setFrameShape(QFrame::StyledPanel);

        horizontalLayout_48->addWidget(lCustomer);


        verticalLayout_8->addLayout(horizontalLayout_48);

        horizontalLayout_49 = new QHBoxLayout();
        horizontalLayout_49->setSpacing(6);
        horizontalLayout_49->setObjectName(QString::fromUtf8("horizontalLayout_49"));
        label_63 = new QLabel(layoutWidget);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setMinimumSize(QSize(0, 20));
        label_63->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_49->addWidget(label_63);

        lVehicule = new QLabel(layoutWidget);
        lVehicule->setObjectName(QString::fromUtf8("lVehicule"));
        lVehicule->setMinimumSize(QSize(200, 20));
        lVehicule->setMaximumSize(QSize(16777215, 20));
        lVehicule->setFrameShape(QFrame::StyledPanel);

        horizontalLayout_49->addWidget(lVehicule);


        verticalLayout_8->addLayout(horizontalLayout_49);

        splitter_3->addWidget(layoutWidget);
        label_64 = new QLabel(splitter_3);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setMinimumSize(QSize(0, 40));
        label_64->setMaximumSize(QSize(16777215, 40));
        label_64->setFont(font4);
        splitter_3->addWidget(label_64);
        layoutWidget_4 = new QWidget(splitter_3);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        verticalLayout_10 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_51 = new QHBoxLayout();
        horizontalLayout_51->setSpacing(6);
        horizontalLayout_51->setObjectName(QString::fromUtf8("horizontalLayout_51"));
        label_65 = new QLabel(layoutWidget_4);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        label_65->setMinimumSize(QSize(0, 20));
        label_65->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_51->addWidget(label_65);

        lcurW = new QLabel(layoutWidget_4);
        lcurW->setObjectName(QString::fromUtf8("lcurW"));
        lcurW->setMinimumSize(QSize(150, 20));
        lcurW->setMaximumSize(QSize(200, 20));
        lcurW->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_51->addWidget(lcurW);


        verticalLayout_10->addLayout(horizontalLayout_51);

        horizontalLayout_52 = new QHBoxLayout();
        horizontalLayout_52->setSpacing(6);
        horizontalLayout_52->setObjectName(QString::fromUtf8("horizontalLayout_52"));
        label_66 = new QLabel(layoutWidget_4);
        label_66->setObjectName(QString::fromUtf8("label_66"));
        label_66->setMinimumSize(QSize(0, 20));
        label_66->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_52->addWidget(label_66);

        lcurM = new QLabel(layoutWidget_4);
        lcurM->setObjectName(QString::fromUtf8("lcurM"));
        lcurM->setMinimumSize(QSize(0, 20));
        lcurM->setMaximumSize(QSize(16777215, 20));
        lcurM->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_52->addWidget(lcurM);


        verticalLayout_10->addLayout(horizontalLayout_52);

        horizontalLayout_53 = new QHBoxLayout();
        horizontalLayout_53->setSpacing(6);
        horizontalLayout_53->setObjectName(QString::fromUtf8("horizontalLayout_53"));
        label_67 = new QLabel(layoutWidget_4);
        label_67->setObjectName(QString::fromUtf8("label_67"));
        label_67->setMinimumSize(QSize(0, 20));
        label_67->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_53->addWidget(label_67);

        lcurY = new QLabel(layoutWidget_4);
        lcurY->setObjectName(QString::fromUtf8("lcurY"));
        lcurY->setMinimumSize(QSize(0, 20));
        lcurY->setMaximumSize(QSize(16777215, 20));
        lcurY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_53->addWidget(lcurY);


        verticalLayout_10->addLayout(horizontalLayout_53);

        splitter_3->addWidget(layoutWidget_4);
        commandLinkButton = new QCommandLinkButton(frame3_2);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(420, 50, 168, 41));

        verticalLayout_7->addWidget(frame3_2);


        horizontalLayout_22->addLayout(verticalLayout_7);


        gridLayout_35->addLayout(horizontalLayout_22, 1, 0, 1, 1);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalSpacer_10 = new QSpacerItem(244, 33, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_10);

        pbAddItem = new QPushButton(ItemsTab);
        pbAddItem->setObjectName(QString::fromUtf8("pbAddItem"));

        horizontalLayout_17->addWidget(pbAddItem);

        pbModifyItem = new QPushButton(ItemsTab);
        pbModifyItem->setObjectName(QString::fromUtf8("pbModifyItem"));

        horizontalLayout_17->addWidget(pbModifyItem);

        pbDeleteItem = new QPushButton(ItemsTab);
        pbDeleteItem->setObjectName(QString::fromUtf8("pbDeleteItem"));

        horizontalLayout_17->addWidget(pbDeleteItem);

        pbPrintItems = new QPushButton(ItemsTab);
        pbPrintItems->setObjectName(QString::fromUtf8("pbPrintItems"));

        horizontalLayout_17->addWidget(pbPrintItems);


        gridLayout_35->addLayout(horizontalLayout_17, 0, 0, 1, 1);

        tabWidget->addTab(ItemsTab, QString());
        PriceListTab = new QWidget();
        PriceListTab->setObjectName(QString::fromUtf8("PriceListTab"));
        gridLayout_17 = new QGridLayout(PriceListTab);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalSpacer_13 = new QSpacerItem(767, 33, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_13);

        pbAddPriceList = new QPushButton(PriceListTab);
        pbAddPriceList->setObjectName(QString::fromUtf8("pbAddPriceList"));

        horizontalLayout_20->addWidget(pbAddPriceList);

        pbModifyPriceList = new QPushButton(PriceListTab);
        pbModifyPriceList->setObjectName(QString::fromUtf8("pbModifyPriceList"));

        horizontalLayout_20->addWidget(pbModifyPriceList);

        pbDeletePriceList = new QPushButton(PriceListTab);
        pbDeletePriceList->setObjectName(QString::fromUtf8("pbDeletePriceList"));

        horizontalLayout_20->addWidget(pbDeletePriceList);

        pbPrintPriceList = new QPushButton(PriceListTab);
        pbPrintPriceList->setObjectName(QString::fromUtf8("pbPrintPriceList"));

        horizontalLayout_20->addWidget(pbPrintPriceList);


        gridLayout_17->addLayout(horizontalLayout_20, 0, 0, 1, 1);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        tvLists = new QTableView(PriceListTab);
        tvLists->setObjectName(QString::fromUtf8("tvLists"));
        tvLists->setMaximumSize(QSize(300, 16777215));
        tvLists->setAlternatingRowColors(true);
        tvLists->setSelectionMode(QAbstractItemView::SingleSelection);
        tvLists->setSortingEnabled(true);

        horizontalLayout_21->addWidget(tvLists);

        tvPriceList = new QTableView(PriceListTab);
        tvPriceList->setObjectName(QString::fromUtf8("tvPriceList"));
        tvPriceList->setAlternatingRowColors(true);
        tvPriceList->setSelectionMode(QAbstractItemView::SingleSelection);
        tvPriceList->setTextElideMode(Qt::ElideRight);
        tvPriceList->setSortingEnabled(true);

        horizontalLayout_21->addWidget(tvPriceList);


        gridLayout_17->addLayout(horizontalLayout_21, 1, 0, 1, 1);

        tabWidget->addTab(PriceListTab, QString());
        ReportTab1 = new QWidget();
        ReportTab1->setObjectName(QString::fromUtf8("ReportTab1"));
        gridLayout_5 = new QGridLayout(ReportTab1);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        frame = new QFrame(ReportTab1);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_13->addWidget(label_12);

        deDate = new QDateEdit(frame);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setTime(QTime(0, 0, 0));
        deDate->setCalendarPopup(true);

        horizontalLayout_13->addWidget(deDate);

        horizontalSpacer_7 = new QSpacerItem(244, 33, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_7);

        pbPrint = new QPushButton(frame);
        pbPrint->setObjectName(QString::fromUtf8("pbPrint"));

        horizontalLayout_13->addWidget(pbPrint);


        gridLayout_6->addLayout(horizontalLayout_13, 0, 0, 1, 1);


        gridLayout_5->addWidget(frame, 0, 0, 1, 1);

        tvReport = new QTableView(ReportTab1);
        tvReport->setObjectName(QString::fromUtf8("tvReport"));

        gridLayout_5->addWidget(tvReport, 1, 0, 1, 1);

        tabWidget->addTab(ReportTab1, QString());
        ReportTab2 = new QWidget();
        ReportTab2->setObjectName(QString::fromUtf8("ReportTab2"));
        gridLayout_7 = new QGridLayout(ReportTab2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame_4 = new QFrame(ReportTab2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setEnabled(true);
        frame_4->setAutoFillBackground(false);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_14 = new QGridLayout(frame_4);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        label_28 = new QLabel(frame_4);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        horizontalLayout_28->addWidget(label_28);

        leCustomerLR = new QLineEdit(frame_4);
        leCustomerLR->setObjectName(QString::fromUtf8("leCustomerLR"));
        leCustomerLR->setMinimumSize(QSize(240, 0));
        leCustomerLR->setMaximumSize(QSize(240, 16777215));
        leCustomerLR->setBaseSize(QSize(240, 34));

        horizontalLayout_28->addWidget(leCustomerLR);

        label_29 = new QLabel(frame_4);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_28->addWidget(label_29);

        deFrom = new QDateEdit(frame_4);
        deFrom->setObjectName(QString::fromUtf8("deFrom"));
        deFrom->setMinimumSize(QSize(150, 0));
        deFrom->setTime(QTime(0, 0, 0));
        deFrom->setCalendarPopup(true);

        horizontalLayout_28->addWidget(deFrom);

        label_30 = new QLabel(frame_4);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_28->addWidget(label_30);

        deTo = new QDateEdit(frame_4);
        deTo->setObjectName(QString::fromUtf8("deTo"));
        deTo->setMinimumSize(QSize(150, 0));
        deTo->setCalendarPopup(true);

        horizontalLayout_28->addWidget(deTo);

        horizontalSpacer_16 = new QSpacerItem(244, 33, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_16);

        pbQuery = new QPushButton(frame_4);
        pbQuery->setObjectName(QString::fromUtf8("pbQuery"));

        horizontalLayout_28->addWidget(pbQuery);

        pbPrintCL = new QPushButton(frame_4);
        pbPrintCL->setObjectName(QString::fromUtf8("pbPrintCL"));

        horizontalLayout_28->addWidget(pbPrintCL);


        gridLayout_14->addLayout(horizontalLayout_28, 0, 0, 1, 1);


        verticalLayout_5->addWidget(frame_4);

        tvCustLifting = new QTableView(ReportTab2);
        tvCustLifting->setObjectName(QString::fromUtf8("tvCustLifting"));

        verticalLayout_5->addWidget(tvCustLifting);


        gridLayout_7->addLayout(verticalLayout_5, 0, 0, 1, 1);

        tabWidget->addTab(ReportTab2, QString());
        ReportTab3 = new QWidget();
        ReportTab3->setObjectName(QString::fromUtf8("ReportTab3"));
        gridLayout_11 = new QGridLayout(ReportTab3);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_34 = new QLabel(ReportTab3);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        horizontalLayout_15->addWidget(label_34);

        leCustomerCLI = new QLineEdit(ReportTab3);
        leCustomerCLI->setObjectName(QString::fromUtf8("leCustomerCLI"));
        leCustomerCLI->setMinimumSize(QSize(220, 0));
        leCustomerCLI->setMaximumSize(QSize(250, 16777215));
        leCustomerCLI->setBaseSize(QSize(220, 34));

        horizontalLayout_15->addWidget(leCustomerCLI);

        label_25 = new QLabel(ReportTab3);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_15->addWidget(label_25);

        leItemCLI = new QLineEdit(ReportTab3);
        leItemCLI->setObjectName(QString::fromUtf8("leItemCLI"));
        leItemCLI->setMinimumSize(QSize(160, 0));
        leItemCLI->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_15->addWidget(leItemCLI);

        label_35 = new QLabel(ReportTab3);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        horizontalLayout_15->addWidget(label_35);

        deFromCLI = new QDateEdit(ReportTab3);
        deFromCLI->setObjectName(QString::fromUtf8("deFromCLI"));
        deFromCLI->setMinimumSize(QSize(150, 0));
        deFromCLI->setMaximumSize(QSize(120, 16777215));
        deFromCLI->setTime(QTime(0, 0, 0));
        deFromCLI->setCalendarPopup(true);

        horizontalLayout_15->addWidget(deFromCLI);

        label_36 = new QLabel(ReportTab3);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        horizontalLayout_15->addWidget(label_36);

        deToCLI = new QDateEdit(ReportTab3);
        deToCLI->setObjectName(QString::fromUtf8("deToCLI"));
        deToCLI->setMinimumSize(QSize(150, 0));
        deToCLI->setMaximumSize(QSize(120, 16777215));
        deToCLI->setCalendarPopup(true);

        horizontalLayout_15->addWidget(deToCLI);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_8);

        pbQueryCLI = new QPushButton(ReportTab3);
        pbQueryCLI->setObjectName(QString::fromUtf8("pbQueryCLI"));
        pbQueryCLI->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_15->addWidget(pbQueryCLI);

        pbPrintCLI = new QPushButton(ReportTab3);
        pbPrintCLI->setObjectName(QString::fromUtf8("pbPrintCLI"));
        pbPrintCLI->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_15->addWidget(pbPrintCLI);


        gridLayout_11->addLayout(horizontalLayout_15, 0, 0, 1, 1);

        tvCustLiftingCLI = new QTableView(ReportTab3);
        tvCustLiftingCLI->setObjectName(QString::fromUtf8("tvCustLiftingCLI"));
        tvCustLiftingCLI->setAlternatingRowColors(true);

        gridLayout_11->addWidget(tvCustLiftingCLI, 1, 0, 1, 1);

        tabWidget->addTab(ReportTab3, QString());
        ReportTab4 = new QWidget();
        ReportTab4->setObjectName(QString::fromUtf8("ReportTab4"));
        gridLayout_9 = new QGridLayout(ReportTab4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        frame_5 = new QFrame(ReportTab4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setEnabled(true);
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_15 = new QGridLayout(frame_5);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        label_31 = new QLabel(frame_5);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setMinimumSize(QSize(100, 25));

        horizontalLayout_29->addWidget(label_31);

        leTransporterD = new QLineEdit(frame_5);
        leTransporterD->setObjectName(QString::fromUtf8("leTransporterD"));
        leTransporterD->setMinimumSize(QSize(220, 26));
        leTransporterD->setMaximumSize(QSize(300, 26));
        leTransporterD->setBaseSize(QSize(220, 34));

        horizontalLayout_29->addWidget(leTransporterD);

        label_32 = new QLabel(frame_5);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_29->addWidget(label_32);

        deFromTBD = new QDateEdit(frame_5);
        deFromTBD->setObjectName(QString::fromUtf8("deFromTBD"));
        deFromTBD->setMinimumSize(QSize(150, 0));
        deFromTBD->setTime(QTime(0, 0, 0));
        deFromTBD->setCalendarPopup(true);

        horizontalLayout_29->addWidget(deFromTBD);

        label_33 = new QLabel(frame_5);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        horizontalLayout_29->addWidget(label_33);

        deToTBD = new QDateEdit(frame_5);
        deToTBD->setObjectName(QString::fromUtf8("deToTBD"));
        deToTBD->setMinimumSize(QSize(150, 0));
        deToTBD->setCalendarPopup(true);

        horizontalLayout_29->addWidget(deToTBD);

        horizontalSpacer_17 = new QSpacerItem(244, 33, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_17);

        pbQueryTBD = new QPushButton(frame_5);
        pbQueryTBD->setObjectName(QString::fromUtf8("pbQueryTBD"));

        horizontalLayout_29->addWidget(pbQueryTBD);

        pbPrintTBD = new QPushButton(frame_5);
        pbPrintTBD->setObjectName(QString::fromUtf8("pbPrintTBD"));

        horizontalLayout_29->addWidget(pbPrintTBD);


        gridLayout_15->addLayout(horizontalLayout_29, 0, 0, 1, 1);


        gridLayout_9->addWidget(frame_5, 0, 0, 1, 1);

        tvTransLiftD = new QTableView(ReportTab4);
        tvTransLiftD->setObjectName(QString::fromUtf8("tvTransLiftD"));

        gridLayout_9->addWidget(tvTransLiftD, 1, 0, 1, 1);

        tabWidget->addTab(ReportTab4, QString());
        ReportTab5 = new QWidget();
        ReportTab5->setObjectName(QString::fromUtf8("ReportTab5"));
        gridLayout_10 = new QGridLayout(ReportTab5);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_37 = new QLabel(ReportTab5);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        horizontalLayout_16->addWidget(label_37);

        leTransporterTDI = new QLineEdit(ReportTab5);
        leTransporterTDI->setObjectName(QString::fromUtf8("leTransporterTDI"));
        leTransporterTDI->setMinimumSize(QSize(220, 34));
        leTransporterTDI->setMaximumSize(QSize(300, 34));
        leTransporterTDI->setBaseSize(QSize(220, 34));

        horizontalLayout_16->addWidget(leTransporterTDI);

        label_26 = new QLabel(ReportTab5);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_16->addWidget(label_26);

        leItemTDI = new QLineEdit(ReportTab5);
        leItemTDI->setObjectName(QString::fromUtf8("leItemTDI"));
        leItemTDI->setMinimumSize(QSize(120, 0));
        leItemTDI->setMaximumSize(QSize(250, 34));

        horizontalLayout_16->addWidget(leItemTDI);

        label_38 = new QLabel(ReportTab5);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        horizontalLayout_16->addWidget(label_38);

        deFromTDI = new QDateEdit(ReportTab5);
        deFromTDI->setObjectName(QString::fromUtf8("deFromTDI"));
        deFromTDI->setMinimumSize(QSize(150, 0));
        deFromTDI->setMaximumSize(QSize(120, 16777215));
        deFromTDI->setTime(QTime(0, 0, 0));
        deFromTDI->setCalendarPopup(true);

        horizontalLayout_16->addWidget(deFromTDI);

        label_39 = new QLabel(ReportTab5);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        horizontalLayout_16->addWidget(label_39);

        deToTDI = new QDateEdit(ReportTab5);
        deToTDI->setObjectName(QString::fromUtf8("deToTDI"));
        deToTDI->setMinimumSize(QSize(150, 0));
        deToTDI->setMaximumSize(QSize(120, 16777215));
        deToTDI->setCalendarPopup(true);

        horizontalLayout_16->addWidget(deToTDI);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_9);

        pbQueryTDI = new QPushButton(ReportTab5);
        pbQueryTDI->setObjectName(QString::fromUtf8("pbQueryTDI"));
        pbQueryTDI->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_16->addWidget(pbQueryTDI);

        pbPrintTDI = new QPushButton(ReportTab5);
        pbPrintTDI->setObjectName(QString::fromUtf8("pbPrintTDI"));
        pbPrintTDI->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_16->addWidget(pbPrintTDI);


        gridLayout_10->addLayout(horizontalLayout_16, 0, 0, 1, 1);

        tvTransLiftingTDI = new QTableView(ReportTab5);
        tvTransLiftingTDI->setObjectName(QString::fromUtf8("tvTransLiftingTDI"));
        tvTransLiftingTDI->setAlternatingRowColors(true);

        gridLayout_10->addWidget(tvTransLiftingTDI, 1, 0, 1, 1);

        tabWidget->addTab(ReportTab5, QString());
        ReportTab6 = new QWidget();
        ReportTab6->setObjectName(QString::fromUtf8("ReportTab6"));
        gridLayout_19 = new QGridLayout(ReportTab6);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        frame_6 = new QFrame(ReportTab6);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setEnabled(true);
        frame_6->setAutoFillBackground(false);
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_18 = new QGridLayout(frame_6);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        label_40 = new QLabel(frame_6);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        horizontalLayout_30->addWidget(label_40);

        leCustomerCLS = new QLineEdit(frame_6);
        leCustomerCLS->setObjectName(QString::fromUtf8("leCustomerCLS"));
        leCustomerCLS->setMinimumSize(QSize(240, 0));
        leCustomerCLS->setMaximumSize(QSize(240, 16777215));
        leCustomerCLS->setBaseSize(QSize(240, 34));

        horizontalLayout_30->addWidget(leCustomerCLS);

        label_41 = new QLabel(frame_6);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_30->addWidget(label_41);

        deFromCLS = new QDateEdit(frame_6);
        deFromCLS->setObjectName(QString::fromUtf8("deFromCLS"));
        deFromCLS->setMinimumSize(QSize(150, 0));
        deFromCLS->setTime(QTime(0, 0, 0));
        deFromCLS->setCalendarPopup(true);

        horizontalLayout_30->addWidget(deFromCLS);

        label_42 = new QLabel(frame_6);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        horizontalLayout_30->addWidget(label_42);

        deToCLS = new QDateEdit(frame_6);
        deToCLS->setObjectName(QString::fromUtf8("deToCLS"));
        deToCLS->setMinimumSize(QSize(150, 0));
        deToCLS->setCalendarPopup(true);

        horizontalLayout_30->addWidget(deToCLS);

        horizontalSpacer_18 = new QSpacerItem(244, 33, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_18);

        pbQueryCLS = new QPushButton(frame_6);
        pbQueryCLS->setObjectName(QString::fromUtf8("pbQueryCLS"));

        horizontalLayout_30->addWidget(pbQueryCLS);

        pbPrintCLS = new QPushButton(frame_6);
        pbPrintCLS->setObjectName(QString::fromUtf8("pbPrintCLS"));

        horizontalLayout_30->addWidget(pbPrintCLS);


        gridLayout_18->addLayout(horizontalLayout_30, 0, 0, 1, 1);


        verticalLayout_6->addWidget(frame_6);

        tvCustLiftingSum = new QTableView(ReportTab6);
        tvCustLiftingSum->setObjectName(QString::fromUtf8("tvCustLiftingSum"));

        verticalLayout_6->addWidget(tvCustLiftingSum);


        gridLayout_19->addLayout(verticalLayout_6, 0, 0, 1, 1);

        tabWidget->addTab(ReportTab6, QString());
        SalesReport = new QWidget();
        SalesReport->setObjectName(QString::fromUtf8("SalesReport"));
        gridLayout_22 = new QGridLayout(SalesReport);
        gridLayout_22->setSpacing(6);
        gridLayout_22->setContentsMargins(11, 11, 11, 11);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_21 = new QGridLayout();
        gridLayout_21->setSpacing(6);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        frame_7 = new QFrame(SalesReport);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setEnabled(true);
        frame_7->setAutoFillBackground(false);
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_20 = new QGridLayout(frame_7);
        gridLayout_20->setSpacing(6);
        gridLayout_20->setContentsMargins(11, 11, 11, 11);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        label_44 = new QLabel(frame_7);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        horizontalLayout_31->addWidget(label_44);

        deFromSR = new QDateEdit(frame_7);
        deFromSR->setObjectName(QString::fromUtf8("deFromSR"));
        deFromSR->setMinimumSize(QSize(150, 0));
        deFromSR->setTime(QTime(0, 0, 0));
        deFromSR->setCalendarPopup(true);

        horizontalLayout_31->addWidget(deFromSR);

        label_45 = new QLabel(frame_7);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        horizontalLayout_31->addWidget(label_45);

        deToSR = new QDateEdit(frame_7);
        deToSR->setObjectName(QString::fromUtf8("deToSR"));
        deToSR->setMinimumSize(QSize(150, 0));
        deToSR->setCalendarPopup(true);

        horizontalLayout_31->addWidget(deToSR);

        horizontalSpacer_19 = new QSpacerItem(244, 33, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_19);

        pbQuerySR = new QPushButton(frame_7);
        pbQuerySR->setObjectName(QString::fromUtf8("pbQuerySR"));

        horizontalLayout_31->addWidget(pbQuerySR);

        pbPrintSR = new QPushButton(frame_7);
        pbPrintSR->setObjectName(QString::fromUtf8("pbPrintSR"));

        horizontalLayout_31->addWidget(pbPrintSR);


        gridLayout_20->addLayout(horizontalLayout_31, 0, 0, 1, 1);


        gridLayout_21->addWidget(frame_7, 0, 0, 1, 1);

        tvSalesRep = new QTableView(SalesReport);
        tvSalesRep->setObjectName(QString::fromUtf8("tvSalesRep"));

        gridLayout_21->addWidget(tvSalesRep, 1, 0, 1, 1);


        gridLayout_22->addLayout(gridLayout_21, 0, 0, 1, 1);

        tabWidget->addTab(SalesReport, QString());
        ItemsDetailTab = new QWidget();
        ItemsDetailTab->setObjectName(QString::fromUtf8("ItemsDetailTab"));
        gridLayout_26 = new QGridLayout(ItemsDetailTab);
        gridLayout_26->setSpacing(6);
        gridLayout_26->setContentsMargins(11, 11, 11, 11);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        frame_9 = new QFrame(ItemsDetailTab);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setEnabled(true);
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        gridLayout_25 = new QGridLayout(frame_9);
        gridLayout_25->setSpacing(6);
        gridLayout_25->setContentsMargins(11, 11, 11, 11);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        label_15 = new QLabel(frame_9);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_33->addWidget(label_15);

        leItemILD = new QLineEdit(frame_9);
        leItemILD->setObjectName(QString::fromUtf8("leItemILD"));
        leItemILD->setMinimumSize(QSize(200, 0));

        horizontalLayout_33->addWidget(leItemILD);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_14);

        label_49 = new QLabel(frame_9);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        horizontalLayout_33->addWidget(label_49);

        deFromILD = new QDateEdit(frame_9);
        deFromILD->setObjectName(QString::fromUtf8("deFromILD"));
        deFromILD->setMinimumSize(QSize(150, 0));
        deFromILD->setTime(QTime(0, 0, 0));
        deFromILD->setCalendarPopup(true);

        horizontalLayout_33->addWidget(deFromILD);

        label_50 = new QLabel(frame_9);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        horizontalLayout_33->addWidget(label_50);

        deToILD = new QDateEdit(frame_9);
        deToILD->setObjectName(QString::fromUtf8("deToILD"));
        deToILD->setMinimumSize(QSize(150, 0));
        deToILD->setCalendarPopup(true);

        horizontalLayout_33->addWidget(deToILD);

        horizontalSpacer_21 = new QSpacerItem(244, 33, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_21);

        pbQueryILD = new QPushButton(frame_9);
        pbQueryILD->setObjectName(QString::fromUtf8("pbQueryILD"));

        horizontalLayout_33->addWidget(pbQueryILD);

        pbPrintILD = new QPushButton(frame_9);
        pbPrintILD->setObjectName(QString::fromUtf8("pbPrintILD"));

        horizontalLayout_33->addWidget(pbPrintILD);


        gridLayout_25->addLayout(horizontalLayout_33, 0, 0, 1, 1);


        gridLayout_26->addWidget(frame_9, 0, 0, 1, 1);

        tvItemLiftD = new QTableView(ItemsDetailTab);
        tvItemLiftD->setObjectName(QString::fromUtf8("tvItemLiftD"));

        gridLayout_26->addWidget(tvItemLiftD, 1, 0, 1, 1);

        tabWidget->addTab(ItemsDetailTab, QString());
        ItemsSummaryTab = new QWidget();
        ItemsSummaryTab->setObjectName(QString::fromUtf8("ItemsSummaryTab"));
        gridLayout_24 = new QGridLayout(ItemsSummaryTab);
        gridLayout_24->setSpacing(6);
        gridLayout_24->setContentsMargins(11, 11, 11, 11);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        frame_8 = new QFrame(ItemsSummaryTab);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setEnabled(true);
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        gridLayout_23 = new QGridLayout(frame_8);
        gridLayout_23->setSpacing(6);
        gridLayout_23->setContentsMargins(11, 11, 11, 11);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        label_46 = new QLabel(frame_8);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        horizontalLayout_32->addWidget(label_46);

        deFromIS = new QDateEdit(frame_8);
        deFromIS->setObjectName(QString::fromUtf8("deFromIS"));
        deFromIS->setMinimumSize(QSize(150, 0));
        deFromIS->setTime(QTime(0, 0, 0));
        deFromIS->setCalendarPopup(true);

        horizontalLayout_32->addWidget(deFromIS);

        label_47 = new QLabel(frame_8);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        horizontalLayout_32->addWidget(label_47);

        deToIS = new QDateEdit(frame_8);
        deToIS->setObjectName(QString::fromUtf8("deToIS"));
        deToIS->setMinimumSize(QSize(150, 0));
        deToIS->setCalendarPopup(true);

        horizontalLayout_32->addWidget(deToIS);

        rbSales = new QRadioButton(frame_8);
        rbSales->setObjectName(QString::fromUtf8("rbSales"));

        horizontalLayout_32->addWidget(rbSales);

        horizontalSpacer_20 = new QSpacerItem(244, 33, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_20);

        pbQueryIS = new QPushButton(frame_8);
        pbQueryIS->setObjectName(QString::fromUtf8("pbQueryIS"));

        horizontalLayout_32->addWidget(pbQueryIS);

        pbPrintIS = new QPushButton(frame_8);
        pbPrintIS->setObjectName(QString::fromUtf8("pbPrintIS"));

        horizontalLayout_32->addWidget(pbPrintIS);


        gridLayout_23->addLayout(horizontalLayout_32, 0, 0, 1, 1);


        gridLayout_24->addWidget(frame_8, 0, 0, 1, 1);

        tvItemLiftIS = new QTableView(ItemsSummaryTab);
        tvItemLiftIS->setObjectName(QString::fromUtf8("tvItemLiftIS"));

        gridLayout_24->addWidget(tvItemLiftIS, 1, 0, 1, 1);

        tabWidget->addTab(ItemsSummaryTab, QString());
        HelpTab = new QWidget();
        HelpTab->setObjectName(QString::fromUtf8("HelpTab"));
        gridLayout_27 = new QGridLayout(HelpTab);
        gridLayout_27->setSpacing(6);
        gridLayout_27->setContentsMargins(11, 11, 11, 11);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        splitter_2 = new QSplitter(HelpTab);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        twHelp = new QTabWidget(splitter_2);
        twHelp->setObjectName(QString::fromUtf8("twHelp"));
        twHelp->setMaximumSize(QSize(300, 16777215));
        ContentsTab = new QWidget();
        ContentsTab->setObjectName(QString::fromUtf8("ContentsTab"));
        scrollArea = new QScrollArea(ContentsTab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(830, 300, 120, 80));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 118, 78));
        scrollArea->setWidget(scrollAreaWidgetContents);
        twHelp->addTab(ContentsTab, QString());
        IndexTab = new QWidget();
        IndexTab->setObjectName(QString::fromUtf8("IndexTab"));
        twHelp->addTab(IndexTab, QString());
        splitter_2->addWidget(twHelp);

        gridLayout_27->addWidget(splitter_2, 0, 0, 1, 1);

        tabWidget->addTab(HelpTab, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_30 = new QGridLayout(tab);
        gridLayout_30->setSpacing(6);
        gridLayout_30->setContentsMargins(11, 11, 11, 11);
        gridLayout_30->setObjectName(QString::fromUtf8("gridLayout_30"));
        gridLayout_28 = new QGridLayout();
        gridLayout_28->setSpacing(6);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        frame_10 = new QFrame(tab);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setEnabled(true);
        frame_10->setAutoFillBackground(false);
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        gridLayout_29 = new QGridLayout(frame_10);
        gridLayout_29->setSpacing(6);
        gridLayout_29->setContentsMargins(11, 11, 11, 11);
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        label_48 = new QLabel(frame_10);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        horizontalLayout_34->addWidget(label_48);

        deFromSRS = new QDateEdit(frame_10);
        deFromSRS->setObjectName(QString::fromUtf8("deFromSRS"));
        deFromSRS->setMinimumSize(QSize(150, 0));
        deFromSRS->setTime(QTime(0, 0, 0));
        deFromSRS->setCalendarPopup(true);

        horizontalLayout_34->addWidget(deFromSRS);

        label_51 = new QLabel(frame_10);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setMinimumSize(QSize(0, 0));

        horizontalLayout_34->addWidget(label_51);

        deToSRS = new QDateEdit(frame_10);
        deToSRS->setObjectName(QString::fromUtf8("deToSRS"));
        deToSRS->setMinimumSize(QSize(150, 0));
        deToSRS->setCalendarPopup(true);

        horizontalLayout_34->addWidget(deToSRS);

        horizontalSpacer_22 = new QSpacerItem(244, 33, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_34->addItem(horizontalSpacer_22);

        pbQuerySRS = new QPushButton(frame_10);
        pbQuerySRS->setObjectName(QString::fromUtf8("pbQuerySRS"));

        horizontalLayout_34->addWidget(pbQuerySRS);

        pbPrintSRS = new QPushButton(frame_10);
        pbPrintSRS->setObjectName(QString::fromUtf8("pbPrintSRS"));

        horizontalLayout_34->addWidget(pbPrintSRS);


        gridLayout_29->addLayout(horizontalLayout_34, 0, 0, 1, 1);


        gridLayout_28->addWidget(frame_10, 0, 0, 1, 1);

        tvSalesRepSum = new QTableView(tab);
        tvSalesRepSum->setObjectName(QString::fromUtf8("tvSalesRepSum"));

        gridLayout_28->addWidget(tvSalesRepSum, 1, 0, 1, 1);


        gridLayout_30->addLayout(gridLayout_28, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1162, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuImport = new QMenu(menuFile);
        menuImport->setObjectName(QString::fromUtf8("menuImport"));
        menuSetup = new QMenu(menuBar);
        menuSetup->setObjectName(QString::fromUtf8("menuSetup"));
        menuReports = new QMenu(menuBar);
        menuReports->setObjectName(QString::fromUtf8("menuReports"));
        menuCustomers = new QMenu(menuReports);
        menuCustomers->setObjectName(QString::fromUtf8("menuCustomers"));
        menuTransporter = new QMenu(menuReports);
        menuTransporter->setObjectName(QString::fromUtf8("menuTransporter"));
        menuItems = new QMenu(menuReports);
        menuItems->setObjectName(QString::fromUtf8("menuItems"));
        menuSales_Report = new QMenu(menuReports);
        menuSales_Report->setObjectName(QString::fromUtf8("menuSales_Report"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(tvTicket, leVehicule);
        QWidget::setTabOrder(leVehicule, leCustomer);
        QWidget::setTabOrder(leCustomer, leTransporter);
        QWidget::setTabOrder(leTransporter, leDriver);
        QWidget::setTabOrder(leDriver, leRemark);
        QWidget::setTabOrder(leRemark, rb0);
        QWidget::setTabOrder(rb0, rb1);
        QWidget::setTabOrder(rb1, rb2);
        QWidget::setTabOrder(rb2, rb3);
        QWidget::setTabOrder(rb3, rb4);
        QWidget::setTabOrder(rb4, rb5);
        QWidget::setTabOrder(rb5, rb6);
        QWidget::setTabOrder(rb6, rb7);
        QWidget::setTabOrder(rb7, rb8);
        QWidget::setTabOrder(rb8, rb9);
        QWidget::setTabOrder(rb9, pbWeigh);
        QWidget::setTabOrder(pbWeigh, pbClearTransaction);
        QWidget::setTabOrder(pbClearTransaction, tvResult);
        QWidget::setTabOrder(tvResult, leCustomer1);
        QWidget::setTabOrder(leCustomer1, leMaterial);
        QWidget::setTabOrder(leMaterial, leVehicule1);
        QWidget::setTabOrder(leVehicule1, leTransporter1);
        QWidget::setTabOrder(leTransporter1, leDriver1);
        QWidget::setTabOrder(leDriver1, deStartTime);
        QWidget::setTabOrder(deStartTime, deEndTime);
        QWidget::setTabOrder(deEndTime, pbSearch);
        QWidget::setTabOrder(pbSearch, pbClear);
        QWidget::setTabOrder(pbClear, pbExport);
        QWidget::setTabOrder(pbExport, pbPrintTicket);
        QWidget::setTabOrder(pbPrintTicket, pbAddOperator);
        QWidget::setTabOrder(pbAddOperator, pbModifyOperator);
        QWidget::setTabOrder(pbModifyOperator, pbDeleteOperator);
        QWidget::setTabOrder(pbDeleteOperator, tvOperators);
        QWidget::setTabOrder(tvOperators, pbAddCustomer);
        QWidget::setTabOrder(pbAddCustomer, pbModifyCustomer);
        QWidget::setTabOrder(pbModifyCustomer, pbDeleteCustomer);
        QWidget::setTabOrder(pbDeleteCustomer, pbPrintCustomers);
        QWidget::setTabOrder(pbPrintCustomers, tvCustomers);
        QWidget::setTabOrder(tvCustomers, pbAddItem);
        QWidget::setTabOrder(pbAddItem, pbModifyItem);
        QWidget::setTabOrder(pbModifyItem, pbDeleteItem);
        QWidget::setTabOrder(pbDeleteItem, pbPrintItems);
        QWidget::setTabOrder(pbPrintItems, tvItems);
        QWidget::setTabOrder(tvItems, pbAddPriceList);
        QWidget::setTabOrder(pbAddPriceList, pbModifyPriceList);
        QWidget::setTabOrder(pbModifyPriceList, pbDeletePriceList);
        QWidget::setTabOrder(pbDeletePriceList, pbPrintPriceList);
        QWidget::setTabOrder(pbPrintPriceList, tvLists);
        QWidget::setTabOrder(tvLists, tvPriceList);
        QWidget::setTabOrder(tvPriceList, deDate);
        QWidget::setTabOrder(deDate, pbPrint);
        QWidget::setTabOrder(pbPrint, tvReport);
        QWidget::setTabOrder(tvReport, leCustomerLR);
        QWidget::setTabOrder(leCustomerLR, deFrom);
        QWidget::setTabOrder(deFrom, deTo);
        QWidget::setTabOrder(deTo, pbQuery);
        QWidget::setTabOrder(pbQuery, pbPrintCL);
        QWidget::setTabOrder(pbPrintCL, tvCustLifting);
        QWidget::setTabOrder(tvCustLifting, leCustomerCLI);
        QWidget::setTabOrder(leCustomerCLI, leItemCLI);
        QWidget::setTabOrder(leItemCLI, deFromCLI);
        QWidget::setTabOrder(deFromCLI, deToCLI);
        QWidget::setTabOrder(deToCLI, pbQueryCLI);
        QWidget::setTabOrder(pbQueryCLI, pbPrintCLI);
        QWidget::setTabOrder(pbPrintCLI, tvCustLiftingCLI);
        QWidget::setTabOrder(tvCustLiftingCLI, leTransporterD);
        QWidget::setTabOrder(leTransporterD, deFromTBD);
        QWidget::setTabOrder(deFromTBD, deToTBD);
        QWidget::setTabOrder(deToTBD, pbQueryTBD);
        QWidget::setTabOrder(pbQueryTBD, pbPrintTBD);
        QWidget::setTabOrder(pbPrintTBD, tvTransLiftD);
        QWidget::setTabOrder(tvTransLiftD, leTransporterTDI);
        QWidget::setTabOrder(leTransporterTDI, leItemTDI);
        QWidget::setTabOrder(leItemTDI, deFromTDI);
        QWidget::setTabOrder(deFromTDI, deToTDI);
        QWidget::setTabOrder(deToTDI, pbQueryTDI);
        QWidget::setTabOrder(pbQueryTDI, pbPrintTDI);
        QWidget::setTabOrder(pbPrintTDI, tvTransLiftingTDI);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSetup->menuAction());
        menuBar->addAction(menuReports->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLogin);
        menuFile->addSeparator();
        menuFile->addAction(menuImport->menuAction());
        menuFile->addAction(actionServer);
        menuFile->addSeparator();
        menuFile->addAction(actionBackup);
        menuFile->addAction(actionRestore);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuImport->addAction(actionCustomersImport);
        menuImport->addAction(actionTransactionsImport);
        menuSetup->addAction(actionOperators);
        menuSetup->addAction(actionCustomers);
        menuSetup->addAction(actionItems);
        menuSetup->addSeparator();
        menuSetup->addAction(actionSerial_Port);
        menuReports->addAction(actionDaily_Report);
        menuReports->addAction(menuSales_Report->menuAction());
        menuReports->addSeparator();
        menuReports->addAction(menuCustomers->menuAction());
        menuReports->addAction(menuTransporter->menuAction());
        menuReports->addAction(menuItems->menuAction());
        menuReports->addSeparator();
        menuReports->addAction(actionReport_Designer);
        menuCustomers->addAction(actionLifting_Report);
        menuCustomers->addAction(actionLifting_By_Customer_Summary);
        menuCustomers->addAction(actionLifting_By_Item);
        menuTransporter->addAction(actionTrans_By_Date);
        menuTransporter->addAction(actionTransporter_By_Material);
        menuTransporter->addAction(actionBy_Customer);
        menuItems->addAction(actionItem_By_Date_Detailed);
        menuItems->addAction(actionItem_By_Date_Summary);
        menuSales_Report->addAction(actionSalesDetailed);
        menuSales_Report->addAction(actionSalesSummary);
        menuHelp->addAction(actionContents);
        menuHelp->addAction(actionIndex);
        menuHelp->addSeparator();
        menuHelp->addAction(actionWhatisThis);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        pbWeigh->setDefault(false);
        pbClearTransaction->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Weighbrigde Management System", nullptr));
        actionLogin->setText(QApplication::translate("MainWindow", "&Login", nullptr));
        actionOperators->setText(QApplication::translate("MainWindow", "&Operators", nullptr));
        actionCustomersImport->setText(QApplication::translate("MainWindow", "&Customers ", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCustomersImport->setToolTip(QApplication::translate("MainWindow", "Customers List Import", nullptr));
#endif // QT_NO_TOOLTIP
        actionTransactionsImport->setText(QApplication::translate("MainWindow", "&Transactions", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "&Exit", nullptr));
        actionSerial_Port->setText(QApplication::translate("MainWindow", "&Serial Port", nullptr));
        actionCustomers->setText(QApplication::translate("MainWindow", "&Customers", nullptr));
        actionItems->setText(QApplication::translate("MainWindow", "&Items", nullptr));
        actionDaily_Report->setText(QApplication::translate("MainWindow", "&Today's Report", nullptr));
#ifndef QT_NO_STATUSTIP
        actionDaily_Report->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionDaily_Report->setWhatsThis(QApplication::translate("MainWindow", "Report for all transactions for the current day", nullptr));
#endif // QT_NO_WHATSTHIS
        actionLifting_Report->setText(QApplication::translate("MainWindow", "&Lifting By Customer Detailed", nullptr));
        actionLifting_By_Item->setText(QApplication::translate("MainWindow", "Lifting &By Item", nullptr));
        actionPrice_Lists->setText(QApplication::translate("MainWindow", "&Price Lists", nullptr));
        actionTrans_By_Date->setText(QApplication::translate("MainWindow", "&By Date", nullptr));
        actionBy_Customer->setText(QApplication::translate("MainWindow", "By &Customer", nullptr));
        actionTransporter_By_Material->setText(QApplication::translate("MainWindow", "By &Material", nullptr));
        actionLifting_By_Customer_Summary->setText(QApplication::translate("MainWindow", "Lifting By &Customer Summary", nullptr));
        actionItem_By_Date_Detailed->setText(QApplication::translate("MainWindow", "&By Date (Detailed)", nullptr));
        actionItem_By_Date_Summary->setText(QApplication::translate("MainWindow", "By &Date (Summary)", nullptr));
        actionContents->setText(QApplication::translate("MainWindow", "&Contents", nullptr));
        actionIndex->setText(QApplication::translate("MainWindow", "&Index", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", nullptr));
        actionServer->setText(QApplication::translate("MainWindow", "&Server Setup", nullptr));
        actionSales_Report_Summary->setText(QApplication::translate("MainWindow", "Sales Report Summary", nullptr));
        actionSalesDetailed->setText(QApplication::translate("MainWindow", "&Detailed", nullptr));
        actionSalesSummary->setText(QApplication::translate("MainWindow", "&Summary", nullptr));
        actionBackup->setText(QApplication::translate("MainWindow", "&Backup", nullptr));
        actionRestore->setText(QApplication::translate("MainWindow", "&Restore", nullptr));
        actionReport_Designer->setText(QApplication::translate("MainWindow", "Report &Designer", nullptr));
        actionWhatisThis->setText(QApplication::translate("MainWindow", "&WhatsThis", nullptr));
#ifndef QT_NO_TOOLTIP
        tvTicket->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tvTicket->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">This is the list of vehicules inside the yard waiting to load or offload. Just double click on the corresponding entry to weigh the vehicule a second time.</span></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Vehicule:</span></p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        leVehicule->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Vehicule Identification Number</span></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Customer:</span></p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        leCustomer->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Customer Name</span></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Transporter:</span></p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        leTransporter->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Transporter Name</span></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Driver :</span></p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        leDriver->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Driver Name</span></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Remark:</p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        leRemark->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Notes about the transaction</span></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        gbButtons->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Item to weigh</span></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        gbButtons->setTitle(QApplication::translate("MainWindow", "Material", nullptr));
        rb0->setText(QApplication::translate("MainWindow", "Item&1", nullptr));
        rb1->setText(QApplication::translate("MainWindow", "Item&2", nullptr));
        rb2->setText(QApplication::translate("MainWindow", "Item&3", nullptr));
        rb3->setText(QApplication::translate("MainWindow", "Item&4", nullptr));
        rb4->setText(QApplication::translate("MainWindow", "Item&5", nullptr));
        rb5->setText(QApplication::translate("MainWindow", "Item&6", nullptr));
        rb6->setText(QApplication::translate("MainWindow", "Item&7", nullptr));
        rb7->setText(QApplication::translate("MainWindow", "Item&8", nullptr));
        rb8->setText(QApplication::translate("MainWindow", "Item&9", nullptr));
        rb9->setText(QString());
#ifndef QT_NO_WHATSTHIS
        pbWeigh->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>Pressing on this button will register the weigh of the current vehicule.</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        pbWeigh->setText(QApplication::translate("MainWindow", "Register", nullptr));
#ifndef QT_NO_WHATSTHIS
        pbClearTransaction->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Clear the transaction fields</span></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        pbClearTransaction->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Weightab), QApplication::translate("MainWindow", "Weigh", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Time Period          ", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "From:", nullptr));
#ifndef QT_NO_TOOLTIP
        deStartTime->setToolTip(QApplication::translate("MainWindow", "Starting Date for search", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        deStartTime->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_6->setText(QApplication::translate("MainWindow", "To:", nullptr));
        pbSearch->setText(QApplication::translate("MainWindow", "Search", nullptr));
        pbClear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        pbExport->setText(QApplication::translate("MainWindow", "Export", nullptr));
        pbPrintTicket->setText(QApplication::translate("MainWindow", "Print Ticket", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Customer:</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        leCustomer1->setToolTip(QApplication::translate("MainWindow", "Customer to search for", nullptr));
#endif // QT_NO_TOOLTIP
        label_11->setText(QApplication::translate("MainWindow", "Material:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Vehicule:</span></p></body></html>", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Transporter:</span></p></body></html>", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Driver :</span></p></body></html>", nullptr));
        lresult->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(SearchTab), QApplication::translate("MainWindow", "Search", nullptr));
        pbAddOperator->setText(QApplication::translate("MainWindow", "Add", nullptr));
        pbModifyOperator->setText(QApplication::translate("MainWindow", "Modify Password", nullptr));
        pbDeleteOperator->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(OperatorsTab), QApplication::translate("MainWindow", "Operators List", nullptr));
        pbAddCustomer->setText(QApplication::translate("MainWindow", "Add", nullptr));
        pbModifyCustomer->setText(QApplication::translate("MainWindow", "Modify", nullptr));
        pbDeleteCustomer->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        pbPrintCustomers->setText(QApplication::translate("MainWindow", "Print", nullptr));
        label_43->setText(QApplication::translate("MainWindow", "Name :", nullptr));
        label_52->setText(QApplication::translate("MainWindow", "Phone 1:", nullptr));
        label_53->setText(QApplication::translate("MainWindow", "Phone 2:", nullptr));
        label_54->setText(QApplication::translate("MainWindow", "Full Name: ", nullptr));
        label_55->setText(QApplication::translate("MainWindow", "Email:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(CustomersTab), QApplication::translate("MainWindow", "Customers List", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Item Information", nullptr));
        label_60->setText(QApplication::translate("MainWindow", "Short Description : ", nullptr));
        label_59->setText(QApplication::translate("MainWindow", "Long Description : ", nullptr));
        rbSale->setText(QApplication::translate("MainWindow", "S&ales Item", nullptr));
        label_57->setText(QApplication::translate("MainWindow", "Last Transaction", nullptr));
        label_58->setText(QApplication::translate("MainWindow", "Date:", nullptr));
        lDate->setText(QString());
        label_61->setText(QApplication::translate("MainWindow", "Quantity:", nullptr));
        lQuantity->setText(QString());
        label_62->setText(QApplication::translate("MainWindow", "Customer:", nullptr));
        lCustomer->setText(QString());
        label_63->setText(QApplication::translate("MainWindow", "Vehicule:", nullptr));
        lVehicule->setText(QString());
        label_64->setText(QApplication::translate("MainWindow", "Quantities Lifted ", nullptr));
        label_65->setText(QApplication::translate("MainWindow", "Current Week", nullptr));
        lcurW->setText(QString());
        label_66->setText(QApplication::translate("MainWindow", "Current Month", nullptr));
        lcurM->setText(QString());
        label_67->setText(QApplication::translate("MainWindow", "Current Year", nullptr));
        lcurY->setText(QString());
        commandLinkButton->setText(QApplication::translate("MainWindow", "CommandLinkButton", nullptr));
        pbAddItem->setText(QApplication::translate("MainWindow", "Add", nullptr));
        pbModifyItem->setText(QApplication::translate("MainWindow", "Modify", nullptr));
        pbDeleteItem->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        pbPrintItems->setText(QApplication::translate("MainWindow", "Print", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ItemsTab), QApplication::translate("MainWindow", "Items List", nullptr));
        pbAddPriceList->setText(QApplication::translate("MainWindow", "Add", nullptr));
        pbModifyPriceList->setText(QApplication::translate("MainWindow", "Modify", nullptr));
        pbDeletePriceList->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        pbPrintPriceList->setText(QApplication::translate("MainWindow", "Print", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(PriceListTab), QApplication::translate("MainWindow", "Price Lists", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Date:", nullptr));
        deDate->setDisplayFormat(QApplication::translate("MainWindow", "MMM, dd yyyy", nullptr));
        pbPrint->setText(QApplication::translate("MainWindow", "Print", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ReportTab1), QApplication::translate("MainWindow", "Daily Report", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "Customer: ", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "From:", nullptr));
        deFrom->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "          To: ", nullptr));
        deTo->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        pbQuery->setText(QApplication::translate("MainWindow", "Query", nullptr));
        pbPrintCL->setText(QApplication::translate("MainWindow", "Print", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ReportTab2), QApplication::translate("MainWindow", "Customer's Liftings", nullptr));
        label_34->setText(QApplication::translate("MainWindow", "Customer: ", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "Item:", nullptr));
        label_35->setText(QApplication::translate("MainWindow", "From:", nullptr));
        deFromCLI->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        label_36->setText(QApplication::translate("MainWindow", "          To: ", nullptr));
        deToCLI->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        pbQueryCLI->setText(QApplication::translate("MainWindow", "Query", nullptr));
        pbPrintCLI->setText(QApplication::translate("MainWindow", "Print", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ReportTab3), QApplication::translate("MainWindow", "Customer by Item", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "Transporter:", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "From:", nullptr));
        deFromTBD->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        label_33->setText(QApplication::translate("MainWindow", "          To: ", nullptr));
        deToTBD->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        pbQueryTBD->setText(QApplication::translate("MainWindow", "Query", nullptr));
        pbPrintTBD->setText(QApplication::translate("MainWindow", "Print", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ReportTab4), QApplication::translate("MainWindow", "Transporter By Date", nullptr));
        label_37->setText(QApplication::translate("MainWindow", "Transporter :", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "Item:", nullptr));
        label_38->setText(QApplication::translate("MainWindow", "From:", nullptr));
        deFromTDI->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        label_39->setText(QApplication::translate("MainWindow", "          To: ", nullptr));
        deToTDI->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        pbQueryTDI->setText(QApplication::translate("MainWindow", "Query", nullptr));
        pbPrintTDI->setText(QApplication::translate("MainWindow", "Print", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ReportTab5), QApplication::translate("MainWindow", "Transporter By Item", nullptr));
        label_40->setText(QApplication::translate("MainWindow", "Customer: ", nullptr));
        label_41->setText(QApplication::translate("MainWindow", "From:", nullptr));
        deFromCLS->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        label_42->setText(QApplication::translate("MainWindow", "          To: ", nullptr));
        deToCLS->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        pbQueryCLS->setText(QApplication::translate("MainWindow", "Query", nullptr));
        pbPrintCLS->setText(QApplication::translate("MainWindow", "Print", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ReportTab6), QApplication::translate("MainWindow", "Customer Lifting Summary", nullptr));
        label_44->setText(QApplication::translate("MainWindow", "From:", nullptr));
        deFromSR->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        label_45->setText(QApplication::translate("MainWindow", "          To: ", nullptr));
        deToSR->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        pbQuerySR->setText(QApplication::translate("MainWindow", "Query", nullptr));
        pbPrintSR->setText(QApplication::translate("MainWindow", "Print", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SalesReport), QApplication::translate("MainWindow", "Sales Report Detailed", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "Item: ", nullptr));
        label_49->setText(QApplication::translate("MainWindow", "From:", nullptr));
        deFromILD->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        label_50->setText(QApplication::translate("MainWindow", "          To: ", nullptr));
        deToILD->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        pbQueryILD->setText(QApplication::translate("MainWindow", "Query", nullptr));
        pbPrintILD->setText(QApplication::translate("MainWindow", "Print", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ItemsDetailTab), QApplication::translate("MainWindow", "Items Detail", nullptr));
        label_46->setText(QApplication::translate("MainWindow", "From:", nullptr));
        deFromIS->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        label_47->setText(QApplication::translate("MainWindow", "         To: ", nullptr));
        deToIS->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        rbSales->setText(QApplication::translate("MainWindow", "Sales Items", nullptr));
        pbQueryIS->setText(QApplication::translate("MainWindow", "Query", nullptr));
        pbPrintIS->setText(QApplication::translate("MainWindow", "Print", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ItemsSummaryTab), QApplication::translate("MainWindow", "Items Summary ", nullptr));
        twHelp->setTabText(twHelp->indexOf(ContentsTab), QApplication::translate("MainWindow", "Tab 1", nullptr));
        twHelp->setTabText(twHelp->indexOf(IndexTab), QApplication::translate("MainWindow", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HelpTab), QApplication::translate("MainWindow", "Help", nullptr));
        label_48->setText(QApplication::translate("MainWindow", "From:", nullptr));
        deFromSRS->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        label_51->setText(QApplication::translate("MainWindow", "          To: ", nullptr));
        deToSRS->setDisplayFormat(QApplication::translate("MainWindow", "MMM dd, yyyy", nullptr));
        pbQuerySRS->setText(QApplication::translate("MainWindow", "Query", nullptr));
        pbPrintSRS->setText(QApplication::translate("MainWindow", "Print", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Sales Report Summary", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", nullptr));
        menuImport->setTitle(QApplication::translate("MainWindow", "&Import", nullptr));
        menuSetup->setTitle(QApplication::translate("MainWindow", "Set&up", nullptr));
        menuReports->setTitle(QApplication::translate("MainWindow", "&Reports", nullptr));
        menuCustomers->setTitle(QApplication::translate("MainWindow", "&Customers", nullptr));
        menuTransporter->setTitle(QApplication::translate("MainWindow", "T&ransporter", nullptr));
        menuItems->setTitle(QApplication::translate("MainWindow", "&Items", nullptr));
        menuSales_Report->setTitle(QApplication::translate("MainWindow", "&Sales Report", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
