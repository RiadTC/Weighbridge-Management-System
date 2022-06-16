/********************************************************************************
** Form generated from reading UI file 'noticedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTICEDIALOG_H
#define UI_NOTICEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_NoticeDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QDialog *NoticeDialog)
    {
        if (NoticeDialog->objectName().isEmpty())
            NoticeDialog->setObjectName(QString::fromUtf8("NoticeDialog"));
        NoticeDialog->resize(434, 87);
        gridLayout = new QGridLayout(NoticeDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(NoticeDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(NoticeDialog);

        QMetaObject::connectSlotsByName(NoticeDialog);
    } // setupUi

    void retranslateUi(QDialog *NoticeDialog)
    {
        NoticeDialog->setWindowTitle(QApplication::translate("NoticeDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("NoticeDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoticeDialog: public Ui_NoticeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTICEDIALOG_H
