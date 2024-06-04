#pragma once
#include "User.h"
class Chat {
private:
	vector<User> users;
	map<string, User*> userMap;
	vector<pair<string, string>> privateMessages;
	vector<string> publicMessages;
	int size, lastPersonNum;
public:

	void registerUser(string login, string password, string name);

	auto loginUser(string login, string password) -> User*;

	void lsMessage(User* sender, string recipientLogin);

	void broadcastMessage(User* sender, string message);

	void logout(User*& currentUser);

	void showListOfUsers();

	void showLsMessage();

	void showMessageForAll();

	~Chat() {}
};