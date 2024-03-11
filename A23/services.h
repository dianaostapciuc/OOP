#ifndef DIA_SERVICES_H
#define DIA_SERVICES_H

#endif //DIA_SERVICES_H

#include "dynamic_array.h"
#pragma once

typedef struct{
    repository medicine_repo;
    repository* array_of_repos;
    int length_of_array_of_repos;
    int available_redos;
}services;

services create_service();

void testing_service();

void destroy_services(services* service);

void adding_a_repo(services* service, repository new_repo);

int undo_the_last_operation(services* service);

int redo_the_last_operation(services* service);

void adding_medicine(services* service, char name[], int concentration, int quantity, int price);

int deleting_medicine(services* service, char name[]);

repository check_which_medicine_is_available_by_string_search(services* service, char string[]);

repository filter_the_meds_in_short_supply(services* service, int new_quantity);