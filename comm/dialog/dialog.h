
#ifndef CONTROLS_UI_DIALOG_H
#define CONTROLS_UI_DIALOG_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QPixmap>
#include <QEvent>
#include <QMouseEvent>
#include <QFont>
#include <QPoint>
#include <QGraphicsDropShadowEffect>

class Dialog : public QFrame {
Q_OBJECT
public:
    explicit Dialog(QWidget *parent);

public slots:

    void handleClose();

    void handleOn();

    void show(QSize size, QString content);

private:
    int w = 320;
    int h = 180;
    QString content;
    QGraphicsDropShadowEffect *shadow;
    QVBoxLayout *layout;
    QHBoxLayout *layout_top;
    QHBoxLayout *layout_text;
    QHBoxLayout *layout_btn;
    QFont *font;
    QLabel *title;
    QLabel *label_img;
    QLabel *text;
    QPixmap *close_img;
    QWidget *widget_top;
    QWidget *widget_text;
    QWidget *widget_btn;
    QPushButton *btn_cancel;
    QPushButton *btn_ok;
    QPoint start_point;
    QPoint init_point;
protected:
    bool eventFilter(QObject *obj, QEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

signals:

    void emitOn();
};

#endif //CONTROLS_UI_DIALOG_H
