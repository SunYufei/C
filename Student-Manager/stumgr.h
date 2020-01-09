//stumgr.h
#pragma once

#include "student.h"

#define MAXSIZE 100

class stumgr :public student{
private:
	//使用顺序线性表存放student指针
	student data[MAXSIZE];
	int length;
	int maxsize;
public:
	stumgr() :length(0), maxsize(MAXSIZE){}
	void addStudent(string stuID, string stuName, string stuClassroom);
	void addScore(int n, int score);
	void delStudent(int n);
	void display(int n);
	void ShowAll();
	int search(string s, int mode);
	void sort(int mode);
	void motify(int n);
	void compare(string ID1, string ID2);
};