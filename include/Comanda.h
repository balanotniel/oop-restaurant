#ifndef COMANDA_H
#define COMANDA_H

#include <iostream>
#include <vector>

#include "Preparat.h"

class Comanda {
private:
    int id;
    int nrMasa;
    std::vector<Preparat> listaPreparate;

public:
    Comanda(int id, int nrMasa, const std::vector<Preparat>& listaPreparate);

    Comanda(const Comanda& sursa);
    Comanda& operator=(const Comanda& sursa);
    ~Comanda();

    double total() const;
    double profit() const;

    bool esteGoala() const;
    std::vector<Ingredient> ingredienteNecesare() const;

    friend std::ostream& operator<<(std::ostream& os, const Comanda& comanda);
};

#endif