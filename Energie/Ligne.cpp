#include "Ligne.h"

#include <iostream>

// Ligne::Ligne():m_nom("?"),m_capaciteMax(0), m_capaciteReelle(0) {
Ligne::Ligne(): Ligne("?", 0, 0) {
    std::cerr << "Ligne construite D[" << this->m_nom << "]" << std::endl;
}

Ligne::Ligne(const std::string & nom, int capaciteMax, int capaciteReelle):
        m_nom(nom), m_capaciteMax(capaciteMax), m_capaciteReelle(capaciteReelle)
{
    std::cerr << "Ligne construite C[" << this->m_nom << "]" << std::endl;
}

Ligne::~Ligne(){
    // std::cerr << "Ligne detruite" << nom << std::endl;
    std::cerr << "Ligne detruite[" << this->m_nom << "]" << std::endl;
}

const std::string & Ligne::nom() const {
    return m_nom;
}

void Ligne::setNom(const std::string & nom){
    m_nom = nom;
}

int Ligne::capaciteMax() const{
    return m_capaciteMax;
}

void Ligne::setCapaciteMax(int capaciteMax){
    m_capaciteMax = capaciteMax;
}

int Ligne::capaciteReelle() const{
    return m_capaciteReelle;
}
void Ligne::setCapaciteReelle(int capaciteReelle){
    m_capaciteReelle = capaciteReelle;
}
