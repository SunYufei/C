#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>    //��ʼ����
#include <QPixmap>          //��ʼ����ͼ��
#include <QTime>            //��ʱ��

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //��������
    QPixmap pixmap(":/image/splash.jpg");
    QSplashScreen splash(pixmap);
    splash.show();
    //��ʱ3��
    QTime t;
    t.start();
    while(t.elapsed()<3000);
    //��������ʾ
    MainWindow w;
    w.show();
    //�����������
    splash.finish(&w);

    return a.exec();
}
