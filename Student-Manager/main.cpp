//main.cpp
#include <iostream>
#include <string>
using namespace std;
#include "admin.h"
#include "staff.h"
#include "stumgr.h"

//��¼����
int login(admin &Admin, staff &Staff){
	string username, password;
	cout << "--------- LOGIN ---------\n";
	cout << "USERNAME: ";
	cin >> username;
	cout << "PASSWORD: ";
	cin >> password;
	cout << "-------------------------\n";
	//����¼��Ϣ
	if (Admin.check(username, password))
		return 1;
	else if (Staff.check(username, password))
		return 2;
	else
		return 0;
}

//�˵�����
void menu(int mode){
	int i = 1;
	cout << "-------------- MENU --------------\n";
	switch (mode){
	case 1:
		cout << i++ << ".Add Student\t";		//1
		cout << i++ << ".Delete Student\n";		//2
	case 2:
		cout << i++ << ".Sort  \t";				//3,1
		cout << i++ << ".Compare\n";			//4,2
		cout << i++ << ".Search\t";				//5,3
		cout << i++ << ".Motify\n";				//6,4
		cout << i++ << ".Add Score\t";			//7,5
		cout << i++ << ".Show All\n";			//8,6
		cout << i++ << ".Logout & Exit\n";		//9,7
	}
	cout << "----------------------------------\n";
	cout << "Please input your choice: ";
}

int main(){
	//����Ա�빤����Ա
	admin Admin;
	Admin.set("admin", "123");
	staff Staff;
	Staff.set("staff", "456");
	//��¼������ģʽ
	int mode = 0;
	//�˵�ѡ��
	int choice = 0;
	//��¼����
	while (1){
		mode = login(Admin, Staff);
		if (0 == mode)
			cout << "Username or Password Wrong.\n";
		else
			break;
	}
	//ѧ���������Ա�
	stumgr StuMgr;
	//ѧ����Ϣ��ʱ����
	string ID, ID1, ID2, Name, Class;
	string key;
	int n, smode;
	//�˵�����
	while (1){
		menu(mode);
		cin >> choice;
		switch (choice + (mode - 1) * 2){	//ѡ��ת��
		case 1:	//Add Student
			cout << "Please input the following things:\n";
			cout << "ID:\t";
			cin >> ID;
			cout << "Name:\t";
			cin >> Name;
			cout << "Class:\t";
			cin >> Class;
			StuMgr.addStudent(ID, Name, Class);
			break;
		case 4:	//Compare
			cout << "Please input 2 Students' ID you want to compare:\n";
			cin >> ID1 >> ID2;
			StuMgr.compare(ID1, ID2);
			break;
		case 2:	//Delete Student
		case 3:	//Sort
		case 5:	//Search
		case 6:	//Motify
		case 7:	//Add Score			�����ƵĴ��룬���кϲ�
			cout << "Please Select Mode:\n";
			cout << "1.ID\t2.Name\t3.Class\n";
			cout << "Please input your choice(1-3): ";
			cin >> smode;
			if (3 == choice){			//sort
				StuMgr.sort(smode);
				break;
			}
			cout << "Please input Key words: ";
			cin >> key;
			n = StuMgr.search(key, smode);	//��ȡλ��
			if (-1 == n)		//û�ҵ�
				cout << "404 NOT FOUND\n";
			else{
				switch (choice){
				case 2:
					StuMgr.delStudent(n);
					break;
				case 5:
					StuMgr.display(n);
					break;
				case 6:
					StuMgr.motify(n);
					break;
				case 7:
					cout << "Please input the score of this student:";
					int score;
					cin >> score;
					StuMgr.addScore(n, score);
				}
			}
			break;
		case 8:	//Show All
			StuMgr.ShowAll();
			break;
		case 9:	//Logout & Exit
			Admin.~admin();
			Staff.~staff();
			StuMgr.~stumgr();
			return 0;
		default:
			cout << "Input error!\n";
		}
	}
	return 0;
}