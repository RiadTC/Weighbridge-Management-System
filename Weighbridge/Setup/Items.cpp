#include "Items.h"
#include "Setup/ItemDialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>


// getItemId returns the id of item with short description ItemDesc
// in addition to the row number in the items table
int MainWindow::getItemId(QString ItemDesc, int *Position)
{
    int RowCount, CurRow = 0;

    if (!ItemDesc.isEmpty())
    {   RowCount = ItemCompleter->model()->rowCount();
        while ((ItemDesc.compare(ItemCompleter->model()->index(CurRow,1).data().toString() , Qt::CaseInsensitive) !=0) && (CurRow < RowCount)) CurRow++;
        if (CurRow < RowCount)
        {   CurItem->id = ItemCompleter->model()->index(CurRow,0).data().toInt();
            CurItem->ShortDesc = ItemCompleter->model()->index(CurRow,1).data().toString();
            CurItem->LongDesc = ItemCompleter->model()->index(CurRow,2).data().toString();
            CurItem->isSaleItem = ItemCompleter->model()->index(CurRow,3).data().toBool();
            *Position = CurRow;
            return CurItem->id;
        }
    }
    return -1;
}

int MainWindow::getItem(QString ItemDesc)
{
    int RowCount, CurRow = 0;

    if (!ItemDesc.isEmpty())
    {   RowCount = ItemCompleter->model()->rowCount();
        while ((ItemDesc.compare(ItemCompleter->model()->index(CurRow,1).data().toString() , Qt::CaseInsensitive) !=0) && (CurRow < RowCount)) CurRow++;
        if (CurRow < RowCount)
        {   CurItem->id = ItemCompleter->model()->index(CurRow,0).data().toInt();
            CurItem->ShortDesc = ItemCompleter->model()->index(CurRow,1).data().toString();
            CurItem->LongDesc = ItemCompleter->model()->index(CurRow,2).data().toString();
            CurItem->isSaleItem = ItemCompleter->model()->index(CurRow,3).data().toBool();
            return CurItem->id;
        }
    }
    return -1;
}


// csv file must be saved in system code
int MainWindow::getImportedItemId(QString ItemDesc)
{
    int RowCount, CurRow = 0;
    QString d, s;
    int i=1;

    if (!ItemDesc.isEmpty())
    {   RowCount = ItemCompleter->model()->rowCount();
        ItemDesc.remove('"');;
        while (i && (CurRow< RowCount))
        {   d = ItemCompleter->model()->index(CurRow,1).data().toString();
            d.remove('"');
            i = d.compare(ItemDesc, Qt::CaseInsensitive);
            if ( i != 0) CurRow++;
        }
        if (CurRow < RowCount)
        {
            CurItem->id = ItemCompleter->model()->index(CurRow,0).data().toInt();
            CurItem->ShortDesc = ItemCompleter->model()->index(CurRow,1).data().toString();
            CurItem->LongDesc = ItemCompleter->model()->index(CurRow,2).data().toString();
            CurItem->isSaleItem = ItemCompleter->model()->index(CurRow,3).data().toBool();
            return CurItem->id;
        }
    }
    return -1;
}

void MainWindow::getItem(Item *ItemRec, int row)
{

    if (ItemRec != NULL)
    {   if (row < ItemCompleter->model()->rowCount())
        {   ItemRec->id = ItemCompleter->model()->index(row,0).data().toInt();
            ItemRec->ShortDesc = ItemCompleter->model()->index(row,1).data().toString();
            ItemRec->LongDesc = ItemCompleter->model()->index(row,2).data().toString();
            ItemRec->isSaleItem = ItemCompleter->model()->index(row,3).data().toBool();
        }
    }
}

bool AddItem(Item *NewItem, int *Index, QSqlDatabase mydb)
{
    QSqlQuery Query(mydb);
    QSqlError Err;


    Query.prepare("INSERT INTO Item (ShortDesc, LongDesc) "
                             "VALUES (:ShortDesc, :LongDesc)");
    Query.bindValue(":ShortDesc", NewItem->ShortDesc);
    Query.bindValue(":LongDesc", NewItem->LongDesc);
    if (!Query.exec())
    { qDebug("Record was not inserted");
      Err = Query.lastError();
      return false;
    }
   else
    { *Index = Query.lastInsertId().toInt();
       return 1;
    }
}


