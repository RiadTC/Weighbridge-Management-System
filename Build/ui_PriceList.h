/********************************************************************************
** Form generated from reading UI file 'PriceList.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRICELIST_H
#define UI_PRICELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PriceList
{
public:
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QSplitter *splitter_2;
    QLabel *label;
    QLineEdit *lePriceName;
    QTableView *tvPriceList;
    QSplitter *splitter;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;

    void setupUi(QDockWidget *PriceList)
    {
        if (PriceList->objectName().isEmpty())
            PriceList->setObjectName(QString::fromUtf8("PriceList"));
        PriceList->setWindowModality(Qt::NonModal);
        PriceList->resize(650, 430);
        PriceList->setAutoFillBackground(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        dockWidgetContents->setBaseSize(QSize(0, 0));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter_2 = new QSplitter(dockWidgetContents);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        splitter_2->addWidget(label);
        lePriceName = new QLineEdit(splitter_2);
        lePriceName->setObjectName(QString::fromUtf8("lePriceName"));
        lePriceName->setMinimumSize(QSize(60, 0));
        lePriceName->setMaximumSize(QSize(140, 16777215));
        splitter_2->addWidget(lePriceName);

        gridLayout->addWidget(splitter_2, 0, 0, 1, 2);

        tvPriceList = new QTableView(dockWidgetContents);
        tvPriceList->setObjectName(QString::fromUtf8("tvPriceList"));

        gridLayout->addWidget(tvPriceList, 1, 0, 1, 1);

        splitter = new QSplitter(dockWidgetContents);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        pushButton_2 = new QPushButton(splitter);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(16777215, 40));
        splitter->addWidget(pushButton_2);
        pushButton_3 = new QPushButton(splitter);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(111111, 40));
        splitter->addWidget(pushButton_3);
        pushButton_4 = new QPushButton(splitter);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(16777215, 40));
        splitter->addWidget(pushButton_4);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(16777215, 40));
        splitter->addWidget(pushButton);

        gridLayout->addWidget(splitter, 1, 1, 1, 1);

        PriceList->setWidget(dockWidgetContents);

        retranslateUi(PriceList);

        QMetaObject::connectSlotsByName(PriceList);
    } // setupUi

    void retranslateUi(QDockWidget *PriceList)
    {
        PriceList->setWindowTitle(QApplication::translate("PriceList", "Price Level Lists", nullptr));
        label->setText(QApplication::translate("PriceList", "Price List Name:", nullptr));
        pushButton_2->setText(QApplication::translate("PriceList", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("PriceList", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("PriceList", "PushButton", nullptr));
        pushButton->setText(QApplication::translate("PriceList", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PriceList: public Ui_PriceList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRICELIST_H
