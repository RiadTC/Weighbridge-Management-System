#ifndef ITEMDIALOG_H
#define ITEMDIALOG_H

#include "Setup/Items.h"
#include <QAbstractItemModel>
#include <QDialog>

namespace Ui {
class ItemDialog;
}

class ItemDialog : public QDialog
{
    Q_OBJECT

public:
    Item CurItem;
    bool InsertMode;
    QAbstractItemModel *ItemsModel;
    explicit ItemDialog(QAbstractItemModel *Model, QWidget *parent = 0);
    explicit ItemDialog(QAbstractItemModel *Model, Item i, QWidget *parent = 0 );
    ~ItemDialog();

private slots:

    int getItem(QString Desc);
    void on_leShortDesc_editingFinished();
    void on_buttonBox_accepted();

private:
    Ui::ItemDialog *ui;
};

#endif // ITEMDIALOG_H
