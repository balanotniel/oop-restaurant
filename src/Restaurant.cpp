#include "Restaurant.h"

#include <fstream>


Restaurant::Restaurant(const std::string& nume, const std::string& fisierStoc, const std::string& fisierMeniu) {
    this->nume = nume;
    this->nrComenziRespinse = 0;
    incarcaStoc(fisierStoc);
    incarcaMeniu(fisierMeniu);
}

// ===================== CITIRE DIN FISIERE =====================

// Fiecare rand din fisier: nume cantitate pret

void Restaurant::incarcaStoc(const std::string& caleFisier) {
    std::ifstream fin(caleFisier);
    if (!fin) {
        std::cout << "Nu pot deschide fisierul " << caleFisier << "\n";
        return;
    }

    std::string numeIngredient;
    double cantitate = 0;
    double pret = 0;
    while (fin >> numeIngredient >> cantitate >> pret) {
        const Ingredient ingredient(numeIngredient, cantitate, pret);
        stoc.push_back(ingredient);
    }
}

// Un preparat: un rand "nume pret numarIngrediente",
// apoi numarIngrediente randuri "ingredient cantitateNecesara"
void Restaurant::incarcaMeniu(const std::string& caleFisier) {
    std::ifstream fin(caleFisier);
    if (!fin) {
        std::cout << "Nu pot deschide fisierul " << caleFisier << "\n";
        return;
    }

    std::string numePreparat;
    double pret = 0;
    int numarIngrediente = 0;
    while (fin >> numePreparat >> pret >> numarIngrediente) {
        std::vector<Ingredient> reteta;
        for (int i = 0; i < numarIngrediente; i++) {
            std::string numeIngredient;
            double cantitateNecesara = 0;
            fin >> numeIngredient >> cantitateNecesara;

            // pretul ingredientului il luam din stoc
            const Ingredient* dinStoc = gasesteIngredient(numeIngredient);
            if (dinStoc != nullptr) {
                reteta.push_back(dinStoc->portie(cantitateNecesara));
            } else {
                std::cout << "Ingredient necunoscut in reteta: " << numeIngredient << "\n";
            }
        }
        const Preparat preparat(numePreparat, pret, reteta);
        meniu.push_back(preparat);
    }
}

// ===================== CAUTARE DUPA NUME =====================

// Intoarce adresa ingredientului din stoc, sau nullptr daca nu exista
Ingredient* Restaurant::gasesteIngredient(const std::string& numeIngredient) {
    for (Ingredient& ingredient : stoc) {
        if (ingredient.areNumele(numeIngredient)) {
            return &ingredient;
        }
    }
    return nullptr;
}

// Intoarce adresa preparatului din meniu, sau nullptr daca nu exista
const Preparat* Restaurant::gasestePreparat(const std::string& numePreparat) const {
    for (const Preparat& preparat : meniu) {
        if (preparat.areNumele(numePreparat)) {
            return &preparat;
        }
    }
    return nullptr;
}

// ===================== COMENZI =====================

// Incearca sa "gateasca" toata comanda pe o COPIE a stocului.
// Daca vreun ingredient nu ajunge, comanda nu se poate pregati.
// Asa, 2 salate scad de 2 ori rosiile din copie, deci se verifica corect totalul.
bool Restaurant::poatePregati(const Comanda& comanda) const {
    std::vector<Ingredient> stocDeProba = stoc;

    for (const Ingredient& portie : comanda.ingredienteNecesare()) {
        bool scazut = false;
        for (Ingredient& ingredient : stocDeProba) {
            if (ingredient.acelasiNume(portie) && ingredient.consumaPortie(portie)) {
                scazut = true;
            }
        }
        if (!scazut) {
            return false;
        }
    }
    return true;
}

bool Restaurant::proceseazaComanda(const Comanda& comanda) {
    if (comanda.esteGoala()) {
        nrComenziRespinse++;
        std::cout << "Respinsa (comanda goala)\n";
        return false;
    }
    if (!poatePregati(comanda)) {
        nrComenziRespinse++;
        std::cout << "Respinsa (stoc insuficient):\n" << comanda;
        return false;
    }

    // stim sigur ca ajunge, deci scadem din stocul real
    for (const Ingredient& portie : comanda.ingredienteNecesare()) {
        for (Ingredient& ingredient : stoc) {
            if (ingredient.acelasiNume(portie)) {
                ingredient.consumaPortie(portie);
            }
        }
    }

    listaComenzi.push_back(comanda);
    std::cout << "Acceptata:\n" << comanda;
    return true;
}

// O comanda: un rand "id masa numarPreparate", apoi numarPreparate randuri cu numele preparatelor
void Restaurant::proceseazaComenziDinFisier(const std::string& caleFisier) {
    std::ifstream fin(caleFisier);
    if (!fin) {
        std::cout << "Nu pot deschide fisierul " << caleFisier << "\n";
        return;
    }

    int id = 0;
    int masa = 0;
    int numarPreparate = 0;
    while (fin >> id >> masa >> numarPreparate) {
        std::vector<Preparat> preparate;
        for (int i = 0; i < numarPreparate; i++) {
            std::string numePreparat;
            fin >> numePreparat;

            const Preparat* preparat = gasestePreparat(numePreparat);
            if (preparat != nullptr) {
                preparate.push_back(*preparat);
            } else {
                std::cout << "Preparat inexistent in meniu: " << numePreparat << "\n";
            }
        }
        proceseazaComanda(Comanda(id, masa, preparate));
    }
}

// ===================== STOC =====================

bool Restaurant::aprovizioneaza(const std::string& numeIngredient, double cantitate) {
    Ingredient* ingredient = gasesteIngredient(numeIngredient);
    if (ingredient == nullptr) {
        return false;
    }
    ingredient->adaugaCantitate(cantitate);
    return true;
}

std::vector<Ingredient> Restaurant::ingredienteSubPrag(double prag) const {
    std::vector<Ingredient> rezultat;
    for (const Ingredient& ingredient : stoc) {
        if (!ingredient.areSuficient(prag)) {
            rezultat.push_back(ingredient);
        }
    }
    return rezultat;
}

// ===================== RAPORT SI AFISARE =====================

void Restaurant::genereazaRaport(std::ostream& os) const {
    double venit = 0;
    double profitTotal = 0;
    for (const Comanda& comanda : listaComenzi) {
        venit += comanda.total();
        profitTotal += comanda.profit();
    }

    os << "=== Raport " << nume << " ===\n";
    os << "Comenzi acceptate: " << listaComenzi.size() << "\n";
    os << "Comenzi respinse: " << nrComenziRespinse << "\n";
    os << "Venit total: " << venit << " RON\n";
    os << "Profit total: " << profitTotal << " RON\n";
}

std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant) {
    os << "Restaurant " << restaurant.nume << "\n";
    os << "Stoc:\n";
    for (const Ingredient& ingredient : restaurant.stoc) {
        os << "  " << ingredient << "\n";
    }
    os << "Meniu:\n";
    for (const Preparat& preparat : restaurant.meniu) {
        os << "  " << preparat;
        os << "    marja de profit: " << preparat.marjaProfit() << "%\n";
    }
    return os;
}