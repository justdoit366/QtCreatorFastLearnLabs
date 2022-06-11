#ifndef HELLODIALOG_H
#define HELLODIALOG_H

#include <QDialog>

//使用前置声明是为了加快编译速度，也可以避免在一个头文件
//中随意包含其他头文件而产生错误。因为，这里只使用了该类对象的指针，
//因此，可以使用前置声明
namespace Ui {
class HelloDialog;
}

class HelloDialog : public QDialog
{
    //扩展C++类的功能，信号与槽相关。
    Q_OBJECT
public:
    explicit HelloDialog(QWidget *parent = nullptr);
    ~HelloDialog();

private:
    Ui::HelloDialog *ui;
};

#endif // HELLODIALOG_H
