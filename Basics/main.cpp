#include <iostream>
#include <string>
#include <limits>

// using namespace std;

void introduction() {
     // instructions
    std::cout <<  "Coucou tout le monde :)" 
            << std::endl
            << "1 texte : " << "C'est lundi, demarrage un peu difficile !" 
            << std::endl
            << "1 caractere : " << 'Z'
            << std::endl
            << "1 entier : " << 4
            << std::endl
            << "1 nombre decimal : " << 4.3
            << std::endl
            << std::boolalpha
            << "1 booleen : " << true
            << std::endl
            << "1 test boleen : " << (4 > 10)
            << std::endl;

    // cout <<  "Coucou tout le monde :)" 
    //     << endl
    //     << "C'est lundi, demarrage un peu difficile !" 
    //     << endl; 
    double temperature = 15.5; // variable de type double initialisee avec la valeur 15,5
    std::cout << "Temperature : " << temperature << std::endl;
    temperature = 4.5; 
    std::cout << "Temperature : " << temperature << std::endl;
    // temperature = "il fait froid";  // erreur de typage   
    temperature = -1;
    std::cout << "Temperature : " << temperature << std::endl;
    temperature = 1.2E308;
    std::cout << "Temperature : " << temperature << std::endl;
    temperature = temperature *2;
    std::cout << "Temperature : " << temperature << std::endl;
    double res = temperature / temperature;
    std::cout << "Division inf/inf : " << res << std::endl;
    temperature = 1.2E-308;
    std::cout << "Temperature : " << temperature << std::endl;
    double prix = 0.1;
    std::cout.precision(18);
    std::cout << prix << " ; " << (2*prix) << " ; " << (3*prix)  << std::endl;
}

void entiers() {
        // entiers
    char n1 = 65;
    short n2 = 15000;
    int n3 = 2000000000;
    long n4 = 4000000000L;
    long long n5 = 1000000000000000000LL;

    std::cout 
        << "Char : " << n1 << " : " << sizeof(n1) << std::endl
        << "Short : " << n2 << " : " << sizeof(n2) << std::endl
        << "Int : " << n3 << " : " << sizeof(n3) << std::endl
        << "Long : " << n4 << " : " << sizeof(n4) << std::endl
        << "Long long : " << n5 << " : " << sizeof(n5) << std::endl; 

    std::cout << "Type (signed) int, "
        << "min : " << std::numeric_limits<int>::min() 
        << ", max : " << std::numeric_limits<int>::max() 
        << std::endl;
    std::cout << "Type unsigned int, "
        << "min : " << std::numeric_limits<unsigned int>::min() 
        << ", max : " << std::numeric_limits<unsigned int>::max() 
        << std::endl;
    int32_t n = -2000000000;
    std::cout << n << std::endl;
    uint32_t un = 4000000000;
    std::cout << un << std::endl;
}

void operateurs() {
        // operateurs mathetiques : +  -  *  /  %
    int nb = 3;
    int delta = 5;
    nb = (nb + delta) * 7;
    std::cout << nb << std::endl;
    // operateurs contractés : +=  -=  *=  /=  %=  ++  --
    nb += 2; // i.e : nb = nb +2
    std::cout << nb << std::endl;
    nb++;
    std::cout << nb << std::endl;
    nb--;
    std::cout << nb << std::endl;
    ++nb;
    std::cout << nb << std::endl;
    std::cout << ((nb++) * 2) << std::endl; // 59*2 ; nb <- 60
    std::cout << ((++nb) * 2) << std::endl; // nb <- 61 ; 61*2

    std::cout << (nb / 2) << std::endl; // quotient de la division entiere
    std::cout << (nb % 2) << std::endl; // reste de la division entiere
    std::cout << (nb / 2.0) << std::endl; // division des doubles
    
    // operateurs comparaisons avant C++20 : <  >  <=  >=  ==  != 
    std::cout <<  std::boolalpha
        << (nb < 100)
        << " , " << (nb == 61)
        << " , " << (nb == 62)
        << " , " << (nb != 61) 
        << std::endl;

    // operateur comparaison C++20 : <=>    (spaceship, threeway comparison)
    // std::cout <<  std::boolalpha
    //     << (nb <=> 100)
    //     << std::endl;

    std::cout << ((nb < 100) && (nb > 20)) << std::endl;  // T and T => T
    std::cout << ((nb < 100) && (nb > 80)) << std::endl;  // T and F => F
    std::cout << ((nb < 100) || (nb > 80)) << std::endl;  // T or F => T
    std::cout << !((nb < 100) || (nb > 80)) << std::endl; // not T => F
}

