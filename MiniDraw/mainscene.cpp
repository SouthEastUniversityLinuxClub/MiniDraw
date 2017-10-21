#include "mainscene.h"
#include <QMessageBox>
#include <QGraphicsLineItem>
#include <qmath.h>
MainScene::MainScene()
{
    draw_status = false;
    group = createItemGroup(*(new QList<QGraphicsItem*>));
    font = QFont("Times", 18, QFont::Normal);
}

void MainScene::setType(QString t)
{
    if(type=="Free"&&pen->color()==QColor("white"))//之前是橡皮擦
    {
        pen->setColor(QColor("black"));//把画笔颜色设置成黑色
    }
    this->type = t;
}

QString MainScene::getType()
{
    return type;
}

void MainScene::setRect(QRectF rect)
{
    this->rect = rect;
}

void MainScene::setPen(QPen *p)
{
    this->pen = p;
}

QPen* MainScene::getPen()
{
    return pen;
}

void MainScene::setBrush(QBrush *b)
{
    this->brush = b;
}

void MainScene::setFont(QFont f)
{
    this->font = f;
}

void MainScene::setText(QString t)
{
    this->text = t;
}

void MainScene::press(QMouseEvent *event)
{
    draw_status = true;
    start = end = event->pos();
    if(type=="Line")
    {
        QGraphicsLineItem* lineItem = new QGraphicsLineItem();
        lineItem->setLine(start.x(),start.y(),end.x(),end.y());
        lineItem->setPen(*pen);
        items.push_back(lineItem);//新建对象放入Qvector
        group->addToGroup(lineItem);//加入组来决定先后顺序
    }
    if(type=="Rectangle")
    {
        QGraphicsRectItem* rectItem = new QGraphicsRectItem();
        rectItem->setRect(*(new QRect(start,end)));
        rectItem->setPen(*pen);
        rectItem->setBrush(*brush);
        items.push_back(rectItem);//新建对象放入Qvector
        group->addToGroup(rectItem);//加入组来决定先后顺序
    }
    if(type=="Ellipse")
    {
        QGraphicsEllipseItem* ellipseItem = new QGraphicsEllipseItem();
        ellipseItem->setRect(*(new QRect(start,end)));
        ellipseItem->setPen(*pen);
        ellipseItem->setBrush(*brush);
        items.push_back(ellipseItem);//新建对象放入Qvector
        group->addToGroup(ellipseItem);//加入组来决定先后顺序
    }
    if(type=="Polygon")
    {
        if(event->button()==Qt::LeftButton)//点击左键先画线
        {
            if(polygonPoints.isEmpty())
            {
                polygonPoints = QVector<QPoint>();
                polygonPoints.append(start);
                QGraphicsLineItem* lineItem = new QGraphicsLineItem();
                lineItem->setLine(start.x(),start.y(),end.x(),end.y());
                lineItem->setPen(*pen);
                polygonTemp.push_back(lineItem);
                group->addToGroup(lineItem);
            }
            else
            {
                polygonPoints.append(start);
                QGraphicsLineItem* lineItem = new QGraphicsLineItem;
                lineItem->setLine(polygonPoints.at(polygonPoints.size()-2).x(),polygonPoints.at(polygonPoints.size()-2).y(),end.x(),end.y());
                lineItem->setPen(*pen);
                polygonTemp.push_back(lineItem);
                group->addToGroup(lineItem);
                update(rect);
            }
        }
        if(event->button()==Qt::RightButton)//点击右键删除之前的线并改成新的多边形
        {
            int initialCount = polygonTemp.count();
            for(int i=0;i<initialCount;i++)
            {
                group->removeFromGroup(polygonTemp.last());
                removeItem(polygonTemp.last());
                polygonTemp.pop_back();
            }
            QGraphicsPolygonItem* polyItem = new QGraphicsPolygonItem;
            polyItem->setPolygon(*(new QPolygonF(polygonPoints)));
            polyItem->setPen(*pen);
            polyItem->setBrush(*brush);
            items.push_back(polyItem);
            group->addToGroup(polyItem);
            polygonPoints.clear();
        }
    }
    if(type=="Free")
    {
        freePoints = QVector<QPoint>();
        freePoints.append(start);
        QGraphicsLineItem* freeItem = new QGraphicsLineItem();
        freeItem->setLine(start.x(),start.y(),end.x(),end.y());
        freeItem->setPen(*pen);
        items.push_back(freeItem);
        group->addToGroup(freeItem);
    }
    if(type=="Text")
    {
        QGraphicsSimpleTextItem* textItem = new QGraphicsSimpleTextItem();
        if(!text.isEmpty())
        {
            textItem->setText(text);
            textItem->setFont(font);
            textItem->setPos(end);
            textItem->setPen(*pen);
            textItem->setBrush(*brush);
            items.push_back(textItem);
            group->addToGroup(textItem);
        }
    }
}

