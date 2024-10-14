// wordle.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
//Amour Plage Livre Fille Chien Étoile Sable Tasse Porte Souris
int generateword()
{
	const char Mot[] = "Amour", "Plage", "Livre", "Flle", "Chien", "Étoile", "Sable", "Tasse", "Porte", "Souris";
	int num = rand() % 9;
	return Mot[num];
}

int main()
{
	srand(time(0));
	int Mot = generateword();
	return 0;
}

