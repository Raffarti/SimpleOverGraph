#ifndef DATAEXTRACTOR_H
#define DATAEXTRACTOR_H

#include <QTimer>

class DataExtractor : public QTimer
{
    Q_OBJECT
public:
    explicit DataExtractor(QObject *parent = 0);

signals:
    void newData(int);
private slots:
    void extractData();
    
};

#endif // DATAEXTRACTOR_H
