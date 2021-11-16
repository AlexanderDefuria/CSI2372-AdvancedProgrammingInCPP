//
// Alexander De Furia
// 300190815
// 2021-10-04.
//

#ifndef ASSIGNMENT1_HIGHSCOREMANAGER_H
#define ASSIGNMENT1_HIGHSCOREMANAGER_H

#define LIST_SIZE 10

#include <string>

void add(std::string name, int score=0);
void print();
void print(int index);
void search(std::string name);
void search(std::string name, int* playerIndex);
void remove(std::string name);
void menu();

#endif //ASSIGNMENT1_HIGHSCOREMANAGER_H
