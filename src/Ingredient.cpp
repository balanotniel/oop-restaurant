#include "Ingredient.h"

Ingredient::Ingredient(const std::string& nume_, double cantitate_, double pretUnitar_)
    : nume(nume_), cantitate(cantitate_), pretUnitar(pretUnitar_) {}

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
    os << ingredient.nume << " | stoc: " << ingredient.cantitate
       << " | pret unitar: " << ingredient.pretUnitar << " RON";
    return os;
}