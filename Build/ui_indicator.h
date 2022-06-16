/********************************************************************************
** Form generated from reading UI file 'indicator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDICATOR_H
#define UI_INDICATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Indicator
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leStream;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *leDelimiter;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Indicator)
    {
        if (Indicator->objectName().isEmpty())
            Indicator->setObjectName(QString::fromUtf8("Indicator"));
        Indicator->resize(261, 139);
        Indicator->setMaximumSize(QSize(16777215, 16777212));
        gridLayout = new QGridLayout(Indicator);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Indicator);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        leStream = new QLineEdit(Indicator);
        leStream->setObjectName(QString::fromUtf8("leStream"));
        leStream->setMinimumSize(QSize(0, 0));
        leStream->setMaximumSize(QSize(30, 16777215));
        leStream->setFont(font);

        horizontalLayout->addWidget(leStream);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Indicator);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        leDelimiter = new QLineEdit(Indicator);
        leDelimiter->setObjectName(QString::fromUtf8("leDelimiter"));
        leDelimiter->setMaximumSize(QSize(30, 16777215));
        leDelimiter->setFont(font);

        horizontalLayout_2->addWidget(leDelimiter);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Indicator);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(Indicator);
        QObject::connect(buttonBox, SIGNAL(accepted()), Indicator, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Indicator, SLOT(reject()));

        QMetaObject::connectSlotsByName(Indicator);
    } // setupUi

    void retranslateUi(QDialog *Indicator)
    {
        Indicator->setWindowTitle(QApplication::translate("Indicator", "Dialog", nullptr));
        label->setText(QApplication::translate("Indicator", "Stream Length:", nullptr));
        label_2->setText(QApplication::translate("Indicator", "Delimiter:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Indicator: public Ui_Indicator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDICATOR_H
