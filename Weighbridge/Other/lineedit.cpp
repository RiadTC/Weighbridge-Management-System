#include "lineedit.h"

#include <QDebug>
#include <QKeyEvent>

LineEdit::LineEdit(QWidget *parent)
{

}


bool LineEdit::event(QEvent *e)
{
    if (e->type() == QEvent::KeyPress)
    {
        QKeyEvent *ke = static_cast<QKeyEvent *>(e);
        if (ke->key() == Qt::Key_Return)
        {
            focusNextChild();
            qDebug() << "return or tab key";
            emit this->returnPressed();
        }
    }
    else  if (e->type() == QEvent::FocusOut)
    {  qDebug() <<  "focusout";
       emit this->returnPressed();
    }
    return QLineEdit::event(e);
}


