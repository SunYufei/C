#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>      //MessageBox
#include <QInputDialog>     //对话框
#include <cmath>

/*
 * 用于临时存放考勤信息的数组相关函数
 * Written By:杨雨萌
 */

//关键字排序
//start 开始下标 end 结束下标
//从start到end对关键字*key(date,time,name,lesson,absent_type)排序
void sort(student stu[],int start,int end,char *key){
    int i,j;
    char t[50];
    if(!strcmp(key,"date")){
        if(start == end)//只有一个数据
            return;
        else{
            for(i=start;i<end;i++)
                for(j=end-1;j>i;j--)
                    if(strcmp(stu[i].date,stu[j].date)>0)
                    {
                        strcpy(t,stu[i].date);
                        strcpy(stu[i].date,stu[j].date);
                        strcpy(stu[j].date,t);

                        strcpy(t,stu[i].time);
                        strcpy(stu[i].time,stu[j].time);
                        strcpy(stu[j].time,t);

                        strcpy(t,stu[i].lesson);
                        strcpy(stu[i].lesson,stu[j].lesson);
                        strcpy(stu[j].lesson,t);

                        strcpy(t,stu[i].name);
                        strcpy(stu[i].name,stu[j].name);
                        strcpy(stu[j].name,t);

                        strcpy(t,stu[i].absent_type);
                        strcpy(stu[i].absent_type,stu[j].absent_type);
                        strcpy(stu[j].absent_type,t);
                    }
        }
    }
    else if(!strcmp(key,"time")){
        if(start == end)//只有一个结点
            return;
        else{
            for(i=start;i<end;i++)
                for(j=end-1;j>i;j--)
                    if(get_lesson_time(stu[i].time)<get_lesson_time(stu[j].time))
                    {
                        strcpy(t,stu[i].date);
                        strcpy(stu[i].date,stu[j].date);
                        strcpy(stu[j].date,t);

                        strcpy(t,stu[i].time);
                        strcpy(stu[i].time,stu[j].time);
                        strcpy(stu[j].time,t);

                        strcpy(t,stu[i].lesson);
                        strcpy(stu[i].lesson,stu[j].lesson);
                        strcpy(stu[j].lesson,t);

                        strcpy(t,stu[i].name);
                        strcpy(stu[i].name,stu[j].name);
                        strcpy(stu[j].name,t);

                        strcpy(t,stu[i].absent_type);
                        strcpy(stu[i].absent_type,stu[j].absent_type);
                        strcpy(stu[j].absent_type,t);
                    }
        }
    }
    else if(!strcmp(key,"name")){
        if(start == end)//只有一个数据
            return;
        else{
            for(i=start;i<end;i++)
                for(j=end-1;j>i;j--)
                    if(strcmp(stu[i].name,stu[j].name)>0)
                    {
                        strcpy(t,stu[i].date);
                        strcpy(stu[i].date,stu[j].date);
                        strcpy(stu[j].date,t);

                        strcpy(t,stu[i].time);
                        strcpy(stu[i].time,stu[j].time);
                        strcpy(stu[j].time,t);

                        strcpy(t,stu[i].lesson);
                        strcpy(stu[i].lesson,stu[j].lesson);
                        strcpy(stu[j].lesson,t);

                        strcpy(t,stu[i].name);
                        strcpy(stu[i].name,stu[j].name);
                        strcpy(stu[j].name,t);

                        strcpy(t,stu[i].absent_type);
                        strcpy(stu[i].absent_type,stu[j].absent_type);
                        strcpy(stu[j].absent_type,t);
                    }
        }
    }
    else if(!strcmp(key,"lesson")){
        if(start == end)//只有一个数据
            return;
        else{
            for(i=start;i<end;i++)
                for(j=end-1;j>i;j--)
                    if(strcmp(stu[i].lesson,stu[j].lesson)>0)
                    {
                        strcpy(t,stu[i].date);
                        strcpy(stu[i].date,stu[j].date);
                        strcpy(stu[j].date,t);

                        strcpy(t,stu[i].time);
                        strcpy(stu[i].time,stu[j].time);
                        strcpy(stu[j].time,t);

                        strcpy(t,stu[i].lesson);
                        strcpy(stu[i].lesson,stu[j].lesson);
                        strcpy(stu[j].lesson,t);

                        strcpy(t,stu[i].name);
                        strcpy(stu[i].name,stu[j].name);
                        strcpy(stu[j].name,t);

                        strcpy(t,stu[i].absent_type);
                        strcpy(stu[i].absent_type,stu[j].absent_type);
                        strcpy(stu[j].absent_type,t);
                    }
        }
    }
}

