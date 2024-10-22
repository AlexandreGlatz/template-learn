// Template_learn.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <chrono>

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include "Item.h"
#include "Inventory.h"

void capacityTest()
{
    srand(time(NULL));

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;



    /* Getting number of milliseconds as an integer. */

    std::vector<int> vect;
    std::set<int> set;
    std::list<int> list;

    auto vectorCreateTimer1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
        vect.push_back(i);
    auto vectorCreateTimer2 = high_resolution_clock::now();

    auto setCreateTimer1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
        set.insert(i);
    auto setCreateTimer2 = high_resolution_clock::now();

    auto listCreateTimer1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
        list.push_back(i);
    auto listCreateTimer2 = high_resolution_clock::now();

    auto vectorMs_int = duration_cast<milliseconds>(vectorCreateTimer2 - vectorCreateTimer1);
    auto setMs_int = duration_cast<milliseconds>(setCreateTimer2 - setCreateTimer1);
    auto listMs_int = duration_cast<milliseconds>(listCreateTimer2 - listCreateTimer1);

    std::cout << "Time to fill vector :" << vectorMs_int << std::endl;
    std::cout << "Time to fill set :" << setMs_int << std::endl;
    std::cout << "Time to fill list :" << listMs_int << std::endl;

    std::cout << std::endl;

    auto vectorDeleteTimer1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
        vect.pop_back();
    auto vectorDeleteTimer2 = high_resolution_clock::now();

    auto setDeleteTimer1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
        set.erase(i);
    auto setDeleteTimer2 = high_resolution_clock::now();

    auto listDeleteTimer1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
        list.pop_back();
    auto listDeleteTimer2 = high_resolution_clock::now();

    auto delvectorMs_int = duration_cast<milliseconds>(vectorDeleteTimer2 - vectorDeleteTimer1);
    auto delsetMs_int = duration_cast<milliseconds>(setDeleteTimer2 - setDeleteTimer1);
    auto dellistMs_int = duration_cast<milliseconds>(listDeleteTimer2 - listDeleteTimer1);

    std::cout << "Time to delete vector :" << delvectorMs_int << std::endl;
    std::cout << "Time to delete set :" << delsetMs_int << std::endl;
    std::cout << "Time to delete list :" << dellistMs_int << std::endl;
}
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

void inventoryTest()
{
    Item* sword = new Item("Sword", 5);
    Item* shield = new Item("Shield", 12);
    Item* potion = new Item("Potion", 2);
    Item* helmet = new Item("Helmet", 6);
    Item* chestplate = new Item("ChestPlate", 15);
    std::vector<Item*> vect{ sword };
    Inventory* inventory = new Inventory(vect, 100);
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

    inventory->Filter([](Item* item) { return item->GetDetails()->weight > 10; });
    inventory->Print();
}

template<typename T>
int min(std::vector<T> vector, int size)
{
    T minValue = vector[0];
    for (int i = 1; i < size; i++)
    {
        if (vector[i] < minValue )
            minValue = vector[i];
    }

    return minValue;
}

template<typename T>
int AddElem(std::vector<T>& vector, T element)
{
    vector.push_back(element);
    std::cout << "Element added to vector, vector size is now " << vector.size() std::endl;
}

template<typename T>
int sum(std::list<T>)
{
    for (const int& elem : list)
        std::cout << elem;
}

int main()
{
    srand(time(NULL));
    std::vector<int> vecInt;
    std::vector<float> vecFloat;

    for (int i = 0; i < 10; i++)
    {
        vecInt.push_back(rand() % 500);
        vecFloat.push_back(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 500)));
    }

    for (const int& elem : vecInt)
        std::cout << elem << ", ";

    std::cout << std::endl;
    for (const int& elem : vecFloat)
        std::cout << elem << ", ";

    std::cout << std::endl;
    std::cout << "min int = " << min(vecInt, vecInt.size()) <<std::endl;
    std::cout << "min float = " << min(vecFloat, vecFloat.size()) <<std::endl;
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
