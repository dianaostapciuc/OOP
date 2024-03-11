#ifndef A45_XDIANAOST_UI_H
#define A45_XDIANAOST_UI_H

#endif //A45_XDIANAOST_UI_H
#include "services.h"

class ui
{
private:
    services service;
public:
    ui(services service);
    bool validate_input_command(string input);
    void menu();
};