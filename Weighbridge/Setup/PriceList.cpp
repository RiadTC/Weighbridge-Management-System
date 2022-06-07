#include "PriceList.h"
#include "ui_PriceList.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QCompleter>
#include <QSqlQueryModel>
#include <QMessageBox>


void MainWindow::on_tvLists_clicked(const QModelIndex &index)
{
    QSqlQueryModel *Model;
    QSqlQuery Query(db);
    QString Expression = NULL;
    int ListId;

    if (index.isValid())
    {   ListId = ui->tvLists->model()->index(index.row(),0).data().toInt();
        Expression.append("SELECT ShortDesc, Price FROM PriceList ");
        Expression.append("JOIN Item ON PriceList.Item = Item.ItemID ");
        Expression.append("WHERE (ListID = :Val1) ");
        Expression.append("Order By ShortDesc");
        Query.prepare(Expression);
        Query.bindValue(":Val1", ListId);
        if (!Query.exec()) qDebug() << Query.lastError();
        else
        {   Model = new QSqlQueryModel(0);
            Model->setQuery(Query);
            Model->setHeaderData(0, Qt::Horizontal, "Item", 0);
            ui->tvPriceList->setModel(Model);
        }
    }

}

PriceList::PriceList(QSqlDatabase db, QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::PriceList)
{
    QSqlTableModel *Table;
    QSqlQuery Query(db);
    QCompleter *Completer;

    Table = new QSqlTableModel(0, db);
    Table->setTable("Lists");
    Table->select();
    Query.prepare("SELECT * FROM Lists ");
    if (!Query.exec()) qDebug("Query on Lists failed");
    else while (Query.next()) ListNames.append(Query.value(1).toString());
    ui->setupUi(this);
    mydb = db;
    Completer = new QCompleter(ListNames);
    ui->lePriceName->setCompleter(Completer);
}

PriceList::~PriceList()
{
    delete ui;
}

void PriceList::on_lePriceName_editingFinished()
{
    QSqlTableModel *Table;
    QSqlQueryModel *Model;
    QSqlQuery Query(mydb);
    QString Expression;
    int index;

    index = ListNames.indexOf(ui->lePriceName->text());
    // Fetch list from table and display it
    Table = new QSqlTableModel(0, mydb);
    Table->setTable("PriceList");
    Table->select();
    Expression.append("SELECT ShortDesc, Price FROM PriceList, Item " );
    Expression.append("WHERE (PriceList.Item = Item.ItemID ) AND (ListID = :ListID)");
    Query.prepare(Expression);
    Query.bindValue(":ListID", index);
    if (!Query.exec()) qDebug("Cannot read table PriceList");
    Model = new QSqlQueryModel(0);
    Model->setQuery(Query);
    ui->tvPriceList->setModel(Model);
    ui->tvPriceList->setEditTriggers(QAbstractItemView::DoubleClicked);
//    ui->tvPriceList->hideColumn(0);
    ui->tvPriceList->resizeColumnsToContents();
    for (int c = 0; c < ui->tvPriceList->horizontalHeader()->count(); ++c)
       ui->tvPriceList->horizontalHeader()->setSectionResizeMode( c, QHeaderView::Stretch);

}

int GetPriceListId( QAbstractItemModel *Model, QString NewName)
{
    int RowCount, CurRow = 0;

    if (!NewName.isEmpty())
    {   RowCount = Model->rowCount()-1;
        while ((Model->index(CurRow,1).data().toString() != NewName) && (CurRow < RowCount)) CurRow++;
        if (CurRow < RowCount) return Model->index(CurRow,0).data().toInt();
        else return -1;
    }
    return -1;
}

void MainWindow::updateListRow(QModelIndex Start,QModelIndex End)
{
    QSqlTableModel *ListTable, *PriceList;
    QSqlQueryModel *Model;
    QSqlRecord Record;
    QSqlQuery Query(db);
    QSqlError Err;
    QString NewName, Expression;
    QMessageBox Warning;
    int ListID;

    if (addMode)
    {   NewName = ui->tvLists->model()->index(Start.row(),1).data().toString();
        // Check if NewName is unique
        if ((GetPriceListId(ui->tvLists->model(),NewName) < 0) && (NewName != ""))
        {   // insert list into table
            addMode = false;
            ListTable = new QSqlTableModel(0,db);
            ListTable->setTable("Lists");
            ListTable->select();
            Record = ListTable->record();
            Record.setValue("ListName", NewName);
            if (ListTable->insertRecord(-1, Record))
            {   ListID = ListTable->query().lastInsertId().toInt();
                Query.prepare("Select * FROM PriceList WHERE (ListID = 1)");
                if (Query.exec())
                {   PriceList = new QSqlTableModel(0,db);
                    PriceList->setTable("PriceList");
                    PriceList->select();
                    Record = PriceList->record();
                    while (Query.next())
                    {   Record.setValue("ListID", ListID);
                        Record.setValue("Item", Query.record().value("Item").toInt());
                        Record.setValue("Price", Query.record().value("Price").toFloat());
                        if (!PriceList->insertRecord(-1,Record))  qDebug() << "the record not added";;
                    }
                    PriceList->submitAll();
                }
                Expression.append("SELECT ShortDesc, Price FROM PriceList ");
                Expression.append("JOIN Item ON PriceList.Item = Item.ItemID ");
                Expression.append("WHERE (ListID = :Val1) ");
                Expression.append("Order By ShortDesc");
                Query.prepare(Expression);
                Query.bindValue(":Val1", ListID);
                if (!Query.exec()) qDebug() << Query.lastError();
                else
                {   Model = new QSqlQueryModel(0);
                    Model->setQuery(Query);
                    Model->setHeaderData(0, Qt::Horizontal, "Item", 0);
                    ui->tvPriceList->setModel(Model);
                }
                Warning.setText("Price List " + NewName +" has been created.");
                Warning.setStandardButtons(QMessageBox::Ok);
                Warning.exec();
            }
        }
        else
        {   Warning.setText("List name already exists...Choose a new one.");
            Warning.setStandardButtons(QMessageBox::Ok);
            Warning.exec();
            //ui->tvLists->model()->setData(Start,"");
        }
    }
    qDebug() << "the cell has changed";
}


void MainWindow::on_pbAddPriceList_clicked()
{

    addMode = true;
    ui->tvLists->model()->insertRow(ui->tvLists->model()->rowCount(QModelIndex()));
}


void MainWindow::on_pbDeletePriceList_clicked()
{
    QModelIndex rowIndex;
    QSqlQuery Query(db);
    int row, ListID;

    // Get the list index of the selected price list
    rowIndex = ui->tvLists->currentIndex();
    if (rowIndex.isValid())
    {   row = rowIndex.row();
        ListID = ui->tvLists->model()->index(row,0).data().toInt();
        // Delete Price List From both tables
        Query.prepare("DELETE FROM PriceList WHERE (ListID = :Val)");
        Query.bindValue(":Val", ListID);
        if (Query.exec())
        {   ui->tvLists->model()->removeRow(row);
            ui->tvLists->sortByColumn(1, Qt::AscendingOrder);
            ui->tvPriceList->setModel(NULL);
        }
    }
}



void MainWindow::on_tvPriceList_doubleClicked(const QModelIndex &index)
{

    qDebug() << "the cell has changed";
}
