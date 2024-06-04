#include "Chat.h"

void Chat::registerUser(string login, string password, string name) {
	User* user = new User(login, password, name);
	users.push_back(*user);
	userMap[login] = user;
}

auto Chat::loginUser(string login, string password) -> User* {
	if (userMap.find(login) != userMap.end() && userMap[login]->password == password) {
		return userMap[login];
	}
	return nullptr;
}

void Chat::lsMessage(User* sender, string recipientLogin) {
	if (userMap.find(recipientLogin) != userMap.end()) {
		string message;
		cout << "Enter message: ";
		cin >> message;
		cout << sender->name << " sends private message to " << userMap[recipientLogin]->name << ": " << message << endl;
	}
	else {
		cout << "User not found!" << std::endl;
	}
}

void Chat::broadcastMessage(User* sender, string message) {
	for (auto& user : users) {
		if (user.login != sender->login) {
			cout << sender->name << " sends message to all: " << message << endl;
		}
	}
}

void Chat::logout(User*& currentUser)
{
	if (currentUser != nullptr) {
		cout << "you have logged out of your account\n";
		currentUser = nullptr;
	}
	else {
		cout << "you are not logged in\n";
	}
}

void Chat::showListOfUsers() {
	for (auto& user : users) {
		cout << "Login: " << user.login << ", Name: " << user.name << endl;
	}
}

void Chat::showLsMessage() {
	if (privateMessages.empty()) {
		cout << "No messages yet." << endl;
	}
	else {
		cout << "Public messages:" << endl;
		for (auto& message : privateMessages) {
			cout << message.first << " -> " << message.second << endl;
		}
	}
}

void Chat::showMessageForAll() {
	if (publicMessages.empty()) {
		cout << "No messages yet." << endl;
	}
	else {
		cout << "Public messages:" << endl;
		for (const auto& message : publicMessages) {
			cout << message << endl;
		}
	}
}
