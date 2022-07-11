#include "Client.h"
#include <ctime>
#include <sstream>

Client::Client(string URL, int port)
{
	this->URL = URL;
	this->port = port;
}

Client::Client(string URL)
{
	this->URL = URL;
	this->port = 80;
}

char get_random(int min, int max) {
	return (char)((rand() % (max - min + 1)) + min);
}

string Client::get()
{
	stringstream ss;

	for (size_t i = 0; i < 10; i++)
	{
		ss << get_random(97, 122);
	}
	
	return ss.str();
}

string Client::post()
{
	stringstream ss;

	for (size_t i = 0; i < 10; i++)
	{
		ss << get_random(97, 122);
	}

	return ss.str();
}

int Client::getPort()
{
	return port;
}
