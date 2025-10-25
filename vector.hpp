#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

class Vector {
  private:
    double x, y, z;
    int id;
    static int count;

  public:
    //default constructor
    Vector(double x=0.0, double y=0.0, double z=0.0);

    //copy constructors
    Vector(const Vector& v) : x(v.x), y(v.y), z(v.z), id(++count) {}

    //desctructor
    ~Vector();

    //operators overloading
    Vector& operator=(const Vector& v);
    const Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    bool operator==(const Vector& v) const;
    bool operator!=(const Vector& v) const;

    //static attribute initialization
    static int totalObj();

    //functions friends
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    friend double dist(const Vector&u, const Vector& v);
    friend double norma(const Vector& u);
};

#endif //VECTOR_HPP
