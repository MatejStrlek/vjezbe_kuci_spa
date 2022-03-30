#pragma once
#include <string>
using namespace std;

class Lampa
{
public:
	Lampa();
	Lampa(const string model);
	void set_model(const string model);
	string get_model();
	void set_proizvodjac(const string proizvodjac);
	string get_proizvodjac();
	void set_broj_sijalica(const int broj_sijalica);
	int get_broj_sijalica();
	void set_snaga_sijalica(const int snaga_sijalica);
	int get_snaga_sijalica();
	string to_string();
private:
	string model;
	string proizvodjac;
	int broj_sijalica;
	int snaga_sijalica;
};

