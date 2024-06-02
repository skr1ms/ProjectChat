#pragma once
#include "User.h"
class Chat : public User
{
public:
	bool logStatus = false; //флажок для 2го свитча в main
	User* userList = new User[size]; //список пользователей (используется для вывода в функции showListOfUsers)
	User getValidUser(std::string log, std::string pas); // функция, возвращающая зарегистрированного пользователя()
	void log(std::string log, std::string pas); //вход в аккаунт 
	void logout(); //выход из аккаунта 
	void sendMes(std::string message, User& tmp, std::string dir = "");// функция для отправки сообщений
	void show(User& tmp, bool flag = false); // функция для отображения сообщений(Есть баг, который я не могу пофиксить, из-за кривой реализации, именно все видят сообщения, которые не должны видеть)
	void showListOfUsers(); //функция для отобрaжения списка пользователей чата
protected:
	User currUser;//переменная для активного пользователя чата;
	std::string chat; //переменная для общего чата между пользователями
};
//extern int size; //размер для списка пользователей
//extern User* userList; //список пользователей
