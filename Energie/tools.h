#ifndef _TOOLS_
#define _TOOLS_

#include <string>

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


#endif // !_TOOLS_