#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>

#include "AbstracTypes.hpp"

template<typename T>
class Vector {
public:
    Vector(int s);
    ~Vector();
    
    Vector(const Vector& a); // copy constructor
    Vector& operator=(const Vector& a); //copy assignment
    
    
    Vector(Vector&& a);             //move constructor
    Vector& operator=(Vector&& a);  //move assignment
    
    T& operator[](int i); // subscript variable
    const T& operator[](int i) const; // subscript constant
    
    
    int size() const;
private:
    T* elem;
    int sz;
};

template<typename T>
class Vector_container : public Container<T> {
public:
    Vector_container(int s);
    ~Vector_container();
    
    T& operator[](int i);
    int size() const;
private:
    Vector<T> v;
};

#endif /* Vector_hpp */
