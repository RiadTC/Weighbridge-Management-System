#include "miscfunc.h"

#include <QSqlQuery>
#include <QSqlError>

void UpdateTransationBalance(Ticket *CurTicket, QSqlDatabase db)
{
    QSqlQuery Query(db);
    int ListNo, AccountNo;
    float Price, Amount;

    // Get Price List for customer
    Query.prepare("SELECT PriceList, AccountNo FROM Customer WHERE (CustomerID = :Val1)");
    Query.bindValue(":Val1", CurTicket->CustomerID);
    if (Query.exec()) Query.next();
    else qDebug() << Query.lastError();
    ListNo = Query.record().value("PriceList").toInt();
    AccountNo = Query.record().value("AccountNo").toInt();
    // Get Price for item from price list
    Query.prepare("SELECT Price FROM PriceList WHERE ((ListID = :Val1) AND (Item = :Val2))");
    Query.bindValue(":Val1", ListNo);
    Query.bindValue(":Val2", CurTicket->ItemID);
    if (Query.exec()) Query.next();
    else qDebug() << Query.lastError();
    Price = Query.record().value("Price").toFloat();
    Amount = Price * (CurTicket->Full - CurTicket->Empty) / 1000.0;
    // register operation in transactions table
    Query.prepare("INSERT INTO Transactions (Ticket, Customer, Amount)"
                  " VALUES (:Val1, :Val2, :Val3)");
    Query.bindValue(":Val1", CurTicket->id);
    Query.bindValue(":Val2", CurTicket->CustomerID);
    Query.bindValue(":Val3", Amount);
    if (!Query.exec()) qDebug() << Query.lastError();
    // Update account balance for customer
    Query.prepare("UPDATE Accounts SET Balance = Balance + :Val1 WHERE AccountNo = :Val2");
    Query.bindValue(":Val1", Amount);
    Query.bindValue(":Val2", AccountNo);
    if (!Query.exec()) qDebug() << Query.lastError();

}
