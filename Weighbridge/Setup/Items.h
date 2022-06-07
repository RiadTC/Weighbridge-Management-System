#ifndef ITEMS_H
#define ITEMS_H

#include <QFrame>
#include <QSqlRecord>
#include <QSqlDatabase>

typedef struct
{
    int id;
    bool isSaleItem;
    QString ShortDesc, LongDesc;

} Item;



#endif // ITEMS_H
