// John is the administrator of the “Smiles” Pharmacy. He needs a software application to help him manage
// his pharmacy's medicine stocks. Each Medicine has the following attributes: name, concentration,
// quantity and price. John wants the application to help him in the following ways:
// (a) Add, delete or update a medicine. A medicine is uniquely identified by its name and concentration.
// If a product that already exists is added, its quantity will be updated (the new quantity is added to
// the existing one).
// (b) See all available medicines containing a given string (if the string is empty, all the available
// medicines will be considered), sorted ascending by medicine name.

#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>

UI create_UI()
{
    UI new_ui;
    new_ui.service = create_service();
    adding_a_repo(&new_ui.service, new_ui.service.medicine_repo);
    return new_ui;
}
void destroy_ui(services* service)
{
    destroy_services(service);
}

void menu(services* service)
{
    char* choice1;
    choice1 = (char*)malloc(sizeof(char)*50);
    printf("In the 'Smiles' pharmacy, the following can be done:\n");
    printf("1. Adding (or updating if product already exists) a medicine.\n");
    printf("2. Deleting a medicine.\n");
    printf("3. See all available medicine containing a string.\n");
    printf("4. See only the medicines that are in short supply.\n");
    printf("5. UNDO!\n");
    printf("6. REDO!\n");
    printf("7. Exit.\n");

    while(1)
    {
        int choice;
        printf("What would you like to do?\n");
        scanf("%s", choice1);

        choice = atoi(choice1);

        while (choice == 0)
        {
            printf("Bad command, try inputting an integer...\n");
            scanf("%s", choice1);
            choice = atoi(choice1); // atoi = turning strings into integer
        }
        switch(choice)
        {
            case 1:
            {
                printf("Adding a medicine...\n");
                char* name;
                char* concentration1;
                char* quantity1;
                char* price1;
                name = (char*)malloc(sizeof(char)*30);
                concentration1 = (char*)malloc(sizeof(char)*10);
                quantity1 = (char*)malloc(sizeof(char)*10);
                price1 = (char*)malloc(sizeof(char)*10);
                int concentration, quantity, price;
                printf("Name?\n");
                scanf("%s", name);

                printf("Concentration?\n");
                scanf("%s", concentration1);
                concentration = atoi(concentration1);
                while (concentration == 0)
                {
                    printf("Bad input for the concentration, try an integer!\n");
                    scanf("%s", concentration1);
                    concentration = atoi(concentration1);
                }

                printf("Quantity?\n");
                scanf("%s", quantity1);
                quantity = atoi(quantity1);
                while (quantity == 0)
                {
                    printf("Bad input for the quantity, try an integer!\n");
                    scanf("%s", quantity1);
                    quantity = atoi(quantity1);
                }

                printf("Price?\n");
                scanf("%s", price1);
                price = atoi(price1);
                while (price == 0)
                {
                    printf("Bad input for the price, try an integer!\n");
                    scanf("%s", price1);
                    price = atoi(price1);
                }

                adding_medicine (service, name, concentration, quantity, price);
                adding_a_repo(service, service->medicine_repo);
                free(name); free(quantity1); free(concentration1); free(price1);
                break;
            }
            case 2:
            {
                printf("Deleting a medicine...\n");
                char* name;
                name = (char*)malloc(sizeof(char)*30);

                int check_if_medicine_was_deleted;
                printf("%s", "Name?\n");
                scanf("%s", name);
                check_if_medicine_was_deleted = deleting_medicine(service, name);
                adding_a_repo(service, service->medicine_repo);
                if (check_if_medicine_was_deleted == 0)
                    printf("The medicine wasn't deleted!\n");
                else printf("The medicine was deleted!\n");
                free(name);
                break;
            }
            case 3:
            {
                printf("Searching the available medicines...\n");
                char* string;
                string = (char*)malloc(sizeof(char)*100);
                char* result;
                result = (char*)malloc(sizeof(char)*10000);
                printf("%s", "What is the string to search by?\n");
                scanf("%s", string);
                strcpy(result, "");
                repository result_repo;
                result_repo = check_which_medicine_is_available_by_string_search(service, string);
                for (int i=0; i<result_repo.length_of_array_of_meds;i++)
                {
                    char medicine[200];
                    toString(result_repo.array_of_medicine[i], medicine);
                    strcat(result, medicine);
                }
                printf("%s\n", result);
                free(string); free(result);
                break;
            }
            case 4:
            {
                printf("Searching for the medicine in short supply...\n");
                int new_quantity;
                char* result;
                char* new_quantity1;
                result = (char*)malloc(sizeof(char)*10000);
                new_quantity1 = (char*)malloc(sizeof(char)*10);
                strcpy(result, "");
                printf("Medicines with quantity less than:\n");
                scanf("%s", new_quantity1);
                new_quantity = atoi(new_quantity1);
                while (new_quantity == 0)
                {
                    printf("Bad input for the quantity, try an integer!\n");
                    scanf("%s", new_quantity1);
                    new_quantity = atoi(new_quantity1);
                }
                repository result_repo;
                result_repo = filter_the_meds_in_short_supply(service, new_quantity);
                for (int i=0; i<result_repo.length_of_array_of_meds;i++)
                {
                    char medicine[200];
                    toString(result_repo.array_of_medicine[i], medicine);
                    strcat(result, medicine);
                }
                printf("%s\n", result);
                free(result); free(new_quantity1);
                break;
            }
            case 5:
            {
                printf("Undoing the last operation...\n");
                int check_if_the_undo_works = 0;
                check_if_the_undo_works = undo_the_last_operation(service);
                if (check_if_the_undo_works == 0)
                    printf("The undo can no longer be done.\n");
                else printf("The undo was done!\n");
                break;
            }
            case 6:
            {
                printf("Redoing the last operation...\n");
                int check_if_redo_works = 0;
                check_if_redo_works = redo_the_last_operation(service);
                if (check_if_redo_works == 0)
                    printf("The redo can no longer be done.\n");
                else printf("The redo was done!\n");
                break;
            }
            case 7:
            {
                free(choice1);
                //destroy_ui(service);
                //printf("%d", _CrtDumpMemoryLeaks());
                exit(0);
            }
            default:
                printf("Invalid command.. :(\n");
                break;
        }
    }
}


int main()
{
    UI ui;
    ui = create_UI();
    menu(&ui.service);
    return 0;
}
