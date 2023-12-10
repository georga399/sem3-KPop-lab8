#include "passwordinfowidget.h"
#include "ui_passwordinfowidget.h"

#include "managers/managers/passwordManager.h"
PasswordInfoWidget::PasswordInfoWidget(QString key, QString password, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasswordInfoWidget)
{
    ui->setupUi(this);
    ui->keyValueLabel->setText(key);
    ui->passwordLine->setText(password);
}

PasswordInfoWidget::~PasswordInfoWidget()
{
    delete ui;
}

void PasswordInfoWidget::on_hideButton_clicked()
{
    this->hide();
    emit hideUI();
}


void PasswordInfoWidget::on_deleteButton_clicked()
{
    auto passwordManager = PasswordManager();
    auto stdKey = ui->keyValueLabel->text().toStdString();
    passwordManager.DeletePassword(stdKey);
    hide();
    emit hideUI();
}


void PasswordInfoWidget::on_updateButton_clicked()
{
    auto passwordManager = PasswordManager();
    auto stdKey = ui->keyValueLabel->text().toStdString();
    std::string pass = ui->passwordLine->text().toStdString();
    if(passwordManager.AddPassword(stdKey, pass))
    {
        this->hide();
        emit hideUI();
    }
}

