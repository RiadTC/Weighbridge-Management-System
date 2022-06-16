#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>
#include <QSqlDatabase>
#include "Setup/Operators.h"

namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:

    Operator User;
    bool Legal;

    explicit DialogLogin(QSqlDatabase db, QWidget *parent = 0);
    void closeEvent (QCloseEvent *event);
    ~DialogLogin();

private slots:

    void on_leOperator_returnPressed();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogLogin *ui;
    QSqlDatabase mydb;
};

#endif // DIALOGLOGIN_H
