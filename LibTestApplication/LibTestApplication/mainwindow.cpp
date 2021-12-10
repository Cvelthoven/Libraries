#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "libapplicationsettings.h"

#include <QString>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    int i = 0;
    i++;
//-----------------------------------------------------------------------------
//
//  Tests for LibApplicationSettings functions
//
  QString const strDomain = "CVelthoven.com";
  QString const strApplication = "LibTestApplication";
  QString const strOrganization = "CVelthoven";
  LibApplicationSettings *ApllicationSettings = new LibApplicationSettings(strDomain, strOrganization, strApplication);

//  Retrieve a value
    QString strTestSection  = "testSection";
    QString strTestKey      = "testKey";
    QString strTestValue = ApllicationSettings->GetAppSetting(strTestSection, strTestKey);
    qDebug() << "KeyValue: " << strTestValue;

// Set a value
    strTestValue      = "testValue";
    ApllicationSettings->SetAppSetting(strTestSection, strTestKey,strTestValue);

//  Retrieve a value
    strTestValue = ApllicationSettings->GetAppSetting(strTestSection, strTestKey);
    qDebug() << "KeyValue: " << strTestValue;


  ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

