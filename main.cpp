#include "mainwindow.h"
#include "outputwindow.h"
#include <QApplication>
#include "dataextractor.h"
#include "graph.h"
#include "trayicon.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  MainWindow w;
  //  w.show();
    DataExtractor *extractor = new DataExtractor();
    OutputWindow ow;
    ow.setAttribute(Qt::WA_TransparentForMouseEvents);
    ow.setFocusPolicy(Qt::NoFocus);
    ow.setWindowFlags(Qt::X11BypassWindowManagerHint|Qt::WindowStaysOnTopHint);
    Graph *g = new Graph();
    ow.setCentralWidget(g);
    ow.adjustSize();
    ow.show();
    a.connect(extractor, SIGNAL(newData(int)), g, SLOT(addData(int)));
    extractor->start(500);
    a.connect(TrayIcon::factory(),SIGNAL(quit()),&a,SLOT(quit()));

    return a.exec();
}
