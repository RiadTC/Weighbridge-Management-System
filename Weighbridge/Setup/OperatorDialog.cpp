#include "OperatorDialog.h"
#include "ui_OperatorDialog.h"

#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>


OperatorDialog::OperatorDialog(QSqlDatabase db, Operator *op, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OperatorDialog)
{
    ui->setupUi(this);
    Opdb = db;
    if (op->id >= 0)
    {
        User.id = op->id;
        User.Name = op->Name;
        User.Password = op->Password;
        ui->leOperatorName->setText(User.Name);
        ui->leOperatorName->setDisabled(true);
    }
    else
    {
        User.id = -1;
        User.Name.clear();
        User.Password.clear();
    }

}

OperatorDialog::~OperatorDialog()
{
    delete ui;
}

void OperatorDialog::on_leOperatorName_editingFinished()
{
    QSqlTableModel *OperatorTable;
    QMessageBox Err;
    QString UserName;

    // Operator name should not be null
    if (!ui->leOperatorName->text().isEmpty())
    {   //Initialize Operator's Table then Check if operator name is in database.
        OperatorTable = new QSqlTableModel(0, Opdb);
        OperatorTable->setTable("Operator");
        UserName = "Name = '" + ui->leOperatorName->text()+"'";
        OperatorTable->setFilter(UserName);
        OperatorTable->select();
        // if Operator found then repeat name entry
        if (OperatorTable->rowCount())
        {   Err.setText("Operator name already in use");
            Err.setWindowTitle("Operator");
            Err.exec();
            ui->leOperatorName->clear();
            ui->leOperatorName->setFocus();
        }
        else User.Name = ui->leOperatorName->text();
    }
}


void OperatorDialog::on_buttonBox_rejected()
{
    User.id = -1;
    User.Name.clear();
    User.Password.clear();
}


void OperatorDialog::on_buttonBox_accepted()
{
/*    QString Pass1, Pass2;
    QMessageBox Msg;

    Pass1 = ui->leOperatorPass->text();
    Pass2 = ui->leOperatorPass1->text();
    if ((Pass1!= Pass2) || (Pass1 == NULL))
    {   Msg.setText("Password Mismatch!");
        Msg.exec();
        ui->leOperatorPass->clear();
        ui->leOperatorPass1->clear();
        ui->leOperatorPass->setFocus();
        return;
    }
    else User.Password = Pass1;*/
}

void OperatorDialog::on_leOperatorPass1_editingFinished()
{
    QString Pass1, Pass2;
    QMessageBox Msg;

    Pass1 = ui->leOperatorPass->text();
    Pass2 = ui->leOperatorPass1->text();
    if ((Pass1!= Pass2) || (Pass1.isEmpty()))
    {   Msg.setText("Password Mismatch!");
        Msg.exec();
        ui->leOperatorPass->clear();
        ui->leOperatorPass1->clear();
        ui->leOperatorPass->setFocus();
        return;
    }
    else User.Password = Pass1;

}
