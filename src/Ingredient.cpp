#include "Ingredient.h"

Ingredient::Ingredient(const std::string& nume, double cantitate, double pretUnitar) {
    this->nume = nume;
    this->cantitate = cantitate;
    this->pretUnitar = pretUnitar;
}

double Ingredient::valoareTotala() const {
    return cantitate * pretUnitar;
}

bool Ingredient::areSuficient(double cantitateNecesara) const {
    return cantitate >= cantitateNecesara;
}

bool Ingredient::consuma(double cantitateNecesara) {
    if (!areSuficient(cantitateNecesara)) {
        return false;
    }
    cantitate -= cantitateNecesara;
    if (cantitate < 0.000001) {
        cantitate = 0;
    }
    return true;
}

void Ingredient::adaugaCantitate(double cantitateNoua) {
    cantitate += cantitateNoua;
}

bool Ingredient::areNumele(const std::string& altNume) const {
    return nume == altNume;
}

bool Ingredient::acelasiNume(const Ingredient& altul) const {
    return nume == altul.nume;
}

bool Ingredient::consumaPortie(const Ingredient& portie) {
    return consuma(portie.cantitate);
}

Ingredient Ingredient::portie(double cantitateNecesara) const {
    return Ingredient(nume, cantitateNecesara, pretUnitar);
}

std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient) {
    os << ingredient.nume << " | cantitate: " << ingredient.cantitate
       << " | pret unitar: " << ingredient.pretUnitar << " RON";
    return os;
}