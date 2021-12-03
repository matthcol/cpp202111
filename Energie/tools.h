#ifndef _TOOLS_
#define _TOOLS_

#include <string>
#include <fstream>

/**
 * @brief afficher sur std::cout les elements parcourus
 * 
 * @tparam InputIterator 
 * @param first 
 * @param last 
 * @param sep 
 */
template <class InputIterator>
void display(InputIterator first, InputIterator last, const std::string & sep = ", "){
    std::cout << "[";
    if (first != last) {
        std::cout << *first;
        ++first;
        // pour les elements suivants le 1er
        for ( ; first != last; ++first) {
            auto d = *first;
            std::cout << sep << d; 
        }
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Affichesur std::cout les elements du container
 * 
 * @tparam C 
 * @param container 
 */
template <class C>
void displayContainer(const C & container) {
    display(container.cbegin(), container.cend());
}

// void lireLignesCSV(const std::string & filename, std::vector<Ligne> & lignes);
template <class OutputIterator>
bool lireLignesCSV(const std::string & filename, OutputIterator result) {
    // ouvrir fin en lecture sur le fichier filename
    std::fstream fin(filename, std::fstream::in);
    if (!(fin.is_open())) {
        return false;
    }

    // lecture ligne par ligne dans un buffer
    char buffer[255];

    // lecture jusqu'à atteindre EOF
    while (fin.getline(buffer, 255)) {
        // construire un string a partir du buffer
        std::string ligne(buffer);
        auto pos = ligne.find(';');
        if (pos == std::string::npos) {
            return false;
        }
        std::string nom = ligne.substr(0, pos);
        auto pos2 = ligne.find(';', pos+1);
        if (pos2 == std::string::npos) {
            return false;
        }
        std::string str_capaciteMax = ligne.substr(pos+1, pos2 - pos - 1);
        std::string str_capaciteReelle = ligne.substr(pos2+1);

        // std::cout << "#" << ligne << "# -> " 
        //     << nom 
        //     << ", " << str_capaciteMax 
        //     << ", " << str_capaciteReelle 
        //     << std::endl;
        Ligne ligneEnergie(nom, std::stoi(str_capaciteMax), std::stoi(str_capaciteReelle));
        // ecrire la ligne avec l'iterateur en sortie
        *result = ligneEnergie;
        ++result;
    }
    // fermer le fichier
    fin.close();
    return true;
}

template <class OutputIterator>
bool lireLignesCSVre(const std::string & filename, OutputIterator result) {
    // ouvrir fin en lecture sur le fichier filename
    std::fstream fin(filename, std::fstream::in);
    if (!(fin.is_open())) {
        return false;
    }

    // lecture ligne par ligne dans un buffer
    char buffer[255];

    // lecture jusqu'à atteindre EOF
    while (fin.getline(buffer, 255)) {
        // construire un string a partir du buffer
        std::string ligne(buffer);
        
        
        Ligne ligneEnergie(nom, std::stoi(str_capaciteMax), std::stoi(str_capaciteReelle));
        // ecrire la ligne avec l'iterateur en sortie
        *result = ligneEnergie;
        ++result;
    }
    // fermer le fichier
    fin.close();
    return true;
}



template <class InputIterator>
bool ecrireLignesCSV(const std::string & filename, InputIterator first, InputIterator last){
    std::fstream fout(filename, std::fstream::out | std::fstream::trunc);
    // std::fstream fout(filename, std::fstream::out | std::fstream::app);
    if (!(fout.is_open())) {
        return false;
    } 

    // for ( ; first != last; ++first) {
    //     fout << *first << std::endl;
    // }
    std::for_each(first, last,
        [&fout](const auto & ligneEnergie){ 
                fout << ligneEnergie.nom()
                    << ";" << ligneEnergie.capaciteMax() 
                    << ";" << ligneEnergie.capaciteReelle() << std::endl;
            }
    );

    fout.close();
    return true;
}

#endif // !_TOOLS_