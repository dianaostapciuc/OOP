#ifndef A45_XDIANAOST_UI_H
#define A45_XDIANAOST_UI_H

#endif //A45_XDIANAOST_UI_H
#include "services.h"
#include "exceptions.h"
#include "validators.h"

class ui
{
private:
    services service;
    string listing_mode;
public:
    ui(services service, string list_mode);
    static bool validate_input_command(string input);
    void menu();
};
string read_listing_mode();