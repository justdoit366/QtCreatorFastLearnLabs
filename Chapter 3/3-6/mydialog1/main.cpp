#include "mywidget.h"
#include <QApplication>
#include "mydialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    //新建MyDialog类对象
    MyDialog dialog;
    //判断dialog执行结果
    if(dialog.exec() == QDialog::Accepted) {
        //如果是按下了"进入主界面"按钮，则显示主界面
        w.show();
        //程序正常运行
        return a.exec();
    }
    else {
        //否则退出程序
        return 0;
    }

}
