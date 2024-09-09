#pragma once
#include "User.h"
#include "Message.h"

class Chat
{
public:
	Chat() 
	{
		loadMessages();
		loadUsers();
	}
	~Chat()
	{
		saveMessages();
		saveUsers();
	}

	void registerUser(const string& username, const string& password, const string& name);
	void login(const string& username, const string& password);
	void sendMessage(const string& recipient, const string& text);
	void showMessages(const string& username);

private:
	vector<User> users;
	vector<Message> messages;
	User currentUser;

	void loadUsers();		// �������� ������������� �� ����� users.txt � ������ users
	void saveUsers();		// ���������� ������� users � ���� users.txt
	void loadMessages();	// �������� ��������� �� ����� messages.txt � ������ messages
	void saveMessages();	// ���������� ������� messages � ���� messages.txt
};

