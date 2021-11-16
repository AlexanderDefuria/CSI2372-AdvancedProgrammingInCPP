//
// Alexander De Furia
// 300190815
// 2021-10-04.
//

#include <iostream>
#include <utility>
#include "highscoremanager.h"

std::string* playerNames = new std::string [LIST_SIZE];
int playerScores[LIST_SIZE];


void add(std::string name, int score) {
    for (int i = 0; i < LIST_SIZE; i++) {
        if (playerNames[i].empty()) {
            playerNames[i] = name;
            playerScores[i] = score;
            return;
        }
    }
}

void print() {
    std::cout <<std::endl<<std::endl<< "Scoreboard" <<std::endl<<"--------------------------"<<std::endl;
    for (int i = 0; i < LIST_SIZE; i++) {
        if (playerNames[i].empty())
            continue;
        print(i);
    }
}

void print(int index) {
    std::cout << playerNames[index] << ", " << playerScores[index] << std::endl;
}


void search(std::string name) {
    int index = -1;
    search(name , &index);
    if (index != -1)
        print(index);
}

void search(std::string name, int *playerIndex) {
    for (int i = 0; i < LIST_SIZE; i++) {
        if (name == playerNames[i]) {
            *playerIndex = i;
            return;
        }
    }
    std::cout << "Player not found." << std::endl;
}

void remove(std::string name) {
    int index = -1;
    search(name, &index);

    if (index >= 0 && index <= LIST_SIZE) {
        playerNames[index] = "";
        playerScores[index] = 0;
    }


}

void menu() {
    char option;
    std::cout <<std::endl <<std::endl << "Highscore Manager" <<std::endl<< "--------------------------" <<std::endl << "1. Add New Player"
    <<std::endl<<"2. Print Scoreboard" <<std::endl<< "3. Search Player" <<std::endl<< "4. Remove Player" <<std::endl <<
    "Q. Exit Program"  <<std::endl;
    
    std::cin >> option;

    switch (option) {
        case '1': {
            std::string name;
            int score;
            std::cout << "Enter a name: ";
            std::cin >> name;
            std::cout << "Enter a score: ";
            std::cin >> score;
            add(name, score);
            menu();
            break;
        }
        case '2':
            print();
            menu();
            break;
        case '3': {
            std::string name;
            std::cout << "Enter a name: ";
            std::cin >> name;
            std::cout << std::endl;
            search(name);
            menu();
            break;
        }
        case '4': {
            std::string name;
            std::cout << "Enter a name: ";
            std::cin >> name;
            remove(name);
            menu();
            break;
        }
        case 'Q':
            return;

        default:
            menu();
            return;

    }


}


