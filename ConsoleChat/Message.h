#pragma once
#include "User.h"

class Message
{
public:
	Message(const string& sender, const string& recipient, const string& text)
		: sender(sender), recipient(recipient), text(text) {}

	string showMessage();

	// Геттеры
	string getSender();
	string getRecipient();

private:
	string sender;
	string recipient;
	string text;
};

