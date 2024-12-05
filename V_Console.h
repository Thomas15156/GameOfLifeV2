#ifndef V_CONSOLE_H
#define V_CONSOLE_H
#include "V_Display.h"
#include "File.h"

class Console : public Display {
protected:
    Grid& display_grid;
    File& file; // Référence à la classe File pour sauvegarder les générations
    int generation; // Compteur de génération

public:
    Console(Grid& display_grid, File& file);
    void run_display() override;
    void run() override; // Redéfinition de la méthode run
};

#endif //V_CONSOLE_H