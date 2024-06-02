#include "Chat.h"
int lastPersonNum;
User Chat::getValidUser(std::string log, std::string pas) // функция, проверяющая есть ли пользователь в списке зарегистрироввнныех пользователей
{
	for (int i = 0; i < size; i++)
	{
		if (userList[i].getLogin() == log)
		{
			if (userList[i].getPassword() == pas)
			{
				userList[i].online_status = true;
				lastPersonNum = i;
				return userList[i];
			}
		}
	}
	User s;//на случай, если нет, возвращаем пустой объект
	s.reg("", "");
	return s;
}
void Chat::log(std::string log, std::string pas)
{
	User tmp2 = getValidUser(log, pas);//временный объект для проверки
	if (tmp2.getLogin() != "")
	{
		currUser = tmp2;
		std::cout << "Вы успешно вошли!\n";
		logStatus = true;
	}
	else 
	{
		std::cout << "Неверные данные\n";
	}
}
void Chat::logout()
{
	std::cout << "Вы успешно вышли\n";
	currUser.online_status = false;
	userList[lastPersonNum] = currUser;//меняем онлайн статус в списке пользователей
	currUser.clearData();
}
void Chat::sendMes(std::string message, User& tmp, std::string dir)
{
	if (dir == "")
	{
		chat += message + "\n";//переменная для общего чата
		std::cout << "Сообщение успешно отправлено\n";
	}
	else {
		for (int i = 0; i < size; i++)
		{
			if (dir == userList[i].getLogin())//отправка сообщений(запись сообщений происходит в переменную storage[] в классе Users)
			{
				int j = 0;
				while (tmp.getStorage(j) != "")
				{
					j++;
				}
				std::string result_mes = "Сообщение от " + currUser.getLogin() + " для: " + userList[i].getLogin() + "\n" + "Сообщение: " + message;
				tmp.setStorage(result_mes, j);
				std::cout << "Сообщение успешно отправлено\n";
				break;
			}
			if (dir != userList[i].getLogin() && i == size - 1)
			{
				std::cout << "Нет такого пользователя\n";
			}
		}
	}
}
void Chat::show(User& tmp, bool flag)
{
	if (flag == false)//тут просто вывод перменной общего чата
	{
		std::cout << "Общий чат:\n";
		std::cout << chat << std::endl;
	}
	else {//в общем, проверка, есть ли в сообщении ник пользователя, чтобы он увидел сообщение, которое ему/он отправил, работает криво(надо фиксить)
		std::cout << "Ваши сообщения:\n";
		if (tmp.getStorage(0) == "")
		{
			return;
		}
		for (int i = 0; i < 2000; i++)
		{
			if (tmp.getStorage(i).find(currUser.getLogin())&& tmp.getStorage(i)!="")
			{
				std::cout << tmp.getStorage(i).find(currUser.getLogin()) << std::endl;
			}
			else if (tmp.getStorage(i) =="")
			{
				return;
			}
		}
	}
}
void Chat::showListOfUsers()//вывод всех пользователей и их статус прямо сейчас
{
	std::cout << "Список пользователей:\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << "Имя пользователя: " << userList[i].getLogin();
		if (userList[i].online_status == false)
			std::cout << "Статус: Offline\n";
		else
			std::cout << "Статус: Online\n";
	}
}