//stumgr.cpp
#include <iostream>
using namespace std;
#include "stumgr.h"

//添加学生
void stumgr::addStudent(string stuID, string stuName, string stuClass){
	if (length >= maxsize)
		exit(OVERFLOW);
	data[length].ID = stuID;
	data[length].Name = stuName;
	data[length].Class = stuClass;
	++length;
}

//添加成绩
void stumgr::addScore(int n, int score){
	data[n].Score.Score = score;
}

//删除指定学生信息
void stumgr::delStudent(int n){
	for (int i = n; i < length; ++i){
		data[i] = data[i + 1];
	}
	--length;
}

//显示指定学生信息
void stumgr::display(int n){
	cout << "Student #" << n + 1 << endl;
	cout << "----------------------------------\n";
	cout << "ID:\t" << data[n].ID << endl;
	cout << "Name:\t" << data[n].Name << endl;
	cout << "Class:\t" << data[n].Class << endl;
	cout << "Score:\t" << data[n].Score.Score << endl;
	cout << "----------------------------------\n";
}

//显示所有学生信息
void stumgr::ShowAll(){
	//没有学生
	if (0 == length){
		cout << "No students.\n";
		return;
	}
	//从头遍历，输出信息
	for (int i = 0; i < length; i++)
		display(i);
}

//查找学生信息，返回结点位序
int stumgr::search(string s, int mode){
	//从头遍历，寻找符合的信息
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

//排序
void stumgr::sort(int mode){
	//冒泡排序
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

//修改信息
void stumgr::motify(int n){
	string mID, mName, mClass;
	cout << "Please input the following changes:\n";
	cout << "ID:\t";
	cin >> mID;
	cout << "Name:\t";
	cin >> mName;
	cout << "mClass:\t";
	cin >> mClass;
	//输入非空保存修改信息
	if ("" != mID) data[n].ID = mID;
	if ("" != mName) data[n].Name = mName;
	if ("" != mClass) data[n].Class = mClass;
}

//比较
void stumgr::compare(string ID1, string ID2){
	//任何一个学生没找到
	if (-1 == search(ID1, 1) || -1 == search(ID2, 1)){
		cout << "404 NOT FOUND\n";
		return;
	}	
	//显示两个学生的信息
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