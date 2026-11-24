#include "Preparat.h"

Preparat::Preparat(const std::string& nume , double pret , const std::vector <Ingredient>& listaIngrediente)
{
    this->nume=nume;
    this->pret=pret;
    this->listaIngrediente=listaIngrediente;
}


double Preparat::costProductie() const
{
   double s=0;
   for( const Ingredient& ingredient : listaIngrediente)
        {s += ingredient.valoareTotala();}
        
    return s;
}

double Preparat::profit() const {

    return pret-costProductie();

}

double Preparat::marjaProfit() const {
    if(pret==0){return 0;}
    return 100*profit()/pret;
}

std::ostream& operator<<(std::ostream& os, const Preparat& preparat) {
    os << preparat.nume << " | pret: " << preparat.pret << " RON\n";
    for (const Ingredient& ingredient : preparat.listaIngrediente) {
        os << "    - " << ingredient << "\n";
    }
    return os;
}
double Preparat::getPret() const {
    return pret;
}