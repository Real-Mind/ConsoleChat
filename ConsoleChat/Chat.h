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

	void loadUsers();		// Загрузка пользователей из файла users.txt в вектор users
	void saveUsers();		// Сохранение вектора users в файл users.txt
	void loadMessages();	// Загрузка сообщений из файла messages.txt в вектор messages
	void saveMessages();	// Сохранения вектора messages в файл messages.txt
};

