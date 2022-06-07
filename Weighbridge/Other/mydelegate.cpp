#include "mydelegate.h"
#include <QPainter>
#include <QLocale>

MyDelegate::MyDelegate(QObject *parent) :
    QStyledItemDelegate (parent)
{
}


void MyDelegate::paint(QPainter * painter, const QStyleOptionViewItem &option, const QModelIndex & index) const
 {
    QString  s;

     painter->save();
     s =  QLocale(QLocale::English).toString(index.model()->data(index).toInt());
     const QRect outline = option.rect;
     if ((option.state & QStyle::State_Selected) || (option.state & QStyle::State_HasFocus))
     {    painter->fillRect(option.rect, option.palette.highlight());

       // painter->fillRect(option.rect, option.backgroundBrush);
     }
     painter->drawText(outline, Qt::AlignCenter | Qt::AlignRight, s);
     painter->restore();

 }
