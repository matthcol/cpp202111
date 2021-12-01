#ifndef _LIGNE_
#define _LIGNE_

#include <string>

class Ligne {
private:
    std::string m_nom;
    int m_capaciteMax;
    int m_capaciteReelle;   

public:
     // constructeur par defaut
    Ligne();
    // constructeur complet
    Ligne(const std::string & nom, int capaciteMax, int capaciteReelle);
    // destructeur
    // nb : virtual => pratique pour une specialisation de cette classe
    virtual ~Ligne(); 

    // accesseurs : getters and setters
    const std::string & nom() const;
    void setNom(const std::string & nom);

    int capaciteMax() const;
    void setCapaciteMax(int capaciteMax);

    int capaciteReelle() const;
    void setCapaciteReelle(int capaciteReelle);

};

#endif // _LIGNE_