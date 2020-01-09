#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

/*
 * ������ʱ��ſ�����Ϣ�Ľṹ��������غ���
 * Written By:������
 */
typedef struct//ѧ��������Ϣ
{
    char date[20];//ȱ������
    char time[15];//�ڼ��ڿ�(������ڿ��� begin-end ����ʽ��ʾ)
    char lesson[50];//�γ����ƣ��γ������в�����ֿո�
    char name[20];//ѧ������
    char absent_type[20];//ȱ�����ͣ��ٵ������ˡ���ټ����Σ�

}student,*pstu;

void sort(student stu[],int start,int end,char *key);
void statistic_student(student stu[]);
void statistic_date(student stu[]);
void statistic_lesson(student stu[]);

/*
 * ��������غ�������
 * Written By:�����
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
