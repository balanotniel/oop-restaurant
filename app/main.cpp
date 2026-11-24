#include <iostream>
#include <string>

#include "Comanda.h"
#include "Ingredient.h"
#include "Restaurant.h"

int main() {
    Restaurant restaurant("Muddy Moose", "assets/ingrediente.txt", "assets/preparate.txt");
    std::cout << restaurant << "\n";

    std::cout << "=== Procesare comenzi din fisier ===\n";
    restaurant.proceseazaComenziDinFisier("assets/comenzi.txt");

    std::cout << "\n=== Ingrediente de comandat (sub 1 kg) ===\n";
    for (const Ingredient& ingredient : restaurant.ingredienteSubPrag(1.0)) {
        std::cout << "  " << ingredient << "\n";
    }

    std::cout << "\n=== Aprovizionare (de la tastatura) ===\n";
    std::string numeIngredient;
    double cantitate = 0;
    while (std::cin >> numeIngredient >> cantitate) {
        if (restaurant.aprovizioneaza(numeIngredient, cantitate)) {
            std::cout << "Adaugat " << cantitate << " la " << numeIngredient << "\n";
        } else {
            std::cout << "Ingredient necunoscut: " << numeIngredient << "\n";
        }
    }

    std::cout << "\n=== Dupa aprovizionare reincercam comenzile ===\n";
    restaurant.proceseazaComenziDinFisier("assets/comenzi_noi.txt");

    std::cout << "\n=== Copiere si atribuire de comenzi ===\n";
    const Comanda comandaGoala(100, 9, {});
    Comanda copie(comandaGoala);       
    copie = Comanda(101, 1, {});      
    std::cout << "Comanda goala se poate pregati? " << (restaurant.poatePregati(copie) ? "da" : "nu") << "\n";
    restaurant.proceseazaComanda(copie);

    std::cout << "\n";
    restaurant.genereazaRaport(std::cout);
    return 0;
}