//查询某个学生的缺课情况：查询结果按照日期升序排序（从小到大），同一天内按照所缺课程的时间升序排序。
//排序：（按学生的名字排，再按日期排再按时间排）
void statistic_student(student stu[],int size){
    int i;
    int start=0,end=size;
    //先排日期
    sort(stu,start,end,"date");
    //分块对日期相同的排序
    for(i=0;i<size;i++){
        while(!strcmp(stu[i].date,stu[start].date)){
            end=i;
            i++;
        }
        sort(stu,start,end,"time");
        if(end<size)
            start=end+1;
    }
}

//统计某段时间内（以天为单位），旷课学生姓名及旷课节数，查询结果先按旷课节数降序排序，旷课节数相同的学生按姓名升序排序；
//（先按日期排，再按学生排（要先排名字，再排节数））
void statistic_date(student stu[],int size){
    int i;
    int start=0,end=size;
    //先排旷课节数
    sort(stu,start,end,"time");
    //分块对姓名排序
    for(i=0;i<size;i++){
        while(get_lesson_time(stu[i].time)==get_lesson_time(stu[start].time)){
            end=i;
            i++;
        }
        sort(stu,start,end,"name");
        if(end<size)
            start=end+1;
    }
}

//统计某段时间内，有学生旷课的课程及旷课人次，按旷课人次由多到少排序，旷课人次相同的课程按课程名称升序排序。
//（先排时间，再排旷课课程，再排人次）
void statistic_lesson(student stu[],int size){
    int i;
    int start=0,end=size;
    //先排日期
    sort(stu,start,end,"time");
    //分块对课程排序
    for(i=0;i<size;i++){
        while(!strcmp(stu[i].date,stu[start].date)){
            end=i;
            i++;
        }
        sort(stu,start,end,"lesson");
        if(end<size)
            start=end+1;
    }
}

/******************************** END ***********************************/


