#include "account.h"

//设置用户名和密码
void account::set(string username, string password){
	Username = username;
	Password = password;
}
//登录检查
bool account::check(string username, string password){
	return (Username == username && Password == password);
}