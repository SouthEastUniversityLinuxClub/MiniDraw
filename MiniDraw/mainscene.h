#ifndef MAINSCENE_H
#define MAINSCENE_H
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QVector>
#include <QRectF>
#include<QPoint>
#include <QPen>
#include <QInputDialog>

class MainScene : public QGraphicsScene
{
public:
    MainScene();
    void setType(QString t);
    QString getType();
    void setRect(QRectF rect);
    void setPen(QPen* p);
    QPen *getPen();
    void setBrush(QBrush* b);
    void setFont(QFont f);
    void setText(QString t);
    void press(QMouseEvent* event);
    void moving(QMouseEvent* event);
    void release(QMouseEvent* event);
    void deleteOne();
    void deleteALL();
private:
    QString type;
    bool draw_status;
    QPoint start,end;
    QRectF rect;
    QVector<QGraphicsItem*> items;
    QGraphicsItemGroup* group;
    QVector<QPoint> polygonPoints;
    QVector<QPoint> freePoints;
    QVector<QGraphicsItem*> polygonTemp;
    QPen* pen;
    QFont font;
    QString text;
    QBrush* brush;
};

#endif // MAINSCENE_H
