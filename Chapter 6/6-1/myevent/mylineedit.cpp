#include "mylineedit.h"
#include <QKeyEvent>
#include <QDebug>

MyLineEdit::MyLineEdit(QWidget *parent):
    QLineEdit (parent)
{

}

//键盘按下事件
void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("MyLineEdit 键盘按下事件");
    QLineEdit::keyPressEvent(event);    //执行QLineEdit类的默认事件处理
    event->ignore();                    //忽略该事件。
}
