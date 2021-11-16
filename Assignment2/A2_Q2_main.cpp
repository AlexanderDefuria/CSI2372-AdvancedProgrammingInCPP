//
// Created by defur on 2021-10-20.
//
#include <iostream>


struct Player {
    std::string* name;
    int score;
    Player() =default;
    Player(std::string _name, int _score) {
        name = new std::string(_name);
        score = _score;
    }


};

void add(Player* players[], int* size) {
    if (*size == 10)
        return;

    *size += 1;
    Player* temp = new Player[*size];
    for (int i = 0; i < *size - 1; i++)
        temp[i] = *players[i];

    delete[] *players;
    *players = new Player[*size];
    for (int i = 0; i < *size - 1; i++)
        *players[i] = temp[i];

    std::string _name;
    int _score;
    std::cout <<  "Enter a name: ";
    std::cin >> _name;
    std::cout <<  "Enter a score: ";
    std::cin >> _score;
    std::cout << std::endl;

    players[*size - 1] = new Player(_name, _score);
    delete[] temp;
}

void print(Player* players[], const int* size) {
    std::cout <<std::endl<<std::endl<< "Scoreboard" <<std::endl<<"--------------------------"<<std::endl;
    for (int i = 0; i < *size; i++) {
        std::cout << *(players[i]->name) << ", " << players[i]->score << std::endl;
    }
}

void search(Player* players[], const int* size, std::string name) {
    if (*size>0)
        for (int i = 0; i < *size; i++) {
            if (*(players[i]->name) == name) {
                std::cout << *(players[i]->name) << " has a score of " << players[i]->score << std::endl;
                return;
            }

        }
    std::cout << "Player not found." << std::endl;
}

void remove(Player* players[], int* size, const std::string& name) {
    if (*size==0)
        return;
    Player* temp = new Player[*size-1];
    bool removed = false;
    for (int i = 0; i < *size; i++) {
        //std::cout << (*(players[i]->name) != name);
        if (*(players[i]->name) != name ){
            if (removed)
                temp[i-1] = *players[i];
            else
                temp[i] = *players[i];
        } else
            removed=true;
    }
    *players = new Player[*size-1];
    for (int i = 0; i < *size - 1; i++) {
        *players[i] = temp[i];
    }

    *size -= 1;
}

int main() {
    int* size = new int(0);
    Player** players = new Player*();
    //add(players, size);
    //add(players, size);
    //add(players, size);
    //print(players, size);
    //search(players, size, "david");
    //remove(players, size, "david");
    //print(players, size);
    //return 0;

    char option;
    while (true) {

        std::cout <<std::endl <<std::endl << "Highscore Manager" <<std::endl<< "--------------------------" <<std::endl << "1. Add New Player"
                  <<std::endl<<"2. Print Scoreboard" <<std::endl<< "3. Search Player" <<std::endl<< "4. Remove Player" <<std::endl <<
                  "Q. Exit Program"  <<std::endl;

        std::cin >> option;

        switch (option) {
            case '1': {
                add(players, size);
                break;
            }
            case '2':
                print(players, size);
                break;
            case '3': {
                std::string name;
                std::cout << "Enter a name: ";
                std::cin >> name;
                std::cout << std::endl;
                search(players, size,name);
                break;
            }
            case '4': {
                std::string name;
                std::cout << "Enter a name: ";
                std::cin >> name;
                remove(players, size, name);
                break;
            }
            case 'Q':
            default:
                delete players;
                delete size;
                return 0;

        }
    }



}





