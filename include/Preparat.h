#ifndef PREPARAT_H
#define PREPARAT_H

#include <iostream>
#include <string>
#include <vector>

#include "Ingredient.h"

class Preparat {
private:
    std::string nume;
    double pret;
    std::vector<Ingredient> listaIngrediente;

public:
    Preparat(const std::string& nume, double pret, const std::vector<Ingredient>& listaIngrediente);

    double costProductie() const;
    double profit() const;
    double marjaProfit() const;
     double getPret() const; 

    friend std::ostream& operator<<(std::ostream& os, const Preparat& preparat);
};

#endif