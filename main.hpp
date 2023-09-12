#include <iostream>
#include <math.h>

using namespace std;

int choice;
char letter = 'X';
int row;
int column;
bool draw = false;
char chaine[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void display()
{
    system("clear");

    cout << "Joueur 1 [X]\t Joueur 2 [O]" << endl;
    cout << " " << chaine[0][0] << " | " << chaine[0][1] <<" | "<< chaine[0][2] <<"" << endl;
    cout << "---|---|---" << endl;
    cout << " "<< chaine[1][0] <<" | "<< chaine[1][1] <<" | "<< chaine[1][2] <<"" << endl;
    cout << "---|---|---" << endl;
    cout << " "<< chaine[2][0] <<" | "<< chaine[2][1] <<" | "<< chaine[2][2] <<"" << endl;
}

void played()
{
    if(letter == 'X')
    {
        cout << "Joueur 1 [X] à vous de joué" << endl;
    }
    if(letter == 'O')
    {
        cout << "Joueur 2 [O] à vous de joué" << endl;
    }

    cin >> choice;

    switch (choice)
    {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            break;
    }

    if(choice > 0 && choice < 10)
    {
        if(letter == 'X' && chaine[row][column] != 'X' && chaine[row][column] != 'O')
        {
            chaine[row][column] = 'X';
            letter = 'O';
        }
        else if(letter == 'O' && chaine[row][column] != 'X' && chaine[row][column] != 'O')
        {
            chaine[row][column] = 'O';
            letter = 'X';
        }
        else 
        {
            cout << "Cette case est pleine ! \n Choisissez une autre !" << endl;
            played();
        }

        display();
    }
    else
    {
        cout << "Mouvement invalid" << endl;
        played();
    }
}

bool check_game()
{
    for(int i = 0; i < 3; i++)
    {
        if(chaine[i][0] == chaine[i][1] && chaine[i][0] == chaine[i][2] || chaine[0][i] == chaine[1][i] && chaine[0][i] == chaine[2][i])
            return false;
    }

    if(chaine[0][0] == chaine[1][1] && chaine[0][0] == chaine[2][2] || chaine[0][2] == chaine[1][1] && chaine[0][2] == chaine[2][0])
        return false;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(chaine[i][j] != 'X' && chaine[i][j] != 'Y')
                return true;
        }
    }

    draw = true;
    return false;
}