void MainWindow::on_pbAddItem_clicked()
{
    ItemDialog *NewItemDialog;
    QSqlTableModel *Table;
    QSqlRecord Record;

    NewItemDialog = new ItemDialog(ItemCompleter->model() ,this);
    NewItemDialog->exec();
    if (!NewItemDialog->CurItem.ShortDesc.isEmpty())
    {   // Add Item in the model/view
        Table = static_cast <QSqlTableModel *> (ItemCompleter->model());
        Record = Table->record();
        Record.setValue("ShortDesc", NewItemDialog->CurItem.ShortDesc);
        Record.setValue("LongDesc", NewItemDialog->CurItem.LongDesc);
        Record.setValue("Sale", NewItemDialog->CurItem.isSaleItem);
        if (Table->insertRecord(-1, Record))
        {   Table->submitAll();
            ui->tvItems->model()->sort(1, Qt::AscendingOrder);
            //update price lists
        }
    }

}



void MainWindow::on_pbModifyItem_clicked()
{

    QSqlTableModel *Table;
    QSqlRecord ItemRec;
    QSqlQuery Query(db);
    QSqlError Err;
    QMessageBox Warning;
    ItemDialog *ModifyDialog;
    Item ItemToModify, ItemToReplace;
    int index, i;
    QModelIndex Index;

    Index = ui->tvItems->currentIndex();
    if (Index.isValid())
    {   getItem(&ItemToModify, Index.row());
        ModifyDialog = new ItemDialog(ui->tvItems->model(), ItemToModify, this);
        if (ModifyDialog->exec())  // Ok was pressed
        {   if (ItemToModify.ShortDesc == ModifyDialog->CurItem.ShortDesc) // Short Description was not modified
            {   if (ItemToModify.LongDesc != ModifyDialog->CurItem.LongDesc) // Long Description Modified
                {   // Change Long Description in item's table
                    Table = static_cast <QSqlTableModel *> (ItemCompleter->model());
                    ItemRec = Table->record(Index.row());
                    ItemRec.setValue("LongDesc", ModifyDialog->CurItem.LongDesc);
                    ItemRec.setValue("Sale", ModifyDialog->CurItem.isSaleItem);
                    Table->setRecord(Index.row(), ItemRec);
                    ui->tvItems->model()->sort(1, Qt::AscendingOrder);
                }
            }
            else // Short Description was changed
            {   index = getItemId(ModifyDialog->CurItem.ShortDesc, &i);
                if (index < 0)
                {   // Change of item short description to a new one
                    Table = static_cast <QSqlTableModel *> (ItemCompleter->model());
                    ItemRec = Table->record(Index.row());
                    ItemRec.setValue("ShortDesc", ModifyDialog->CurItem.ShortDesc);
                    ItemRec.setValue("LongDesc", ModifyDialog->CurItem.LongDesc);
                    ItemRec.setValue("Sale", ModifyDialog->CurItem.isSaleItem);
                    Table->setRecord(Index.row(), ItemRec);
                    ui->tvItems->model()->sort(1, Qt::AscendingOrder);
                }
                else // Replace item by another
                {   ItemToReplace = *CurItem;
                    Warning.setText("Are you sure you want to replace "+ ItemToModify.ShortDesc
                             + " by " +ItemToReplace.ShortDesc + "?");
                    Warning.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel );
                    Warning.setDefaultButton(QMessageBox::Cancel);
                    if ( Warning.exec() == QMessageBox::Yes)
                    {  // Replace item
                       Table = new QSqlTableModel(0, db);
                       Table->setTable("Ticket");
                       Table->select();
                       Query.prepare("UPDATE Ticket SET ItemID = :NewItemID WHERE (ItemID = :OldItemID)");
                       Query.bindValue(":NewItemID", ItemToReplace.id);
                       Query.bindValue(":OldItemID", ItemToModify.id);
                       if (!Query.exec()) qDebug("Record was not modified");
                       else
                       {    Table = new QSqlTableModel(0, db);
                            Table->setTable("InProcess");
                            Table->select();
                            Query.prepare("UPDATE InProcess SET Material = :NewMaterial WHERE (Material = :OldMaterial)");
                            Query.bindValue(":NewMaterial", ItemToReplace.ShortDesc);
                            Query.bindValue(":OldMaterial", ItemToModify.ShortDesc);
                            if (!Query.exec()) qDebug("Record was not modified");
                            else
                            {   ui->tvItems->model()->removeRow(Index.row());
                                ui->tvItems->model()->submit();
                                ui->tvItems->model()->sort(1, Qt::AscendingOrder);
                                Warning.setText(" Item "+ItemToModify.ShortDesc+ " was removed from the database.");
                                Warning.setStandardButtons(QMessageBox::Ok);
                                Warning.exec();
                            }
                       }
                    }
                }
            }
        }
    }

}


