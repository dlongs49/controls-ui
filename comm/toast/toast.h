
#ifndef CONTROLS_UI_TOAST_H
#define CONTROLS_UI_TOAST_H

#include <QMainWindow>
#include <QWidget>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressBar>
#include <QTimer>
#include <QFileInfo>
#include <QLabel>
#include <QPropertyAnimation>
#include <QDebug>
#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QPixmap>
class Toast : public QFrame {
Q_OBJECT
public:
    explicit  Toast(QWidget *parent);

    ~Toast();

public slots:

    void handleClick(int w, QString str);
    void success(int main_width,QString str);
    void info(int main_width,QString str);
    void warning(int main_width,QString str);
    void error(int main_width,QString str);
    void onMsgTimeOut();
private:
    QPushButton *btn;
    QSize parentSize;
    QHBoxLayout *layout;
    QWidget *widget;
    QTimer *timer;
    QLabel *label;
    QLabel *img_label;
    QFrame *frame;
    QPixmap *pixmap;
    QGraphicsDropShadowEffect *shadow;
    QPropertyAnimation *animation;
    QString text;
};
#endif //CONTROLS_UI_TOAST_H
