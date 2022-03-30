#include "Lampa.h"
#include <sstream>

Lampa::Lampa()
{
    set_model("");
    set_proizvodjac("");
    set_broj_sijalica(0);
    set_snaga_sijalica(0);
}

Lampa::Lampa(const string model):Lampa()
{
    set_model(model);
}

void Lampa::set_model(const string model)
{
    this->model = model;
}

string Lampa::get_model()
{
    return model;
}

void Lampa::set_proizvodjac(const string proizvodjac)
{
    this->proizvodjac = proizvodjac;
}

string Lampa::get_proizvodjac()
{
    return proizvodjac;
}

void Lampa::set_broj_sijalica(const int broj_sijalica)
{
    this->broj_sijalica = broj_sijalica;
}

int Lampa::get_broj_sijalica()
{
    return broj_sijalica;
}

void Lampa::set_snaga_sijalica(const int snaga_sijalica)
{
    this->snaga_sijalica = snaga_sijalica;
}

int Lampa::get_snaga_sijalica()
{
    return snaga_sijalica;
}

string Lampa::to_string()
{
    stringstream ss;

    ss << "model: " << model <<
        ", proizvodjac: " << proizvodjac
        << ", broj sijalica: " << broj_sijalica
        << ", snaga sijalica: " << snaga_sijalica << "W";

    return ss.str();
}
