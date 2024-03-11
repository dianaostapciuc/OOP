#include "repository.h"
#include "assert.h"
using namespace std;

repository::repository(DynamicArray<Dog> array_of_repo1, DynamicArray<Dog> array_of_adopted_dogs1, DynamicArray<Dog> sorted_array_of_dogs1)
{
    this->array_of_repo = array_of_repo;
    this->array_of_adopted_dogs = array_of_adopted_dogs;
    this->sorted_array_of_dogs = sorted_array_of_dogs;
    this->array_of_repo.creating_dynamic_array(20);
    this->array_of_adopted_dogs.creating_dynamic_array(20);
    this->sorted_array_of_dogs.creating_dynamic_array(20);
}
void repository::generating_startup_entries()
{
    Dog new_dog1 = Dog("Akita", "Fluff", 3, "https://idog.ro/wp-content/uploads/2021/05/Caine-Akita-Inu-morocanos.jpg");
    Dog new_dog2 = Dog("Bulldog", "Ice", 5, "https://cdn.britannica.com/78/232778-050-D3701AB1/English-bulldog-dog.jpg");
    Dog new_dog3 = Dog("Pit-bull", "Mister Worldwide", 2, "https://nationaltoday.com/wp-content/uploads/2022/07/14-Pitbull-Awareness-Month-640x514.jpg.webp");
    Dog new_dog4 = Dog("Field Spaniel", "Suki", 7, "https://www.e-vet.ro/wp-content/uploads/2021/06/spaniel-ul-de-camp-field-spaniel-01.jpg");
    Dog new_dog5 = Dog("Bichon", "Bella", 3, "https://img.spynews.ro/?u=https%3A%2F%2Fspynews.ro%2Fuploads%2Fmodules%2Fnews%2F0%2F2022%2F6%2F19%2F281952%2Fbichon.jpg");
    Dog new_dog6 = Dog("Akita", "Yuki", 6, "https://cdn.britannica.com/59/234759-050-DA4F2DCF/Akita-dog-Japan.jpg");
    Dog new_dog7 = Dog("Husky", "Screechy", 5, "https://www.allthingsdogs.com/wp-content/uploads/2019/12/Red-Husky-Feature.jpg");
    Dog new_dog8 = Dog("Corgi", "Hot-dog", 2, "https://blog.petissimo.ro/media/cache/optimized/uploads/cropped/corgi_kutya.%20%281%29_crop_60ade782a67ee.jpg");
    Dog new_dog9 = Dog("Corgi", "Mustard", 9, "https://www.hepper.com/wp-content/uploads/2021/11/corgi-2-1.jpg");
    Dog new_dog10 = Dog("Bulldog", "Cheese", 1, "https://highlandcanine.com/wp-content/uploads/2021/02/bulldog-puppy-sitting-in-grass.jpg");
    this->array_of_repo.adding_an_element(new_dog1);
    this->array_of_repo.adding_an_element(new_dog2);
    this->array_of_repo.adding_an_element(new_dog3);
    this->array_of_repo.adding_an_element(new_dog4);
    this->array_of_repo.adding_an_element(new_dog5);
    this->array_of_repo.adding_an_element(new_dog6);
    this->array_of_repo.adding_an_element(new_dog7);
    this->array_of_repo.adding_an_element(new_dog8);
    this->array_of_repo.adding_an_element(new_dog9);
    this->array_of_repo.adding_an_element(new_dog10);

}
DynamicArray<Dog> repository::get_repo()
{
    return this->array_of_repo;
}

DynamicArray<Dog> repository::get_sorted_repo()
{
    return this->sorted_array_of_dogs;
}

int repository::get_number_of_dogs()
{
    return this->array_of_repo.get_size();
}

int repository::get_number_of_sorted_dogs()
{
    return this->sorted_array_of_dogs.get_size();
}

int repository::get_capacity_of_array()
{
    return this->array_of_repo.get_capacity();
}

void repository::adding_a_dog(Dog dog)
{
    this->array_of_repo.adding_an_element(dog);
}

