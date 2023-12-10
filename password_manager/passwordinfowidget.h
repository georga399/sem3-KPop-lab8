#ifndef PASSWORDINFOWIDGET_H
#define PASSWORDINFOWIDGET_H

#include <QWidget>

namespace Ui {
class PasswordInfoWidget;
}

class PasswordInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordInfoWidget(QString key, QString password, QWidget *parent = nullptr);
    ~PasswordInfoWidget();

private slots:
    void on_hideButton_clicked();

    void on_deleteButton_clicked();

    void on_updateButton_clicked();

signals:
       void hideUI();

private:
    Ui::PasswordInfoWidget *ui;
};

#endif // PASSWORDINFOWIDGET_H
