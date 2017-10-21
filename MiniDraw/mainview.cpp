#include "mainview.h"
#include <QMessageBox>
#include <QDebug>
MainView::MainView(MainScene *scene)
{
    this->scene = scene;
    setScene(scene);
}

void MainView::mousePressEvent(QMouseEvent *event)
{
    scene->press(event);
    qDebug()<<"Press";
}

void MainView::mouseMoveEvent(QMouseEvent *event)
{
    if(scene->getType()!="Text")
    {
        scene->moving(event);
        qDebug()<<"Move";
    }
}

void MainView::mouseReleaseEvent(QMouseEvent *event)
{
    scene->release(event);
    qDebug()<<"Release";
}
