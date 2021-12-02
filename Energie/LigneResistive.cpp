#include "LigneResistive.h"

LigneResistive::LigneResistive(): Ligne(), m_resistivite(0)
{
    m_buffer = new int8_t[1];
    std::cerr << "Ligne Resisitive construite D[" << this->nom() << "]" << std::endl;
    
}

LigneResistive::LigneResistive(const std::string & nom, int capaciteMax, 
        int capaciteReelle, double resistivite
): Ligne(nom, capaciteMax, capaciteReelle), m_resistivite(resistivite)
{
    m_buffer = new int8_t[500000000];
    for (int i = 0; i < 500000000; i++) {
        m_buffer[i] = 65;
    }
    // std::cerr << "Zone allouee : " << m_buffer << std::endl;
    std::cerr << "Ligne Resisitive construite C[" << this->nom() << "]" << std::endl;
}

LigneResistive::~LigneResistive(){
    delete m_buffer;
    std::cerr << "Ligne Resitive detruite[" << this->nom() << "]" << std::endl;
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