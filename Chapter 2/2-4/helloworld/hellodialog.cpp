#include "hellodialog.h"
#include "ui_hellodialog.h"

HelloDialog::HelloDialog(QWidget *parent):
    QDialog(parent),ui(new Ui::HelloDialog)
{
    //ui = new Ui::HelloDialog;
    //为该类所代表的对话框创建界面
    ui->setupUi(this);
}

HelloDialog::~HelloDialog()
{
    delete ui;
}
