// pour executer l'application, windows doit connaitre le repertoire qui contient la dll
set PATH=%PATH%;C:\C:\<chemin vers les fichiers dll|so>\EnergieLibDynamique

// pour builder l'application
// en 1 etape
g++ .\main.cpp -o main.exe -I"C:\<chemin vers les fichiers header>\EnergieLibDynamique" -L"C:\<chemin vers les fichiers dll|so>\EnergieLibDynamique" -lligne 

// en compilation separee : chaque .cpp => .o ou .obj en indiquant où sont les headers des dll
// et edition des liens : rassembler les .o => .exe en indiquant les dll utilisees
g++ -c .\main.cpp -o main.o -I"C:\<chemin vers les fichiers header>\EnergieLibDynamique" 
g++ .\main.o -o main.exe -L"C:\<chemin vers les fichiers dll|so>\EnergieLibDynamique" -lligne 