void repository::adding_a_dog_to_adopted_list(Dog& dog)
{
    this->array_of_adopted_dogs.adding_an_element(dog);
}

void repository::adding_a_dog_to_sorted_list(Dog& dog)
{
    this->sorted_array_of_dogs.adding_an_element(dog);
}

void repository::deleting_a_dog(int delete_index)
{
    this->array_of_repo.removing_an_element(delete_index);
}

void repository::deleting_a_dog_from_sorted_array(int delete_index)
{
    this->sorted_array_of_dogs.removing_an_element(delete_index);
}

void repository::updating_a_dog(int update_index, Dog new_dog)
{
    this->array_of_repo.updating_an_element(update_index, new_dog);
}

string repository::displaying_each_dog(int index)
{
    string result = "";
    result = this->array_of_repo.get_elements()[index].turn_into_string() + "\n";
    return result;
}

string repository::displaying_adoption_list()
{
    string result ="";
    for (int i=0; i<this->array_of_adopted_dogs.get_size(); i++)
        result = result + this->array_of_adopted_dogs.get_elements()[i].turn_into_string() + "\n";
    return result;
}

repository::~repository() = default;

void testing_repo()
{
    DynamicArray<Dog> test_array;
    DynamicArray<Dog> test_array_dogs;
    DynamicArray<Dog> test_array_sorted_dogs;
    test_array.creating_dynamic_array(2);
    test_array_dogs.creating_dynamic_array(2);
    test_array_sorted_dogs.creating_dynamic_array(2);
    repository test_repo(test_array, test_array_dogs, test_array_sorted_dogs);
    test_repo.generating_startup_entries();

    assert(test_repo.get_repo()[0].get_name() == "Fluff");
    assert(test_repo.get_capacity_of_array() == 20);
    assert(test_repo.get_number_of_dogs() == 10);
    assert(test_repo.get_number_of_sorted_dogs() == 0);

    Dog test_dog = Dog("Pit-bull", "Oli", 10, "photo-link");
    test_repo.adding_a_dog(test_dog);
    assert(test_repo.get_repo()[10].get_name() == "Oli");
    test_repo.deleting_a_dog(10);
    assert(test_repo.get_number_of_dogs() == 10);
    test_repo.adding_a_dog_to_sorted_list(test_dog);
    test_repo.adding_a_dog_to_adopted_list(test_dog);
    assert(test_repo.get_number_of_sorted_dogs() == 1);
    assert(test_repo.get_sorted_repo()[0].get_name() == "Oli");
    test_repo.deleting_a_dog_from_sorted_array(0);
    assert(test_repo.get_number_of_sorted_dogs() == 0);
    Dog test_dog2 = Dog("Pit-bull", "Max", 7, "photo-link");
    test_repo.updating_a_dog(2, test_dog2);
    assert(test_repo.get_repo()[2].get_name() == "Max");

    DynamicArray<Dog> test_array2;
    DynamicArray<Dog> test_array_dogs2;
    DynamicArray<Dog> test_array_sorted_dogs2;
    test_array2.creating_dynamic_array(20);
    test_array_dogs2.creating_dynamic_array(20);
    test_array_sorted_dogs2.creating_dynamic_array(20);
    repository test_repo2(test_array2, test_array_dogs2, test_array_sorted_dogs2);
    test_repo2.adding_a_dog(test_dog);
    test_repo2.adding_a_dog_to_adopted_list(test_dog);
    test_repo2.adding_a_dog_to_sorted_list(test_dog);
    string result2;
    result2 = test_repo2.displaying_adoption_list();
    assert(result2 == "The dog named Oli is of breed: Pit-bull, of age: 10 and its link is: \nphoto-link\n");
    string result3;
    result3 = test_repo2.displaying_each_dog(0);
    assert(result3 == "The dog named Oli is of breed: Pit-bull, of age: 10 and its link is: \nphoto-link\n");

}
//"The dog named Oli is of breed: Pit-bull, of age: 10 and its link is: \nphoto-link\n")