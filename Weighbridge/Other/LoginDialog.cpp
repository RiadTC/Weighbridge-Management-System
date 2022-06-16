#include "LoginDialog.h"
#include "ui_LoginDialog.h"
#include "iostream"

#include "QtSql/QSqlDatabase"
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QCloseEvent>


DialogLogin::DialogLogin(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);
    ui->leOperator->setFocus();
    mydb = db;
}

DialogLogin::~DialogLogin()
{
    delete ui;
}


void DialogLogin::on_leOperator_returnPressed()
{
    QSqlQuery Query(mydb);
    QString Key;
    QMessageBox Err;

    // User name should not be null
    if (!ui->leOperator->text().isEmpty())
    {   //Initialize Operator's Table then Check if user is in database.
        //Key = "729308A8E815F6A46EB3A8AE6D5463CA7B64A0E2E11BC26A68106FC7697E727E37011";
        //Query.prepare("SELECT OperatorID, AES_DECRYPT(Password, :Key) FROM Operator WHERE Name = :Name");
        Query.prepare("SELECT OperatorID, Password FROM Operator WHERE Name = :Name");
        Query.bindValue(":Name", ui->leOperator->text());
        //Query.bindValue(":Key", Key);
        if (!Query.exec()) qDebug() << Query.lastError();
        else
        {   if (Query.next())
            {
                User.id = Query.value("OperatorID").toInt();
                User.Name = ui->leOperator->text();
                User.Password = Query.value(1).toString();
            }
            else
            {   // if Operator not found then repeat name entry
                Err.setText("Incorrect Operator name");
                Err.setWindowTitle("Operator");
                Err.exec();
                ui->leOperator->clear();
                ui->leOperator->setFocus();
            }
        }
    }
}

void DialogLogin::on_buttonBox_accepted()
{
    QMessageBox Msg;

    // Check if password is correct
    if (ui->lePassword->text().isEmpty())
    {   Msg.setText("Password cannot be empty");
        Msg.setWindowTitle("Operator Password");
        Msg.exec();
        ui->lePassword->setFocus();
    }
    else
    if (User.Password != ui->lePassword->text())
    {   Msg.setText("Incorrect Password");
        Msg.setWindowTitle("Operator Password");
        Msg.exec();
        ui->lePassword->clear();
        ui->lePassword->setFocus();
    }
    else
    { correctPass = true;
      this->close();
    }
}

void DialogLogin::on_buttonBox_rejected()
{
    this->close();
}
