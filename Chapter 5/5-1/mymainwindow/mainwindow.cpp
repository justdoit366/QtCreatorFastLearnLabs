#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QActionGroup>
#include <QToolButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //添加编辑菜单
    QMenu *editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));
    //添加打开菜单
    QAction *action_Open = editMenu->addAction(
    QIcon(":/image/images/open.png"), tr("打开文件(&O)"));
    //设置快捷键
    action_Open->setShortcut(QKeySequence("Ctrl+O"));
    //在工具栏中添加动作
    ui->mainToolBar->addAction(action_Open);

    //建立动作组
    QActionGroup *group = new QActionGroup(this);
    //向动作组中添加动作
    QAction *action_L = group->addAction(tr("左对齐(&L)"));
    //设置动作checkable属性为true
    action_L->setCheckable(true);
    QAction *action_R = group->addAction(tr("右对齐(&R)"));
    action_R->setCheckable(true);
    QAction *action_C = group->addAction(tr("居中(&C)"));
    action_C->setCheckable(true);
    //最后指定action_L为选中状态
    action_L->setChecked(true);
    //向菜单中添加间隔器
    editMenu->addSeparator();
    //向菜单中添加动作
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);

    //创建QToolButton
    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setText(tr("颜色"));
    //创建一个菜单
    QMenu *colorMenu = new QMenu(this);
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    //添加菜单
    toolBtn->setMenu(colorMenu);
    //设置弹出模式
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);
    //向工具栏添加QToolButton按钮
    ui->mainToolBar->addWidget(toolBtn);
    //创建QSpinBox
    QSpinBox *spinBox = new QSpinBox(this);
    //向工具栏添加QSpinBox部件
    ui->mainToolBar->addWidget(spinBox);

    //启动时先隐藏dock部件
    ui->dockWidget->hide();

    //显示临时消息，显示2000毫秒即2秒
    ui->statusBar->showMessage(tr("欢迎使用多文档编辑器"),2000);
    //创建标签，设置标签样式并显示信息，然后将其以永久部件的形式添加到状态栏
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("www.qter.org");
    ui->statusBar->addPermanentWidget(permanent);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_New_triggered()
{
    //新建文本编辑器部件
    QTextEdit *edit = new QTextEdit(this);
    //使用QMdiArea类的addSubWindow()函数创建子窗口，以文本编辑器为中心部件
    QMdiSubWindow *child = ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle(tr("多文档编辑器子窗口"));
    child->show();
}

void MainWindow::on_action_Dock_triggered()
{
    ui->dockWidget->show();

}
