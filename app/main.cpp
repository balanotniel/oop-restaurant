#include <iostream>
#include <vector>

#include "Ingredient.h"
#include "Preparat.h"
#include "Comanda.h"

int main() {
    std::vector<Ingredient> retetaSalata = {
        Ingredient("Rosie", 0.25, 6.5),
        Ingredient("Castravete", 0.2, 5),
        Ingredient("Branza feta", 0.1, 38)
    };
    std::vector<Ingredient> retetaCiorba = {
        Ingredient("Morcov", 0.15, 4),
        Ingredient("Ceapa", 0.1, 3),
        Ingredient("Cartof", 0.2, 3.5)
    };

    Preparat salata("Salata greceasca", 28, retetaSalata);
    Preparat ciorba("Ciorba de legume", 18, retetaCiorba);

    Comanda c1(1, 4, {salata, salata, ciorba});
    std::cout << c1;
    std::cout << "Profit comanda: " << c1.profit() << " RON\n\n";

    Comanda c2 = c1;
    std::cout << "Copie (constructor de copiere):\n" << c2 << "\n";

    Comanda c3(2, 7, {ciorba});
    std::cout << "Inainte de atribuire:\n" << c3;
    c3 = c1;
    std::cout << "Dupa atribuire (operator=):\n" << c3;

    return 0;
}