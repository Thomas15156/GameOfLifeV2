#ifndef V_INTERFACE_H
#define V_INTERFACE_H

#include <string>


class Interface {
public:
    Interface();
    int ChooseFile();
    std::string get_display_mode();
    std::string ChooseMode();
    std::string display_mode;
};

#endif