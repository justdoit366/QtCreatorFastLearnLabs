#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QProgressDialog>
#include <QErrorMessage>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    errordlg = new QErrorMessage(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_showColorDialog_clicked()
{
    //直接调用调色板对话框
    //QColor color = QColorDialog::getColor(Qt::red, this, tr("颜色对话框"),
    //                                      QColorDialog::ShowAlphaChannel);
    //qDebug() << "color: " << color;

    //创建对象
    QColorDialog dialog(Qt::red, this);
    //显示alpha选项
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    //以模态方式运行对话框
    dialog.exec();
    //获取当前颜色
    QColor color = dialog.currentColor();
    //输出颜色信息
    qDebug() << "color: " << color;
}

void MyWidget::on_showFileDialog_clicked()
{
    //QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("文件对话框"),
    //                                               "D:", tr("图片文件( *png *jpg);;文本文件(*txt)"));
    //qDebug() << "fileNames:" << fileNames;
    QString fileName = QFileDialog::getOpenFileName(this, tr("文件对话框"),
                                                    "D:", tr("图片文件( *png *jpg);;文本文件(*txt)"));
    qDebug() << "fileName:" << fileName;
}

void MyWidget::on_showFontDialog_clicked()
{

    //ok用于标记是否单击了OK按钮
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    QString text = "没有选择字体";
    std::string testStr= "我就试试";

    //如果单机OK按钮，那么让"字体对话框"按钮使用新字体
    //如果单击Cancel按钮，那么输出信息
    if(ok) ui->showFontDialog->setFont(font);
    else qDebug() << tr("没有选择字体!");

}

void MyWidget::on_showInputDialog_clicked()
{
    bool ok;
    //获取字符串
    QString string = QInputDialog::getText(this, tr("输入字符串对话框"),
                                          tr("请输入用户名:"), QLineEdit::Normal, tr("admin"), &ok);
    if(ok) qDebug() << "string:" << string;
    //获取整数
    int value1 = QInputDialog::getInt(this, tr("输入整数对话框"),
                                      tr("请输入 -1000到1000之间的数值"), 100, -1000, 1000, 10, &ok);
    if(ok) qDebug() << "value1:" << value1;
    //获取浮点数
    double value2 = QInputDialog::getDouble(this, tr("输入浮点数对话框"),
                                            tr("请输入 -1000到1000之间的数值"), 0.00, -1000, 1000, 2, &ok);
    if(ok) qDebug() << "value2:" <<value2;
    QStringList items;
    items << tr("条目1") << tr("条目2");
    //获取条目
    QString item = QInputDialog::getItem(this, tr("输入条目对话框"),
                                         tr("请选择或输入一个条目"), items, 0, true, &ok);
    if(ok) qDebug() << "item:" << item;
}

void MyWidget::on_showMsgDialog_clicked()
{
    //问题对话框
    int ret1 = QMessageBox::question(this, tr("问题对话框"),
                                     tr("你了解Qt吗?"), QMessageBox::Yes, QMessageBox::No);
    if(ret1 == QMessageBox::Yes) qDebug() << tr("问题!");
    //提示对话框
    int ret2 = QMessageBox::information(this, tr("提示对话框"),
                                        tr("这是Qt书籍!"), QMessageBox::Ok);
    if(ret2 == QMessageBox::Ok) qDebug() << tr("提示");
    //警告对话框
    int ret3 = QMessageBox::warning(this, tr("警告对话框"),
                                    tr("不能提前结束!"), QMessageBox::Abort);
    if(ret3 == QMessageBox::Abort) qDebug() << tr("警告!");
    //错误对话框
    int ret4 = QMessageBox::critical(this, tr("严重错误对话框"),
                                     tr("发现一个严重错误!现在要关闭所有文件!"), QMessageBox::YesAll);
    if(ret4 == QMessageBox::YesAll) qDebug() << tr("错误");
    //关于对话框
    QMessageBox::about(this, tr("关于对话框"), tr("好好学习，天天向上!"));
}

void MyWidget::on_showProgressDialog_clicked()
{
    QProgressDialog dialog(tr("文件复制进度"),tr("取消"), 0, 50000, this);
    //设置窗口标题
    dialog.setWindowTitle(tr("进度对话框"));
    //将对话框设置为模态
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();
    //演示复制进度
    for (int i=0; i < 50000; i++) {
        dialog.setValue(i);
        //避免界面冻结
        QCoreApplication::processEvents();
        //按下取消按钮则中断
        if(dialog.wasCanceled())
            break;
    }
    //这样才能显示100%，因为for循环中少加了一个数
    dialog.setValue(50000);
    qDebug() << tr("复制结束!");
}

void MyWidget::on_showErrorMsgDialog_clicked()
{
    errordlg->setWindowTitle(tr("错误信息对话框"));
    errordlg->showMessage(tr("这里是出错信息!"));

}

//向导页面1
QWizardPage *MyWidget::createPage1()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("介绍");
    return page;
}

//向导页面2
QWizardPage *MyWidget::createPage2()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("用户选择信息"));
    return page;
}

//向导页面3
QWizardPage *MyWidget::createPage3()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("结束"));
    return page;
}

void MyWidget::on_showWizardDialog_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("向导对话框"));
    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();
}
