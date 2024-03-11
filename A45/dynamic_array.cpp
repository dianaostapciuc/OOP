#include "dynamic_array.h"
#include "assert.h"
void testing_dynamic_array()
{
    DynamicArray<Dog> test_array;
    test_array.creating_dynamic_array(2);
    Dog test_dog1 = Dog("Bulldog", "Oli", 1, "photo-link");
    Dog test_dog2 = Dog("Pit-bull", "Max", 7, "photo-link");
    Dog test_dog3 = Dog("Bulldog", "Rex", 9, "photo-link");
    test_array.adding_an_element(test_dog1);
    assert(test_array.get_size() == 1);
    assert(test_array.get_capacity() == 2);
    assert(test_array.get_elements()[0].get_breed() == "Bulldog");
    assert(test_array.get_elements()[0].get_name() == "Oli");
    assert(test_array.get_elements()[0].get_age() == 1);
    assert(test_array.get_elements()[0].get_photo() == "photo-link");
    test_array.adding_an_element(test_dog2);
    test_array.adding_an_element(test_dog3);
    test_array.removing_an_element(2);
    assert(test_array.get_elements()[1].get_name() == "Max");
    test_array.updating_an_element(1, test_dog3);
    assert(test_array.get_elements()[1].get_name() == "Rex");
}