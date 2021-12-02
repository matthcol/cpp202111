#include "Ligne.h"

#include <iostream>
#include <sstream>

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

bool Ligne::operator==(const Ligne & other) const{
    // return this->m_capaciteMax == other.m_capaciteMax;
    return (this->m_nom == other.m_nom)
        && (this->m_capaciteMax == other.m_capaciteMax);
}

bool Ligne::operator!=(const Ligne & other) const{
    return ! (*this == other);
}

bool Ligne::operator<(const Ligne & other) const {
    return this->m_capaciteMax < other.m_capaciteMax;
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


std::string Ligne::toString() const {
    std::stringstream buf;
    buf << m_nom
        << "[M=" <<  m_capaciteMax
        << ", T=" << m_capaciteReelle
        << "]";
    return buf.str();
}

double Ligne::pourcentageCharge() const{
    // return this->m_capaciteReelle * 1.0 / this->m_capaciteMax;

    // cast explicite du 1er operande, cast implicite du 2e operande
    return ((double) this->m_capaciteReelle)  / this->m_capaciteMax;
}

std::ostream & operator<<(std::ostream & out, const Ligne & ligne) {
    return out << ligne.toString();
}