/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include "dialoglineedit.h"

QT_BEGIN_NAMESPACE

class Ui_DialogLogin
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    DialogLineEdit *leOperator;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    DialogLineEdit *lePassword;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogLogin)
    {
        if (DialogLogin->objectName().isEmpty())
            DialogLogin->setObjectName(QString::fromUtf8("DialogLogin"));
        DialogLogin->setWindowModality(Qt::ApplicationModal);
        DialogLogin->resize(268, 175);
        QFont font;
        font.setPointSize(11);
        DialogLogin->setFont(font);
        DialogLogin->setFocusPolicy(Qt::StrongFocus);
        DialogLogin->setModal(true);
        gridLayout = new QGridLayout(DialogLogin);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DialogLogin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        leOperator = new DialogLineEdit(DialogLogin);
        leOperator->setObjectName(QString::fromUtf8("leOperator"));

        horizontalLayout->addWidget(leOperator);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(DialogLogin);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lePassword = new DialogLineEdit(DialogLogin);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setFocusPolicy(Qt::StrongFocus);
        lePassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lePassword);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DialogLogin);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setFocusPolicy(Qt::StrongFocus);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        QWidget::setTabOrder(leOperator, lePassword);

        retranslateUi(DialogLogin);

        QMetaObject::connectSlotsByName(DialogLogin);
    } // setupUi

    void retranslateUi(QDialog *DialogLogin)
    {
        DialogLogin->setWindowTitle(QCoreApplication::translate("DialogLogin", "Login Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogLogin", "Operator : ", nullptr));
        leOperator->setInputMask(QString());
        leOperator->setText(QString());
        label_2->setText(QCoreApplication::translate("DialogLogin", "Password :", nullptr));
        lePassword->setInputMask(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogLogin: public Ui_DialogLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
