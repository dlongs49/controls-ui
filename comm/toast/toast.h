
#ifndef CONTROLS_UI_TOAST_H
#define CONTROLS_UI_TOAST_H

#include <QHBoxLayout>
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
class Toast : public QFrame {
Q_OBJECT
public:
    explicit  Toast(QWidget *parent);

    ~Toast();

public slots:

    void handleClick(int w, QString str,bool  flag);
    void success(int main_width,QString str);
    void info(int main_width,QString str);
    void warning(int main_width,QString str);
    void error(int main_width,QString str);
    void message(int main_width,QString str);
    void beforeTimer();
    void onMsgTimeOut();
private:
    QSize parentSize;
    QHBoxLayout *layout;
    QTimer *timer;
    QLabel *label;
    QLabel *img_label;
    QPixmap *pixmap;
    QGraphicsDropShadowEffect *shadow;
    QPropertyAnimation *animation;
};
#endif //CONTROLS_UI_TOAST_H
