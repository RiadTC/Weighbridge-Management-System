/********************************************************************************
** Form generated from reading UI file 'ItemDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMDIALOG_H
#define UI_ITEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ItemDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *leLongDesc;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leShortDesc;
    QSpacerItem *horizontalSpacer;
    QRadioButton *rbSale;

    void setupUi(QDialog *ItemDialog)
    {
        if (ItemDialog->objectName().isEmpty())
            ItemDialog->setObjectName(QString::fromUtf8("ItemDialog"));
        ItemDialog->setWindowModality(Qt::WindowModal);
        ItemDialog->resize(400, 194);
        gridLayout_2 = new QGridLayout(ItemDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ItemDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        leLongDesc = new QLineEdit(ItemDialog);
        leLongDesc->setObjectName(QString::fromUtf8("leLongDesc"));

        horizontalLayout_2->addWidget(leLongDesc);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ItemDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ItemDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        leShortDesc = new QLineEdit(ItemDialog);
        leShortDesc->setObjectName(QString::fromUtf8("leShortDesc"));
        leShortDesc->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leShortDesc->sizePolicy().hasHeightForWidth());
        leShortDesc->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(leShortDesc);

        horizontalSpacer = new QSpacerItem(44, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        rbSale = new QRadioButton(ItemDialog);
        rbSale->setObjectName(QString::fromUtf8("rbSale"));
        rbSale->setFont(font);

        gridLayout->addWidget(rbSale, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        QWidget::setTabOrder(leShortDesc, leLongDesc);

        retranslateUi(ItemDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ItemDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ItemDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ItemDialog);
    } // setupUi

    void retranslateUi(QDialog *ItemDialog)
    {
        ItemDialog->setWindowTitle(QCoreApplication::translate("ItemDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("ItemDialog", "Long Description : ", nullptr));
        label->setText(QCoreApplication::translate("ItemDialog", "Short Description : ", nullptr));
        rbSale->setText(QCoreApplication::translate("ItemDialog", "Sales Item", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ItemDialog: public Ui_ItemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMDIALOG_H
