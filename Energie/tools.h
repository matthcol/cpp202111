#ifndef _TOOLS_
#define _TOOLS_

#include <string>

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

template <class C>
void displayContainer(const C & container) {
    display(container.cbegin(), container.cend());
}


#endif // !_TOOLS_