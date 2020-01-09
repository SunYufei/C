#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>      //MessageBox
#include <QInputDialog>     //�Ի���
#include <cmath>

/*
 * ������ʱ��ſ�����Ϣ��������غ���
 * Written By:������
 */

//�ؼ�������
//start ��ʼ�±� end �����±�
//��start��end�Թؼ���*key(date,time,name,lesson,absent_type)����
void sort(student stu[],int start,int end,char *key){
    int i,j;
    char t[50];
    if(!strcmp(key,"date")){
        if(start == end)//ֻ��һ������
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
        if(start == end)//ֻ��һ�����
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
        if(start == end)//ֻ��һ������
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
        if(start == end)//ֻ��һ������
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

//��ѯĳ��ѧ����ȱ���������ѯ������������������򣨴�С���󣩣�ͬһ���ڰ�����ȱ�γ̵�ʱ����������
//���򣺣���ѧ���������ţ��ٰ��������ٰ�ʱ���ţ�
void statistic_student(student stu[],int size){
    int i;
    int start=0,end=size;
    //��������
    sort(stu,start,end,"date");
    //�ֿ��������ͬ������
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

//ͳ��ĳ��ʱ���ڣ�����Ϊ��λ��������ѧ�����������ν�������ѯ����Ȱ����ν����������򣬿��ν�����ͬ��ѧ����������������
//���Ȱ������ţ��ٰ�ѧ���ţ�Ҫ�������֣����Ž�������
void statistic_date(student stu[],int size){
    int i;
    int start=0,end=size;
    //���ſ��ν���
    sort(stu,start,end,"time");
    //�ֿ����������
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

//ͳ��ĳ��ʱ���ڣ���ѧ�����εĿγ̼������˴Σ��������˴��ɶൽ�����򣬿����˴���ͬ�Ŀγ̰��γ�������������
//������ʱ�䣬���ſ��ογ̣������˴Σ�
void statistic_lesson(student stu[],int size){
    int i;
    int start=0,end=size;
    //��������
    sort(stu,start,end,"time");
    //�ֿ�Կγ�����
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
 * �����弰���ְ�ť����
 * Written by: �����
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
    //���������
    bool ok;
    QString string=QInputDialog::getText(this,
                                         QString::fromLocal8Bit("¼��"),
                                         QString::fromLocal8Bit("������ѧ��������Ϣ(��2015-06-27 3-4 ���������� ���� �ٵ�/����/���/����):"),
                                         QLineEdit::Normal,
                                         "",
                                         &ok);
    //����OK������
    if(ok){
        //�ж������Ƿ���ȷ
        char date[11];  //2015-06-27
        char time[6];   //3-4
        char lesson[100];    //����������
        char name[50];  //����
        char reason[20];  //�ٵ������ˡ���١�����
        char str[200];
        strcpy(str,string.toLocal8Bit().data());
        //�����ȷ������Ϣ������ȷ��ʾ����
        if(separate(str,date,time,lesson,name,reason)){
            //��ȡ�������
            int rows=ui->tableWidget->rowCount();
            //������һ��
            ui->tableWidget->insertRow(rows);
            ui->tableWidget->selectRow(rows);
            //��������Ϣ
            ui->tableWidget->setItem(rows,0,new QTableWidgetItem(QString::fromLocal8Bit(date)));
            ui->tableWidget->setItem(rows,1,new QTableWidgetItem(QString::fromLocal8Bit(time)));
            ui->tableWidget->setItem(rows,2,new QTableWidgetItem(QString::fromLocal8Bit(lesson)));
            ui->tableWidget->setItem(rows,3,new QTableWidgetItem(QString::fromLocal8Bit(name)));
            ui->tableWidget->setItem(rows,4,new QTableWidgetItem(QString::fromLocal8Bit(reason)));
        }
        else
            QMessageBox::information(NULL,
                                     QString::fromLocal8Bit("��ʾ"),
                                     QString::fromLocal8Bit("��ʽ������������ȷ��ʽ��"),
                                     QMessageBox::Ok);
    }
}

void MainWindow::on_BtnMotify_clicked()
{
    //��ȡ�������
    int rows=ui->tableWidget->rowCount();
    //0�б��ֱ�ӷ���
    if(rows==0)
        return;
    //��ȡ��ǰ����λ��
    QTableWidgetItem *item = ui->tableWidget->currentItem();
    //����Ի���
    bool ok;
    QString str;
    //����ѡ�������������������Ϣ�޸�
    switch(item->column()){
        case 3:
            str=QInputDialog::getText(this,
                                      QString::fromLocal8Bit("�޸�"),
                                      QString::fromLocal8Bit("�������µ�ѧ������:"),
                                      QLineEdit::Normal,
                                      "",
                                      &ok);
            if(ok && !str.isEmpty())
                item->setText(str);
            break;
        case 2:
            str=QInputDialog::getText(this,
                                      QString::fromLocal8Bit("�޸�"),
                                      QString::fromLocal8Bit("�������µĿγ�����:"),
                                      QLineEdit::Normal,
                                      "",
                                      &ok);
            if(ok && !str.isEmpty())
                item->setText(str);
            break;
        case 0:
            str=QInputDialog::getText(this,
                                      QString::fromLocal8Bit("�޸�"),
                                      QString::fromLocal8Bit("�������µ�ȱ������(��2015-06-27):"),
                                      QLineEdit::Normal,
                                      "",
                                      &ok);
            if(ok && !str.isEmpty()){
                if(is_date(str.toLocal8Bit().data()))
                    item->setText(str);
                else
                    QMessageBox::warning(NULL,
                                         QString::fromLocal8Bit("��ʾ"),
                                         QString::fromLocal8Bit("�����ʽ�������������룡"),
                                         QMessageBox::Ok);
            }
            break;
        case 1:
            str=QInputDialog::getText(this,
                                      QString::fromLocal8Bit("�޸�"),
                                      QString::fromLocal8Bit("�������µ�ȱ�νڴ�(��3-4):"),
                                      QLineEdit::Normal,
                                      "",
                                      &ok);
            if(ok && !str.isEmpty()){
                if(get_lesson_time(str.toLocal8Bit().data()))
                    item->setText(str);
                else
                    QMessageBox::warning(NULL,
                                         QString::fromLocal8Bit("��ʾ"),
                                         QString::fromLocal8Bit("�����ʽ�������������룡"),
                                         QMessageBox::Ok);
            }
            break;
        case 4:
            QStringList list;
            list<<QString::fromLocal8Bit("�ٵ�")<<QString::fromLocal8Bit("����")<<QString::fromLocal8Bit("���")<<QString::fromLocal8Bit("����");
            str=QInputDialog::getItem(this,
                                      QString::fromLocal8Bit("�޸�"),
                                      QString::fromLocal8Bit("��ѡ���µ�ȱ������:"),
                                      list,0,false,&ok);
            if (ok)
                item->setText(str);
            break;
    }
}

void MainWindow::on_BtnDel_clicked()
{
    //��ȡ��ѡ��������в�����ɾ��
    QTableWidgetItem * item = ui->tableWidget->currentItem();
    if(item==Q_NULLPTR)
        return;
    ui->tableWidget->removeRow(item->row());
}

void MainWindow::on_BtnAbout_clicked()
{
    QMessageBox::information(NULL,
                             QString::fromLocal8Bit("����"),
                             QString::fromLocal8Bit("ѧ�����ڹ���ϵͳ v1.0.0.150704 (����Qt����) \n����Qt�����в��������գ�\n��л����ʹ�ã�"),
                             QMessageBox::Ok);
}

void MainWindow::on_BtnSearch_clicked()
{
    int i;
    //��ȡ�������
    int rows=ui->tableWidget->rowCount();
    //0�в����в���
    if(rows==0)
        return;
    //��ѧ����������list�в�����
    QStringList list;
    for(i=0;i<rows;i++)
        if(list.indexOf(ui->tableWidget->item(i,3)->text())==-1)
            list.append(ui->tableWidget->item(i,3)->text());
    list.sort();
    //�����б�����򣬻�ȡѧ������
    QString name;
    bool ok;
    name = QInputDialog::getItem(this,
                                 QString::fromLocal8Bit("��ѯ"),
                                 QString::fromLocal8Bit("��ѡ������ѯ��ѧ������:"),
                                 list,0,false,&ok);
    //�������ok�������в�ѯ��������
    if(ok){
        //��ȡ������������Ŀ����
        int n=0;
        for(i=0;i<rows;i++)
            if(name == ui->tableWidget->item(i,3)->text())
                n++;
        //��������
        student stu[n];
        //��������������Ϣ��������
        for(i=0,n=0;i<rows;i++)
            if(name == ui->tableWidget->item(i,3)->text()){
                strcpy(stu[n].date,  ui->tableWidget->item(i,0)->text().toLocal8Bit().data());
                strcpy(stu[n].time,  ui->tableWidget->item(i,1)->text().toLocal8Bit().data());
                strcpy(stu[n].lesson,ui->tableWidget->item(i,2)->text().toLocal8Bit().data());
                strcpy(stu[n].name,  ui->tableWidget->item(i,3)->text().toLocal8Bit().data());
                strcpy(stu[n].absent_type,ui->tableWidget->item(i,4)->text().toLocal8Bit().data());
                n++;
            }
        //����
        statistic_student(stu,n);
        //��ȡ�������Ϣ
        QString info = getinfo(stu,n,"name");
        //�����Ϣ
        QMessageBox::information(NULL,
                                 QString::fromLocal8Bit("ͳ����Ϣ"),
                                 info,
                                 QMessageBox::Ok);
    }
}

void MainWindow::on_BtnCount_clicked()
{
    int i;
    //��ȡ�������
    int rows=ui->tableWidget->rowCount();
    //0�в����в���
    if(rows==0)
        return;
    QStringList list;
    bool ok;
    //ѡ�����뷽ʽ
    list<<QString::fromLocal8Bit("��ʱ��ͳ��ѧ�����ν���")<<QString::fromLocal8Bit("���γ�ͳ��ѧ����������");
    QString str = QInputDialog::getItem(this,
                                        QString::fromLocal8Bit("ͳ��"),
                                        QString::fromLocal8Bit("��ѡ��ͳ�Ʒ�ʽ"),
                                        list,0,false,&ok);
    if(ok){
        if(!strcmp(str.toLocal8Bit().data(),"��ʱ��ͳ��ѧ�����ν���")){
            //��������б�
            list.clear();
            //��ʱ������list�в�����
            for(i=0;i<rows;i++)
                if(list.indexOf(ui->tableWidget->item(i,0)->text())==-1)
                    list.append(ui->tableWidget->item(i,0)->text());
            list.sort();
            //�����б�����򣬻�ȡ����ʱ��
            QString date;
            ok = false;
            date = QInputDialog::getItem(this,
                                         QString::fromLocal8Bit("ͳ��"),
                                         QString::fromLocal8Bit("��ѡ����ͳ�Ƶ�ʱ��:"),
                                         list,0,false,&ok);
            //����OK����ͳ�ƽ�������
            if(ok){
                //��ȡ������������Ŀ����
                int n=0;
                for(i=0;i<rows;i++)
                    if(date == ui->tableWidget->item(i,0)->text())
                        n++;
                //��������
                student stu[n];
                //��������������Ϣ��������
                for(i=0,n=0;i<rows;i++)
                    if(date == ui->tableWidget->item(i,0)->text()){
                        strcpy(stu[n].date,  ui->tableWidget->item(i,0)->text().toLocal8Bit().data());
                        strcpy(stu[n].time,  ui->tableWidget->item(i,1)->text().toLocal8Bit().data());
                        strcpy(stu[n].lesson,ui->tableWidget->item(i,2)->text().toLocal8Bit().data());
                        strcpy(stu[n].name,  ui->tableWidget->item(i,3)->text().toLocal8Bit().data());
                        strcpy(stu[n].absent_type,ui->tableWidget->item(i,4)->text().toLocal8Bit().data());
                        n++;
                    }
                //����
                statistic_date(stu,n);
                //��ȡ��Ϣ
                QString info = getinfo(stu,n,"date");
                //�����Ϣ
                QMessageBox::information(NULL,
                                         QString::fromLocal8Bit("��Ϣ"),
                                         info,
                                         QMessageBox::Ok);
            }
        }
        else if(!strcmp(str.toLocal8Bit().data(),"���γ�ͳ��ѧ����������")){
            //��������б�
            list.clear();
            //���γ�����list�в�����
            for(i=0;i<rows;i++)
                if(list.indexOf(ui->tableWidget->item(i,2)->text()) == -1)
                    list.append(ui->tableWidget->item(i,2)->text());
            list.sort();
            //�����б�����򣬻�ȡ����ʱ��
            QString lesson;
            ok = false;
            lesson = QInputDialog::getItem(this,
                                           QString::fromLocal8Bit("ͳ��"),
                                           QString::fromLocal8Bit("��ѡ����ͳ�ƵĿγ�:"),
                                           list,0,false,&ok);
            //����OK����ͳ�ƽ�������
            if(ok){
                //��ȡ������������Ŀ����
                int n=0;
                for(i=0;i<rows;i++)
                    if(lesson == ui->tableWidget->item(i,2)->text())
                        n++;
                //��������
                student stu[n];
                //��������������Ϣ��������
                for(i=0,n=0;i<rows;i++)
                    if(lesson == ui->tableWidget->item(i,2)->text()){
                        strcpy(stu[n].date,  ui->tableWidget->item(i,0)->text().toLocal8Bit().data());
                        strcpy(stu[n].time,  ui->tableWidget->item(i,1)->text().toLocal8Bit().data());
                        strcpy(stu[n].lesson,ui->tableWidget->item(i,2)->text().toLocal8Bit().data());
                        strcpy(stu[n].name,  ui->tableWidget->item(i,3)->text().toLocal8Bit().data());
                        strcpy(stu[n].absent_type,ui->tableWidget->item(i,4)->text().toLocal8Bit().data());
                        n++;
                    }
                //����
                statistic_lesson(stu,n);
                //��ȡ��Ϣ
                QString info = getinfo(stu,n,"lesson");
                //�����Ϣ
                QMessageBox::information(NULL,
                                         QString::fromLocal8Bit("��Ϣ"),
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
 * ��������Ϣת��Ϊһ���ַ���
 * ����ֵʾ����
 * ѧ������������
 * 2015-06-01 3-4 ���� �ٵ�
 * 2015-06-02 7-8 ��ɢ ����
 * char *keyΪ�ؼ��֣�name��date��lesson��
 */
QString getinfo(student stu[],int size,char *key){
    int i;
    QString qstr;

    if(!strcmp(key,"name")){
        qstr+=QString::fromLocal8Bit("ѧ��������");
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
        qstr+=QString::fromLocal8Bit("���ڣ�");
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
        qstr+=QString::fromLocal8Bit("�γ����ƣ�");
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
 * ����������Ϣ����
 * Written by ������
 */
//�ж��Ƿ�Ϊ��ȷʱ��
int is_date(char* date){

    int y,m,d;
    int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    if(date[4]!='-')
        return 0;

    if(date[7]!='-')
        return 0;

    if(strlen(date)!=10)  //date��ȡһ��Ҫ�ϸ�
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

//��ȡ�ڴγ���
//����ֵ�������ʽ���󣬷���0����ʽ��ȷ���ؽڴγ���
int get_lesson_time(char* time){
    //��ȷ��ʽ begin-end 3-4
    //��ȡ'-'λ�ò��жϸ�ʽ�Ƿ���ȷ
    int i;
    int n=0;
    for(i=0;i<strlen(time);i++)
        if(time[i]=='-')
            n=i;
    if(n==0)
        return 0;
    //��ȡbegin���ж��Ƿ���ȷ
    int begin=0;
    for(i=0;i<n;i++){
        if(time[i]>='0' && time[i]<='9')
            begin+=(time[i]-'0')*pow(10,n-1-i);
        else
            return 0;
    }
    if(begin==0)
        return 0;
    //��ȡend���ж��Ƿ���ȷ
    int end=0;
    for(i=n+1;i<strlen(time);i++){
        if(time[i]>='0' && time[i]<='9')
            end+=(time[i]-'0')*pow(10,strlen(time)-1-i);
        else
            return 0;
    }
    if(end==0)
        return 0;
    //�ж�begin end��С��ϵ
    if(begin>=end)
        return 0;

    return end-begin;
}

//�ú�������������д��ֻ��ԭ�����б��ڣ�Ҫô����ʱ��ʾ������������������
int is_reason(char* reason)
{
    if(!strcmp(reason,"�ٵ�") || !strcmp(reason,"����") || !strcmp(reason,"���") || !strcmp(reason,"����"))
        return 1;
    else
        return 0;
}

//���벢�ж�������Ϣ��ʽ�Ƿ���ȷ
int separate(char* string,char* date,char* time,char* lesson,char *name,char* reason)
{
    int i,j,n=0,sp[4];
    //�жϿո�����Ƿ�Ϊ4
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

    //��������

    //���벢�ж�����
    char date_t[20];
    for(i=0,j=0;i<sp[0];i++,j++)
        date_t[j]=string[i];
    date_t[j]='\0';
    if(is_date(date_t))
        strcpy(date,date_t);
    else
        return 0;
    //���벢�жϽڴ�
    char time_t[20];
    for(i=sp[0]+1,j=0;i<sp[1];i++,j++)
        time_t[j]=string[i];
    time_t[j]='\0';
    if(get_lesson_time(time_t))
        strcpy(time,time_t);
    else
        return 0;
    //����γ�
    char lesson_t[50];
    for(i=sp[1]+1,j=0;i<sp[2];i++,j++)
        lesson_t[j]=string[i];
    lesson_t[j]='\0';
    strcpy(lesson,lesson_t);
    //��������
    char name_t[50];
    for(i=sp[2]+1,j=0;i<sp[3];i++,j++)
        name_t[j]=string[i];
    name_t[j]='\0';
    strcpy(name,name_t);
    //���벢�жϳٵ�ԭ��
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
