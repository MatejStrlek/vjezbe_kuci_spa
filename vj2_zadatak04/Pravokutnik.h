#pragma once
#include <string>
class Pravokutnik
{
private:
	int sirina;
	int visina;
public:
	Pravokutnik(int sirina, int visina);
	std::string oblik(char rub, char sadrzaj, bool iscrtaj);
};

