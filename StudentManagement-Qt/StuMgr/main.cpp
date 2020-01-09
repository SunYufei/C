#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>    //起始画面
#include <QPixmap>          //起始画面图像
#include <QTime>            //计时器

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //启动画面
    QPixmap pixmap(":/image/splash.jpg");
    QSplashScreen splash(pixmap);
    splash.show();
    //延时3秒
    QTime t;
    t.start();
    while(t.elapsed()<3000);
    //主窗口显示
    MainWindow w;
    w.show();
    //启动画面结束
    splash.finish(&w);

    return a.exec();
}
