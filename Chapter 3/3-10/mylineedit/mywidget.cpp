#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QValidator>
#include <QRegExp>
#include <QCompleter>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    //新建验证器，指定范围为100-900
    //QValidator *validator = new QIntValidator(100, 999, this);


    //通过正则表达式限定字符
    //输入“-”号或者不输入，然后输入1~3个数字的限制
    QRegExp rx("-?\\d{1,3}");
    QValidator *validator = new QRegExpValidator(rx,this);

    //在行编辑器中使用验证器
    ui->lineEdit3->setValidator(validator);


    //自动补全
    QStringList wordList;
    wordList << "Qt" << "Qt Creator" <<"QQ Music"<< tr("你好");
    QCompleter *completer = new QCompleter(wordList, this); //新建自动完成器
    completer->setCaseSensitivity(Qt::CaseInsensitive); //设置大小写不敏感
    ui->lineEdit4->setCompleter(completer);

}

MyWidget::~MyWidget()
{
    delete ui;
}

//回车键按下信号的槽
void MyWidget::on_lineEdit2_returnPressed()
{
    //让lineEdit3获得焦点
    ui->lineEdit3->setFocus();
    //输出lineEdit2的内容
    qDebug()<< ui->lineEdit2->text();
    //输出lineEdit2显示的内容
    qDebug()<< ui->lineEdit2->displayText();
}

void MyWidget::on_lineEdit3_returnPressed()
{
    qDebug() << ui->lineEdit3->text();
}
