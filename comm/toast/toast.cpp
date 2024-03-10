#include "toast.h"
Toast::Toast(QWidget *parent) : QFrame(parent) {

    parentSize = parent->size();

    int height = 40;
    this->setVisible(false);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onMsgTimeOut()));
    this->setStyleSheet("QFrame{background: rgba(255, 255, 255, 1);border-radius: 6px;padding:5px 5px;}");
    this->setMinimumHeight(height);
    layout = new QHBoxLayout;
    layout->setSpacing(0);
    layout->setMargin(0);
    label = new QLabel;
    label->setStyleSheet("QLabel{color: #000;padding:0;background:transparent}"); //transparent
    label->setText("");
    label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    img_label = new QLabel;
    img_label->setStyleSheet("QLabel{background:transparent}"); //transparent
    img_label->setFixedSize(30, 30);
    img_label->setAlignment(Qt::AlignTop);

    pixmap = new QPixmap(":/resource/imgs/toast_info.png");
    img_label->setPixmap(*pixmap);
    img_label->setScaledContents(true);
    layout->addWidget(img_label);
    layout->addWidget(label);
    this->setLayout(layout);

    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(1, 0);
    shadow->setColor(QColor("#cccccc"));
    shadow->setBlurRadius(10);
    this->setGraphicsEffect(shadow);
}

void Toast::handleClick(int w, QString str) {
    text = "<p style='line-height:18px;font-size:13px;text-align:left;padding:0;'>"+str+"</p>";
    label->setText(text);
    if (label->sizeHint().width() + 40 >= w) {
        this->setMinimumWidth(w - 100);
        label->setFixedWidth(this->size().width() - 46);
        label->setWordWrap(true);
        qDebug() <<  this->size() << label->sizeHint() << w;
    } else {
        this->setFixedWidth(label->sizeHint().width() + 30 + 15);
        label->setFixedWidth(label->sizeHint().width());
    }
    this->setMinimumHeight(label->sizeHint().height() + 19);
    label->setMinimumHeight(label->sizeHint().height() + 9);


    int ws = (w / 2) - (this->size().width() / 2);
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(100);
    animation->setStartValue(QRect(ws, 0, w, this->height()));
    animation->setEndValue(QRect(ws, 30, w, this->height()));

    this->setVisible(true);
    this->animation->start();
    this->timer->start(1500);

}
void Toast::info(int w,QString str){
    img_label->setPixmap(QPixmap(":/resource/imgs/toast_info.png"));
    this->handleClick(w,str);
}
void Toast::success(int w,QString str) {
    img_label->setPixmap(QPixmap(":/resource/imgs/toast_success.png"));
    this->handleClick(w,str);
}
void Toast::warning(int w,QString str) {
    img_label->setPixmap(QPixmap(":/resource/imgs/toast_warning.png"));
    this->handleClick(w,str);
}
void Toast::error(int w,QString str) {
    img_label->setPixmap(QPixmap(":/resource/imgs/toast_error.png"));
    this->handleClick(w,str);
}
void Toast::onMsgTimeOut() {
    this->timer->stop();
    this->setVisible(false);
}

Toast::~Toast() {

}

