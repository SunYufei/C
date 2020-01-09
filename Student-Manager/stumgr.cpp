//stumgr.cpp
#include <iostream>
using namespace std;
#include "stumgr.h"

//���ѧ��
void stumgr::addStudent(string stuID, string stuName, string stuClass){
	if (length >= maxsize)
		exit(OVERFLOW);
	data[length].ID = stuID;
	data[length].Name = stuName;
	data[length].Class = stuClass;
	++length;
}

//��ӳɼ�
void stumgr::addScore(int n, int score){
	data[n].Score.Score = score;
}

//ɾ��ָ��ѧ����Ϣ
void stumgr::delStudent(int n){
	for (int i = n; i < length; ++i){
		data[i] = data[i + 1];
	}
	--length;
}

//��ʾָ��ѧ����Ϣ
void stumgr::display(int n){
	cout << "Student #" << n + 1 << endl;
	cout << "----------------------------------\n";
	cout << "ID:\t" << data[n].ID << endl;
	cout << "Name:\t" << data[n].Name << endl;
	cout << "Class:\t" << data[n].Class << endl;
	cout << "Score:\t" << data[n].Score.Score << endl;
	cout << "----------------------------------\n";
}

//��ʾ����ѧ����Ϣ
void stumgr::ShowAll(){
	//û��ѧ��
	if (0 == length){
		cout << "No students.\n";
		return;
	}
	//��ͷ�����������Ϣ
	for (int i = 0; i < length; i++)
		display(i);
}

//����ѧ����Ϣ�����ؽ��λ��
int stumgr::search(string s, int mode){
	//��ͷ������Ѱ�ҷ��ϵ���Ϣ
	for (int i = 0; i < length; i++){
		switch (mode){
		case 1:
			if (data[i].ID == s)
				return i;
			break;
		case 2:
			if (data[i].Name == s)
				return i;
			break;
		case 3:
			if (data[i].Class == s)
				return i;
			break;
		}
	}
	return -1;
}

//����
void stumgr::sort(int mode){
	//ð������
	for (int i = 0; i < length - 1; ++i)
		for (int j = 0; j < length - i - 1; ++j){
			switch (mode){
			case 1:
				if (data[j].ID > data[j + 1].ID)
					swap(data[j], data[j + 1]);
				break;
			case 2:
				if (data[j].Name > data[j + 1].Name)
					swap(data[j], data[j + 1]);
				break;
			case 3:
				if (data[j].Class > data[j + 1].Class)
					swap(data[j], data[j + 1]);
				break;
			}
		}
}

//�޸���Ϣ
void stumgr::motify(int n){
	string mID, mName, mClass;
	cout << "Please input the following changes:\n";
	cout << "ID:\t";
	cin >> mID;
	cout << "Name:\t";
	cin >> mName;
	cout << "mClass:\t";
	cin >> mClass;
	//����ǿձ����޸���Ϣ
	if ("" != mID) data[n].ID = mID;
	if ("" != mName) data[n].Name = mName;
	if ("" != mClass) data[n].Class = mClass;
}

//�Ƚ�
void stumgr::compare(string ID1, string ID2){
	//�κ�һ��ѧ��û�ҵ�
	if (-1 == search(ID1, 1) || -1 == search(ID2, 1)){
		cout << "404 NOT FOUND\n";
		return;
	}	
	//��ʾ����ѧ������Ϣ
	int n1 = search(ID1, 1);
	int n2 = search(ID2, 1);
	cout << "Compare Student" << endl;
	cout << "----------------------------------\n";
	cout << "ID:\t" << data[n1].ID << "\t" << data[n2].ID << endl;
	cout << "Name:\t" << data[n1].Name << "\t" << data[n2].Name << endl;
	cout << "Class:\t" << data[n1].Class << "\t" << data[n2].Class << endl;
	cout << "Score:\t" << data[n1].Score.Score << "\t" << data[n2].Score.Score << endl;
	cout << "----------------------------------\n";
}