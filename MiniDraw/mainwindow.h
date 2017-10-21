#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPen>
#include <QColorDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QBrush>
#include <QScreen>
#include <QTime>
#include "mainview.h"
#include "mainscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    const QString styles[6]= {"NoPen","SolidLine","DashLine","DotLine","DashDotLine","DashDotDotLine"};

private slots:
    void on_actionLine_triggered();//设置为画直线状态

    void on_actionRectangle_triggered();//设置为画矩形状态

    void on_actionEllipse_triggered();//设置为画椭圆状态

    void on_actionPolygon_triggered();//设置为画多边形状态

    void on_actionFree_triggered();//设置为自由绘画状态

    void on_actionDelete_triggered();//删除上一个图形

    void on_actionClear_triggered();//删除所有图形

    void on_actionColor_triggered();//设置画笔颜色

    void on_actionNoPen_triggered();//设置画笔风格为无(只有用到填色功能才有无边框效果)

    void on_actionSolidLine_triggered();//设置画笔风格为实线

    void on_actionDashLine_triggered();//设置画笔风格为"---"

    void on_actionDotLine_triggered();//设置画笔风格为"..."

    void on_actionDashDotLine_triggered();//设置画笔风格为"-.-."

    void on_actionDashDotDotLine_triggered();//设置画笔风格为"-..-.."

    void on_actionAbout_Me_triggered();//显示个人信息

    void on_actionAbout_Qt_triggered();//显示Qt信息

    void on_action1px_triggered();//设置画笔宽度为1px

    void on_action2px_triggered();//设置画笔宽度为2px

    void on_action3px_triggered();//设置画笔宽度为3px

    void on_actionCustom_triggered();//设置画笔宽度为(输入值)px

    void on_actionSave_As_triggered();//保存图片

    void on_actionEraser_triggered();//橡皮擦

    void on_actionText_triggered();//设置为写文字状态

    void on_actionFont_triggered();//设置文字字体

    void on_actionBrushColor_triggered();//设置填充颜色

    void on_actionHollow_triggered();//设置是否镂空，默认是镂空，也就是图像互不遮盖。

    void on_actionSolid_triggered();//实心填充

    void on_actionDense1_triggered();//密集点阵1，数字越大越稀疏

    void on_actionDense2_triggered();//密集点阵2

    void on_actionDense3_triggered();//密集点阵3

    void on_actionDense4_triggered();//密集点阵4

    void on_actionDense5_triggered();//密集点阵5

    void on_actionDense6_triggered();//密集点阵6

    void on_actionDense7_triggered();//密集点阵7

    void on_actionHorizontalLine_triggered();//水平线填充

    void on_actionVerticalLine_triggered();//竖直线填充

    void on_actionCrossLine_triggered();//横纵交叉线填充

    void on_actionBDiagLine_triggered();//东北西南线填充

    void on_actionFDiagLine_triggered();//西北东南线填充

    void on_actionDiagCrossLine_triggered();//1. 双对角交叉线填充




    private:
        Ui::MainWindow *ui;
        QLabel* status;//显示在QStatusBar上的提示信息。
        MainView *view;//View层的画图区域，实际只起到显示图像和传递鼠标事件。
        MainScene *scene;//Controller层的实际的画图操作区域，处理MainView传来的鼠标事件。
        QPen* pen;//画笔风格的设置，写成指针是为了同步修改风格而不必每次传值。
        QBrush* brush;
    };

    #endif // MAINWINDOW_H
