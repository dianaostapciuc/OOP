#include "services.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

services create_service(){
    services new_services;
    new_services.array_of_repos = (repository*)malloc(sizeof(repository)*15);
    new_services.medicine_repo = create_repo(20);
    generate_startup_entries(&new_services.medicine_repo);
    new_services.length_of_array_of_repos = 0;
    new_services.available_redos = 0;
    return new_services;
};
void destroy_services(services* service)
{
    for (int i=0; i<service->length_of_array_of_repos; i++)
        destroy_repo(&service->array_of_repos[i]);
    free(service->array_of_repos);
    destroy_repo(&service->medicine_repo);
}
void adding_a_repo(services* service, repository new_repo)
{
    service->array_of_repos[service->length_of_array_of_repos] = new_repo;
    service->length_of_array_of_repos++;
    service->available_redos = 0;
}
int undo_the_last_operation(services* service)
{
    if (service->length_of_array_of_repos != 0)
    {
        service->length_of_array_of_repos--;
        service->medicine_repo = service->array_of_repos[service->length_of_array_of_repos-1];
        service->available_redos++;
        return 1;
    }
    return 0;
}
int redo_the_last_operation(services* service)
{
    if (service->available_redos != 0)
    {
        service->medicine_repo = service->array_of_repos[service->length_of_array_of_repos];
        service->length_of_array_of_repos++;
        service->available_redos--;
        return 1;
    }
    return 0;
}

void adding_medicine(services* service, char name[], int concentration, int quantity, int price)
{
    Medicine new_medicine;
    new_medicine = create_medicine(name, concentration, quantity, price);
    adding_a_medicine(&service->medicine_repo, new_medicine);
}

int deleting_medicine(services* service, char name[])
{
    int check_if_medicine_was_deleted;
    check_if_medicine_was_deleted = deleting_a_medicine(&service->medicine_repo, name);
    return check_if_medicine_was_deleted;
}

repository check_which_medicine_is_available_by_string_search(services* service, char string[])
{
    return check_which_medicine_is_available_by_string_matching(&service->medicine_repo, string);
}
repository filter_the_meds_in_short_supply(services* service, int new_quantity)
{
    return filter_the_medicine_that_are_in_short_supply(&service->medicine_repo, new_quantity);
}
void testing_service()
{
    services test_service = create_service();
    generate_startup_entries(&test_service.medicine_repo);

    // testing the adding&update

    adding_medicine(&test_service, "Pill", 10, 10, 10);
    adding_medicine(&test_service, "Pill", 10, 10, 10);
    assert(test_service.medicine_repo.array_of_medicine[10].quantity == 20);

    //testing the deleting
    int check_delete;
    check_delete = deleting_medicine(&test_service, "Pill");
    assert(check_delete == 1);

    //testing the undo and redo
    adding_medicine(&test_service, "Pill", 10, 10, 10);
    adding_a_repo(&test_service, test_service.medicine_repo);
    adding_medicine(&test_service, "Pill2", 10, 10, 10);
    adding_a_repo(&test_service, test_service.medicine_repo);
    int check_undo, check_redo;
    check_undo = undo_the_last_operation(&test_service);
    assert(check_undo == 1);

    check_redo = redo_the_last_operation(&test_service);
    assert(check_redo == 1);

}