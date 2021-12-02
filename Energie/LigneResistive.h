#ifndef _LIGNE_RESISITIVE_
#define _LIGNE_RESISITIVE_

#include "Ligne.h"

class LigneResistive: public Ligne {
private:
    double m_resistivite;

public:
    LigneResistive();
    LigneResistive(const std::string & nom, int capaciteMax, 
            int capaciteReelle, double resistivite);
    virtual ~LigneResistive();

    double resistivite() const;
    void setResistivite(double resistivite);

    virtual std::string toString() const override;
};

#endif // !_LIGNE_RESISITIVE_
