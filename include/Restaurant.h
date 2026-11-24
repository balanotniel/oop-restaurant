#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include <vector>

#include "Comanda.h"
#include "Ingredient.h"
#include "Preparat.h"

class Restaurant {
private:
    std::string nume;
    std::vector<Ingredient> stoc;
    std::vector<Preparat> meniu;
    std::vector<Comanda> listaComenzi;
    int nrComenziRespinse;

    void incarcaStoc(const std::string& caleFisier);
    void incarcaMeniu(const std::string& caleFisier);
    Ingredient* gasesteIngredient(const std::string& numeIngredient);
    const Preparat* gasestePreparat(const std::string& numePreparat) const;

public:
    Restaurant(const std::string& nume, const std::string& fisierStoc, const std::string& fisierMeniu);

    bool poatePregati(const Comanda& comanda) const;
    bool proceseazaComanda(const Comanda& comanda);
    void proceseazaComenziDinFisier(const std::string& caleFisier);
    bool aprovizioneaza(const std::string& numeIngredient, double cantitate);
    std::vector<Ingredient> ingredienteSubPrag(double prag) const;
    void genereazaRaport(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant);
};

#endif