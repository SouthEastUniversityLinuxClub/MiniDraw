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
    void setType(QString t);//设置绘制类型
    QString getType();//获取绘制类型
    void setRect(QRectF rect);//设置刷新区域
    void setPen(QPen* p);//设置画笔风格
    QPen *getPen();//获取画笔风格
    void setBrush(QBrush* b);//设置填充风格
    void setFont(QFont f);//设置文字字体
    void setText(QString t);//设置文字内容
    void press(QMouseEvent* event);//鼠标点击处理函数
    void moving(QMouseEvent* event);//鼠标移动处理函数
    void release(QMouseEvent* event);//鼠标释放处理函数
    void deleteOne();//删除上一个图形
    void deleteALL();//删除全部图形
private:
    QString type;//绘制类型
    bool draw_status;//绘画状态
    QPoint start,end;//图形的起始点和结束点
    QRectF rect;//绘制刷新区域
    QVector<QGraphicsItem*> items;//装有父类指针的QVector，指向的是不同的子类对象。
    QGraphicsItemGroup* group;//装有QGraphicsItem指针的组，用于决定图形之间的相互覆盖关系。
    QVector<QPoint> polygonPoints;//暂存的多边形的点集
    QVector<QPoint> freePoints;//暂存的自由绘画的点集
    QVector<QGraphicsItem*> polygonTemp;//用于暂存多边形的各条边，用于随后清除。
    QPen* pen;//画笔风格
    QFont font;//文字字体
    QString text;//文字内容
    QBrush* brush;//填充风格
};

#endif // MAINSCENE_H
