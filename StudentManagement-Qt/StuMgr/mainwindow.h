#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

/*
 * 用于临时存放考勤信息的结构体数组相关函数
 * Written By:杨雨萌
 */
typedef struct//学生考勤信息
{
    char date[20];//缺课日期
    char time[15];//第几节课(连续多节课用 begin-end 的形式表示)
    char lesson[50];//课程名称（课程名称中不会出现空格）
    char name[20];//学生姓名
    char absent_type[20];//缺课类型（迟到、早退、请假及旷课）

}student,*pstu;

void sort(student stu[],int start,int end,char *key);
void statistic_student(student stu[]);
void statistic_date(student stu[]);
void statistic_lesson(student stu[]);

/*
 * 主窗体相关函数声明
 * Written By:孙钰斐
 * Based On Qt
 */
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_BtnExit_clicked();

    void on_BtnAdd_clicked();

    void on_BtnMotify_clicked();

    void on_BtnDel_clicked();

    void on_BtnAbout_clicked();

    void on_BtnSearch_clicked();

    void on_BtnCount_clicked();

    void on_tableWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};

int separate(char *string, char *date, char *time, char *lesson, char *name, char *reason);
int is_date(char *date);
int get_lesson_time(char *time);
int is_reason(char *reason);
QString getinfo(student stu[],int size,char *key);

#endif // MAINWINDOW_H
