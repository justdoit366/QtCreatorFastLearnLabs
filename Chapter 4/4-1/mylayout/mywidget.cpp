#include "mywidget.h"
#include "ui_mywidget.h"
#include <QHBoxLayout>
#include <QGridLayout>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
      //新建水平布局管理器
//    QHBoxLayout *layout = new QHBoxLayout;
//    //向布局管理器中添加部件
//    layout->addWidget(ui->fontComboBox);
//    layout->addWidget(ui->textEdit);
//    //设置布局间的间隔
//    layout->setSpacing(50);
//    //设置布局管理器到边界的距离
//    //4个参数顺序是左，上，右，下
//    layout->setContentsMargins(0,0,50,100);
//    //将这个布局设置为MyWidget类的布局
//    setLayout(layout);


    //新建栅格布局管理器（QGridLayout）
//    QGridLayout *layout = new QGridLayout;
//    //添加部件，从第0行0列开始，占据1行2列
//    layout->addWidget(ui->fontComboBox, 0, 0, 1, 2);
//    //添加部件，从第0行2列开始，占据1行1列
//    layout->addWidget(ui->pushButton, 0, 2, 1, 1);
//    //添加部件，从第1行0列开始，占据1行3列
//    layout->addWidget(ui->textEdit, 1, 0, 1, 3);
//    setLayout(layout);

    //让文本编辑器隐藏，也可以使用setVisible(false)函数
    ui->textEdit->hide();

}

MyWidget::~MyWidget()
{
    delete ui;
}

//显示隐藏窗口按钮
void MyWidget::on_pushButton_toggled(bool checked)
{
    //设置文本编辑器的显示和隐藏
    ui->textEdit->setVisible(checked);
    if(checked)
        ui->pushButton->setText(tr("隐藏可扩展窗口"));
    else {
        ui->pushButton->setText("显示可扩展窗口");
    }
}
