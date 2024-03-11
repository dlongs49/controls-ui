#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {
    this->resize(800, 500);

    layouts = new QHBoxLayout();
    layouts->setAlignment(Qt::AlignTop);
    QList<QString> list;
    list << "信息" << "成功" << "警告" << "失败";
    for (int i = 0; i < 4; i++) {
        btnList[i] = new QPushButton(this);
        btnList[i]->setObjectName("btn_" + QString::number(i));
        btnList[i]->setText(list.at(i));
        btnList[i]->setFixedSize(100,32);
        btnList[i]->setCursor(Qt::PointingHandCursor);
        layouts->addWidget(btnList[i]);
        connect(btnList[i], &QPushButton::clicked, this, [=](){handleClick(i);});
    }
    widgets = new QWidget(this);
    widgets->setFixedSize(800, 500);
    widgets->setLayout(layouts);

    toast = new Toast(this);
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
    }
}
MainWindow::~MainWindow() {

}

