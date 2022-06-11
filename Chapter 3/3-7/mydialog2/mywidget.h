#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QWizard>

class QErrorMessage;

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void on_showColorDialog_clicked();

    void on_showFileDialog_clicked();

    void on_showFontDialog_clicked();

    void on_showInputDialog_clicked();

    void on_showMsgDialog_clicked();

    void on_showProgressDialog_clicked();

    void on_showErrorMsgDialog_clicked();

    void on_showWizardDialog_clicked();

private:
    Ui::MyWidget *ui;
    QErrorMessage *errordlg;
    QWizardPage *createPage1();
    QWizardPage *createPage2();
    QWizardPage *createPage3();
};

#endif // MYWIDGET_H
