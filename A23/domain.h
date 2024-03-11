#ifndef DIA_DOMAIN_H
#define DIA_DOMAIN_H

#endif //DIA_DOMAIN_H

#pragma once

typedef struct
{
    char* name;
    int concentration, quantity, price;

}Medicine;

Medicine create_medicine(char name[], int concentration, int quantity, int price);

void destroy_domain(Medicine* medicine);

void testing_domain();

void toString(Medicine medicine, char string[]);
