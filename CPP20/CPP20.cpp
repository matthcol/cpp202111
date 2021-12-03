// CPP20.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <format>
#include <numbers>

int main()
{
    int x = 14;
    int y = 20;
    auto cmp = x <=> y;
    
    std::cout << std::boolalpha
        << "== : " << std::is_eq(cmp)
        << " ; < : " << std::is_lt(cmp)
        << " ; >= : " << std::is_gteq(cmp)
        << std::endl;
    
    std::cout << "PI=" << std::numbers::pi << std::endl;

    // feature non encore dispo avec msvc 2015-2022
    //std::cout << std::format("x={} ; y={}", x, y) << std::endl;


}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
