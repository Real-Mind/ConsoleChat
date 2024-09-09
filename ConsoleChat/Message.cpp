#include "Message.h"

string Message::showMessage()
{
	return sender + " -> " + recipient + ": " + text;
}

string Message::getRecipient()
{
	return recipient;
}

string Message::getSender()
{
	return sender;
}