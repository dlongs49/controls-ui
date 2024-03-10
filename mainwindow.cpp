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
    qDebug() << i ;
    if(i == 0){
        toast->info(this->size().width(),"众里寻他千百度");
    }else if(i == 1){
        toast->success(this->size().width(),"叶圣陶散文》为“名家经典珍藏”丛书之一，收录了叶圣陶先生的散文精品数十篇，丰富，题材各异，构思精巧，文笔精巧、语言幽默、内蕴深厚、风格恬淡，充分显示了叶圣陶先生");
    }else if(i == 2){
        toast->warning(this->size().width(),"请求异常");
    }else if(i == 3){
        toast->error(this->size().width(),"网络异常");
    }
}
MainWindow::~MainWindow() {

}

