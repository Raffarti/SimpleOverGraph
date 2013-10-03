#ifndef GRAPH_H
#define GRAPH_H
#define MAX_DATA_LENGTH 180
#include <QWidget>
#include <QPen>

class Graph : public QWidget
{
    Q_OBJECT
public:
    explicit Graph(QWidget *parent = 0);
    
protected:
    void paintEvent(QPaintEvent *event);

private:
    QBrush background;
    QBrush filler;
    QBrush circleBrush;
    QBrush gridBrush;
    QPen circlePen;
    QPen gridPen;
    QList<int> data;
signals:
    
public slots:
    void addData(int data);
    
};

#endif // GRAPH_H