/*
 * 主窗体及各种按钮函数
 * Written by: 孙钰斐
 * Based on Qt
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnExit_clicked()
{
    this->close();
}

void MainWindow::on_BtnAdd_clicked()
{
    //生成输入框
    bool ok;
    QString string=QInputDialog::getText(this,
                                         QString::fromLocal8Bit("录入"),
                                         QString::fromLocal8Bit("请输入学生考勤信息(如2015-06-27 3-4 心理健康辅导 张三 迟到/早退/请假/旷课):"),
                                         QLineEdit::Normal,
                                         "",
                                         &ok);
    //按下OK键继续
    if(ok){
        //判断输入是否正确
        char date[11];  //2015-06-27
        char time[6];   //3-4
        char lesson[100];    //心理健康辅导
        char name[50];  //张三
        char reason[20];  //迟到、早退、请假、旷课
        char str[200];
        strcpy(str,string.toLocal8Bit().data());
        //如果正确插入信息，不正确提示错误
        if(separate(str,date,time,lesson,name,reason)){
            //获取表格行数
            int rows=ui->tableWidget->rowCount();
            //插入新一行
            ui->tableWidget->insertRow(rows);
            ui->tableWidget->selectRow(rows);
            //插入新信息
            ui->tableWidget->setItem(rows,0,new QTableWidgetItem(QString::fromLocal8Bit(date)));
            ui->tableWidget->setItem(rows,1,new QTableWidgetItem(QString::fromLocal8Bit(time)));
            ui->tableWidget->setItem(rows,2,new QTableWidgetItem(QString::fromLocal8Bit(lesson)));
            ui->tableWidget->setItem(rows,3,new QTableWidgetItem(QString::fromLocal8Bit(name)));
            ui->tableWidget->setItem(rows,4,new QTableWidgetItem(QString::fromLocal8Bit(reason)));
        }
        else
            QMessageBox::information(NULL,
                                     QString::fromLocal8Bit("提示"),
                                     QString::fromLocal8Bit("格式错误，请输入正确格式！"),
                                     QMessageBox::Ok);
    }
}

void MainWindow::on_BtnMotify_clicked()
{
    //获取表格行数
    int rows=ui->tableWidget->rowCount();
    //0行表格直接返回
    if(rows==0)
        return;
    //获取当前表格的位置
    QTableWidgetItem *item = ui->tableWidget->currentItem();
    //输入对话框
    bool ok;
    QString str;
    //根据选定表格的列数分类进行信息修改
    switch(item->column()){
        case 3:
            str=QInputDialog::getText(this,
                                      QString::fromLocal8Bit("修改"),
                                      QString::fromLocal8Bit("请输入新的学生姓名:"),
                                      QLineEdit::Normal,
                                      "",
                                      &ok);
            if(ok && !str.isEmpty())
                item->setText(str);
            break;
        case 2:
            str=QInputDialog::getText(this,
                                      QString::fromLocal8Bit("修改"),
                                      QString::fromLocal8Bit("请输入新的课程名称:"),
                                      QLineEdit::Normal,
                                      "",
                                      &ok);
            if(ok && !str.isEmpty())
                item->setText(str);
            break;
        case 0:
            str=QInputDialog::getText(this,
                                      QString::fromLocal8Bit("修改"),
                                      QString::fromLocal8Bit("请输入新的缺课日期(如2015-06-27):"),
                                      QLineEdit::Normal,
                                      "",
                                      &ok);
            if(ok && !str.isEmpty()){
                if(is_date(str.toLocal8Bit().data()))
                    item->setText(str);
                else
                    QMessageBox::warning(NULL,
                                         QString::fromLocal8Bit("提示"),
                                         QString::fromLocal8Bit("输入格式错误，请重新输入！"),
                                         QMessageBox::Ok);
            }
            break;
        case 1:
            str=QInputDialog::getText(this,
                                      QString::fromLocal8Bit("修改"),
                                      QString::fromLocal8Bit("请输入新的缺课节次(如3-4):"),
                                      QLineEdit::Normal,
                                      "",
                                      &ok);
            if(ok && !str.isEmpty()){
                if(get_lesson_time(str.toLocal8Bit().data()))
                    item->setText(str);
                else
                    QMessageBox::warning(NULL,
                                         QString::fromLocal8Bit("提示"),
                                         QString::fromLocal8Bit("输入格式错误，请重新输入！"),
                                         QMessageBox::Ok);
            }
            break;
        case 4:
            QStringList list;
            list<<QString::fromLocal8Bit("迟到")<<QString::fromLocal8Bit("早退")<<QString::fromLocal8Bit("请假")<<QString::fromLocal8Bit("旷课");
            str=QInputDialog::getItem(this,
                                      QString::fromLocal8Bit("修改"),
                                      QString::fromLocal8Bit("请选择新的缺课类型:"),
                                      list,0,false,&ok);
            if (ok)
                item->setText(str);
            break;
    }
}

void MainWindow::on_BtnDel_clicked()
{
    //获取所选表格所在行并将其删除
    QTableWidgetItem * item = ui->tableWidget->currentItem();
    if(item==Q_NULLPTR)
        return;
    ui->tableWidget->removeRow(item->row());
}

void MainWindow::on_BtnAbout_clicked()
{
    QMessageBox::information(NULL,
                             QString::fromLocal8Bit("关于"),
                             QString::fromLocal8Bit("学生考勤管理系统 v1.0.0.150704 (基于Qt开发) \n初尝Qt，若有不足请多关照！\n感谢您的使用！"),
                             QMessageBox::Ok);
}

void MainWindow::on_BtnSearch_clicked()
{
    int i;
    //获取表格行数
    int rows=ui->tableWidget->rowCount();
    //0行不进行操作
    if(rows==0)
        return;
    //将学生姓名列入list中并排序
    QStringList list;
    for(i=0;i<rows;i++)
        if(list.indexOf(ui->tableWidget->item(i,3)->text())==-1)
            list.append(ui->tableWidget->item(i,3)->text());
    list.sort();
    //下拉列标输入框，获取学生姓名
    QString name;
    bool ok;
    name = QInputDialog::getItem(this,
                                 QString::fromLocal8Bit("查询"),
                                 QString::fromLocal8Bit("请选择所查询的学生姓名:"),
                                 list,0,false,&ok);
    //如果按下ok键，进行查询并输出结果
    if(ok){
        //获取符合条件的项目数量
        int n=0;
        for(i=0;i<rows;i++)
            if(name == ui->tableWidget->item(i,3)->text())
                n++;
        //定义数组
        student stu[n];
        //将符合条件的信息输入数组
        for(i=0,n=0;i<rows;i++)
            if(name == ui->tableWidget->item(i,3)->text()){
                strcpy(stu[n].date,  ui->tableWidget->item(i,0)->text().toLocal8Bit().data());
                strcpy(stu[n].time,  ui->tableWidget->item(i,1)->text().toLocal8Bit().data());
                strcpy(stu[n].lesson,ui->tableWidget->item(i,2)->text().toLocal8Bit().data());
                strcpy(stu[n].name,  ui->tableWidget->item(i,3)->text().toLocal8Bit().data());
                strcpy(stu[n].absent_type,ui->tableWidget->item(i,4)->text().toLocal8Bit().data());
                n++;
            }
        //排序
        statistic_student(stu,n);
        //获取排序后信息
        QString info = getinfo(stu,n,"name");
        //输出信息
        QMessageBox::information(NULL,
                                 QString::fromLocal8Bit("统计信息"),
                                 info,
                                 QMessageBox::Ok);
    }
}

void MainWindow::on_BtnCount_clicked()
{
    int i;
    //获取表格行数
    int rows=ui->tableWidget->rowCount();
    //0行不进行操作
    if(rows==0)
        return;
    QStringList list;
    bool ok;
    //选择输入方式
    list<<QString::fromLocal8Bit("按时间统计学生旷课节数")<<QString::fromLocal8Bit("按课程统计学生旷课人数");
    QString str = QInputDialog::getItem(this,
                                        QString::fromLocal8Bit("统计"),
                                        QString::fromLocal8Bit("请选择统计方式"),
                                        list,0,false,&ok);
    if(ok){
        if(!strcmp(str.toLocal8Bit().data(),"按时间统计学生旷课节数")){
            //清空下拉列标
            list.clear();
            //将时间列入list中并排序
            for(i=0;i<rows;i++)
                if(list.indexOf(ui->tableWidget->item(i,0)->text())==-1)
                    list.append(ui->tableWidget->item(i,0)->text());
            list.sort();
            //下拉列标输入框，获取旷课时间
            QString date;
            ok = false;
            date = QInputDialog::getItem(this,
                                         QString::fromLocal8Bit("统计"),
                                         QString::fromLocal8Bit("请选择所统计的时间:"),
                                         list,0,false,&ok);
            //按下OK键，统计结果并输出
            if(ok){
                //获取符合条件的项目数量
                int n=0;
                for(i=0;i<rows;i++)
                    if(date == ui->tableWidget->item(i,0)->text())
                        n++;
                //定义数组
                student stu[n];
                //将符合条件的信息输入链表
                for(i=0,n=0;i<rows;i++)
                    if(date == ui->tableWidget->item(i,0)->text()){
                        strcpy(stu[n].date,  ui->tableWidget->item(i,0)->text().toLocal8Bit().data());
                        strcpy(stu[n].time,  ui->tableWidget->item(i,1)->text().toLocal8Bit().data());
                        strcpy(stu[n].lesson,ui->tableWidget->item(i,2)->text().toLocal8Bit().data());
                        strcpy(stu[n].name,  ui->tableWidget->item(i,3)->text().toLocal8Bit().data());
                        strcpy(stu[n].absent_type,ui->tableWidget->item(i,4)->text().toLocal8Bit().data());
                        n++;
                    }
                //排序
                statistic_date(stu,n);
                //获取信息
                QString info = getinfo(stu,n,"date");
                //输出信息
                QMessageBox::information(NULL,
                                         QString::fromLocal8Bit("信息"),
                                         info,
                                         QMessageBox::Ok);
            }
        }
        else if(!strcmp(str.toLocal8Bit().data(),"按课程统计学生旷课人数")){
            //清空下拉列标
            list.clear();
            //将课程列入list中并排序
            for(i=0;i<rows;i++)
                if(list.indexOf(ui->tableWidget->item(i,2)->text()) == -1)
                    list.append(ui->tableWidget->item(i,2)->text());
            list.sort();
            //下拉列标输入框，获取旷课时间
            QString lesson;
            ok = false;
            lesson = QInputDialog::getItem(this,
                                           QString::fromLocal8Bit("统计"),
                                           QString::fromLocal8Bit("请选择所统计的课程:"),
                                           list,0,false,&ok);
            //按下OK键，统计结果并输出
            if(ok){
                //获取符合条件的项目数量
                int n=0;
                for(i=0;i<rows;i++)
                    if(lesson == ui->tableWidget->item(i,2)->text())
                        n++;
                //定义数组
                student stu[n];
                //将符合条件的信息输入链表
                for(i=0,n=0;i<rows;i++)
                    if(lesson == ui->tableWidget->item(i,2)->text()){
                        strcpy(stu[n].date,  ui->tableWidget->item(i,0)->text().toLocal8Bit().data());
                        strcpy(stu[n].time,  ui->tableWidget->item(i,1)->text().toLocal8Bit().data());
                        strcpy(stu[n].lesson,ui->tableWidget->item(i,2)->text().toLocal8Bit().data());
                        strcpy(stu[n].name,  ui->tableWidget->item(i,3)->text().toLocal8Bit().data());
                        strcpy(stu[n].absent_type,ui->tableWidget->item(i,4)->text().toLocal8Bit().data());
                        n++;
                    }
                //排序
                statistic_lesson(stu,n);
                //获取信息
                QString info = getinfo(stu,n,"lesson");
                //输出信息
                QMessageBox::information(NULL,
                                         QString::fromLocal8Bit("信息"),
                                         info,
                                         QMessageBox::Ok);
            }
        }
    }
}

void MainWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

/*
 * 将数组信息转化为一个字符串
 * 返回值示例：
 * 学生姓名：张三
 * 2015-06-01 3-4 心里 迟到
 * 2015-06-02 7-8 离散 早退
 * char *key为关键字（name、date、lesson）
 */
