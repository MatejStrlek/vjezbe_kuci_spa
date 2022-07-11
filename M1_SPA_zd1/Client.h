#pragma once
#include <iostream>
using namespace std;

class Client {
public:
	Client(string URL, int port);
	Client(string URL);
	string get();
	string post();
	int getPort();
private:
	string URL;
	int port;
};