#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QtHelp/QHelpEngine>
#include <QtHelp/QHelpContentWidget>
#include <QtHelp/QHelpIndexWidget>
#include <QTextBrowser>

class HelpBrowser : public QTextBrowser
{
public:

    HelpBrowser(QHelpEngine* helpEngine, QWidget* parent = 0);
    QVariant loadResource (int type, const QUrl& name);
private:
    QHelpEngine* helpEngine;
};

HelpBrowser::HelpBrowser(QHelpEngine* helpEngine,
                         QWidget* parent):QTextBrowser(parent),
                         helpEngine(helpEngine)
{
}

QVariant HelpBrowser::loadResource(int type, const QUrl &name){
    if (name.scheme() == "qthelp")
        return QVariant(helpEngine->fileData(name));
    else
        return QTextBrowser::loadResource(type, name);
}

void MainWindow::on_actionContents_triggered()
{
    QHelpEngine* helpEngine ;
    HelpBrowser *tbHelp;
    static bool isNew = true;
    QString Path;

   if (isNew)
   {    Path = QCoreApplication::applicationDirPath()+"/Help/help.qhc";
        helpEngine = new QHelpEngine(Path);
        helpEngine->setupData();
        tbHelp = new HelpBrowser(helpEngine);
        ui->splitter_2->insertWidget(1, tbHelp);
        ui->twHelp->removeTab(0);
        ui->twHelp->removeTab(0);
        ui->twHelp->addTab(helpEngine->contentWidget(), "Contents");
        ui->twHelp->addTab(helpEngine->indexWidget(), "Index");
        tbHelp->setSource(QUrl(QCoreApplication::applicationDirPath()+"/Help/index.html"));
        connect(helpEngine->contentWidget(), SIGNAL(linkActivated(QUrl)), tbHelp, SLOT(setSource(QUrl)));
        connect(helpEngine->indexWidget(), SIGNAL(linkActivated(QUrl, QString)),  tbHelp, SLOT(setSource(QUrl)));
        isNew = false;
   }
   ui->tabWidget->addTab(ReportTab[13], "Help");
   ui->tabWidget->setCurrentWidget(ReportTab[13]);
   ui->twHelp->setCurrentIndex(0);
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About"), tr("WMS\n"
                              "Weighbridge Management System\n"
                              "Version 0.1"));
}

