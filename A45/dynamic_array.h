#ifndef A45_XDIANAOST_DYNAMIC_ARRAY_H
#define A45_XDIANAOST_DYNAMIC_ARRAY_H

#endif //A45_XDIANAOST_DYNAMIC_ARRAY_H

#include <domain.h>

template <typename TElem>
class DynamicArray
{
private:
    TElem* elements;
    int capacity;
    int size;
    void resizing_the_array();

public:
    void creating_dynamic_array(int capacity);
    void adding_an_element(TElem element);
    void removing_an_element(int index);
    void updating_an_element(int position, TElem element);
    TElem& operator[](int index);
    void * operator new(size_t size);
    void* operator new[](size_t size);
    ~DynamicArray();
    int get_size();
    int get_capacity();
    TElem* get_elements();
};


template <typename TElem>
void DynamicArray<TElem>::creating_dynamic_array(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    this->elements = new TElem[this->capacity];
}
template <typename TElem>
TElem& DynamicArray<TElem>::operator[](int index)
{
    return this->elements[index];
}

template <typename TElem>
void DynamicArray<TElem>::resizing_the_array()
{
    TElem* new_array_of_elements;
    new_array_of_elements = new TElem [this->capacity*2];
    for (int i = 0; i < this->capacity; i++)
        new_array_of_elements[i] = this->elements[i];
    this->capacity = this->capacity*2;
    delete[] this->elements;
    this->elements = new_array_of_elements;
}

template <typename TElem>
void DynamicArray<TElem>::adding_an_element(TElem element)
{
    if (this->capacity == this->size)
        resizing_the_array();
    this->elements[this->size] = element;
    this->size++;
}

template <typename TElem>
void DynamicArray<TElem>::removing_an_element(int index)
{
    for (int i = index; i < this-> size - 1; i++)
        this->elements[i] = this->elements[i+1];
    this->size--;
}

template <typename TElem>
void DynamicArray<TElem>::updating_an_element(int position, TElem element)
{
    this->elements[position] = element;
}

template <typename TElem>
TElem* DynamicArray<TElem>::get_elements()
{
    return this->elements;
}

template <typename TElem>
int DynamicArray<TElem>::get_capacity()
{
    return this->capacity;
}

template <typename TElem>
int DynamicArray<TElem>::get_size()
{
    return this->size;
}

template <typename TElem>
DynamicArray<TElem>::~DynamicArray()
{
}

void testing_dynamic_array();
