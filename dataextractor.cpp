#include "dataextractor.h"
#include <QProcess>
#include <QApplication>
#include <QDebug>

DataExtractor::DataExtractor(QObject *parent) :
    QTimer(parent)
{
    connect(this,SIGNAL(timeout()),this,SLOT(extractData()));
}

void DataExtractor::extractData()
{
    QProcess process;
    process.start("python reader.py");
    process.waitForFinished();
    QString output = process.readAll();
    emit newData(output.toInt());
    qDebug() << output.toInt();

}
