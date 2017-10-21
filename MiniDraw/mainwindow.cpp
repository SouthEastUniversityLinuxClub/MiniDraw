#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainview.h"
#include "mainscene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    status = new QLabel("");
    QActionGroup *groupFigure = new QActionGroup(this);
    groupFigure->addAction(ui->actionLine);
    groupFigure->addAction(ui->actionRectangle);
    groupFigure->addAction(ui->actionEllipse);
    groupFigure->addAction(ui->actionPolygon);
    groupFigure->addAction(ui->actionFree);
    groupFigure->addAction(ui->actionEraser);
    groupFigure->addAction(ui->actionText);
    QActionGroup *groupStyle = new QActionGroup(this);
    groupStyle->addAction(ui->actionNoPen);
    groupStyle->addAction(ui->actionSolidLine);
    groupStyle->addAction(ui->actionDashLine);
    groupStyle->addAction(ui->actionDotLine);
    groupStyle->addAction(ui->actionDashDotLine);
    groupStyle->addAction(ui->actionDashDotDotLine);
    QActionGroup *groupWidth = new QActionGroup(this);
    groupWidth->addAction(ui->action1px);
    groupWidth->addAction(ui->action2px);
    groupWidth->addAction(ui->action3px);
    groupWidth->addAction(ui->actionCustom);
    QActionGroup *groupBrushStyle = new QActionGroup(this);
    groupBrushStyle->addAction(ui->actionSolid);
    groupBrushStyle->addAction(ui->actionDense1);
    groupBrushStyle->addAction(ui->actionDense2);
    groupBrushStyle->addAction(ui->actionDense3);
    groupBrushStyle->addAction(ui->actionDense4);
    groupBrushStyle->addAction(ui->actionDense5);
    groupBrushStyle->addAction(ui->actionDense6);
    groupBrushStyle->addAction(ui->actionDense7);
    groupBrushStyle->addAction(ui->actionHorizontalLine);
    groupBrushStyle->addAction(ui->actionVerticalLine);
    groupBrushStyle->addAction(ui->actionCrossLine);
    groupBrushStyle->addAction(ui->actionBDiagLine);
    groupBrushStyle->addAction(ui->actionFDiagLine);
    groupBrushStyle->addAction(ui->actionDiagCrossLine);
    ui->statusBar->addPermanentWidget(status);
    this->showMaximized();

    scene = new MainScene();
    view = new MainView(scene);
    this->setCentralWidget(view);
    scene->setSceneRect(0,0,view->width(),view->height());
    scene->setRect(view->rect());
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->setRenderHint(QPainter::Antialiasing);
    pen = new QPen();
    scene->setPen(pen);
    brush = new QBrush(*(new QColor("white")),Qt::NoBrush);
    scene->setBrush(brush);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionLine_triggered()
{
    scene->setType(QString("Line"));
    status->setText("Brush Color: "+brush->color().name()+"\t"+"Line\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
    scene->setSceneRect(0,0,view->width(),view->height());
    scene->setRect(view->rect());
}

void MainWindow::on_actionRectangle_triggered()
{
    scene->setType(QString("Rectangle"));
    status->setText("Brush Color: "+brush->color().name()+"\t"+"Rectangle\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
    scene->setSceneRect(0,0,view->width(),view->height());
    scene->setRect(view->rect());
}

void MainWindow::on_actionEllipse_triggered()
{
    scene->setType(QString("Ellipse"));
    status->setText("Brush Color: "+brush->color().name()+"\t"+"Ellipse\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
    scene->setSceneRect(0,0,view->width(),view->height());
    scene->setRect(view->rect());
}

void MainWindow::on_actionPolygon_triggered()
{
    scene->setType(QString("Polygon"));
    status->setText("Brush Color: "+brush->color().name()+"\t"+"Polygon\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
    scene->setSceneRect(0,0,view->width(),view->height());
    scene->setRect(view->rect());
}

void MainWindow::on_actionFree_triggered()
{
    scene->setType(QString("Free"));
    status->setText("Brush Color: "+brush->color().name()+"\t"+"Free\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
    scene->setSceneRect(0,0,view->width(),view->height());
    scene->setRect(view->rect());
}

void MainWindow::on_actionDelete_triggered()
{
    scene->deleteOne();
}

void MainWindow::on_actionClear_triggered()
{
    scene->deleteALL();
}

void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor();
    if(color.isValid())
    {
        pen->setColor(color);
        status->setText("Brush Color: "+brush->color().name()+"\t"+scene->getType()+"\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
    }
}

void MainWindow::on_actionNoPen_triggered()
{
    pen->setStyle(Qt::NoPen);
    status->setText("Brush Color: "+brush->color().name()+"\t"+scene->getType()+"\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
}

void MainWindow::on_actionSolidLine_triggered()
{
    pen->setStyle(Qt::SolidLine);
    status->setText("Brush Color: "+brush->color().name()+"\t"+scene->getType()+"\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
}

void MainWindow::on_actionDashLine_triggered()
{
    pen->setStyle(Qt::DashLine);
    status->setText("Brush Color: "+brush->color().name()+"\t"+scene->getType()+"\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
}

void MainWindow::on_actionDotLine_triggered()
{
    pen->setStyle(Qt::DotLine);
    status->setText("Brush Color: "+brush->color().name()+"\t"+scene->getType()+"\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
}

void MainWindow::on_actionDashDotLine_triggered()
{
    pen->setStyle(Qt::DashDotLine);
    status->setText("Brush Color: "+brush->color().name()+"\t"+scene->getType()+"\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
}

void MainWindow::on_actionDashDotDotLine_triggered()
{
    pen->setStyle(Qt::DashDotDotLine);
    status->setText("Brush Color: "+brush->color().name()+"\t"+scene->getType()+"\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
}

void MainWindow::on_actionAbout_Me_triggered()
{
    QMessageBox::about(NULL,"About Me","Email: wjwzzc@163.com\nGitHub: https://github.com/SouthEastUniversityLinuxClub/MiniDraw");
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(NULL,"About Qt");
}

void MainWindow::on_action1px_triggered()
{
    pen->setWidthF(1);
    status->setText("Brush Color: "+brush->color().name()+"\t"+scene->getType()+"\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
}

void MainWindow::on_action2px_triggered()
{
    pen->setWidthF(2);
    status->setText("Brush Color: "+brush->color().name()+"\t"+scene->getType()+"\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
}

void MainWindow::on_action3px_triggered()
{
    pen->setWidthF(3);
    status->setText("Brush Color: "+brush->color().name()+"\t"+scene->getType()+"\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
}

void MainWindow::on_actionCustom_triggered()
{
    bool ok;
    QString num = QInputDialog::getText(this,tr("Set Width"),tr("Enter width"),QLineEdit::Normal,"",&ok);
    if(ok&&!num.isEmpty())
    {
        pen->setWidthF(num.toDouble());
        status->setText("Brush Color: "+brush->color().name()+"\t"+scene->getType()+"\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
    }
}

void MainWindow::on_actionSave_As_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this,tr("Save As"),"untitled.png",tr("Images (*.png *.bmp *.jpg)"));
    QScreen *screen = QGuiApplication::primaryScreen();
    QTime n=QTime::currentTime();
    QTime now;
    do{
        now=QTime::currentTime();
    }while (n.msecsTo(now)<=1000);

    screen->grabWindow(view->winId()).save(filePath);
}

void MainWindow::on_actionEraser_triggered()
{
    scene->setType(QString("Free"));
    pen->setStyle(Qt::SolidLine);
    pen->setColor(*(new QColor("white")));
    status->setText("Brush Color: "+brush->color().name()+"\t"+"Eraser\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
    scene->setSceneRect(0,0,view->width(),view->height());
    scene->setRect(view->rect());
}

void MainWindow::on_actionText_triggered()
{
    scene->setType(QString("Text"));
    status->setText("Brush Color: "+brush->color().name()+"\t"+"Text\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
    scene->setSceneRect(0,0,view->width(),view->height());
    scene->setRect(view->rect());
    bool ok;
    QString text = QInputDialog::getText(this,tr("Input"),tr("Enter: "),QLineEdit::Normal,"",&ok);
    scene->setText(text);
    this->setMouseTracking(false);
    if(brush->style()==Qt::NoBrush)
    {
        on_actionHollow_triggered();
    }
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok);
    if(ok)
    {
        scene->setFont(font);
    }
}

void MainWindow::on_actionBrushColor_triggered()
{
    QColor color = QColorDialog::getColor();
    if(color.isValid())
    {
        brush->setColor(color);
        status->setText("Brush Color: "+brush->color().name()+"\t"+scene->getType()+"\t"+pen->color().name()+"\t\t"+styles[QString::number(pen->style()).toInt()]+"\t"+QString::number(pen->widthF())+"px");
    }
}

void MainWindow::on_actionHollow_triggered()
{
    if(brush->style()==Qt::NoBrush)
    {
        brush->setStyle(Qt::SolidPattern);
        brush->setColor(QColor("black"));
    }
    else
    {
        brush->setStyle(Qt::NoBrush);
        brush->setColor(QColor("white"));
    }
}

void MainWindow::on_actionSolid_triggered()
{
    brush->setStyle(Qt::SolidPattern);
}

void MainWindow::on_actionDense1_triggered()
{
    brush->setStyle(Qt::Dense1Pattern);
}

void MainWindow::on_actionDense2_triggered()
{
    brush->setStyle(Qt::Dense2Pattern);
}

void MainWindow::on_actionDense3_triggered()
{
    brush->setStyle(Qt::Dense3Pattern);
}

void MainWindow::on_actionDense4_triggered()
{
    brush->setStyle(Qt::Dense4Pattern);
}

void MainWindow::on_actionDense5_triggered()
{
    brush->setStyle(Qt::Dense5Pattern);
}

void MainWindow::on_actionDense6_triggered()
{
    brush->setStyle(Qt::Dense6Pattern);
}

void MainWindow::on_actionDense7_triggered()
{
    brush->setStyle(Qt::Dense7Pattern);
}

void MainWindow::on_actionHorizontalLine_triggered()
{
    brush->setStyle(Qt::HorPattern);
}

void MainWindow::on_actionVerticalLine_triggered()
{
    brush->setStyle(Qt::VerPattern);
}

void MainWindow::on_actionCrossLine_triggered()
{
    brush->setStyle(Qt::CrossPattern);
}

void MainWindow::on_actionBDiagLine_triggered()
{
    brush->setStyle(Qt::BDiagPattern);
}

void MainWindow::on_actionFDiagLine_triggered()
{
    brush->setStyle(Qt::FDiagPattern);
}

void MainWindow::on_actionDiagCrossLine_triggered()
{
    brush->setStyle(Qt::DiagCrossPattern);
}
