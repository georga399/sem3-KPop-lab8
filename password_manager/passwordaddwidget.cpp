#include "passwordaddwidget.h"
#include "ui_passwordaddwidget.h"

#include "managers/managers/passwordManager.h"

PasswordAddWidget::PasswordAddWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasswordAddWidget)
{
    ui->setupUi(this);
}

PasswordAddWidget::~PasswordAddWidget()
{
    delete ui;
}

void PasswordAddWidget::on_saveButton_clicked()
{
    std::string key = ui->keyLineEdit->text().toStdString();
    std::string pass = ui->passwordLineEdit->text().toStdString();
    size_t spaceFound = key.find(' ');
    if(spaceFound >= 0 && spaceFound<key.size())
        return;
    if(key == "" || pass == "")
        return;
    auto passwordManager = PasswordManager();
    if(passwordManager.AddPassword(key, pass))
    {
        emit hideUI();
        this->hide();
    }
}


void PasswordAddWidget::on_generateButton_clicked()
{
    auto passwordManager = PasswordManager();
    std::string generatedPass = passwordManager.GenPassword(20);
    ui->passwordLineEdit->setText(QString::fromStdString(generatedPass));
}

