
#ifndef CONTROLS_UI_DIALOG_H
#define CONTROLS_UI_DIALOG_H
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QPixmap>
#include <QFont>
#include <QGraphicsDropShadowEffect>
class Dialog : public QFrame{
public:
    explicit  Dialog(QWidget *parent);

public slots:
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
private:

};
#endif //CONTROLS_UI_DIALOG_H
