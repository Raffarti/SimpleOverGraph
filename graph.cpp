#include "graph.h"
#include <QPainter>

Graph::Graph(QWidget *parent) :
    QWidget(parent)
{
    setFixedWidth(MAX_DATA_LENGTH);
    setFixedHeight(100);
    background = QBrush(QColor(0,50,0,50));
    filler = QBrush(QColor(255,0,0,115));
    circleBrush = QBrush(QColor(255,0,0,175));
    circlePen = QPen(circleBrush,1);
    gridBrush = QBrush(QColor(0,255,0,175));
    gridPen = QPen(gridBrush,1);
    for (int s = 0; s < MAX_DATA_LENGTH; s++)
        data << -50;
}

void Graph::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.setBackground(background);
    painter.eraseRect(rect());
    QPoint *points = new QPoint[MAX_DATA_LENGTH +2];
    points[0] = QPoint(0,150);
    points[MAX_DATA_LENGTH +1] = QPoint(MAX_DATA_LENGTH,150);
    for (int s = 0; s < MAX_DATA_LENGTH; s++){
        points[s +1] = QPoint(s,100 - data.at(data.length() - s -1));
    }
    painter.setPen(gridPen);
    painter.setBrush(filler);
    for (int s = 0; s < MAX_DATA_LENGTH / 30; s++){
        painter.drawLine(MAX_DATA_LENGTH - 30 * (s+1), 0,MAX_DATA_LENGTH - 30 * (s+1), 100);
    }
    for (int s = 0; s < 10; s++){
        painter.drawLine(0, 10*s,MAX_DATA_LENGTH, 10*s);
    }
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(circlePen);
    painter.drawPolygon(points,MAX_DATA_LENGTH +2);
    painter.end();
    delete points;
}

void Graph::addData(int data)
{
    this->data.prepend(data);
    while (this->data.length() > MAX_DATA_LENGTH) this->data.pop_back();
    repaint();
}
