#ifndef V_INTERFACE_H
#define V_INTERFACE_H

#include <string>

class Interface {
public:
    Interface();
    std::string ChooseMode();
    float ChooseUpdateInterval();
    bool ChooseToroidal();
    std::string get_display_mode() const;
    int get_update_interval() const;

private:
    std::string display_mode;
    bool is_toroidal;
    int update_interval;
};

#endif // V_INTERFACE_H