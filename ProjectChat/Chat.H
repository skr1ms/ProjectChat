#pragma once
#include "User.h"
class Chat : public User
{
public:
	bool logStatus = false; //������ ��� 2�� ������ � main
	User* userList = new User[size]; //������ ������������� (������������ ��� ������ � ������� showListOfUsers)
	User getValidUser(std::string log, std::string pas); // �������, ������������ ������������������� ������������()
	void log(std::string log, std::string pas); //���� � ������� 
	void logout(); //����� �� �������� 
	void sendMes(std::string message, User& tmp, std::string dir = "");// ������� ��� �������� ���������
	void show(User& tmp, bool flag = false); // ������� ��� ����������� ���������(���� ���, ������� � �� ���� ���������, ��-�� ������ ����������, ������ ��� ����� ���������, ������� �� ������ ������)
	void showListOfUsers(); //������� ��� �����a����� ������ ������������� ����
protected:
	User currUser;//���������� ��� ��������� ������������ ����;
	std::string chat; //���������� ��� ������ ���� ����� ��������������
};
//extern int size; //������ ��� ������ �������������
//extern User* userList; //������ �������������
