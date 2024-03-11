#ifndef DIA_UI_H
#define DIA_UI_H


#pragma once
#include "services.h"

typedef struct
{
    services service;
}UI;

UI create_UI();

void destroy_ui(services* service);

void menu(services* service);

#endif //DIA_UI_H