QString getinfo(student stu[],int size,char *key){
    int i;
    QString qstr;

    if(!strcmp(key,"name")){
        qstr+=QString::fromLocal8Bit("学生姓名：");
        qstr+=QString::fromLocal8Bit(stu[0].name);
        qstr+="\n\n";
        for(i=0;i<size;i++){
            qstr+=QString::fromLocal8Bit(stu[i].date);
            qstr+='\t';
            qstr+=QString::fromLocal8Bit(stu[i].time);
            qstr+='\t';
            qstr+=QString::fromLocal8Bit(stu[i].lesson);
            qstr+='\t';
            qstr+=QString::fromLocal8Bit(stu[i].absent_type);
            qstr+="\n";
        }
        return qstr;
    }
    else if(!strcmp(key,"date")){
        qstr+=QString::fromLocal8Bit("日期：");
        qstr+=QString::fromLocal8Bit(stu[0].date);
        qstr+="\n\n";
        for(i=0;i<size;i++){
            qstr+=QString::fromLocal8Bit(stu[i].time);
            qstr+='\t';
            qstr+=QString::fromLocal8Bit(stu[i].lesson);
            qstr+='\t';
            qstr+=QString::fromLocal8Bit(stu[i].name);
            qstr+='\t';
            qstr+=QString::fromLocal8Bit(stu[i].absent_type);
            qstr+='\n';
        }
        return qstr;
    }
    else if(!strcmp(key,"lesson")){
        qstr+=QString::fromLocal8Bit("课程名称：");
        qstr+=QString::fromLocal8Bit(stu[0].lesson);
        qstr+="\n\n";
        for(i=0;i<size;i++){
            qstr+=QString::fromLocal8Bit(stu[i].date);
            qstr+='\t';
            qstr+=QString::fromLocal8Bit(stu[i].time);
            qstr+='\t';
            qstr+=QString::fromLocal8Bit(stu[i].name);
            qstr+='\t';
            qstr+=QString::fromLocal8Bit(stu[i].absent_type);
            qstr+='\n';
        }
        return qstr;
    }
    else
        return NULL;
}

