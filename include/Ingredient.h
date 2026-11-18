#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <iostream>
#include <string>

class Ingredient {
private:
    std::string nume;
    double cantitate;
    double pretUnitar;

public:
    Ingredient(const std::string& nume, double cantitate, double pretUnitar);

    double valoareTotala() const;
    bool areSuficient(double cantitateNecesara) const;
    bool consuma(double cantitateNecesara);
    void adaugaCantitate(double cantitateNoua);

    friend std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient);
};

#endif