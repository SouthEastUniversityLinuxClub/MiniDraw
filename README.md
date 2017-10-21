# 计算机图形学第一次作业

# 71115115    王子卓

## 一.需求分析

- 作业要求：
  1. 写一个画图小程序MiniDraw，要求画直线(Line)，椭圆(Ellipse)，矩形(Rectangle)，多边形(Polygon)等图形元素(图元)。
  2. 每种图元需用一个类（对象）来封装，如Line, Ellipse, Rect, Polygon, Freehand；
  3. 各种图元可从一个父类Figure来继承；
  4. 每种图元的绘制不一样，但是绘制接口在父类中是一样，因此可学习和使用类的多态性。
- 自我要求：
  1. 使用MVC架构，在Model层使用QGraphicsItem接口以及其子类，在Controller层继承使用QGraphicsScene，在View层继承使用QGraphicsView。
  2. 添加文字和橡皮擦功能。
  3. 可以设置画笔风格、画笔颜色、画笔宽度和文字字体。
  4. 实现抗锯齿。
  5. 保存图片。
  6. 不使用GDI底层以跨平台使用。

## 二.概要设计

![](https://raw.githubusercontent.com/ZizhuoWang/ImageBed/network/uml.png)

## 三.详细设计

### 3.1 MainWindow类

#### 3.1.1 属性

1. `QLabel* status`是显示在QStatusBar上的提示信息。
2. `MainView *view`是View层的画图区域，实际只起到显示图像和传递鼠标事件。
3. `MainScene *scene`是Controller层的实际的画图操作区域，处理MainView传来的鼠标事件。
4. `QPen* pen`是画笔风格的设置，写成指针是为了同步修改风格而不必每次传值。
5. `QBrush* brush`是填充风格的设置，写成指针是为了同步修改风格而不必每次传值。

#### 3.1.2 方法

​	无

#### 3.1.3 槽

​	由于使用QMetaObject::connectSlotsByName()方法，所以不用写connect语句。

1. void on_actionLine_triggered();设置为画直线状态
2. void on_actionRectangle_triggered();设置为画矩形状态
3. void on_actionEllipse_triggered();设置为画椭圆状态
4. void on_actionPolygon_triggered();设置为画多边形状态
5. void on_actionFree_triggered();设置为自由绘画状态
6. void on_actionDelete_triggered();删除上一个图形
7. void on_actionClear_triggered();删除所有图形
8. void on_actionColor_triggered();设置画笔颜色
9. void on_actionNoPen_triggered();设置画笔风格为无(只有用到填色功能才有无边框效果)
10. void on_actionSolidLine_triggered();设置画笔风格为实线
11. void on_actionDashLine_triggered();设置画笔风格为"---"
12. void on_actionDotLine_triggered();设置画笔风格为"..."
13. void on_actionDashDotLine_triggered();设置画笔风格为"-.-."
14. void on_actionDashDotDotLine_triggered();设置画笔风格为"-..-.."
15. void on_actionAbout_Me_triggered();显示个人信息
16. void on_actionAbout_Qt_triggered();显示Qt信息
17. void on_action1px_triggered();设置画笔宽度为1px
18. void on_action2px_triggered();设置画笔宽度为2px
19. void on_action3px_triggered();设置画笔宽度为3px
20. void on_actionCustom_triggered();设置画笔宽度为(输入值)px
21. void on_actionSave_As_triggered();保存图片
22. void on_actionEraser_triggered();橡皮擦
23. void on_actionText_triggered();设置为写文字状态
24. void on_actionFont_triggered();设置文字字体
25. void on_actionBrushColor_triggered();设置填充颜色
26. void on_actionHollow_triggered();设置是否镂空，默认是镂空，也就是图像互不遮盖。
27. void on_actionSolid_triggered();实心填充
28. void on_actionDense1_triggered();密集点阵1，数字越大越稀疏
29. void on_actionDense2_triggered();密集点阵2
30. void on_actionDense3_triggered();密集点阵3
31. void on_actionDense4_triggered();密集点阵4
32. void on_actionDense5_triggered();密集点阵5
33. void on_actionDense6_triggered();密集点阵6
34. void on_actionDense7_triggered();密集点阵7
35. void on_actionHorizontalLine_triggered();水平线填充
36. void on_actionVerticalLine_triggered();竖直线填充
37. void on_actionCrossLine_triggered();横纵交叉线填充
38. void on_actionBDiagLine_triggered();东北西南线填充
39. void on_actionFDiagLine_triggered();西北东南线填充
40. void on_actionDiagCrossLine_triggered();双对角交叉线填充



### 3.2 MainView类

#### 3.2.1 属性

1. MainScene* scene;这是实际的图形绘制和操作层的指针。

#### 3.2.2 方法

1. void mousePressEvent(QMouseEvent* event);将鼠标点击事件传给MainScene* scene
2. void mouseMoveEvent(QMouseEvent \*event);将鼠标移动事件传给MainScene* scene
3. void mouseReleaseEvent(QMouseEvent \*event);将鼠标释放事件传给MainScene* scene

#### 3.2.3 槽

​	无

### 3.3 MainScene类

#### 3.3.1 属性

1. `QString type`绘制类型
2. `bool draw_status`绘画状态
3. `QPoint start,end`图形的起始点和结束点
4. `QRectF rect`绘制刷新区域
5. `QVector<QGraphicsItem*> items`装有父类指针的QVector，指向的是不同的子类对象。
6. `QGraphicsItemGroup* group;`装有QGraphicsItem指针的组，用于决定图形之间的相互覆盖关系。
7. `QVector<QPoint> polygonPoints;`暂存的多边形的点集
8. `QVector<QPoint> freePoints;`暂存的自由绘画的点集
9. `QVector<QGraphicsItem*> polygonTemp;`用于暂存多边形的各条边，用于随后清除。
10. `QPen* pen;`画笔风格
11. `QFont font;`文字字体
12. `QString text;`文字内容
13. `QBrush* brush`填充风格

#### 3.3.2 方法

1. `void setType(QString t);`设置绘制类型
2. `QString getType();`获取绘制类型
3. `void setRect(QRectF rect);`设置刷新区域
4. `void setPen(QPen* p);`设置画笔风格
5. `QPen *getPen();`获取画笔风格
6. `void setBrush(QBrush* b);`设置填充风格
7. `void setFont(QFont f);`设置文字字体
8. `void setText(QString t);`设置文字内容
9. `void press(QMouseEvent* event);`鼠标点击处理函数
10. `void moving(QMouseEvent* event);`鼠标移动处理函数
11. `void release(QMouseEvent* event);`鼠标释放处理函数
12. `void deleteOne();`删除上一个图形
13. `void deleteALL();`删除全部图形

#### 3.3.3 槽

​	无

## 四.原理叙述

- 使用Qt Creator设计UI界面，并用`Go to slot`功能以及QMetaObject::connectSlotsByName()方法连接，可以避免connect函数因声明和连接顺序错乱可能产生的连接失败问题。
- UI界面中需要互斥的选项加到一个QActionGroup中。
- 将继承自QGraphicsView的MainView类对象放在MainWindow的中心，作为MVC模式的View层。
- 将继承自QGraphicsScene的MainScene类对象作为MainView的绘图层，作为MVC模式的Controller层。
- 将继承自QGraphicsItem的QGraphicsLineItem、QGraphicsRectItem、QGraphicsEllipseItem、QGraphicsPolygonItem、QGraphicsSimpleTextItem类对象作为MainScene的模型，作为MVC模式的Model层。
- View层将鼠标事件传给Controller层，由MainScene处理。
- MainScene新建对应的模型，并加入QVector\<QGraphicsItem*\>属性中，运用多态思想，存储父类指针，指向的实际是各个子类对象。

## 五.交互界面与方法

![](https://raw.githubusercontent.com/ZizhuoWang/ImageBed/network/DeepinScreenshot_20171021010240.png)

![](https://raw.githubusercontent.com/ZizhuoWang/ImageBed/network/untitled.png)

提供的功能有：

1. 画直线、矩形、椭圆、多边形、自由线、文本。
2. 提供橡皮擦，撤销，清空操作。
3. 设置各个图像的线条的颜色、粗细和样式。
4. 设置文本的字体和颜色。
5. 设置各个封闭图形的填充颜色和填充样式。
6. 设置是否镂空，也就是上层图元会不会覆盖下层图元。
7. 将图片另存为图片文件。



关于各个图元的处理：

- 直线：按下鼠标左键时，创建一个新的QGraphicsLineItem\*对象，设置画笔风格，并将之存入QVector中，鼠标拖动时不断更新直线现在的状态。
- 矩形：按下鼠标左键时，创建一个新的QGraphicsRectItem\*对象，设置画笔风格，设置填充风格，并将之存入QVector中，鼠标拖动时不断更新直线现在的状态。
- 椭圆：按下鼠标左键时，创建一个新的QGraphicsEllipseItem\*对象，设置画笔风格，设置填充风格，并将之存入QVector中，鼠标拖动时不断更新直线现在的状态。
- 多边形：按下鼠标左键时，保存每一个点，设置画笔风格，根据已有的点先画出已有的边。最后点击鼠标右键，创建一个新的QGraphicsPolygonItem\*对象，设置画笔风格，设置填充风格，并将之存入QVector中。
- 自由绘制：按下鼠标左键时，保存每一个点，根据点画出任意线条。
- 文字：按下文字按钮会要求设定文字内容，设置字体、位置、轮廓风格和填充风格，之后按下鼠标左键，创建一个新的QGraphicsSimpleTextItem*对象，并将之存入QVector中。

## 六.问题与想法

### 6.1问题

1. 由于无法获知多数人的画板使用习惯，所以只是按照自己的使用习惯制作了这个画板。结果做出来的画板可能功能比较繁杂。
2. 由于没有使用QPainter类的任何对象和函数，所以自由绘制并没有办法使用draw_polyline()这种方法，只是线条的拼接，所以在线条宽度比较大的时候会有明显棱角。
3. 工程必须用Qt Creator打开，否则无法正确编译。

### 6.2想法

​	我最初制作这个程序的时候就不只是要完成这次作业，而是作为给社团开技术讲座用的工具来做的。虽然市面上比这个更好用的画板比比皆是，但是自己做的果然还是最顺手的。

​	由于我没有装好Windows系统的电脑，所以只能在Linux上用Qt Creator来做。做出来的东西理论上讲是跨平台的，但是我并没有测试过。

​	完全没有参照教程，真是不好意思。