#ifndef Shapes_hpp
#define Shapes_hpp

#include <stdio.h>
#include "vector"

struct Point {
    double x, y;
};

class Shape {
public:
    virtual Point center() const =0;
    virtual void move(Point to) =0;
    
    virtual void draw() const =0;
    virtual void rotate(int angle) =0;
    
    // suppressing copy and move operations
    Shape(const Shape&) =delete;
    Shape& operator=(const Shape&) =delete;
    
    Shape(Shape&&) =delete;
    Shape& operator=(Shape&&) =delete;
    
    virtual ~Shape() {}
};

class Circle :public Shape {
public:
    Circle(Point p, int r);
    
    Point center() const;
    void move(Point to);
    
    void draw() const;
    void rotate(int);
private:
    Point x;
    int r;
};

class Smiley :public Circle {
public:
    Smiley(Point p, int r) : Circle(p, r), mouth{nullptr} {}
    
    ~Smiley()
    {
        delete mouth;
        for (auto p : eyes) delete p;
    }
    
    void move(Point to);
    
    void draw() const;
    void rotate(int);
    
    void add_eye(Shape* s) {eyes.push_back(s); }
    void set_mouth(Shape* s);
    virtual void wink(int i);
    
    
private:
    std::vector<Shape*> eyes;
    Shape* mouth;
};

#endif /* Shapes_hpp */
