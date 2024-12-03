//
// Created by benjamin Bourlet on 03/12/2024.
//
#ifndef M_GRID_TEST_HPP
#define M_GRID_TEST_HPP

#include <iostream>
#include "M_Grid.h"

void test_get_temp_grid(auto& get_temp_grid)
{
 Grid grid(get_temp_grid);
 const auto& grid_test = grid.get_grid();
 bool verif = true;
 for (int i = 0; i < get_temp_grid.size(); ++i)
 {
  for (int j = 0; j < get_temp_grid[i].size(); ++j)
  {
   if (grid_test[i][j] != get_temp_grid[i][j])
   {
    verif = false;
    break;
   }
  }
 }
 if (verif) {std::cout << "initialisation de la grille ok" << std::endl;}
 else {std::cout << "Erreur d'initialisation de la grille" << std::endl;}
}

void test_next_grid()
{
 std::vector<std::vector<int>> test_init_grid =
  {
  {0, 0, 0},
  {1, 0, 1},
  {0, 0, 0}
  };
 Grid test_grid(test_init_grid);
 test_grid.next_generation();
 const auto& grid_test = test_grid.get_grid();
 std::vector<std::vector<int>> test_next_grid = {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
 };
 bool verif = true;
 for (int i = 0; i < test_next_grid.size(); ++i){
  for (int j = 0; j < test_next_grid[i].size(); ++j){
   if (grid_test[i][j] != test_next_grid[i][j])
    {verif = false; break;}
  }
 }
 if (verif) {std::cout << "vérification de la géneration suivante ok" << std::endl;}
 else {std::cout<<"Erreur de vérification de la géneration suivante" << std::endl;}
}

void test_stable_grid()
{
 std::vector<std::vector<int>> test_stable_grid = {
  {0, 1, 0},
  {1, 0, 1},
  {0, 1, 0}
 };
 Grid test_grid(test_stable_grid);
 test_grid.next_generation();
 if (test_grid.is_stable()) {std::cout<<"méthode de stabilisation ok"<<std::endl;}
 else {std::cout<<"Erreur sur la méthode de stabilisation"<<std::endl;}
}


void test_live_neighbors()
{
 std::vector<std::vector<int>> test_live_neighbors = {
  {0, 1, 0},
  {1, 0, 1},
  {0, 1, 0}
 };
 Grid test_grid(test_live_neighbors);

 //test au centre
 int test_neighbors_center = test_grid.count_live_neighbors(1,1);
 if (test_neighbors_center == 4) {std::cout<<"test_count_live_neighbors (center) ok."<<std::endl;}
 else {std::cout<<"test_count_live_neighbors (center) failed. Expected 4, got " << test_neighbors_center << std::endl;}
 //test au coin
 int test_neighbors_corner = test_grid.count_live_neighbors(0,0);
 if (test_neighbors_corner == 2) {std::cout<<"test_count_live_neighbors (corner) ok."<<std::endl;}
 else {std::cout<<"test_count_live_neighbors (corner) failed. Expected 2, got " << test_neighbors_corner << std::endl;}
 //test au bord
 int test_neighbors_edge = test_grid.count_live_neighbors(-1,0);
 if (test_neighbors_edge == 1) {std::cout<<"test_count_live_neighbors (edge) ok."<<std::endl;}
 else {std::cout<<"test_count_live_neighbors (edge) failed. Expected 1, got " << test_neighbors_edge << std::endl;}
 // nombreux de voisins théorique:
 /*
  *2 1 2
  *1 4 1
  *2 1 2
  *
  */



};


void run_grid_test(auto& get_temp_grid)
{
 std::cout << "\nTesting Grid class : " << std::endl;
 test_get_temp_grid(get_temp_grid);
 test_next_grid();
 test_stable_grid();
 test_live_neighbors();
}
#endif // M_GRID_TEST_HPP
