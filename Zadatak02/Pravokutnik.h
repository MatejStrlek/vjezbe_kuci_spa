#pragma once
#include <string>
using namespace std;

class Pravokutnik
{
private:
	int sirina, visina;

public:
	void set_sirina(int sirina);
	void set_visina(int visina);
	double povrsina();
	string to_string();
};

