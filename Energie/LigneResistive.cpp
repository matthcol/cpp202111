#include "LigneResistive.h"

LigneResistive::LigneResistive(): Ligne(), m_resistivite(0)
{

}

LigneResistive::LigneResistive(const std::string & nom, int capaciteMax, 
        int capaciteReelle, double resistivite
): Ligne(nom, capaciteMax, capaciteReelle), m_resistivite(resistivite)
{

}

LigneResistive::~LigneResistive(){

}

double LigneResistive::resistivite() const{
    return m_resistivite;
}

void LigneResistive::setResistivite(double resistivite){
    m_resistivite = resistivite;
}

std::string LigneResistive::toString() const{
    return "ligne resisitive";
}