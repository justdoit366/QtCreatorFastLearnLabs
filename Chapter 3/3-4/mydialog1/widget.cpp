#include "widget.h"
#include "ui_widget.h"
#include <QDialog>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //连接信号和槽
    connect(ui->showChildButton, &QPushButton::clicked,
            this, &Widget::showChildDialog);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showChildDialog()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();
}
