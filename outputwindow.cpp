#include "outputwindow.h"
#include "ui_outputwindow.h"

OutputWindow::OutputWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OutputWindow)
{
    ui->setupUi(this);
    setStyleSheet("background:transparent;");
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
}

OutputWindow::~OutputWindow()
{
    delete ui;
}

