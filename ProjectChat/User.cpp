#include "User.h"
int size = 0; //размер для списка пользователей (глобальная переменная)
void User::reg(std::string log, std::string pas)//геттер
{
	login = log;
	password = pas;
	std::cout << "Вы успешно зарегистрировались\n";
}
std::string User::getPassword()//геттер
{
	return this->password;
}
std::string User::getLogin()//геттер
{
	return this->login;
}
void User::clearData()// функция для очищения полей у класса User, для повторной авторизации
{
	login = "";
	password = "";
	online_status = false;
}