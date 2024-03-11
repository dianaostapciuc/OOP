#ifndef A45_XDIANAOST_SERVICES_H
#define A45_XDIANAOST_SERVICES_H

#endif //A45_XDIANAOST_SERVICES_H

#include <repository.h>

class services
{
private:
    repository repo;
public:
    // constructor:
    services(repository repo);
    // others:
    DynamicArray<Dog> get_services();
    DynamicArray<Dog> get_sorted_services();
    bool add_service(string breed, string name, int age, string photo);
    void adding_to_adoption_list(Dog dog);
    void sorting_the_array_of_dogs(string breed, int age);
    bool delete_service(string name);
    bool delete_dog_from_sorted_list(string name);
    bool updating_service(string old_name, string new_name, string new_breed, int new_age, string new_photo);
    string display_each_dog(int index);
    int get_number_of_dogs();
    int get_number_of_sorted_dogs();
    string displaying_adoption_list();
    // destructor:
    ~services();

};
void testing_services();