#ifndef DIA_REPO_H
#define DIA_REPO_H

#endif //DIA_REPO_H

#pragma once
#include "domain.h"

typedef Medicine TElem;

typedef struct{
    Medicine* array_of_medicine;
    int length_of_array_of_meds;
    int capacity;
}repository;

repository create_repo(int capacity);

void testing_array();

void destroy_repo(repository* repo);

void adding_a_medicine(repository *repo, Medicine new_medicine);

repository* resize_dynamic_array(repository* repo);

int deleting_a_medicine(repository* repo, char name[]);

void sort_the_medicine_in_ascending_order(repository* repo);

repository check_which_medicine_is_available_by_string_matching(repository* repo, char string[]);

repository filter_the_medicine_that_are_in_short_supply(repository* repo, int new_quantity);

void generate_startup_entries(repository* repo);