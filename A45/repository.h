#ifndef A45_XDIANAOST_REPOSITORY_H
#define A45_XDIANAOST_REPOSITORY_H

#endif //A45_XDIANAOST_REPOSITORY_H
#include <dynamic_array.h>


class repository
{
private:
    DynamicArray<Dog> array_of_repo;
    DynamicArray<Dog> array_of_adopted_dogs;
    DynamicArray<Dog> sorted_array_of_dogs;
public:
    // constructor:
    repository(DynamicArray<Dog> array_of_repo, DynamicArray<Dog> array_of_adopted_dogs, DynamicArray<Dog> sorted_array_of_dogs);
    void generating_startup_entries();
    DynamicArray<Dog> get_repo();
    DynamicArray<Dog> get_sorted_repo();
    int get_number_of_dogs();
    int get_number_of_sorted_dogs();
    int get_capacity_of_array();
    void adding_a_dog(Dog dog);
    void adding_a_dog_to_adopted_list(Dog& dog);
    void adding_a_dog_to_sorted_list(Dog& dog);
    void deleting_a_dog(int delete_index);
    void deleting_a_dog_from_sorted_array(int delete_index);
    void updating_a_dog(int update_index, Dog new_dog);
    string displaying_each_dog(int index);
    string displaying_adoption_list();
    // destructor:
    ~repository();
};
void testing_repo();