#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QObject>
#include <QLineEdit>

class LineEdit : public QLineEdit
{
public:

    explicit LineEdit (QWidget * parent = 0);

    bool event(QEvent *e);

};

#endif // LINEEDIT_H
