#ifndef MYSTRINGDELEGATE_H
#define MYSTRINGDELEGATE_H

#include <QStyledItemDelegate>

class MyStringDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:

    explicit MyStringDelegate(QObject *parent = 0);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

signals:

public slots:

};

#endif // MYSTRINGDELEGATE_H
