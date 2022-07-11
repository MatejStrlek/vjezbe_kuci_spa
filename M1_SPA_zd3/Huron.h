#pragma once
#include <string>
class Huron
{
private:
	int godina;
	double vodostaj;
public:
	Huron(int godina, double vodostaj);
	double get_vodostaj();
	int get_godina();
	std::string to_string();
};

