#include <iostream>
#include <cstdlib>
#include <vector>

int main() {
    // construction
    // 1 classe = 1 type complexe
    // temperatures est 1 objet de la classe std::vector
    // construction le vector avec 1 initializer_list
    std::vector<double> temperatures {4.5, 8.7, 24.8, -5.3, 40.2, 36.2};

    // constructeur un vecteur vide (constructeur défaut)
    std::vector<int> distances;

    // construction un vecteur de 4 cases remplies avec la valeur "Pau"
    std::vector<std::string> villes (4, "Pau");

    // constructeur par copie
    std::vector<double> temperaturesArchive (temperatures);

    // operator << non défini entre ostream (cout) et vector<double> 
    // std::cout << temperatures  << std::endl;

    for (auto temperature : temperatures) {
        std::cout << "T = " << temperature << std::endl;
    }

    // parcours d'un tableau vide
    for (auto d : distances) {
        std::cout << "d = " << d << std::endl;
    }

    for (auto v : villes) {
        std::cout << "v = " << v << std::endl;
    }

    for (auto temperature : temperaturesArchive) {
        std::cout << "Ta = " << temperature << std::endl;
    }

    // utilisation des iterateur de maniere explicite
    // auto it   => std::vector<double>::iterator
    // auto t   => double t
    for (auto it = temperatures.begin() ; it != temperatures.end(); ++it) {
        auto t = *it;
        std::cout << "t = " << t << std::endl;
    }

    // auto it   => std::vector<double>::reverse_iterator
    for (auto it = temperatures.rbegin() ; it != temperatures.rend(); ++it) {
        auto t = *it;
        std::cout << "tr = " << t << std::endl;
    }

    for (auto it = temperatures.begin()+1 ; it != temperatures.end()-1; ++it) {
        auto t = *it;
        std::cout << "t_ = " << t << std::endl;
    }

    for (auto it = std::next(temperatures.begin(), 2) ; 
        it != std::next(temperatures.end(), -1); 
        std::advance(it, 1)) 
    {
        auto t = *it;
        std::cout << "_t_ = " << t << std::endl;
    }

    // NB : [] non protégé vs at() protégé
    std::cout << "Taille : " << temperatures.size() << std::endl
            << "Element at : " << temperatures[2] << std::endl
            << "Element at : " << temperatures.at(2) << std::endl
            << "1er element : " << temperatures.front()  << std::endl
            << "dernier element : " << temperatures.back() << std::endl;
    
    temperatures.push_back(27.1);

     for (auto temperature : temperatures) {
        std::cout << "T = " << temperature << std::endl;
    }

    std::vector<double> todayTemperatures {-1.0, 2.3, 10};
    temperatures.insert(
            temperatures.end(),
            todayTemperatures.begin(),
            todayTemperatures.end());

     for (auto temperature : temperatures) {
        std::cout << "_T_ = " << temperature << std::endl;
    }

    // return 0;
    return EXIT_SUCCESS;
}