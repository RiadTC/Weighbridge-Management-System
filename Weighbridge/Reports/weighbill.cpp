#include "weighbill.h"
#include "ui_weighbill.h"

WeighBill::WeighBill(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::WeighBill)
{
    ui->setupUi(this);
}

WeighBill::~WeighBill()
{
    delete ui;
}
