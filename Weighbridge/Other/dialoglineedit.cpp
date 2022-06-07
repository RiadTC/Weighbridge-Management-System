#include "dialoglineedit.h"

#include <QEvent>
#include <QKeyEvent>
#include <QApplication>

DialogLineEdit::DialogLineEdit(QObject *parent)
{
}


bool DialogLineEdit::event(QEvent *e)
{
    if (e->type() == QEvent::KeyPress)
    {
        QKeyEvent *ke = static_cast<QKeyEvent *>(e);

        if (ke->key() == Qt::Key_Return)
        {   QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
            QApplication::postEvent(this , event);
            return true;}

    }
    else  if (e->type() == QEvent::FocusOut)
    {
       emit this->returnPressed();
    }
    return QLineEdit::event(e);
}
