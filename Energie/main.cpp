#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <numeric>
#include <utility>
// C++20
// #include <numbers>
// #include <format>

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

void heritage() {
    Ligne l1("PAU1", 1500, 1000);

    // 1 LigneResistive est 1 Ligne 
    LigneResistive l2("GRAUROI1", 1800, 1100, 22.8);

    std::cout << l1 << std::endl;

    // operator<<(ostream&, const Ligne&) appelé
    // grace au mecanisme de substitution (heritage)
    //      appel de Lig (si pas virtual)
    //      appel de LigneResistivie::toString (si virtual)
    std::cout << l2 << std::endl; 
    
    // test
    // appel de LigneResistive::toString
    std::cout << l2.toString() << std::endl;

    Ligne * ptr_ligne = new LigneResistive("MURET1", 1500, 1000, 22.7);
    std::cout << (*ptr_ligne) << std::endl;

    char c;
    std::cin >> c;  // attente clavier

     // call destructeur(s) : les 2 si virtual, seulement celui Ligne si pas virtual
    delete ptr_ligne;

    std::cin >> c;  // attente clavier
}

bool greaterInt(int a, int b) {
    return a > b;
}

void algorithms() {
        Ligne l1("PAU1", 1500, 1000);
    Ligne l2("GRAUROI1", 1800, 1100);
    Ligne l3("MURET1", 1300, 800);

    std::vector<Ligne> vLignes {l1, l2, l3};
    std::vector<int> capacites {1000, 800, 1200};
    std::list<int> lCapacites {1000, 800, 1200};

    // algo tri : n log(n)
    // tri suivant le < du type int : ordre croissant
    std::sort(capacites.begin(), capacites.end());
    displayContainer(capacites);

    // ordre decroissant : operator >
    // std::sort(capacites.begin(), capacites.end(), greaterInt);
    // displayContainer(capacites);

    // ordre decroissant : operator >
    std::sort(capacites.begin(), capacites.end(), std::greater<int>() );
    displayContainer(capacites);


    // tri interdit car l'iterateur de list n'est pas un RandomAccessIterator
    // => trop couteux
    // std::sort(lCapacites.begin(), lCapacites.end());

    // sort avec l'operator< de Ligne
    std::sort(vLignes.begin(), vLignes.end());
    displayContainer(vLignes);

    // tri avec ordre custom sous la forme d'une lambda fonction
    // https://en.cppreference.com/w/cpp/language/lambda
    std::sort(vLignes.begin(), vLignes.end(), 
        // [](const auto &l1, const auto &l2) {
        // [](const auto &l1, const auto &l2)->bool {
        [](const Ligne &l1, const Ligne &l2)->bool {
            return l1.nom() < l2.nom();
        }
    );
    displayContainer(vLignes);


    // somme des capacites
    // int somme =0;
    // for (auto c : capacites) {
    //     somme += c;
    // }
    int somme = std::accumulate(capacites.begin(), capacites.end(), 0);
    std::cout << "Total capacites : " << somme << std::endl;

    int reste = std::accumulate(capacites.begin(), capacites.end(), 5000, std::minus<int>());
    std::cout << "Total capacites : " << reste << std::endl;

    int sommeCustom = std::accumulate(capacites.begin(), capacites.end(), 0, 
            [](auto c1, auto c2){ return c1 + 2*c2;}
            );
    std::cout << "Total capacites : " << sommeCustom << std::endl;

    int coeff = 3;
    int sommeCustom2 = std::accumulate(capacites.begin(), capacites.end(), 0, 
            [coeff](auto c1, auto c2){ return c1 + coeff*c2;}  // capture par copie
            // [&coeff](auto c1, auto c2){ return c1 + coeff*c2;} // capture par ref
            // [=](auto c1, auto c2){ return c1 + coeff*c2;} // capture tt var par copie
            // [&](auto c1, auto c2){ return c1 + coeff*c2;} // capture tt var par ref
            );
    std::cout << "Total capacites : " << sommeCustom2 << std::endl;

    // somme des capacites reelles des lignes de vLigne
    int sommeCapacitReelles = std::accumulate(vLignes.begin(), vLignes.end(), 0,
        [](auto a, const auto &l){
            return a + l.capaciteReelle();
        }
    );

    // utiliser find_if pour trouver la 1ere capacité < 1100
    auto it = std::find_if(capacites.begin(), capacites.end(),
        [](auto c){return c < 1100;}
    );
    if (it != capacites.end()) {
        int capacite = *it;
        std::cout << "Capacite trouvee : " << std::endl;
    } else {
        std::cout << "Aucune Capacite trouvee : " << std::endl;
    }

    // utiliser find_if pour trouver la 1ere Ligne dont la capacité reelle < 1000




    std::fill(capacites.begin(), capacites.end(), 0);
    displayContainer(capacites);

}

// exemple d'utilisation de paire
// pour 3 et + elements : voir std::tuple, std::make_tuple, std::get<pos>(t)
std::pair<int,int> lireCapaciteCapteur() {
    // capacite Max, capacite Reelle
    // std::pair<int,int> res(1500, 1200);
    // return res;
    return std::make_pair(1500, 1200);
}

void testPair() {
    auto capacites = lireCapaciteCapteur();
    std::cout << capacites.first << ", " << capacites.second << std::endl;
}

void testLectureLignes() {
    std::vector<Ligne> lignes(10);
    if (lireLignesCSV("lignes.csv", lignes.begin())) {
        // exploiter le resultat
        displayContainer(lignes);
    } else {
        std::cout << "Pb pendant la lecture du fichier" << std::endl;
    }
}

void testEcritureLigne() {
    Ligne l1("PAU1", 1500, 1000);
    Ligne l2("GRAUROI1", 1800, 1100);
    Ligne l3("MURET1", 1300, 800);

    std::vector<Ligne> vLignes {l1, l2, l3};

    // std::cout << l1 << std::endl;
    
    if (ecrireLignesCSV("lignes2.csv", vLignes.cbegin(), vLignes.cend())) {
        std::cout << "Lignes sauvees avec succes" << std::endl;
    } else{
        std::cout << "Probleme lors de la sauvegarde" << std::endl;
    }
    // ecrireLignesCSV("lignes2.csv", vLignes.cbegin(), vLignes.cbegin()+2);
}

int main() {
    //testLectureLignes();
    testEcritureLigne();


    return EXIT_SUCCESS;
}  





