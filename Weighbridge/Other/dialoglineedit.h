#ifndef DIALOGLINEEDIT_H
#define DIALOGLINEEDIT_H

#include <QLineEdit>

class DialogLineEdit : public QLineEdit
{
    Q_OBJECT
public:

    explicit DialogLineEdit(QObject *parent = 0);

    bool event(QEvent *e);

signals:

public slots:

};

#endif // DIALOGLINEEDIT_H
