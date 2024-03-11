#include "services.h"
#include "assert.h"
#include "cstring"
services::services(repository repo1): repo(repo1)
{
}

DynamicArray<Dog> services::get_services()
{
    return this->repo.get_repo();
}
DynamicArray<Dog> services::get_sorted_services()
{
    return this->repo.get_sorted_repo();
}
bool services::add_service(string breed, string name, int age, string photo)
{
    for (int i = 0; i < this->repo.get_number_of_dogs(); i++)
    {
        string new_name, new_breed;
        int new_age;
        new_name = this->get_services()[i].get_name();
        new_breed = this->get_services()[i].get_breed();
        new_age = this->get_services()[i].get_age();
        if (new_name == name)
            return true;
    }
    Dog new_dog = Dog(breed, name, age, photo);
    this->repo.adding_a_dog(new_dog);
    return false;
}
void services::adding_to_adoption_list(Dog dog)
{
    this->repo.adding_a_dog_to_adopted_list(dog);
}

bool compare_strings(string string1, string string2)
{
    if(string1.length() != string2.length())
        return false;
    for(int i = 0; i< string1.length(); i++)
        if(string1[i] != string2[i])
            return false;
    return true;
}

void services::sorting_the_array_of_dogs(string breed, int age)
{
    for (int i=0; i<this->repo.get_number_of_sorted_dogs(); i++)
        this->repo.deleting_a_dog_from_sorted_array(i);
    for (int i=0; i< this->repo.get_number_of_dogs(); i++)
    {
        string new_breed;
        new_breed = this->repo.get_repo()[i].get_breed();
        if ((compare_strings(breed, new_breed) || breed == "-") && this->repo.get_repo()[i].get_age() < age)
            this->repo.adding_a_dog_to_sorted_list(this->repo.get_repo()[i]);
    }
}
int services::get_number_of_sorted_dogs()
{
    return this->repo.get_number_of_sorted_dogs();
}
string services::displaying_adoption_list()
{
    return this->repo.displaying_adoption_list();
}
bool services::delete_service(string name)
{
    int check_if_dog_exists = 0, index_to_delete;
    for (int i = 0; i < this->repo.get_number_of_dogs(); i++)
    {
        string new_name;
        new_name = this->get_services()[i].get_name();
        if (new_name == name)
        {
            check_if_dog_exists = 1;
            index_to_delete = i;
            break;
        }
    }
    if (check_if_dog_exists == 1)
    {
        this->repo.deleting_a_dog(index_to_delete);
        return true;
    }
    else return false;
}
bool services::delete_dog_from_sorted_list(string name)
{
    int check_if_dog_exists = 0, index_to_delete;
    for (int i = 0; i < this->repo.get_number_of_sorted_dogs(); i++)
    {
        string new_name;
        new_name = this->get_sorted_services()[i].get_name();
        if (new_name == name)
        {
            check_if_dog_exists = 1;
            index_to_delete = i;
            break;
        }
    }
    if (check_if_dog_exists == 1)
    {
        this->repo.deleting_a_dog_from_sorted_array(index_to_delete);
        return true;
    }
    else return false;
}

bool services::updating_service(string old_name, string new_name, string new_breed, int new_age, string new_photo)
{
    int check_if_dog_exists = 0, update_index;
    for (int j = 0; j < this->repo.get_number_of_dogs(); j++)
    {
        string check_name;
        check_name = this->get_services()[j].get_name();
        if (old_name == check_name)
            check_if_dog_exists = 1, update_index = j;
    }
    if (check_if_dog_exists == 0)
        return false;
    else
    {
        this->repo.updating_a_dog(update_index, Dog(new_breed, new_name, new_age, new_photo));
        return true;
    }
}
string services::display_each_dog(int index)
{
    return this->repo.displaying_each_dog(index);
}
int services::get_number_of_dogs()
{
    return this->repo.get_number_of_dogs();
}
services::~services() = default;


void testing_services()
{
    Dog test_dog = Dog("Pit-bull", "Oli", 10, "photo-link");
    DynamicArray<Dog> test_array;
    DynamicArray<Dog> test_array_of_dogs;
    DynamicArray<Dog> test_sorted_array;
    test_array.creating_dynamic_array(20);
    test_array_of_dogs.creating_dynamic_array(20);
    test_sorted_array.creating_dynamic_array(20);
    repository test_repo = repository(test_array, test_array_of_dogs, test_sorted_array);
    test_repo.generating_startup_entries();
    services test_service = services(test_repo);
    test_service.add_service("Bulldog", "Oli", 15, "photo-link");
    test_service.adding_to_adoption_list(test_dog);
    assert(test_service.get_services()[10].get_name() == "Oli");
    test_service.sorting_the_array_of_dogs("Bulldog", 20);
    assert(test_service.get_number_of_sorted_dogs() == 3);
    assert(test_service.get_sorted_services()[2].get_name() == "Oli");
    assert(test_service.get_number_of_dogs() == 11);
    test_service.delete_dog_from_sorted_list("Oli");
    assert(test_service.get_number_of_sorted_dogs() == 2);
    test_service.delete_service("Oli");
    assert(test_service.get_number_of_dogs() == 10);
    test_service.updating_service("Fluff", "Rex", "Bichon", 4, "photo-link");
    assert(test_service.delete_service("zzz") == false);
    assert(test_service.delete_dog_from_sorted_list("zzz") == false);

    DynamicArray<Dog> test_array2;
    DynamicArray<Dog> test_array_of_dogs2;
    DynamicArray<Dog> test_sorted_array2;
    test_array.creating_dynamic_array(20);
    test_array_of_dogs.creating_dynamic_array(20);
    test_sorted_array.creating_dynamic_array(20);
    repository test_repo2 = repository(test_array, test_array_of_dogs, test_sorted_array);
    test_repo.generating_startup_entries();
    services test_service2 = services(test_repo2);
    test_service2.adding_to_adoption_list(test_dog);
    test_service2.add_service("Pit-bull", "Oli", 10, "photo-link");
    string result;
    result = test_service2.displaying_adoption_list();
    assert(result == "The dog named Oli is of breed: Pit-bull, of age: 10 and its link is: \nphoto-link\n");
    string result3;
    result3 = test_service2.display_each_dog(0);
    assert(result3 == "The dog named Oli is of breed: Pit-bull, of age: 10 and its link is: \nphoto-link\n");
}
//Dog test_dog = Dog("Pit-bull", "Oli", 10, "photo-link");
