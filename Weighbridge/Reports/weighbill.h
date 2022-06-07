#ifndef WEIGHBILL_H
#define WEIGHBILL_H

#include <QFrame>

namespace Ui {
class WeighBill;
}

class WeighBill : public QFrame
{
    Q_OBJECT

public:
    explicit WeighBill(QWidget *parent = 0);
    ~WeighBill();

private:
    Ui::WeighBill *ui;
};

#endif // WEIGHBILL_H