void MainWindow::on_pbDeleteItem_clicked()
{

    QSqlTableModel *Table;
    QSqlQuery Query(db);
    QSqlError Err;
    Item ItemToDelete;
    QMessageBox Warning;
    QModelIndex Index;

    Index = ui->tvItems->currentIndex();
    if (Index.isValid()) getItem(&ItemToDelete , Index.row());
    else return;
    Warning.setText("Are you sure you want to delete "+ ItemToDelete.ShortDesc + "?");
    Warning.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel );
    Warning.setDefaultButton(QMessageBox::Cancel);
    if ( Warning.exec() == QMessageBox::Yes)
    {   // Check if the item is used in transactions
        Table = new QSqlTableModel(0, db);
        Table->setTable("Ticket");
        Table->select();
        Query.prepare("SELECT * FROM Ticket WHERE (ItemID = :ItemID)");
        Query.bindValue(":ItemID", ItemToDelete.id);
        if (!Query.exec()) qDebug("Error in Query");
        else if (Query.size()<=0)
        {   // Check if the item is used in transactions
            Table = new QSqlTableModel(0, db);
            Table->setTable("InProcess");
            Table->select();
            Query.prepare("SELECT * FROM InProcess WHERE (Material = :SDesc)");
            Query.bindValue(":Material", ItemToDelete.ShortDesc);
            if (!Query.exec()) qDebug("Error in Query");
            else if (Query.size()<=0)
            {   // Item can be deleted
                Query.prepare("DELETE FROM Item WHERE (ItemID = :ItemID)");
                Query.bindValue(":ItemID", ItemToDelete.id);
                if (!Query.exec()) qDebug("Record was not deleted");
                else
                    {   ItemCompleter->model()->removeRow(Index.row());
                        ItemCompleter->model()->submit();
                        ui->tvItems->model()->sort(1, Qt::AscendingOrder);
                    }
                }
                else
                {   Warning.setText( ItemToDelete.ShortDesc + "is used in some transactions and cannot be deleted.");
                     Warning.setStandardButtons(QMessageBox::Ok );
                     Warning.exec();
                }
           }
        else
        {   Warning.setText( ItemToDelete.ShortDesc + "is used in some transactions and cannot be deleted.");
            Warning.setStandardButtons(QMessageBox::Ok );
            Warning.exec();
        }
    }
}


void MainWindow::updateItemRow(int row, QSqlRecord &Record)
{
    QSqlTableModel *Table;
    QSqlRecord ItemRec;
    QSqlQuery Query(db);
    QSqlError Err;
    QString NewDesc;
    Item ItemToModify, ItemToReplace;
    QMessageBox Warning;
    int Pos;

    if (Record.isGenerated(1)) // Short Description is being modified
    {   NewDesc = Record.value(1).toString();
        ItemCompleter->model()->revert();
        if (getItemId(NewDesc, &Pos) >= 0)
        {   // Get old value of the cell
            getItem(&ItemToModify, row);
            Warning.setText("Are you sure you want to replace "+ ItemToModify.ShortDesc
                            + " by " + NewDesc + " that already exists?");
            Warning.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel );
            Warning.setDefaultButton(QMessageBox::Cancel);
            if (Warning.exec() == QMessageBox::Yes)
            {  getItem(&ItemToReplace, Pos);
               Table = new QSqlTableModel(0, db);
               Table->setTable("Ticket");
               Table->select();
               Query.prepare("UPDATE Ticket SET ItemID = :NewItemID WHERE (ItemID = :OldItemID)");
               Query.bindValue(":NewItemID", ItemToReplace.id);
               Query.bindValue(":OldItemID", ItemToModify.id);
               if (!Query.exec()) qDebug("Record was not modified");
               else
               {    Table = new QSqlTableModel(0, db);
                    Table->setTable("InProcess");
                    Table->select();
                    Query.prepare("UPDATE InProcess SET Material = :NewMaterial WHERE (Material = :OldMaterial)");
                    Query.bindValue(":NewMaterial", ItemToReplace.ShortDesc);
                    Query.bindValue(":OldMaterial", ItemToModify.ShortDesc);
                    if (!Query.exec()) qDebug("Record was not modified");
                    else
                    {   ItemCompleter->model()->removeRow(row);
                        ui->tvItems->model()->sort(1, Qt::AscendingOrder);
                        Warning.setText(" Item "+ItemToModify.ShortDesc+ " was removed from the database.");
                        Warning.setStandardButtons(QMessageBox::Ok);
                        Warning.exec();
                    }
               }
            }
        }
        else Record.setValue(1, NewDesc);
    }
    qDebug() << "the cell has changed";
}


