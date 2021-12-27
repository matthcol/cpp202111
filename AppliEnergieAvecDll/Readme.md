# Compiler une application utilisant une librairie dynamique (Windows)

## Pour executer l'application, windows doit connaitre le repertoire qui contient la dll
set PATH=%PATH%;C:\C:\<chemin vers les fichiers dll|so>\EnergieLibDynamique

## Pour builder l'application avec libligne.dll (1 étape)
g++ main.cpp -o main.exe -I"C:\<chemin vers les fichiers header>\EnergieLibDynamique" -L"C:\<chemin vers les fichiers dll|so>\EnergieLibDynamique" -lligne 

## Pour builder l'application avec libligne.dll (compilation séparée et édition des liens)
### chaque .cpp => .o ou .obj en indiquant où sont les headers des dll
g++ -c main.cpp -o main.o -I"C:\<chemin vers les fichiers header>\EnergieLibDynamique" 
### édition des liens : rassembler les .o => .exe en indiquant les dll utilisees
g++ main.o -o main.exe -L"C:\<chemin vers les fichiers dll|so>\EnergieLibDynamique" -lligne 
