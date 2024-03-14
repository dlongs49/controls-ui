#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {
    this->resize(800, 500);

    layout_toast = new QHBoxLayout();
    layout_toast->setAlignment(Qt::AlignTop);
    QList<QString> list;
    list << "信息" << "成功" << "警告" << "失败" << "提示";
    for (int i = 0; i < 5; i++) {
        btnList[i] = new QPushButton(this);
        btnList[i]->setObjectName("btn_" + QString::number(i));
        btnList[i]->setText(list.at(i));
        btnList[i]->setFixedSize(100,32);
        btnList[i]->setCursor(Qt::PointingHandCursor);
        layout_toast->addWidget(btnList[i]);
        connect(btnList[i], &QPushButton::clicked, this, [=](){handleClick(i);});
    }
    widget_toast = new QWidget(this);
    widget_toast->setFixedSize(800, 50);
    widget_toast->setLayout(layout_toast);

    widget_dialog = new QWidget(this);
    widget_dialog->setFixedSize(800, 50);
    dialog_btn = new QPushButton();
    dialog_btn->setObjectName("dia_btn");
    dialog_btn->setText("提示框");
    dialog_btn->setCursor(Qt::PointingHandCursor);
    dialog_btn->setFixedSize(100,32);
    layout_dialog = new QHBoxLayout();
    layout_dialog->setAlignment(Qt::AlignLeft);
    layout_dialog->addWidget(dialog_btn);
    widget_dialog->setLayout(layout_dialog);

    layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignTop);
    layout->addWidget(widget_toast);
    layout->addWidget(widget_dialog);

    widget = new QWidget(this);
    widget->setFixedSize(800, 500);
    widget->setLayout(layout);



    toast = new Toast(this);
//    dialog = new Dialog(this);
}

int MainWindow::handleClick(int i) {
    if(i == 0){
        toast->info(this->size().width(),"一个信息提示");
    }else if(i == 1){
        toast->success(this->size().width(),"操作成功");
    }else if(i == 2){
        toast->warning(this->size().width(),"参数错误,请检查重试!");
    }else if(i == 3){
        toast->error(this->size().width(),"网络异常,请检查网络是否连接正常");
    }else if(i == 4){
        toast->message(this->size().width(),"轻提示");
    }
}
MainWindow::~MainWindow() {

}