void MainScene::moving(QMouseEvent *event)//鼠标移动时不断刷新以预览
{
    end = event->pos();
    if(type=="Line"&&!items.isEmpty())
    {
        QGraphicsLineItem* lineItem = static_cast<QGraphicsLineItem*>(items.last());
        lineItem->setLine(start.x(),start.y(),end.x(),end.y());
        update(rect);
    }
    if(type=="Rectangle"&&!items.isEmpty())
    {
        QGraphicsRectItem* rectItem = static_cast<QGraphicsRectItem*>(items.last());
        rectItem->setRect(*(new QRect(start,end)));
        update(rect);
    }
    if(type=="Ellipse"&&!items.isEmpty())
    {
        QGraphicsEllipseItem* ellipseItem = static_cast<QGraphicsEllipseItem*>(items.last());
        ellipseItem->setRect(*(new QRect(start,end)));
        update(rect);
    }
    if(type=="Free"&&!items.isEmpty())
    {
        QGraphicsLineItem* freeItem = new QGraphicsLineItem();
        freeItem->setLine(freePoints.last().x(),freePoints.last().y(),end.x(),end.y());
        freeItem->setPen(*pen);
        items.push_back(freeItem);
        group->addToGroup(freeItem);
        freePoints.append(end);
    }
}

void MainScene::release(QMouseEvent *event)//鼠标释放时彻底成型
{
    draw_status = false;
    end = event->pos();
    if(type=="Line"&&!items.isEmpty())
    {
        QGraphicsLineItem* lineItem = static_cast<QGraphicsLineItem*>(items.last());
        lineItem->setLine(start.x(),start.y(),end.x(),end.y());
        update(rect);
    }
    if(type=="Rectangle"&&!items.isEmpty())
    {
        QGraphicsRectItem* rectItem = static_cast<QGraphicsRectItem*>(items.last());
        rectItem->setRect(*(new QRect(start,end)));
        update(rect);
    }
    if(type=="Ellipse"&&!items.isEmpty())
    {
        QGraphicsEllipseItem* ellipseItem = static_cast<QGraphicsEllipseItem*>(items.last());
        ellipseItem->setRect(*(new QRect(start,end)));
        update(rect);
    }

}

void MainScene::deleteOne()
{
    if(!items.isEmpty())
    {
        group->removeFromGroup(items.last());
        removeItem(items.last());
        update(rect);
        items.pop_back();
    }
    else
    {
        QMessageBox::information(NULL,"Info","There's nothing to delete");
    }
}

void MainScene::deleteALL()
{
    if(items.isEmpty())
    {
        QMessageBox::information(NULL,"Info","There's nothing to delete");
    }
    else
    {
        int initialCount = items.count();
        for(int i=0;i<initialCount;i++)
        {
            group->removeFromGroup(items.last());
            removeItem(items.last());
            items.pop_back();
        }
        update(rect);
    }
}
