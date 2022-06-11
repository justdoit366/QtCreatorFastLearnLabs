#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPixmap>
#include <QMovie>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->frame->setFrameShape(QFrame::Box);
    ui->frame->setFrameShadow(QFrame::Sunken);
    //以上两个函数可以使用
    //setFrameStyle(QFrame::Box | QFrame::Sunken)代替
    ui->frame->setLineWidth(5);
    ui->frame->setMidLineWidth(10);

    QFont font;
    font.setFamily("华文正楷");
    font.setPointSize(20);
    font.setBold(true);
    font.setItalic(true);
    ui->label->setFont(font);

    //自动忽略过长的内容
    QString string = tr("标题太长，需要进行省略!");
    QString str = ui->label->fontMetrics().elidedText(string, Qt::ElideRight, 180);
    ui->label->setText(str);

    //显示图片
    ui->label->setPixmap(QPixmap("../../../Res/logo.png"));

    //显示gif
    QMovie *movie = new QMovie("../../../Res/giphy.gif");
    //在标签中添加动画
    ui->label->setMovie(movie);
    //开始播放
    movie->start();

}

MyWidget::~MyWidget()
{
    delete ui;
}
