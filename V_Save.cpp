//
// Created by benjamin Bourlet on 05/12/2024.
//

#include "V_Save.h"
#include <fstream>
#include <iostream>

Save::Save(Grid& dispplay_grid) : grid(dispplay_grid) {}

void Save::save_to_file(const std::string filename, int cycle) {
  std::string out_filname = filename + "_out.txt";
  std::ofstream file(out_filname, std::ios::out);
  if (!file.is_open()){
    file << "cycle: " << cycle << "\n";
    for (const auto& row : grid.get_grid()){
      for (const auto& col : row){
        file << col << " ";
      }
      file << "\n";
    }
    file.close();
  }else{std::cerr << "Can't open file " << out_filname << std::endl;}

}

void Save::run_display() {}
