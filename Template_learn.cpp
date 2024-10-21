// Template_learn.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include "Item.h"
#include "Inventory.h"
void vectorTest(std::vector<int>& vect)
{
    vect.push_back(1);
    std::sort(vect.begin(), vect.end());

    for (const int& elem : vect)
        std::cout << elem;

    std::cout<< std::endl;

}

void setTest(std::set<int> set)
{
    set.insert(1);
    if (set.contains(2) == false)
        return;
    set.erase(2);
    
    for (std::set<int>::iterator i = set.begin(); i != set.end(); i++)
    {
        std::cout << *i;
    }
    std::cout<< std::endl;
}

void listTest(std::list<int> list)
{
    list.push_back(1);
    list.erase(std::find(list.begin(), list.end(), 1));

    list.sort();
    for (const int& elem : list)
        std::cout << elem;
    std::cout << std::endl;
}

int main()
{
    Item* sword = new Item("Sword", 5);
    Item* shield = new Item("Shield", 12);
    Item* potion = new Item("Potion", 2);
    Item* helmet = new Item("Helmet", 6);
    Item* chestplate = new Item("ChestPlate", 15);
    std::vector<Item*> vect{ sword };
    Inventory* inventory = new Inventory(vect);
    inventory->Print();

    inventory->AddItem(potion);
    inventory->AddItem(helmet);
    inventory->AddItem(chestplate);
    inventory->Print();

    inventory->SortByName();
    inventory->Print();

    inventory->SortByWeight(ASCENDING);
    inventory->Print(); 
    
    inventory->SortByWeight(DESCENDING);
    inventory->Print();

    inventory->DeleteItem("butter");
    inventory->DeleteItem("Sword");
    inventory->Print();

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
