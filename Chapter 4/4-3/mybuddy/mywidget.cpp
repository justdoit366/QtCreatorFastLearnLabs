#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    //lineEdit在spinBox前面
    setTabOrder(ui->lineEdit, ui->spinBox);
    //spinBox在pushButton前面
    setTabOrder(ui->spinBox, ui->pushButton);
    //pushButton在checkBox前面
    setTabOrder(ui->pushButton, ui->checkBox);
}

MyWidget::~MyWidget()
{
    delete ui;
}
