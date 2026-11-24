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

    bool areNumele(const std::string& altNume) const;
    bool acelasiNume(const Ingredient& altul) const;
    bool consumaPortie(const Ingredient& necesar);
    Ingredient portie(double cantitateNecesara) const;

    friend std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient);
};

#endif