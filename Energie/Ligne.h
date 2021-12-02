#ifndef _LIGNE_
#define _LIGNE_

#include <string>
#include <iostream>

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

    // surcharges operateurs
    bool operator==(const Ligne & other) const;
    bool operator!=(const Ligne & other) const;

    //   <  d'apres la capacite max
    bool operator<(const Ligne & other) const;

    // accesseurs : getters and setters
    const std::string & nom() const;
    void setNom(const std::string & nom);

    int capaciteMax() const;
    void setCapaciteMax(int capaciteMax);

    int capaciteReelle() const;
    void setCapaciteReelle(int capaciteReelle);

    // methodes supplementaires
    virtual std::string toString() const;

    // pourcentageCharge = cap reelle / cap max
    double pourcentageCharge() const;

};

std::ostream & operator<<(std::ostream & out, const Ligne & ligne);


#endif // _LIGNE_