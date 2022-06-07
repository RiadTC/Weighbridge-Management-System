/********************************************************************************
** Form generated from reading UI file 'CustomerDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERDIALOG_H
#define UI_CUSTOMERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CustomerDialog
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leName;
    QSpacerItem *horizontalSpacer;
    QRadioButton *rbActive;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lePhone1;
    QLabel *label_3;
    QLineEdit *lePhone2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *leFullName;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *leAccount;
    QLabel *label_6;
    QLineEdit *leOpening;

    void setupUi(QDialog *CustomerDialog)
    {
        if (CustomerDialog->objectName().isEmpty())
            CustomerDialog->setObjectName(QString::fromUtf8("CustomerDialog"));
        CustomerDialog->setWindowModality(Qt::WindowModal);
        CustomerDialog->resize(600, 327);
        gridLayout = new QGridLayout(CustomerDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(CustomerDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        buttonBox = new QDialogButtonBox(frame);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QFont font;
        font.setPointSize(12);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 6, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        leName = new QLineEdit(frame);
        leName->setObjectName(QString::fromUtf8("leName"));
        leName->setMaximumSize(QSize(200, 16777215));
        leName->setFont(font);

        horizontalLayout->addWidget(leName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 2);

        rbActive = new QRadioButton(frame);
        rbActive->setObjectName(QString::fromUtf8("rbActive"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rbActive->sizePolicy().hasHeightForWidth());
        rbActive->setSizePolicy(sizePolicy);
        rbActive->setFont(font);

        gridLayout_2->addWidget(rbActive, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        lePhone1 = new QLineEdit(frame);
        lePhone1->setObjectName(QString::fromUtf8("lePhone1"));
        lePhone1->setMinimumSize(QSize(100, 0));
        lePhone1->setFont(font);

        horizontalLayout_3->addWidget(lePhone1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        lePhone2 = new QLineEdit(frame);
        lePhone2->setObjectName(QString::fromUtf8("lePhone2"));
        lePhone2->setMinimumSize(QSize(100, 0));
        lePhone2->setFont(font);

        horizontalLayout_3->addWidget(lePhone2);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 0, 1, 2);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setLineWidth(4);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 5, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(100, 0));
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        leFullName = new QLineEdit(frame);
        leFullName->setObjectName(QString::fromUtf8("leFullName"));
        leFullName->setMinimumSize(QSize(300, 0));
        leFullName->setMaximumSize(QSize(16777215, 16777215));
        leFullName->setFont(font);

        horizontalLayout_2->addWidget(leFullName);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(100, 0));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        leAccount = new QLineEdit(frame);
        leAccount->setObjectName(QString::fromUtf8("leAccount"));
        leAccount->setMinimumSize(QSize(120, 0));
        leAccount->setFont(font);

        horizontalLayout_5->addWidget(leAccount);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_5->addWidget(label_6);

        leOpening = new QLineEdit(frame);
        leOpening->setObjectName(QString::fromUtf8("leOpening"));
        leOpening->setFont(font);

        horizontalLayout_5->addWidget(leOpening);


        gridLayout_2->addLayout(horizontalLayout_5, 3, 0, 1, 2);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(CustomerDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CustomerDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CustomerDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CustomerDialog);
    } // setupUi

    void retranslateUi(QDialog *CustomerDialog)
    {
        CustomerDialog->setWindowTitle(QCoreApplication::translate("CustomerDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CustomerDialog", "Name :", nullptr));
        rbActive->setText(QCoreApplication::translate("CustomerDialog", "Acti&ve", nullptr));
        label_2->setText(QCoreApplication::translate("CustomerDialog", "Phone 1:", nullptr));
        label_3->setText(QCoreApplication::translate("CustomerDialog", "Phone 2:", nullptr));
        label_4->setText(QCoreApplication::translate("CustomerDialog", "Full Name: ", nullptr));
        label_5->setText(QCoreApplication::translate("CustomerDialog", "Account No :", nullptr));
        label_6->setText(QCoreApplication::translate("CustomerDialog", "Opening Balance:", nullptr));
        leOpening->setText(QCoreApplication::translate("CustomerDialog", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerDialog: public Ui_CustomerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERDIALOG_H
