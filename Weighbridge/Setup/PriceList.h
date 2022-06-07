#ifndef PRICELIST_H
#define PRICELIST_H

#include <QDockWidget>
#include <QStringList>
#include <QSqlDatabase>
#include <QAbstractItemModel>

namespace Ui {
class PriceList;
}

class PriceList : public QDockWidget
{
    Q_OBJECT
    QStringList ListNames;

public:
    explicit PriceList(QSqlDatabase db, QWidget *parent = 0);
    ~PriceList();

private slots:
    void on_lePriceName_editingFinished();


private:
    Ui::PriceList *ui;
    QSqlDatabase mydb;
};

int GetPriceListId( QAbstractItemModel *Model, QString NewName);

#endif // PRICELIST_H
