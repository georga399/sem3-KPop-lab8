#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "passwordaddwidget.h"
#include "QDebug"
#include "authwidget.h"
#include "passwordinfowidget.h"

#include "managers/managers/passwordManager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateList();
//    QObject::connect(ui->widget->);
//    connect(ui->widget, SIGNAL(ui->widget->hide()), this, SLOT(hide()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    auto layout = ui->widget->layout();
    if(layout == nullptr)
    {
        ui->widget->setLayout(new QVBoxLayout);
        layout = ui->widget->layout();
    }
    else
    {
        while (layout->count()>0)
        {
          auto item = layout->takeAt(0);
          item->widget()->hide();
          delete item;
        }
    }
//    layout->addWidget(new PasswordAddWidget);
    auto passwordAddWidget = new PasswordAddWidget(this);
    layout->addWidget(passwordAddWidget);
    QObject::connect(passwordAddWidget, SIGNAL(hideUI()), this, SLOT(updateList()));
}

void MainWindow::on_logoutButton_clicked()
{
    this->hide();
    auto authW = new AuthWidget();
    authW->show();
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    auto layout = ui->widget->layout();
    if(layout == nullptr)
    {
        ui->widget->setLayout(new QVBoxLayout);
        layout = ui->widget->layout();
    }
    else
    {
        while (layout->count()>0)
        {
          auto item = layout->takeAt(0);
          item->widget()->hide();
          delete item;
        }
    }
    auto passwordManager = PasswordManager();
    auto key = item->text();
    auto stdKey = key.toStdString();
    auto stdPass = passwordManager.GetPassword(stdKey);
    auto passwordInfoWidget = new PasswordInfoWidget(key, QString::fromStdString(stdPass), this);
    layout->addWidget(passwordInfoWidget);
    QObject::connect(passwordInfoWidget, SIGNAL(hideUI()), this, SLOT(updateList()));
}

void MainWindow::updateList()
{
    ui->listWidget->clear();
    PasswordManager passwordManager;
    auto keys = passwordManager.GetAllKeys();
    for(auto &&k : keys)
    {
        ui->listWidget->addItem(QString::fromStdString(k));
    }

}
