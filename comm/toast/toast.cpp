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
    label->setStyleSheet("color: #000;padding:0;background:transparent;");
    label->setText("");
    label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    img_label = new QLabel;
    img_label->setStyleSheet("QLabel{background:transparent}");
    img_label->setFixedSize(30, 30);

    pixmap = new QPixmap(":/resource/imgs/toast_info.png");
    img_label->setPixmap(*pixmap);
    img_label->setScaledContents(true);
    layout->addWidget(img_label);
    layout->addWidget(label);
    layout->setAlignment(Qt::AlignLeft);
    this->setLayout(layout);

    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(1, 0);
    shadow->setColor(QColor("#cccccc"));
    shadow->setBlurRadius(10);
    this->setGraphicsEffect(shadow);
}

void Toast::handleClick(int w, QString str,bool flag = true) {
    if(flag){
        this->setStyleSheet("QFrame{background: rgba(255, 255, 255, 1);border-radius: 6px;padding:5px 5px;}");
        label->setStyleSheet("color: #000;padding:0;background:transparent;");
    }
    this->setFixedSize(0, 0);
    this->setMinimumSize(0, 40);
    label->setFixedSize(0, 30);
    label->setText(str);

    // 图标30 + 左右内边距10
    int mar_pad = 40;
    // label 建议宽度
    int label_width = label->sizeHint().width();
    qDebug() << this->size() << label_width;


    // 当 label 宽度超出主窗口时处理
    if (label_width + mar_pad >= w) {
        // 提示内容应在窗口内防止超出隐藏
        this->setMinimumWidth(w - 100);
        label->setFixedWidth(this->size().width() - mar_pad);
    } else {
        label->setFixedWidth(label_width);
        // 提示窗口的宽度：label宽度 + 内边距10 + 图标30  + QLabel默认宽度
        this->setFixedWidth(label_width + mar_pad+6);
    }
    label->setFixedHeight(label->sizeHint().height());

    int ws = (w / 2) - (this->size().width() / 2);
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(100);
    animation->setStartValue(QRect(ws, 0, w, this->height()));
    animation->setEndValue(QRect(ws, 30, w, this->height()));

    this->setVisible(true);
    this->animation->start();
    this->timer->start(1500);
}

void Toast::info(int w, QString str) {
    beforeTimer();
    img_label->setPixmap(QPixmap(":/resource/imgs/toast_info.png"));
    this->handleClick(w, str);
}

void Toast::success(int w, QString str) {
    beforeTimer();
    img_label->setPixmap(QPixmap(":/resource/imgs/toast_success.png"));
    this->handleClick(w, str);
}

void Toast::warning(int w, QString str) {
    beforeTimer();
    img_label->setPixmap(QPixmap(":/resource/imgs/toast_warning.png"));
    this->handleClick(w, str);
}

void Toast::error(int w, QString str) {
    img_label->setPixmap(QPixmap(":/resource/imgs/toast_error.png"));
    this->handleClick(w, str);
}
void Toast::message(int w, QString str) {
    img_label->setVisible(false);
    layout->setAlignment(Qt::AlignCenter);
    this->setStyleSheet("QFrame{background: rgba(0, 0, 0, 0.6);border-radius: 6px;padding:5px 5px;}");

    label->setStyleSheet(label->styleSheet()+"color:#fff");
    this->handleClick(w, str,false);
}


void Toast::beforeTimer(){
    img_label->setVisible(true);
    if (timer->isActive()) {
        timer->stop();
    }
}
void Toast::onMsgTimeOut() {
    timer->stop();
    this->setVisible(false);
}

Toast::~Toast() {

}

