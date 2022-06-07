#include "ItemDialog.h"
#include "ui_ItemDialog.h"
#include "Setup/Items.h"

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>


ItemDialog::ItemDialog(QAbstractItemModel *Model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemDialog)
{
    ui->setupUi(this);
    InsertMode = true;
    ItemsModel = Model;
    ui->leShortDesc->setFocus();
}

ItemDialog::ItemDialog(QAbstractItemModel *Model, Item i, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemDialog)
{
    ui->setupUi(this);
    ItemsModel = Model;
    if (!i.ShortDesc.isEmpty())
    {    CurItem = i;
         InsertMode = false;
         ui->leShortDesc->setText(i.ShortDesc);
         ui->leLongDesc->setText(i.LongDesc);
         ui->rbSale->setChecked(i.isSaleItem);
    }
    ui->leShortDesc->setFocus();
}


ItemDialog::~ItemDialog()
{
    delete ui;
}


int ItemDialog::getItem(QString Name)
{
    int i=0;

    while (i < ItemsModel->rowCount())
    {   if (!Name.compare(ItemsModel->index(i,1).data().toString(), Qt::CaseInsensitive)) return i;
        i++;
    }
    return -1;
}


void ItemDialog::on_leShortDesc_editingFinished()
{
    QMessageBox Err;

    // Item name should not be null and must be unique
    if (InsertMode)
       if (!ui->leShortDesc->text().isEmpty())
       {    // Check if Item is in database
            if (getItem(ui->leShortDesc->text()) >= 0)
              {   Err.setText("Item already exits");
                  Err.setWindowTitle("Item");
                  Err.exec();
                  ui->leShortDesc->clear();
                  ui->leShortDesc->setFocus();
               }
       }
}

void ItemDialog::on_buttonBox_accepted()
{
    if (!ui->leShortDesc->text().isEmpty())
    {   CurItem.ShortDesc = ui->leShortDesc->text();
        CurItem.LongDesc = ui->leLongDesc->text();
        CurItem.isSaleItem = ui->rbSale->isChecked();
    }

}
