#ifndef OUTPUTWINDOW_H
#define OUTPUTWINDOW_H

#include <QMainWindow>

namespace Ui {
class OutputWindow;
}

class OutputWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit OutputWindow(QWidget *parent = 0);
    ~OutputWindow();

protected:

public slots:
    
private:
    Ui::OutputWindow *ui;
};

#endif // OUTPUTWINDOW_H
