#ifndef OPERATORDIALOG_H
#define OPERATORDIALOG_H

#include <Setup/Operators.h>
#include <QDialog>
#include <QString>
#include <QSqlDatabase>

namespace Ui {
class OperatorDialog;
}

class OperatorDialog : public QDialog
{
    Q_OBJECT

public:

    Operator User;
    explicit OperatorDialog(QSqlDatabase db, Operator *op, QWidget *parent = 0);
    ~OperatorDialog();

private slots:

    void on_leOperatorName_editingFinished();

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void on_leOperatorPass1_editingFinished();

private:
    QSqlDatabase Opdb;
    Ui::OperatorDialog *ui;

};

#endif // OPERATORDIALOG_H
