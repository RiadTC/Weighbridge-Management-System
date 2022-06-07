#include "mysearchmodel.h"

MySearchModel::MySearchModel(QObject *parent) :
    QSqlQueryModel(parent)
{
}


QVariant MySearchModel::data(const QModelIndex &index, int role) const
{

    if ((index.column() >= 8) && (role == Qt::TextAlignmentRole)) {return Qt::AlignBottom;}
    return QSqlQueryModel::data(index, role);

}
