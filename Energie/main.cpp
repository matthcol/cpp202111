#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>

#include "Ligne.h"
#include "LigneResistive.h"
#include "tools.h"


Ligne * beginWithLine() {
      // mode direct : Stack
    // avec constructeur par defaut
    Ligne ligne;
    // std::cout << ligne.nom() << ", " << ligne.capaciteMax() 
    //         << ", " << ligne.capaciteReelle() << std::endl;
    std::cout << ligne.toString() << std::endl;
    ligne.setNom("PAU1");
    ligne.setCapaciteMax(1500);
    std::cout << ligne.toString() << std::endl;
    // std::cout << ligne.nom() << ", " << ligne.capaciteMax() 
            // << ", " << ligne.capaciteReelle() << std::endl;

    // mode direct : Stack
    // avec constructeur à 3 parametres
    Ligne ligne2("GRAUROIG1", 1800, 1000);
    std::cout << ligne2.toString() << std::endl;
    // std::cout << ligne2.nom() << ", " << ligne2.capaciteMax() 
            // << ", " << ligne2.capaciteReelle() << std::endl;

    // std::cout << ligne2;
    std::cout << "Egal : " << std::boolalpha << (ligne == ligne2) << std::endl;
    std::cout << "Inegal : " << std::boolalpha << (ligne != ligne2) << std::endl;
    std::cout << "Inerieur : " << std::boolalpha << (ligne < ligne2) << std::endl;
    // std::cout << "Superieur : " << std::boolalpha << (ligne > ligne2) << std::endl;
    // std::cout << boolalpha << (ligne < ligne2);
    // std::cout << (ligne + ligne2);
    // ligne += 100;

    // copie avec l'operateur de copie =
    ligne2 = ligne;
    std::cout << "Egal (after copy): " << std::boolalpha << (ligne == ligne2) << std::endl;

    // constructeur par copie (cadeau)
    Ligne ligne4(ligne);
    // Ligne ligne4 = Ligne(ligne);  // forme correcte equivalent mais peu utilisee

    // allocation dynamique d'une Ligne
    Ligne * ptr_ligne3 =  new  Ligne("MURET2", 3000, 2000);       // &ligne2;
    std::cout << ptr_ligne3->toString() << std::endl;
    // std::cout << ptr_ligne3->nom() << ", " << ptr_ligne3->capaciteMax() 
    //         << ", " << ptr_ligne3->capaciteReelle() << std::endl;
    // // delete ptr_ligne3;

    Ligne * ptr_ligne5 = new Ligne(ligne);
    std::cout << ptr_ligne5->toString() << std::endl;
    delete ptr_ligne5;

    return ptr_ligne3;

} // destructeurs des 2 objets Line dans le stack sont appelés

void callBeginWithLine() {
    Ligne * ptr_ligne = beginWithLine();
    delete ptr_ligne;
}

void containerLigne(){
    Ligne l1("PAU1", 1500, 1000);
    Ligne l2("GRAUROI1", 1800, 1100);
    Ligne l3("MURET1", 1300, 800);

    std::vector<Ligne> vLignes {l1, l2, l3};

    l1.setCapaciteReelle(1200);

    std::set<Ligne> sLignes {l1, l2, l3};

    l1.setCapaciteReelle(1300);

    std::cout << l1 << std::endl;
    std::cerr << l2 << std::endl;

    displayContainer(vLignes);
    displayContainer(sLignes);

    Ligne l = vLignes[0];  // copie =
    l.setCapaciteReelle(200);
   
    displayContainer(vLignes);
    std::cout << l << std::endl;

    Ligne & rl = vLignes[0];  
    rl.setCapaciteReelle(200);

    displayContainer(vLignes);
    std::cout << rl << std::endl;

    std::cout.precision(2);
    // std::cout << std::fixed << l1.pourcentageCharge() << std::endl;
    std::cout << std::scientific << l1.pourcentageCharge() << std::endl;

    // afficher le pourcentage de charge des lignes du vecteur
    for (const auto & ligne : vLignes) {
        std::cout << std::scientific << l1.pourcentageCharge() << std::endl;
    }

    // pour partager les donnees en entree dans un container :
    // std::vector<Ligne &> vrLignes;  // NOK : pointeur sur reference interdit
    // std::vector<Ligne *> vpLignes; // OK 

}

int main() {
    Ligne l1("PAU1", 1500, 1000);

    // 1 LigneResistive est 1 Ligne 
    LigneResistive l2("GRAUROI1", 1800, 1100, 22.8);

    std::cout << l1 << std::endl;

    // operator<<(ostream&, const Ligne&) appelé
    // grace au mecanisme de substitution (heritage)
    //      appel de Lig (si pas virtual)
    //      appel de LigneResistivie::toString (si virtual)
    std::cout << l2 << std::endl; 
    
    // appel de LigneResistive::toString
    std::cout << l2.toString() << std::endl;

    return EXIT_SUCCESS;
}  





