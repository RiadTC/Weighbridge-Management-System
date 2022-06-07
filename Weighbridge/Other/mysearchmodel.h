#ifndef MYSEARCHMODEL_H
#define MYSEARCHMODEL_H

#include <QSqlQueryModel>

class MySearchModel : public QSqlQueryModel
{
    Q_OBJECT

public:

    explicit MySearchModel(QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const;

signals:

public slots:

};

#endif // MYSEARCHMODEL_H
