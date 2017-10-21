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
    void mousePressEvent(QMouseEvent* event);//将鼠标点击事件传给MainScene* scene
    void mouseMoveEvent(QMouseEvent *event);//将鼠标移动事件传给MainScene* scene
    void mouseReleaseEvent(QMouseEvent *event);//将鼠标释放事件传给MainScene* scene
private:
    MainScene* scene;
};

#endif // MAINVIEW_H
