#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "domain.h"

Medicine create_medicine(char* name, int concentration, int quantity, int price)
{
    Medicine new_medicine;
    new_medicine.name = (char*)malloc(sizeof(char)*64);
    strcpy(new_medicine.name, name);
    new_medicine.concentration = concentration;
    new_medicine.quantity = quantity;
    new_medicine.price = price;
    return new_medicine;
}
void destroy_domain(Medicine* medicine)
{
    free(medicine->name);
}
void toString(Medicine medicine, char string[])
{
    sprintf(string, "The medicine %s has a concentration of %d, a quantity of %d and the price %d.\n", medicine.name, medicine.concentration, medicine.quantity, medicine.price);
}
void testing_domain()
{
    int concentration, quantity, price;
    char* name;
    char* string;
    string = (char*)malloc(sizeof(char)*1000);

    name = "Pill";
    concentration = 10; quantity = 10; price = 10;
    Medicine test_med;
    test_med = create_medicine(name, concentration, quantity, price);
    toString(test_med, string);
    assert(strcmp("The medicine Pill has a concentration of 10, a quantity of 10 and the price 10.\n", string) == 0);

}