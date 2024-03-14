#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QFrame(parent) {
    int w = 320;
    int h = 200;
    this->resize(w, h);
    this->move(250,200);
    this->setStyleSheet("QFrame{background:#f0f;background:#fff;border-radius:6px;}");
    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(1, 0);
    shadow->setColor(QColor("#c0c0c0"));
    shadow->setBlurRadius(14);
    this->setGraphicsEffect(shadow);

    layout_top = new QHBoxLayout;
    layout_top->setSpacing(0);
    layout_top->setMargin(0);
    widget_top = new QWidget(this);
    widget_top->setFixedSize(w,45);
    widget_top->setStyleSheet("border-bottom:1px solid #eee;");
    font = new QFont("SimHei",12);
    title = new QLabel;
    title->setText("提示");
    title->setFont(*font);
    close_img = new QPixmap(":/resource/imgs/close.png");
    label_img = new QLabel;
    label_img->setPixmap(*close_img);
    label_img->setScaledContents(true);
    label_img->setFixedSize(15,15);
    label_img->setStyleSheet("QLabel{background:transparent;padding:0;border:none;}");
    label_img->setCursor(Qt::PointingHandCursor);
    layout_top->addSpacing(10);
    layout_top->addWidget(title);
    layout_top->addWidget(label_img);
    layout_top->addSpacing(15);
    widget_top->setLayout(layout_top);

    layout_text = new QHBoxLayout;
    layout_text->setSpacing(0);
    layout_text->setMargin(0);
    layout_text->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    widget_text = new QWidget(this);
    widget_text->setFixedSize(w,h - 100);
    text = new QLabel;
    text->setText("<p style='line-height:15px;'>"
                  "蛾儿雪柳黄金缕，笑语盈盈暗香去，众里寻她千百度，漠然回首，那人却在灯火阑珊处"
                  "</p>");
    font = new QFont("SimHei",10);
    text->setFont(*font);
    text->setFixedSize(w - 24,h - 110);
    text->setWordWrap(true);
    layout_text->addWidget(text);
    widget_text->setLayout(layout_text);


    widget_btn = new QWidget(this);
    widget_btn->setFixedSize(w,45);
    layout_btn = new QHBoxLayout;
    layout_btn->setSpacing(0);
    layout_btn->setMargin(0);
    layout_btn->setAlignment(Qt::AlignRight | Qt::AlignTop);
    btn_cancel = new QPushButton;
    btn_cancel->setFixedSize(80,30);
    btn_cancel->setText("取消");
    btn_cancel->setStyleSheet("QPushButton{border-radius:4px;background:#eee;color: #666;border:none;}QPushButton:hover{background:#f2f1f1;} QPushButton::pressed{background:#d0cece;}");
    btn_cancel->setCursor(Qt::PointingHandCursor);
    btn_ok = new QPushButton;
    btn_ok->setFixedSize(80,30);
    btn_ok->setText("确定");
    btn_ok->setStyleSheet("QPushButton{border-radius:4px;background:#b98af6;color: #fff;border:none;} QPushButton:hover{background:#c194fb;} QPushButton::pressed{background:#a162f2;}");
    btn_ok->setCursor(Qt::PointingHandCursor);
    layout_btn->addWidget(btn_cancel);
    layout_btn->addSpacing(10);
    layout_btn->addWidget(btn_ok);
    layout_btn->addSpacing(10);
    widget_btn->setLayout(layout_btn);

    layout = new QVBoxLayout;
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->setAlignment(Qt::AlignTop);
    layout->addWidget(widget_top);
    layout->addSpacing(10);
    layout->addWidget(widget_text);
    layout->addWidget(widget_btn);
    this->setLayout(layout);
}