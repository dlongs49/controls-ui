#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {
    int width = 210;
    int height = 40;
    this->resize(800, 500);

    btn = new QPushButton(this);
    btn->setText("点击");
    layout = new QHBoxLayout();
    layout->addWidget(btn);
    this->setLayout(layout);


    widget = new QFrame(this);
    widget->move(325,10);
    widget->setVisible(true);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onMsgTimeOut()));
    widget->setStyleSheet("QFrame{background: rgba(255, 255, 255, 1);border-radius: 6px;padding:5px 5px;}");
    widget->setMinimumHeight(height);
    layout = new QHBoxLayout;
    layout->setSpacing(0);
    layout->setMargin(0);
    label = new QLabel;
    label->setStyleSheet("QLabel{color: #000;padding:0;background:transparent}"); //transparent
    label->setText(
            "<p style='line-height:18px;font-size:13px;text-align:left;padding:0;'>众里寻他千百度幅 </p>");
    qDebug() << label->sizeHint() << this->size();
    widget->setMaximumWidth(this->size().width() - 100);

    if (label->sizeHint().width() + 40 >= this->size().width()) {
        widget->setMinimumWidth(this->size().width() - 100);
        qDebug() << widget->size();
        label->setFixedWidth(widget->size().width() - 46);
        label->setWordWrap(true);
    } else {
        widget->setFixedWidth(label->sizeHint().width() + 30 + 10);
        label->setFixedWidth(label->sizeHint().width());
    }
    qDebug() << label->sizeHint() << this->size();

    widget->setMinimumHeight(label->sizeHint().height() + 19);

    label->setMinimumHeight(label->sizeHint().height() + 9);


    label->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    layout->setAlignment(Qt::AlignBottom);

    img_label = new QLabel;
    img_label->setStyleSheet("QLabel{background:transparent}"); //transparent
    img_label->setFixedSize(30, 30);
    img_label->setAlignment(Qt::AlignTop);

    pixmap = new QPixmap(":/info.png");
    img_label->setPixmap(*pixmap);
    img_label->setScaledContents(true);
    layout->addWidget(img_label);

    layout->addWidget(label);

    widget->setLayout(layout);

    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(1, 0);
    shadow->setColor(QColor("#cccccc"));
    shadow->setBlurRadius(10);
    widget->setGraphicsEffect(shadow);

    animation = new QPropertyAnimation(widget, "geometry", this);
    animation->setDuration(100);
    animation->setStartValue(QRect(100, 0, 100, 40));
    animation->setEndValue(QRect(100, 30, 100, 40));
    connect(btn, SIGNAL(clicked()), this, SLOT(handleClick()));
}

void MainWindow::handleClick() {
    this->timer->start(1500);
    int w = this->widget->size().width();
    int h = this->widget->size().height();
    this->widget->setVisible(true);
    this->animation->start();
}

void MainWindow::onMsgTimeOut() {
    this->timer->stop();
    this->widget->hide();
}

MainWindow::~MainWindow() {

}