/********************** END *************************/

/*****************************************************
 * 分离输入信息函数
 * Written by 杨雨萌
 */
//判断是否为正确时间
int is_date(char* date){

    int y,m,d;
    int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    if(date[4]!='-')
        return 0;

    if(date[7]!='-')
        return 0;

    if(strlen(date)!=10)  //date提取一定要严格
        return 0;

    y=(date[0]-'0')*1000+(date[1]-'0')*100+(date[2]-'0')*10+(date[3]-'0');
    m=(date[5]-'0')*10+(date[6]-'0');
    d=(date[8]-'0')*10+(date[9]-'0');
    if(y<1000 || y>9999)
        return 0;
    if((y%4==0 && y%100!=0)||(y%400==0))
        day[1]=29;
    if(m==0 || m>12)
        return 0;
    if(d==0 || d>day[m-1])
        return 0;

    return 1;
}

//获取节次长度
//返回值：如果格式错误，返回0；格式正确返回节次长度
int get_lesson_time(char* time){
    //正确格式 begin-end 3-4
    //获取'-'位置并判断格式是否正确
    int i;
    int n=0;
    for(i=0;i<strlen(time);i++)
        if(time[i]=='-')
            n=i;
    if(n==0)
        return 0;
    //获取begin并判断是否正确
    int begin=0;
    for(i=0;i<n;i++){
        if(time[i]>='0' && time[i]<='9')
            begin+=(time[i]-'0')*pow(10,n-1-i);
        else
            return 0;
    }
    if(begin==0)
        return 0;
    //获取end并判断是否正确
    int end=0;
    for(i=n+1;i<strlen(time);i++){
        if(time[i]>='0' && time[i]<='9')
            end+=(time[i]-'0')*pow(10,strlen(time)-1-i);
        else
            return 0;
    }
    if(end==0)
        return 0;
    //判断begin end大小关系
    if(begin>=end)
        return 0;

    return end-begin;
}

