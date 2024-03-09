#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

public slots:

    void handleClick();

    void onMsgTimeOut();

private:
    QPushButton *btn;

    QHBoxLayout *layout;
    QWidget *widget;
    QTimer *timer;
    QLabel *label;
    QLabel *img_label;
    QFrame *frame;
    QPixmap *pixmap;
    QGraphicsDropShadowEffect *shadow;
    QPropertyAnimation *animation;


    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
