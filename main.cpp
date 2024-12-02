#include "V_Interface.h"

#include <iostream>

int main() {
    Interface interface;

    // Si le fichier est ouvert avec succès, on lance ChooseMode
    if (interface.ChooseFile()) {
        interface.ChooseMode();
    } else {
        std::cout << "Failed to open file. Exiting..." << std::endl;
    }

    return 0;
}
