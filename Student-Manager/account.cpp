#include "account.h"

//�����û���������
void account::set(string username, string password){
	Username = username;
	Password = password;
}
//��¼���
bool account::check(string username, string password){
	return (Username == username && Password == password);
}