#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "dynamic_array.h"

repository create_repo(int capacity){
    repository new_repo;
    new_repo.capacity = capacity;
    new_repo.array_of_medicine = (Medicine*)malloc(sizeof(TElem)*20);
    new_repo.length_of_array_of_meds = 0;

    return new_repo;
}
void destroy_repo(repository* repo)
{
    for(int i=0; i<repo->length_of_array_of_meds; i++)
        destroy_domain(&repo->array_of_medicine[i]);
    free(repo->array_of_medicine);
}
repository* resize_dynamic_array(repository* repo)
{
    repo->capacity = repo->capacity*2;
    repository* aux;
    aux = realloc(repo->array_of_medicine, sizeof(Medicine) * repo->capacity);
    return aux;
}
void adding_a_medicine(repository* repo, Medicine new_medicine)
{
    int checking_if_medicine_exists = 0, position_of_medicine;
    if (repo->length_of_array_of_meds+1 > repo->capacity)
        repo = resize_dynamic_array(repo);
    for (int i=0; i< repo->length_of_array_of_meds; i++)
        if (strcmp(new_medicine.name, repo->array_of_medicine[i].name) == 0 && (new_medicine.concentration == repo->array_of_medicine[i].concentration))
            checking_if_medicine_exists = 1, position_of_medicine = i;
    if (checking_if_medicine_exists == 0)
    {
        repo->array_of_medicine[repo->length_of_array_of_meds] = new_medicine;
        repo->length_of_array_of_meds++;
    }
    else
    {
        repo->array_of_medicine[position_of_medicine].quantity += new_medicine.quantity;
    }
    //printf("%d", repo->length_of_array_of_meds);

}

int deleting_a_medicine(repository* repo, char name[])
{
    for (int i = 0; i < repo->length_of_array_of_meds; i++)
        if (strcmp(repo->array_of_medicine[i].name, name) == 0)
        {
            repo->array_of_medicine[i] = repo->array_of_medicine[repo->length_of_array_of_meds - 1];
            repo->length_of_array_of_meds--;
            return 1;
        }
    return 0;
}

void sort_the_medicine_in_ascending_order(repository* repo)
{
    repository new_repo;
    new_repo = create_repo(20);
    for (int i=0; i<repo->length_of_array_of_meds-1;i++)
        for (int j=i+1; j<repo->length_of_array_of_meds; j++)
            if (strcmp(repo->array_of_medicine[i].name, repo->array_of_medicine[j].name) > 0)
            {
                new_repo.array_of_medicine[0] = repo->array_of_medicine[j];
                repo->array_of_medicine[j] = repo->array_of_medicine[i];
                repo->array_of_medicine[i] = new_repo.array_of_medicine[0];
            }
}

repository check_which_medicine_is_available_by_string_matching(repository* repo, char string[])
{

    repository new_repo;
    new_repo = create_repo(20);
    int string_found = 0;

    if (strcmp(string, "-") == 0)
    {
        sort_the_medicine_in_ascending_order(repo);
        return *repo;
    }
    else
    {
        for (int i=0; i<repo->length_of_array_of_meds;i++)
            if (strstr(repo->array_of_medicine[i].name, string) != NULL)
                adding_a_medicine(&new_repo, repo->array_of_medicine[i]), string_found = 1;
    }

    if (string_found == 0)
    {
        sort_the_medicine_in_ascending_order(repo);
        return *repo;
    }
    else if (string_found == 1)
    {
        sort_the_medicine_in_ascending_order(&new_repo);
        return new_repo;
    }

}

repository filter_the_medicine_that_are_in_short_supply(repository* repo, int new_quantity)
{
    repository new_repo;
    new_repo = create_repo(20);
    int check_if_such_medicine_exists = 0;

    for (int i=0; i< repo->length_of_array_of_meds; i++)
        if (repo->array_of_medicine[i].quantity < new_quantity)
            adding_a_medicine(&new_repo, repo->array_of_medicine[i]), check_if_such_medicine_exists = 1;

    if (check_if_such_medicine_exists != 0)
        return new_repo;
    else
    {
        repository empty;
        empty = create_repo(20);
        return empty;
    }
}

void generate_startup_entries(repository* repo)
{

    Medicine new_medicine1 = create_medicine("Algocalmin", 200, 89, 25);
    Medicine new_medicine2 = create_medicine("Saridon", 250, 123, 30);
    Medicine new_medicine3 = create_medicine("Fervex", 120,30, 10);
    Medicine new_medicine4 = create_medicine("Theraflu", 125, 31, 11);
    Medicine new_medicine5 = create_medicine("Strepsils", 80, 200, 13);
    Medicine new_medicine6 = create_medicine ("Awp", 400, 1, 50);
    Medicine new_medicine7 = create_medicine ("Setralina", 320, 21, 20);
    Medicine new_medicine8 = create_medicine ("Ventolin",300, 60, 65);
    Medicine new_medicine9 = create_medicine ("Nurofen", 100, 236, 55);
    Medicine new_medicine10 = create_medicine ("Zinat", 315, 34, 100);

    adding_a_medicine(repo, new_medicine1);
    adding_a_medicine(repo, new_medicine2);
    adding_a_medicine(repo, new_medicine3);
    adding_a_medicine(repo, new_medicine4);
    adding_a_medicine(repo, new_medicine5);
    adding_a_medicine(repo, new_medicine6);
    adding_a_medicine(repo, new_medicine7);
    adding_a_medicine(repo, new_medicine8);
    adding_a_medicine(repo, new_medicine9);
    adding_a_medicine(repo, new_medicine10);

}

void testing_array()
{
    repository test_repo = create_repo(20);
    generate_startup_entries(&test_repo);

    //testing the add&update:

    Medicine test_medicine = create_medicine("Pill", 5, 5, 5);
    adding_a_medicine(&test_repo, test_medicine);
    adding_a_medicine(&test_repo, test_medicine);
    assert(test_repo.array_of_medicine[10].quantity == 10);

    //testing the delete:
    deleting_a_medicine(&test_repo, "Pill");
    assert(strcmp(test_repo.array_of_medicine[10].name, "Pill") == 0);

    // testing the sort:
    sort_the_medicine_in_ascending_order(&test_repo);
    for (int i=0; i<test_repo.length_of_array_of_meds-1; i++)
        assert(strcmp(test_repo.array_of_medicine[i].name, test_repo.array_of_medicine[i+1].name) == -1);
}