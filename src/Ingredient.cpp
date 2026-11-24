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
    return true;
}

void Ingredient::adaugaCantitate(double cantitateNoua) {
    cantitate += cantitateNoua;
}

std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient) {
    os << ingredient.nume << " | cantitate_necesara: " << ingredient.cantitate
       << " | pret unitar: " << ingredient.pretUnitar << " RON";
    return os;
}