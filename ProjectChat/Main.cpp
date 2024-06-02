#include "Chat.h"
int main()
{
	setlocale(LC_ALL, "rus"); \
	User a;
	Chat chat;
	int choice;
	std::string log;
	std::string pas;
	int s = 1;
	int s2 = 0;
	while (s == 1)
	{
		std::cout << "Добро пожаловать, для того, чтобы начать пользоваться чатом необходимо войти в аккаунт\n";
		std::cout << "1 - регистрация\n";
		std::cout << "2 - вход\n";
		std::cout << "3 - выход\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			std::cout << "Придумайте логин\n";
			std::cin >> log;
			std::cout << "Придумайте пароль\n";
			std::cin >> pas;
			a.reg(log, pas);
			size++;
			User* tmp = new User[size];//реализация динамического массива
			std::copy_n(chat.userList, size - 1, tmp);
			delete[] chat.userList;
			chat.userList = new User[size];
			std::copy_n(tmp, size, chat.userList);
			delete[] tmp;
			chat.userList[size - 1] = a;
			break;
		}
		case 2:
		{
			std::cout << "Введите логин:\n";
			std::cin >> log;
			std::cout << "Введите пароль\n";
			std::cin >> pas;
			chat.log(log, pas);
			if (chat.logStatus = false)
			{
				break;
			}
			s2 = 1;
			while (s2 == 1)// главный цикл, обработки исключений пока что нет
			{
				std::cout << "Добро пожаловать в чат:\n";
				std::cout << "1 - отправить сообщение в чат\n2 - отправить сообщение конкретному пользователю\n3 - выйти из аккаунта\n4 - просмотреть список пользователей\n5 - просмотреть общий чат\n6 - просмотреть личные сообщения\n";
				int choice2;
				std::cin >> choice2;
				switch (choice2)
				{
				case 1:
				{
					std::cout << "Введите свое сообщение:\n";
					std::string message;
					std::cin >> message;
					chat.sendMes(message, a);
					break;
				}
				case 2:
				{
					std::cout << "Введите свое сообщение:\n";
					std::string message;
					std::cin >> message;
					std::string nick;
					std::cout << "Введите имя получателя\n";
					std::cin >> nick;
					chat.sendMes(message, a, nick);
					break;
				}

				case 3:
				{
					chat.logout();
					s2 = 0;
					break;
				}

				case 4:
				{
					chat.showListOfUsers();
					break;
				}

				case 5:
				{
					chat.show(a);
					break;
				}
				case 6:
				{
					chat.show(a, true);
					break;
				}
				}
			}
			break;
		}
		case 3:
		{
			std::cout << "Досвидание!";
			s = 0;
			
		}
		}
	}
	return 0;
}
