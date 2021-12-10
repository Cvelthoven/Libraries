#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "libapplicationsettings.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    int i = 0;
    i++;
//    LibApplicationSettings *ApllicationSettings = new LibApplicationSettings();
//
  QString const strDomain = "CVelthoven.com";
  QString const strApplication = "LibTestApplication";
  QString const strOrganization = "CVelthoven";
  LibApplicationSettings *ApllicationSettings = new LibApplicationSettings(strDomain, strOrganization, strApplication);
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

