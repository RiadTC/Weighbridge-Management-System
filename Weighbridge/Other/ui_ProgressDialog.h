/********************************************************************************
** Form generated from reading UI file 'ProgressDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSDIALOG_H
#define UI_PROGRESSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_ProgDialog
{
public:
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QFrame *ProgDialog)
    {
        if (ProgDialog->objectName().isEmpty())
            ProgDialog->setObjectName(QString::fromUtf8("ProgDialog"));
        ProgDialog->setWindowModality(Qt::WindowModal);
        ProgDialog->resize(400, 145);
        ProgDialog->setFrameShape(QFrame::StyledPanel);
        ProgDialog->setFrameShadow(QFrame::Raised);
        label = new QLabel(ProgDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 261, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        progressBar = new QProgressBar(ProgDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(30, 90, 341, 23));
        progressBar->setValue(24);

        retranslateUi(ProgDialog);

        QMetaObject::connectSlotsByName(ProgDialog);
    } // setupUi

    void retranslateUi(QFrame *ProgDialog)
    {
        ProgDialog->setWindowTitle(QCoreApplication::translate("ProgDialog", "Frame", nullptr));
        label->setText(QCoreApplication::translate("ProgDialog", "Transactions import in progress...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgDialog: public Ui_ProgDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSDIALOG_H