void MainWindow::on_tvItems_clicked(const QModelIndex &index)
{
    QSqlRecord TicketRec;
    QSqlQuery Query(db);
    QString Expression;
    int row, ItemID;
    float Weight;
    bool found = false;

    row = index.row();
    ItemID =  ui->tvItems->model()->data(ui->tvItems->model()->index(row,0)).toInt();
    Expression.append("SELECT Netweight, TicketID, Vehicule, TimeOut, Name FROM Ticket ");
    Expression.append("JOIN Customer ON Ticket.CustomerID = Customer.CustomerID ");
    Expression.append("WHERE ((ItemID = :ID) AND (YEARWEEK(TimeOut) = YEARWEEK(now())))");
    Expression.append("Order by TicketID");
    Query.prepare(Expression);
    Query.bindValue(":ID", ItemID);
    if (!Query.exec()) qDebug() << Query.lastError();
    else
    {   Weight = 0;
        while (Query.next())
        {
            Weight += Query.value(0).toFloat();
        }
    }
    ui->lcurW->setText(QString::number(Weight/1000.0, 'f', 2));
    if ((Weight!=0) && !found)
    {
        if (Query.last()) TicketRec = Query.record();
        found = true;
    }
    Expression.clear();
    Expression.append("SELECT Netweight, TicketID, Vehicule, TimeOut, Name FROM Ticket ");
    Expression.append("JOIN Customer ON Ticket.CustomerID = Customer.CustomerID ");
    Expression.append("WHERE ((ItemID = :ID) AND  (YEAR(TimeOut) = YEAR(now())) AND (MONTH(TimeOut) = MONTH(now())) ) ");
    Expression.append("Order by TicketID");
    Query.prepare(Expression);
    Query.bindValue(":ID", ItemID);
    if (!Query.exec()) qDebug() << Query.lastError();
    else
    {   Weight = 0;
        while (Query.next())
        {
            Weight += Query.value(0).toFloat();
        }
    }
    ui->lcurM->setText(QString::number(Weight/1000.0,'f', 2));
    if ((Weight!=0) && !found)
    {
        if (Query.last()) TicketRec = Query.record();
        found = true;
    }
    Expression.clear();
    Expression.append("SELECT Netweight, TicketID, Vehicule, TimeOut, Name FROM Ticket ");
    Expression.append("JOIN Customer ON Ticket.CustomerID = Customer.CustomerID ");
    Expression.append("WHERE ((ItemID = :ID) AND  (YEAR(TimeOut) = YEAR(now()))) ");
    Expression.append("Order by TicketID");
    Query.prepare(Expression);
    Query.bindValue(":ID", ItemID);
    if (!Query.exec()) qDebug() << Query.lastError();
    else
    {   Weight = 0;
        while (Query.next())
        {
            Weight += Query.value(0).toFloat();
        }
    }
    ui->lcurY->setText(QString::number(Weight/1000.0,'f', 2));
    if ((Weight!=0) && !found)
    {
        if (Query.isActive() && Query.isSelect())
        {   Query.previous();
            TicketRec = Query.record();
        }
        found = true;
    }
    if (found)
    {
        ui->lDate->setText(TicketRec.value("TimeOut").toString());
        ui->lQuantity->setText(TicketRec.value("Netweight").toString());
        ui->lCustomer->setText(TicketRec.value("Name").toString());
        ui->lVehicule->setText(TicketRec.value("Vehicule").toString());
    }
}

