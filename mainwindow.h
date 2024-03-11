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
#include "comm/toast/toast.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

public slots:

    int handleClick(int i);

private:
    QPushButton *btnList[5];

    QHBoxLayout *layout;
    QHBoxLayout *layouts;
    QWidget *widgets;
    QTimer *timer;
    QLabel *label;
    QLabel *img_label;
    QFrame *widget;
    QPixmap *pixmap;
    QGraphicsDropShadowEffect *shadow;
    QPropertyAnimation *animation;
    Toast *toast;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
