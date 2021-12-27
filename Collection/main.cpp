#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>

/**
 * @brief display iterable items on one line [e1, e2, ..., en]
 * Operator << must be defined for the items displayed
 * @tparam InputIterator type of iterator used to display items
 * @param first iterator on the first item to display (included)
 * @param last iterator on the last item (excluded)
 * @param sep separator used between each item
 */
template <class InputIterator>
void display(
    InputIterator first, 
    InputIterator last, 
    const std::string & sep = ", ",
    const std::string & delimiterFirst = "[ ",
    const std::string & delimiterLast = " ]",
    bool endline = true)
{
    // begin display with delimiterFirst
    std::cout << delimiterFirst;
    if (first != last) {
        // display first element
        std::cout << *first;
        ++first;
        // display following elements
        for ( ; first != last; ++first) {
            // The following 2 lines can be written in one without local variable
            auto d = *first; // accessing element
            std::cout << sep << d; 
        }
    }
    // ending display with delimiterLast
    std::cout << delimiterLast;
    // optional endline
    if (endline) {
        std::cout << std::endl;
    }
}

template <class Container>
void displayContainer(const Container & container) {
    // Illustrating usage of const, the following instruction is forbidden
    // vector.push_back(99999999);  
    display(container.cbegin(), container.cend());
}


void playWithConollections() {
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
}

void demoMemoire() {
    char c;
    std::vector<int8_t> data(2000000000, 65);
    std::cout << "Tableau cree" << std::endl;
    display(data.begin(), data.begin()+10);
    std::cin >> c;  
}

void memoryReferencePointer(){
    double d = 3.14;
    double & rdist = d;
    std::cout << d << ", " << (rdist * 2.3) << std::endl;
    d = 1.2;
    std::cout << d << ", " << (rdist * 2.3) << std::endl;
    rdist = 5.0;
    std::cout << d << ", " << (rdist * 2.3) << std::endl; 
    double * pdist = nullptr;
    pdist = &d;
    std::cout << pdist << ", " << *pdist << std::endl;   
    *pdist = 12.3;
    std::cout << pdist << ", " << *pdist << std::endl;  
    pdist = new double(3);  // allocation dynamique dans le HEAP
    std::cout << pdist << ", " << *pdist << std::endl;  
    delete pdist; // desallouer la zone memoire
    // std::cout << pdist << ", " << *pdist << std::endl;  
    pdist = nullptr; // securité de code
    std::cout << pdist << ", " << *pdist << std::endl; 
}

int main() {
    // char c;
    // demoMemoire();
    // std::cin >> c; 

    double data[100]; // type double[]
    std::cout << "All data:" << std::endl;
    display(std::begin(data), std::end(data));
    data[0] = 3.14;
    data[1] = 23.4;
    std::cout << "First 2 items:" << std::endl;
    display(std::begin(data), std::begin(data)+2); 
    std::cout << "Sum of first 2 items: " << (data[0] + data[1]) << std::endl;

    // table de double alloue dynamiquement (HEAP)
    double * bigdata = new double[500000000]; 
    bigdata[0] = 3.14;
    bigdata[1] = 23.4;
    std::cout << "First 10 items:" << std::endl;
    display(bigdata, bigdata+10); 
    delete[] bigdata;

    // return 0;
    return EXIT_SUCCESS;
}
