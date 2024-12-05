#ifndef V_INTERFACE_H
#define V_INTERFACE_H

#include <string>

class Interface {
public:
    Interface();
    std::string get_display_mode() const;
    std::string ChooseMode();
    bool ChooseToroidal();
    int ChooseUpdateInterval(); // Nouvelle méthode pour choisir l'intervalle de mise à jour

private:
    std::string display_mode;
    bool is_toroidal;
    int update_interval; // Ajouter un membre pour stocker l'intervalle de mise à jour
};

#endif