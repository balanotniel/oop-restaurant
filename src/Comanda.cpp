#include "Comanda.h"

Comanda::Comanda(int id, int nrMasa, const std::vector<Preparat>& listaPreparate) {
    this->id = id;
    this->nrMasa = nrMasa;
    this->listaPreparate = listaPreparate;
}

Comanda::Comanda(const Comanda& sursa) {
    this->id = sursa.id;
    this->nrMasa = sursa.nrMasa;
    this->listaPreparate = sursa.listaPreparate;
}

Comanda& Comanda::operator=(const Comanda& sursa) {
    if (this != &sursa) {
        this->id = sursa.id;
        this->nrMasa = sursa.nrMasa;
        this->listaPreparate = sursa.listaPreparate;
    }
    return *this;
}

Comanda::~Comanda() {
}

double Comanda::total() const {
    double s = 0;
    for (const Preparat& preparat : listaPreparate) {
        s += preparat.getPret();
    }
    return s;
}

double Comanda::profit() const {
    double s = 0;
    for (const Preparat& preparat : listaPreparate) {
        s += preparat.profit();
    }
    return s;
}

std::ostream& operator<<(std::ostream& os, const Comanda& comanda) {
    os << "Comanda #" << comanda.id << " | masa " << comanda.nrMasa
       << " | total: " << comanda.total() << " RON\n";
    for (const Preparat& preparat : comanda.listaPreparate) {
        os << "  " << preparat;
    }
    return os;
}