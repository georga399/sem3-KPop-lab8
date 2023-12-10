#ifndef AUTHWIDGET_H
#define AUTHWIDGET_H

#include <QWidget>

namespace Ui {
class AuthWidget;
}

class AuthWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AuthWidget(QWidget *parent = nullptr);
    ~AuthWidget();

private slots:
    void on_SignButton_clicked();

private:
    Ui::AuthWidget *ui;
};

#endif // AUTHWIDGET_H
