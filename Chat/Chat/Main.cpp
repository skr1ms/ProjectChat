#include "Chat.h"

int main() {
	Chat chat;
	User* currentUser = nullptr;
	int option = 1;
	while (option) {
		cout << "1. Register" << endl;
		cout << "2. Login" << endl;
		cout << "3. Send message to user" << endl;
		cout << "4. Send message for all" << endl;
		cout << "5. Get out of the account" << endl;
		cout << "6. Show list of users" << endl;
		cout << "7. Show private messages" << endl;
		cout << "8. Show messages for all" << endl;
		cout << "9. Exit" << endl;
		cout << "Choose 1 of the options " << endl;

		int choice;
		cin >> choice;

		switch (choice) {
		case 1: {

			string login, password, name;
			cout << "Enter login: ";
			cin >> login;
			cout << "Enter password: ";
			cin >> password;
			cout << "Enter name: ";
			cin >> name;
			chat.registerUser(login, password, name);
			cout << "Registration successful!" << endl;
			break;
		}

		case 2:
		{

			string login, password;
			cout << "Enter login: ";
			cin >> login;
			cout << "Enter password: ";
			cin >> password;
			currentUser = chat.loginUser(login, password);
			if (currentUser) {
				cout << "Login successful!" << endl;
			}
			else {
				cout << "Invalid login or password!" << endl;
			}
			break;
		}

		case 3: {

			if (currentUser != nullptr) {
				string recipientLogin;
				cout << "Enter recipient login: ";
				cin >> recipientLogin;
				chat.lsMessage(currentUser, recipientLogin);
			}
			break;
		}

		case 4: {

			string senderLogin, message;
			cout << "Enter sender login: ";
			cin >> senderLogin;
			cout << "Enter message: ";
			cin >> message;
			User* sender = chat.loginUser(senderLogin, "");
			if (sender) {
				chat.broadcastMessage(sender, message);
			}
			else {
				cout << "Invalid login!" << endl;
			}
			break;
		}

		case 5: {

			chat.logout(currentUser);
			break;
		}

		case 6: {
			chat.showListOfUsers();
			break;
		}

		case 7: {
			chat.showLsMessage();
			break;
		}

		case 8: {
			chat.showMessageForAll();
			break;
		}

		case 9: {
			option = 0;
			break;
		}

		default: {
			cout << "Invalid choice!" << endl;
			break;
		}
		}
	}
	return 0;
}