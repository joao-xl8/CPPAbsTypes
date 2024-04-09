#include "AbstracTypes.hpp"

template<typename T>
List_container<T>::List_container() {}

template<typename T>
List_container<T>::List_container(std::initializer_list<T> il) : ld{il} {}

template<typename T>
List_container<T>::~List_container() {}

template<typename T>
T& List_container<T>::operator[](int i)
{
    for (auto& x: ld) {
        if(i==0) return x;
        --i;
    }
    throw std::out_of_range("List container");
}

template<typename T>
int List_container<T>::size() const {
    return ld.size();
}