//该函数不建议这样写，只是原因不在列表内，要么输入时提示清楚，否则不算输入错误
int is_reason(char* reason)
{
    if(!strcmp(reason,"迟到") || !strcmp(reason,"早退") || !strcmp(reason,"请假") || !strcmp(reason,"旷课"))
        return 1;
    else
        return 0;
}

//分离并判断输入信息格式是否正确
int separate(char* string,char* date,char* time,char* lesson,char *name,char* reason)
{
    int i,j,n=0,sp[4];
    //判断空格个数是否为4
    for(i=0;i<strlen(string);i++)
        if(string[i]==' '){
            n++;
            if(n>4)
                return 0;
            else
                sp[n-1]=i;
        }
    if(n!=4)
        return 0;

    //分离数据

    //分离并判断日期
    char date_t[20];
    for(i=0,j=0;i<sp[0];i++,j++)
        date_t[j]=string[i];
    date_t[j]='\0';
    if(is_date(date_t))
        strcpy(date,date_t);
    else
        return 0;
    //分离并判断节次
    char time_t[20];
    for(i=sp[0]+1,j=0;i<sp[1];i++,j++)
        time_t[j]=string[i];
    time_t[j]='\0';
    if(get_lesson_time(time_t))
        strcpy(time,time_t);
    else
        return 0;
    //分离课程
    char lesson_t[50];
    for(i=sp[1]+1,j=0;i<sp[2];i++,j++)
        lesson_t[j]=string[i];
    lesson_t[j]='\0';
    strcpy(lesson,lesson_t);
    //分离姓名
    char name_t[50];
    for(i=sp[2]+1,j=0;i<sp[3];i++,j++)
        name_t[j]=string[i];
    name_t[j]='\0';
    strcpy(name,name_t);
    //分离并判断迟到原因
    char reason_t[20];
    for(i=sp[3]+1,j=0;i<strlen(string);i++,j++)
        reason_t[j]=string[i];
    reason_t[j]='\0';
    if(is_reason(reason_t))
        strcpy(reason,reason_t);
    else
        return 0;

    return 1;
}

/********************** End ***********************/
