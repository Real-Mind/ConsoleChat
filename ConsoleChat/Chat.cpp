#include "Chat.h"

void Chat::loadMessages()
{
	ifstream messageFile;
	messageFile.open("messages.txt");
	if (!messageFile.is_open()) throw runtime_error("������ �������� ����� ���������!");

	string sender, recipient, text;
	while (messageFile >> sender >> recipient >> text)
	{
		messages.push_back(Message(sender, recipient, text));
	}
	messageFile.close();
}

void Chat::saveMessages()
{
	ofstream messageFile;
	messageFile.open("messages.txt");
	if (!messageFile.is_open()) throw runtime_error("������ �������� ����� ��� ������ ���������!");

	for (Message& message : messages) 
	{
		messageFile << message.getSender() << " " << message.getRecipient() << " " << message.showMessage() << endl;
	}
	messageFile.close();
}

void Chat::loadUsers()
{
	ifstream userFile;
	userFile.open("users.txt");
	if (!userFile.is_open()) throw runtime_error("������ �������� ����� �������������!");

	string username, password, name;
	while (userFile >> username >> password >> name) 
	{
		users.push_back(User(username, password, name));
	}
	userFile.close();
}

void Chat::saveUsers()
{
	ofstream userFile;
	userFile.open("users.txt");
	if (!userFile.is_open()) throw runtime_error("������ �������� ����� ��� ������ �������������!");

	for (User& user : users) 
	{
		userFile << user.getUsername() << " " << user.getPassword() << " " << user.getName() << endl;
	}
	userFile.close();
}

void Chat::registerUser(const string& username, const string& password, const string& name)
{
	for (User& user : users)
	{
		if (user.getUsername() == username) throw runtime_error("������������ � ����� ������� ��� ����������!");
		if (user.getName() == name) throw runtime_error("������������ � ����� ������ ��� ����������!");
	}
	users.push_back(User(username, password, name));
}

void Chat::login(const string& username, const string& password) {
	for (User& user : users) {
		if (user.getUsername() == username && user.getPassword() == password) 
		{
			currentUser = user;
			return;
		}
	}
	throw runtime_error("�������� ����� ��� ������!");
}

void Chat::sendMessage(const string& recipient, const string& text) {
	if (currentUser.getUsername().empty()) 
	{
		throw runtime_error("�� ������ ��������������, ����� ���������� ���������!");
	}

	Message message(currentUser.getUsername(), recipient, text);
	messages.push_back(message);
}

void Chat::showMessages(const string& username) {
	for (Message& message : messages) {
		if (message.getRecipient() == username || message.getSender() == username) {
			cout << message.showMessage() << endl;
		}
	}
}