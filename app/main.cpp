#include <iostream>
#include <vector>

#include "Ingredient.h"
#include "Preparat.h"

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
    std::cout << rosie << "\n\n";

    std::vector<Ingredient> retetaSalata = {
        Ingredient("Rosie", 0.25, 6.5),
        Ingredient("Castravete", 0.2, 5),
        Ingredient("Branza feta", 0.1, 38)
    };
    Preparat salata("Salata greceasca", 28, retetaSalata);
    std::cout << salata;
    std::cout << "Cost productie: " << salata.costProductie() << " RON\n";
    std::cout << "Profit pe portie: " << salata.profit() << " RON\n";
    std::cout << "Marja: " << salata.marjaProfit() << "%\n";

    return 0;
}