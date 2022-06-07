#include "Operators.h"
#include "OperatorDialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QStringList>
#include <QString>
#include <QListView>
#include <QSqlError>
#include <QMessageBox>

Operator User;

void MainWindow::on_tvOperators_clicked(const QModelIndex &index)
{

    int row;

    row = index.row();
    User.id =  ui->tvOperators->model()->data(ui->tvOperators->model()->index(row,0)).toInt();
    User.Name =  ui->tvOperators->model()->data(ui->tvOperators->model()->index(row,1)).toString();
    User.Password = ui->tvOperators->model()->data(ui->tvOperators->model()->index(row,1)).toString();
//    ui->leOperatorName->setText(User.Name);
//    ui->leOperatorPass->setText(User.Password);
    //    ui->leOperatorPass1->clear();

}


int MainWindow::getOperator(QString OpName)
{
    int RowCount, CurRow = 0;

    if (!OpName .isEmpty())
    {   RowCount = ui->tvOperators->model()->rowCount();
        while ((OpName.compare(ui->tvOperators->model()->index(CurRow,1).data().toString() , Qt::CaseInsensitive) !=0) && (CurRow < RowCount)) CurRow++;
        if (CurRow < RowCount)
        {   //CurItem->id = ItemCompleter->model()->index(CurRow,0).data().toInt();
            //CurItem->ShortDesc = ItemCompleter->model()->index(CurRow,1).data().toString();
            //CurItem->LongDesc = ItemCompleter->model()->index(CurRow,2).data().toString();
            //CurItem->isSaleItem = ItemCompleter->model()->index(CurRow,3).data().toBool();
            //return CurItem->id;
            return 1;
        }
    }
    return -1;
}


void MainWindow::on_pbAddOperator_clicked()
{
    QString Key;
    QSqlTableModel *OperatorsTable;
    QSqlQuery Query(db);
    OperatorDialog *Dialog;

    User.id = -1;
    User.Name.clear();
    User.Password.clear();
    Dialog = new OperatorDialog(db , &User, this);
    Dialog->exec();
    if (!Dialog->User.Name.isEmpty())
    {   // insert new operator
        Key = "729308A8E815F6A46EB3A8AE6D5463CA7B64A0E2E11BC26A68106FC7697E727E37011";
        Query.prepare("INSERT INTO Operator (Name, Password) "
                      "VALUES (:Name, AES_ENCRYPT(:Password, :Key))");
        Query.bindValue(":Name", Dialog->User.Name);
        Query.bindValue(":Password", Dialog->User.Password);
        Query.bindValue(":Key", Key);
        if (!Query.exec()) qDebug() << Query.lastError();
        else
        {
            OperatorsTable = new QSqlTableModel(0,db);
            OperatorsTable->setTable("Operator");
            OperatorsTable->select();
            ui->tvOperators->setModel(OperatorsTable);
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
}


void MainWindow::on_pbModifyOperator_clicked()
{
    QString Key;
    int row;
    QSqlQuery Query(db);
    QMessageBox Msg;
    OperatorDialog *Dialog;
    QModelIndex Index;

    Index = ui->tvOperators->currentIndex();
    if (Index.isValid())
    {
        row = Index.row();
        User.id =  ui->tvOperators->model()->data(ui->tvOperators->model()->index(row,0)).toInt();
        User.Name =  ui->tvOperators->model()->data(ui->tvOperators->model()->index(row,1)).toString();
        User.Password = ui->tvOperators->model()->data(ui->tvOperators->model()->index(row,1)).toString();
        Dialog = new OperatorDialog(db , &User, this);
        Dialog->exec();
        if (!Dialog->User.Name.isEmpty())
        {   // Change password
            Key = "729308A8E815F6A46EB3A8AE6D5463CA7B64A0E2E11BC26A68106FC7697E727E37011";
            Query.prepare("UPDATE Operator SET Password = AES_ENCRYPT(:Password, :Key)"
                          "WHERE OperatorID = :ID");
            Query.bindValue(":ID", Dialog->User.id);
            Query.bindValue(":Password", Dialog->User.Password);
            Query.bindValue(":Key", Key);
            if (!Query.exec()) qDebug() << Query.lastError();
        }
    }
}


void MainWindow::on_pbDeleteOperator_clicked()
{
    QString OpName;
    QSqlTableModel *Table;
    QSqlQuery Query(db);
    QMessageBox msg;
    QModelIndex Index;
    int row;

    Index = ui->tvOperators->currentIndex();
    if (Index.isValid())
    {
        row = Index.row();
        User.id =  ui->tvOperators->model()->data(ui->tvOperators->model()->index(row,0)).toInt();
        User.Name =  ui->tvOperators->model()->data(ui->tvOperators->model()->index(row,1)).toString();
        User.Password = ui->tvOperators->model()->data(ui->tvOperators->model()->index(row,2)).toString();
        if ((!User.Name.isEmpty()) && (User.Name != "Admin"))
        {
            // Check if the operator is used in any transaction
            Query.prepare("SELECT * FROM Ticket WHERE (OperatorID = :ID) ");
            Query.bindValue(":ID", User.id);
            if (!Query.exec()) qDebug() << Query.lastError();
            else if (!Query.next())
            {
                Query.prepare("DELETE FROM Operator WHERE (OperatorID = :ID) ");
                Query.bindValue(":ID", User.id);
                if (!Query.exec())
                {   qDebug("No Record was deleted");
                    qDebug() << Query.lastError();
                }
                else
                {
                    Table = new QSqlTableModel(0,db);
                    Table->setTable("Operator");
                    Table->select();
                    ui->tvOperators->setModel(Table);
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
            else
            {   msg.setText("Operator is used in some transactions and cannot be deleted!");
                msg.exec();
            }
        }
    }
}



