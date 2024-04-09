#ifndef AbstracTypes_hpp
#define AbstracTypes_hpp

#include <stdio.h>
#include <iostream>
#include <list>

template<typename T>
class Container {
public:
    virtual T& operator[](int) =0;
    virtual int size() const =0;
    virtual ~Container() {}
};

template<typename T>
class List_container :public Container<T> {
    std::list<T> ld;
public:
    List_container();
    List_container(std::initializer_list<T> il);
    ~List_container();
    
    T& operator[](int i);
    int size() const;
};


#endif /* AbstracTypes_hpp */
