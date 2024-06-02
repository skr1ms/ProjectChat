#pragma once
#include <iostream>
#include <string>
class User {
public:
	bool online_status = false; //статус пользователя
	void reg(std::string log, std::string pas); //регистрация
	std::string getLogin(); //геттер для логина
	std::string getPassword(); //геттер для пароля
	std::string getStorage(int i = 0)// геттер для массива сообщений
	{
		return storage[i];
	}
	void setStorage(std::string mes, int i = 0)// геттер для массива сообщений
	{
		storage[i]=mes;
	}
	void clearData();
protected:
	std::string login = "";
	std::string password = "";
	std::string storage[2000] = { "" }; //массив размером в 10000 для хранения личных сообщений
};
extern int size; //размер для списка пользователей