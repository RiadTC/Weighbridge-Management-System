#include "mystringdelegate.h"

#include <QPainter>
#include <QDateTime>

MyStringDelegate::MyStringDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}


void MyStringDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
 {
    QString s;

     painter->save();
     s= index.model()->data(index).toDateTime().toString("dd.MM.yyyy HH:mm");
     const QRect outline = option.rect;
     if ((option.state & QStyle::State_Selected) || (option.state & QStyle::State_HasFocus))
     {    painter->fillRect(option.rect, option.palette.highlight());}
     painter->drawText(outline, Qt::AlignCenter | Qt::AlignCenter, s);

     painter->restore();

 }
