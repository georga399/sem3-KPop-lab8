#ifndef PASSWORDADDWIDGET_H
#define PASSWORDADDWIDGET_H

#include <QWidget>

namespace Ui {
class PasswordAddWidget;
}

class PasswordAddWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordAddWidget(QWidget *parent = nullptr);
    ~PasswordAddWidget();

private slots:
    void on_saveButton_clicked();

    void on_generateButton_clicked();

signals:
    void hideUI();

private:
    Ui::PasswordAddWidget *ui;
};

#endif // PASSWORDADDWIDGET_H
