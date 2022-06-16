/********************************************************************************
** Form generated from reading UI file 'ServerDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERDIALOG_H
#define UI_SERVERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include "Other/dialoglineedit.h"

QT_BEGIN_NAMESPACE

class Ui_ServerDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    DialogLineEdit *leDatabase;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    DialogLineEdit *leHost;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    DialogLineEdit *lePort;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    DialogLineEdit *leUserN;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    DialogLineEdit *lePassw;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ServerDialog)
    {
        if (ServerDialog->objectName().isEmpty())
            ServerDialog->setObjectName(QString::fromUtf8("ServerDialog"));
        ServerDialog->resize(400, 300);
        QPalette palette;
        ServerDialog->setPalette(palette);
        ServerDialog->setAutoFillBackground(true);
        gridLayout = new QGridLayout(ServerDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ServerDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(130, 0));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        leDatabase = new DialogLineEdit(ServerDialog);
        leDatabase->setObjectName(QString::fromUtf8("leDatabase"));

        horizontalLayout->addWidget(leDatabase);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(ServerDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(130, 0));
        label_2->setFont(font);

        horizontalLayout_5->addWidget(label_2);

        leHost = new DialogLineEdit(ServerDialog);
        leHost->setObjectName(QString::fromUtf8("leHost"));

        horizontalLayout_5->addWidget(leHost);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(ServerDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(130, 0));
        label_5->setFont(font);

        horizontalLayout_2->addWidget(label_5);

        lePort = new DialogLineEdit(ServerDialog);
        lePort->setObjectName(QString::fromUtf8("lePort"));

        horizontalLayout_2->addWidget(lePort);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(ServerDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(130, 0));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        leUserN = new DialogLineEdit(ServerDialog);
        leUserN->setObjectName(QString::fromUtf8("leUserN"));

        horizontalLayout_3->addWidget(leUserN);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(ServerDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(130, 0));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        lePassw = new DialogLineEdit(ServerDialog);
        lePassw->setObjectName(QString::fromUtf8("lePassw"));
        lePassw->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(lePassw);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ServerDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        gridLayout->addWidget(buttonBox, 5, 0, 1, 1);


        retranslateUi(ServerDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ServerDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ServerDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ServerDialog);
    } // setupUi

    void retranslateUi(QDialog *ServerDialog)
    {
        ServerDialog->setWindowTitle(QApplication::translate("ServerDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("ServerDialog", "Database :", nullptr));
        label_2->setText(QApplication::translate("ServerDialog", "Host :", nullptr));
        label_5->setText(QApplication::translate("ServerDialog", "Port :", nullptr));
        label_3->setText(QApplication::translate("ServerDialog", "User Name:", nullptr));
        label_4->setText(QApplication::translate("ServerDialog", "Password:", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonBox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class ServerDialog: public Ui_ServerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERDIALOG_H
