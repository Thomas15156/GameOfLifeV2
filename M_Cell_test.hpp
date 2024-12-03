//
// Created by benjamin Bourlet on 03/12/2024.
//

#ifndef M_CELL_TEST_H
#define M_CELL_TEST_H
#include <iostream>
#include <ostream>

#include "M_Cell.h"

#endif //M_CELL_TEST_H



void test_init_state()
{
    Cell cell;
    if (cell.get_state() == 0){std::cout << "initialisation cellule ok" << std::endl;}
    else {std::cout << "erreur d'initialisation de la cellule" << std::endl;}
}

void test_set_state()
{
    Cell cell;
    cell.set_state(1);
    if (cell.get_state() == 1) {std::cout << "methode de modification ok" << std::endl;}
    else {std::cout << "erreur methode modification" << std::endl;}
}

void test_next_state()
{
    Cell cell(1);
    if (cell.next_state(2) == 1 && cell.next_state(3) == 1
        && cell.next_state(1) == 0 && cell.next_state(4) == 0)
        {std::cout << "Reglès de survie des cellules ok" << std::endl;}
    else {std::cout << "erreur Reglès de survie des cellules" << std::endl;}

    Cell dead_cell(0);
    if (dead_cell.next_state(2) == 0 && dead_cell.next_state(3) == 1)
        {std::cout << "Reglès de mort des cellules ok" << std::endl;}
    else {std::cout << "erreur Reglès de mort des cellules" << std::endl;}
}

void run_cell_test()
{
    std::cout << "\nTesting Cell class : " << std::endl;
    test_init_state();
    test_set_state();
    test_next_state();
}
