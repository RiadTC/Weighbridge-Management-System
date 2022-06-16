/********************************************************************************
** Form generated from reading UI file 'OperatorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATORDIALOG_H
#define UI_OPERATORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include "Other/dialoglineedit.h"

QT_BEGIN_NAMESPACE

class Ui_OperatorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    DialogLineEdit *leOperatorName;
    QLabel *label_2;
    DialogLineEdit *leOperatorPass;
    QLabel *label_3;
    DialogLineEdit *leOperatorPass1;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OperatorDialog)
    {
        if (OperatorDialog->objectName().isEmpty())
            OperatorDialog->setObjectName(QString::fromUtf8("OperatorDialog"));
        OperatorDialog->setWindowModality(Qt::WindowModal);
        OperatorDialog->resize(400, 178);
        QFont font;
        font.setPointSize(12);
        OperatorDialog->setFont(font);
        OperatorDialog->setAcceptDrops(true);
        OperatorDialog->setModal(true);
        verticalLayout = new QVBoxLayout(OperatorDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(OperatorDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(false);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        leOperatorName = new DialogLineEdit(OperatorDialog);
        leOperatorName->setObjectName(QString::fromUtf8("leOperatorName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, leOperatorName);

        label_2 = new QLabel(OperatorDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        leOperatorPass = new DialogLineEdit(OperatorDialog);
        leOperatorPass->setObjectName(QString::fromUtf8("leOperatorPass"));
        leOperatorPass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, leOperatorPass);

        label_3 = new QLabel(OperatorDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        leOperatorPass1 = new DialogLineEdit(OperatorDialog);
        leOperatorPass1->setObjectName(QString::fromUtf8("leOperatorPass1"));
        leOperatorPass1->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, leOperatorPass1);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(OperatorDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(OperatorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OperatorDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OperatorDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OperatorDialog);
    } // setupUi

    void retranslateUi(QDialog *OperatorDialog)
    {
        OperatorDialog->setWindowTitle(QApplication::translate("OperatorDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("OperatorDialog", "Operator : ", nullptr));
        leOperatorName->setInputMask(QString());
        label_2->setText(QApplication::translate("OperatorDialog", "Password : ", nullptr));
        leOperatorPass->setInputMask(QString());
        label_3->setText(QApplication::translate("OperatorDialog", "Confirm Password : ", nullptr));
        leOperatorPass1->setInputMask(QString());
    } // retranslateUi

};

namespace Ui {
    class OperatorDialog: public Ui_OperatorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATORDIALOG_H
