#include "Pravokutnik.h"
#include <sstream>

Pravokutnik::Pravokutnik(int sirina, int visina)
{
    if (sirina <= 0 || visina <= 0) {
        throw std::exception("Morate unijeti vrijednosti vece od 0!");
    }
    this->sirina = sirina;
    this->visina = visina;
}

std::string Pravokutnik::oblik(char rub, char sadrzaj, bool iscrtaj)
{
    std::stringstream ss;

    for (int i = 0; i < visina; i++) {
        for (int j = 0; j < sirina; j++)
        {
            if (i == 0 || j == 0 || i == visina - 1 || j == sirina - 1) {
                ss << rub;
            }
            else {
                if (iscrtaj) {
                    ss << sadrzaj;
                }
                else {
                    ss << " ";
                }
            }
        }
        ss << std::endl;
    }

    return ss.str();
}
