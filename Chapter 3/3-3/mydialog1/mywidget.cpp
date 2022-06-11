#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    //局部变量，因此函数结束后，自动释放掉该对话框
    //QDialog dialog(this);
    //dialog.show();
    //堆变量，因此能一直存在
    QDialog *dialog = new QDialog(this);
    //dialog->setModal(true);
    dialog->setWindowModality(Qt::ApplicationModal);
    dialog->show();
    //模态窗口，阻塞不反回
    //QDialog dialog(this);
    //dialog.exec();
}

MyWidget::~MyWidget()
{
    delete ui;
}
