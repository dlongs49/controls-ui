#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QTimer>
#include <QFileInfo>
#include <QLabel>
#include <QDebug>
#include <QFrame>
#include "comm/toast/toast.h"
#include "comm/dialog/dialog.h"
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
    void handleOn();
    void handleDialogOk();
private:
    QPushButton *btnList[5];
    QPushButton *dialog_btn;

    QVBoxLayout *layout;
    QHBoxLayout *layout_toast;
    QHBoxLayout *layout_dialog;
    QWidget *widget_toast;
    QWidget *widget_dialog;
    QWidget *widget;
    Toast *toast;
    Dialog *dialog;
};

#endif // MAINWINDOW_H
