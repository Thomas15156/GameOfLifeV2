#include "V_Display.h"
#include "V_Console.h"
#include "V_Graphics.h"
#include <stdexcept>

std::unique_ptr<Display> choose_display_mode(const std::string& display_mode, Grid& display_grid, File& file, int update_interval) {
    if (display_mode == "console") {
        return std::make_unique<Console>(display_grid, file);
    } else if (display_mode == "graphics") {
        return std::make_unique<Graphics>(display_grid, update_interval); // Passer l'intervalle de mise à jour
    } else {
        throw std::invalid_argument("Invalid display mode");
    }
}