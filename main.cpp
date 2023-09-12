#include <iostream>
#include "main.hpp"
#include <vector>
#include <array>

using namespace std;

int main()
{
    while(check_game()) {
        display();
        played();
        check_game();
    }

    if(letter == 'O' && draw == false)
    {
        cout << "Le joueur 1 a gagné !" << endl;
    }
    else if(letter == 'X' && draw == false)
    {
        cout << "Le joueur 2 a gagné !" << endl;
    }
    else
    {
        cout << "Fin du jeu !" << endl;
    }

    return 0;
}