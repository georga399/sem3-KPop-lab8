#include "authwidget.h"
#include "ui_authwidget.h"

#include "mainwindow.h"
#include <QDebug>
#include <QString>
#include <string>
#include "managers/managers/passwordManager.h"

AuthWidget::AuthWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthWidget)
{
    ui->setupUi(this);
}

AuthWidget::~AuthWidget()
{
    delete ui;
}

void AuthWidget::on_SignButton_clicked()
{
    std::string username = ui->usernameLineEdit->text().toStdString();
    std::string pass = ui->passwordLineEdit->text().toStdString();
    if(username == "" || pass == "")
        return;
    qDebug() << QString::fromStdString(username);
    qDebug() << QString::fromStdString(pass);
    auto passwordManager = PasswordManager();
    if(passwordManager.Login(username, pass))
    {
        this->hide();
        auto mw = new MainWindow();
        mw->show();
    }

}