void conditionnelles() {
    double temperature = 4.5;
    // double temperature = 14.5;

    // conditionnelle à 1 branche (option)
    if (temperature < 10.0) {
        std::cout << "Il fait froid n'est ce pas ?" << std::endl;
        std::cout << "Je vais mettre un bonnet" << std::endl;
    }
    
    int distance = 10;
    if (distance == 8) {
        std::cout << "8 km à pieds" << std::endl;
    } else {
        std::cout << "des kms à pieds : " << distance <<  std::endl;
    }


    if (distance == 8) {
        std::cout << "8 km à pieds" << std::endl;
    } else if (distance > 8) {
        std::cout << "trop de kms à pieds : " << distance <<  std::endl;
    } else {
        std::cout << "petite distance à pieds : " << distance <<  std::endl;
    }


    switch (distance) {
        case 0:
            std::cout << "distance 0" << std::endl;
            break;
        case 1:
        case 2:
            std::cout << "distance 1 ou 2" << std::endl;
            break;
        case 10:
            std::cout << "distance 10" << std::endl;
            break;
        default: // optionnel
            std::cout << "distance lambda" << std::endl;
    }

    double distanceCorrigee = (distance < 10) ? distance : distance * 1.01;
    std::cout << "Distance corrigee : " << distanceCorrigee << std::endl;

}

void euclide() {
     // boucles : algo euclide = pgcd
    int a = 24;
    int b = 18;
    int r; // non initialisee (contenur random)
    do {
        r = a % b;
        a = b;
        b = r;
    } while (r != 0);
    std::cout << "Pgcd est : " << a << std::endl;
}

void boucleWhile() {
      int cpt = -10;
    while (cpt > 0) {
        std::cout << cpt << std::endl;
        cpt--;
    }
    std::cout << "Sortie de boucle, cpt = " << cpt << std::endl;
}

void bouclFor() {
     // boucle for (old school)
    for (int cpt=10 ; cpt>0 ; cpt--) {
        std::cout << cpt << std::endl;
    }
    // cpt non accessible

    int nb=0;
    for (; nb<10 ;) {
        std::cout << nb++ << std::endl;
    }

    std::string phrase = "On se les gele";
    std::cout << "Longueur texte : " 
        << phrase.size() 
        << " , " << phrase.size() 
        << std::endl;
    std::cout << "Car pos #3 : " << phrase[3] << std::endl;
    
    for (int i=0; i < phrase.size() ; i++) {
        std::cout << "Car #" << i << " = " << phrase[i] << std::endl; 
    }

    // foreach : C++
    // for (char lettre : phrase) {
    for (auto lettre : phrase) {
        std::cout << "Car = " << lettre << std::endl; 
    }
}

int main () {
    bool isOk = true;
    double temperature = 12.444444444;
    int distance = 65;

    std::cout 
        << isOk << std::endl
        << std::boolalpha  << isOk << std::endl
        << std::noboolalpha  << isOk << std::endl;

    std::cout.precision(3);
    std::cout 
        << temperature << ", " << 3.14E12 << std::endl
        << std::fixed  << temperature << ", " << 3.14E12 << std::endl
        << std::scientific  << temperature << ", " << 3.14E12 << std::endl;


}











