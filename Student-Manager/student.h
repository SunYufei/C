//Student.h
#pragma once

#include <string>
using namespace std;
#include "score.h"

class student :public score{
public:
	student() :ID(""), Name(""), Class(""){}
	string ID;
	string Name;
	string Class;
	score Score;
};
