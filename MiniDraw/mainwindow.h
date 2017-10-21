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
    void on_actionLine_triggered();

    void on_actionRectangle_triggered();

    void on_actionEllipse_triggered();

    void on_actionPolygon_triggered();

    void on_actionFree_triggered();

    void on_actionDelete_triggered();

    void on_actionClear_triggered();

    void on_actionColor_triggered();

    void on_actionNoPen_triggered();

    void on_actionSolidLine_triggered();

    void on_actionDashLine_triggered();

    void on_actionDotLine_triggered();

    void on_actionDashDotLine_triggered();

    void on_actionDashDotDotLine_triggered();

    void on_actionAbout_Me_triggered();

    void on_actionAbout_Qt_triggered();

    void on_action1px_triggered();

    void on_action2px_triggered();

    void on_action3px_triggered();

    void on_actionCustom_triggered();

    void on_actionSave_As_triggered();

    void on_actionEraser_triggered();

    void on_actionText_triggered();

    void on_actionFont_triggered();

    void on_actionBrushColor_triggered();

    void on_actionHollow_triggered();

    void on_actionSolid_triggered();

    void on_actionDense1_triggered();

    void on_actionDense2_triggered();

    void on_actionDense3_triggered();

    void on_actionDense4_triggered();

    void on_actionDense5_triggered();

    void on_actionDense6_triggered();

    void on_actionDense7_triggered();

    void on_actionHorizontalLine_triggered();

    void on_actionVerticalLine_triggered();

    void on_actionCrossLine_triggered();

    void on_actionBDiagLine_triggered();

    void on_actionFDiagLine_triggered();

    void on_actionDiagCrossLine_triggered();


private:
    Ui::MainWindow *ui;
    QLabel* status;
    MainView *view;
    MainScene *scene;
    QPen* pen;
    QBrush* brush;
};

#endif // MAINWINDOW_H
