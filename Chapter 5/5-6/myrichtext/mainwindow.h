#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MySyntaxHighlighter;
class QLineEdit;
class QDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showTextFrame();//遍历文档框架
    void showTextBlock();//遍历所有文本块
    void setTextFont(bool checked);  //设置字体格式
    void insertTable(); //插入表格
    void insertList();  //插入列表
    void insertImage(); //插入图片
    void textFind();    //查找文本
    void findNext();    //查找下一个

private:
    Ui::MainWindow *ui;
    QLineEdit *lineEdit;
    QDialog *findDialog;
    MySyntaxHighlighter *highlighter;
};

#endif // MAINWINDOW_H
