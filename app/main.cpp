#include <iostream>

#include "Ingredient.h"

int main() {
    Ingredient rosie("Rosie", 3, 6.5);
    std::cout << rosie << "\n";
    std::cout << "Valoare stoc: " << rosie.valoareTotala() << " RON\n";

    if (rosie.consuma(1.5)) {
        std::cout << "Am consumat 1.5 kg\n";
    }
    if (!rosie.consuma(10)) {
        std::cout << "Nu sunt destule rosii pentru 10 kg\n";
    }

    rosie.adaugaCantitate(2);
    std::cout << rosie << "\n";

    return 0;
}