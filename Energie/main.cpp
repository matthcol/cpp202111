#include <cstdlib>
#include <iostream>

#include "Ligne.h"
// #include "Ligne.h"


Ligne * beginWithLine() {
      // mode direct : Stack
    // avec constructeur par defaut
    Ligne ligne;
    std::cout << ligne.nom << ", " << ligne.getCapaciteMax() 
            << ", " << ligne.capaciteReelle << std::endl;
    ligne.nom = "PAU1";
    ligne.setCapaciteMax(1500);
    std::cout << ligne.nom << ", " << ligne.capaciteMax 
            << ", " << ligne.capaciteReelle << std::endl;

    // mode direct : Stack
    // avec constructeur à 3 parametres
    Ligne ligne2("GRAUROIG1", 1500, 1000);
    std::cout << ligne2.nom << ", " << ligne2.capaciteMax 
            << ", " << ligne2.capaciteReelle << std::endl;

    // allocation dynamique d'une Ligne
    Ligne * ptr_ligne3 =  new  Ligne("MURET2", 3000, 2000);       // &ligne2;
    std::cout << ptr_ligne3->nom << ", " << ptr_ligne3->capaciteMax 
            << ", " << ptr_ligne3->capaciteReelle << std::endl;
    // delete ptr_ligne3;
    return ptr_ligne3;

} // destructeurs des 2 objets Line dans le stack sont appelés

int main() {
    Ligne * ptr_ligne = beginWithLine();
    delete ptr_ligne;
    return EXIT_SUCCESS;
}  