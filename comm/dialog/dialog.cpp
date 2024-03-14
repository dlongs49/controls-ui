#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QFrame(parent) {
    this->resize(60, 40);
    this->setStyleSheet("background:#f0f");
}