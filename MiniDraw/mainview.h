#ifndef MAINVIEW_H
#define MAINVIEW_H
#include <QGraphicsView>
#include <QMouseEvent>
#include "mainscene.h"

class MainView : public QGraphicsView
{
public:
    MainView(MainScene* scene);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    MainScene* scene;
};

#endif // MAINVIEW_H
