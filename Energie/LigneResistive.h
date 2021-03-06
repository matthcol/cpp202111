#ifndef _LIGNE_RESISITIVE_
#define _LIGNE_RESISITIVE_

#include "Ligne.h"

class LigneResistive: public Ligne {
private:
    double m_resistivite;
    int8_t * m_buffer;

public:
    LigneResistive();
    LigneResistive(const std::string & nom, int capaciteMax, 
            int capaciteReelle, double resistivite);
    // ~LigneResistive();
    virtual ~LigneResistive();

    double resistivite() const;
    void setResistivite(double resistivite);

    virtual std::string toString() const override;

    // virtual int f(int x)=0; // methode virtual pure (abstraite)  =0
};

#endif // !_LIGNE_RESISITIVE_
