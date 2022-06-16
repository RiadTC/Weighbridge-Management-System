/********************************************************************************
** Form generated from reading UI file 'Customers.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERS_H
#define UI_CUSTOMERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Customers
{
public:
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pbAddCustomer;
    QPushButton *pbModCustomer;
    QPushButton *pbDelCustomer;
    QSpacerItem *verticalSpacer;
    QPushButton *pbClose;
    QListView *lvCustomers;

    void setupUi(QDockWidget *Customers)
    {
        if (Customers->objectName().isEmpty())
            Customers->setObjectName(QString::fromUtf8("Customers"));
        Customers->resize(649, 449);
        Customers->setAutoFillBackground(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        pbAddCustomer = new QPushButton(dockWidgetContents);
        pbAddCustomer->setObjectName(QString::fromUtf8("pbAddCustomer"));

        verticalLayout->addWidget(pbAddCustomer);

        pbModCustomer = new QPushButton(dockWidgetContents);
        pbModCustomer->setObjectName(QString::fromUtf8("pbModCustomer"));

        verticalLayout->addWidget(pbModCustomer);

        pbDelCustomer = new QPushButton(dockWidgetContents);
        pbDelCustomer->setObjectName(QString::fromUtf8("pbDelCustomer"));

        verticalLayout->addWidget(pbDelCustomer);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pbClose = new QPushButton(dockWidgetContents);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));

        verticalLayout->addWidget(pbClose);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        lvCustomers = new QListView(dockWidgetContents);
        lvCustomers->setObjectName(QString::fromUtf8("lvCustomers"));
        lvCustomers->setAlternatingRowColors(true);
        lvCustomers->setIconSize(QSize(10, 10));
        lvCustomers->setLayoutMode(QListView::SinglePass);
        lvCustomers->setSelectionRectVisible(true);

        gridLayout->addWidget(lvCustomers, 0, 0, 1, 1);

        Customers->setWidget(dockWidgetContents);

        retranslateUi(Customers);

        QMetaObject::connectSlotsByName(Customers);
    } // setupUi

    void retranslateUi(QDockWidget *Customers)
    {
        Customers->setWindowTitle(QApplication::translate("Customers", "&Customers", nullptr));
        pbAddCustomer->setText(QApplication::translate("Customers", "New", nullptr));
        pbModCustomer->setText(QApplication::translate("Customers", "Modify", nullptr));
        pbDelCustomer->setText(QApplication::translate("Customers", "Delete", nullptr));
        pbClose->setText(QApplication::translate("Customers", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Customers: public Ui_Customers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERS_H
