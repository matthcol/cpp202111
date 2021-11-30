#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>

// template <class T>
// void displayVector(const std::vector<T> & vector) {
//     // vector.push_back(99999999);  // interdit avec le const
//     for (auto d : vector) {
//         std::cout << d << std::endl;
//     }
// }


template <class InputIterator>
void display(InputIterator first, InputIterator last, const std::string & sep = ", "){
    std::cout << "[";
    if (first != last) {
        std::cout << *first;
        ++first;
        // pour les elements suivants le 1er
        for ( ; first != last; ++first) {
            auto d = *first;
            // std::cout << *first << std::endl;
            std::cout << sep << d; 
        }
    }
    std::cout << "]" << std::endl;
}

template <class C>
void displayContainer(const C & container) {
    // vector.push_back(99999999);  // interdit avec le const
    // for (auto d : container) {
    //     std::cout << d << std::endl;
    // }
    display(container.cbegin(), container.cend());
}


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

    displayContainer(temperatures);  // T=double
    // for (auto temperature : temperatures) {
    //     std::cout << "T = " << temperature << std::endl;
    // }

    // parcours d'un tableau vide
    displayContainer(distances);
    // for (auto d : distances) {
    //     std::cout << "d = " << d << std::endl;
    // }

    displayContainer(villes);  // T=std::string
    // for (auto v : villes) {
    //     std::cout << "v = " << v << std::endl;
    // }

    displayContainer(temperaturesArchive);
    // for (auto temperature : temperaturesArchive) {
    //     std::cout << "Ta = " << temperature << std::endl;
    // }

    // utilisation des iterateur de maniere explicite
    // auto it   => std::vector<double>::iterator
    // auto t   => double t
    for (auto it = temperatures.begin() ; it != temperatures.end(); ++it) {
        auto t = *it;
        std::cout << "t = " << t << std::endl;
    }

    // auto it   => std::vector<double>::reverse_iterator
    display(temperatures.rbegin(), temperatures.rend());
    // for (auto it = temperatures.rbegin() ; it != temperatures.rend(); ++it) {
    //     auto t = *it;
    //     std::cout << "tr = " << t << std::endl;
    // }

    display(temperatures.begin()+1, temperatures.end()-1, " ; ");
    // for (auto it = temperatures.begin()+1 ; it != temperatures.end()-1; ++it) {
    //     auto t = *it;
    //     std::cout << "t_ = " << t << std::endl;
    // }

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

    // temperatures[9] =  20;
    // temperatures[temperatures.size()-1] = 20;

    auto it = temperatures.end() - 1;
    *it = 20;

    for (auto temperature : temperatures) {
        std::cout << "___T___ = " << temperature << std::endl;
    }

    // pas de doublons, ordonné de manière croissante (<)
    std::set<double> setTemperatures (temperatures.begin(), temperatures.end());
    setTemperatures.insert(15.3);
    setTemperatures.insert(4.5);
    
    displayContainer(setTemperatures);
    // for (auto t : setTemperatures) {
    //     std::cout << "Ts = " << t << std::endl;
    // }

    // return 0;
    return EXIT_SUCCESS;
}