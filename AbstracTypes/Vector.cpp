#include "Vector.hpp"
#include <stdexcept>

template<typename T>
Vector<T>::Vector(int s) :elem{new T[s]}, sz{s} {
    for (int i=0; i!=s; i++) elem[i] = 0;
}


template<typename T>
Vector<T>::Vector(const Vector& a)         // copy constructor
    :elem{new T[a.sz]}, sz{a.sz}   // allocate space for elements
{
    for (int i=0; i!=sz; i++)
        elem[i] = a.elem[i];            // copy elements
}


template<typename T>
Vector<T>::Vector(Vector&& a)              // move constructor
    :elem(a.elem), sz{a.sz}
{
    a.elem = nullptr;
    a.sz = 0;
}
  
template<typename T>
Vector<T>::~Vector() { delete[] elem; }
  

template<typename T>
T& Vector<T>::operator[](int i) {
    if(i<0 || size()<=i)
        throw std::out_of_range("Vector::operator[]");
    return elem[i];
}


template<typename T>
int Vector<T>::size() const {
    return sz;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& a) //copy assignment
{
    double* p = new T[a.sz];
    for (int i=0; i!=a.sz; i++)
        p[i] = a.elem[i];
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
}

template<typename T>
Vector_container<T>::Vector_container(int s) :v{s} {
    for (int i=0; i!=s; i++) v[i] = 0;
}
    

template<typename T>
Vector_container<T>::~Vector_container() {}
    

template<typename T>
T& Vector_container<T>::operator[](int i) {
    return v[i];
}


template<typename T>
int Vector_container<T>::size() const {
    return v.size();
}
