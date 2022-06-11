#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void on_spinBox_valueChanged(const QString &arg1);

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
