#ifndef VETOR_HPP
#define VETOR_HPP

#include <iostream>

class Vetor {
  private:
    double x, y, z;
    int id;
    static int count;

  public:
    //default constructor
    Vetor(double x=0.0, double y=0.0, double z=0.0);

    //copy constructors
    Vetor(const Vetor& v) : x(v.x), y(v.y), z(v.z), id(++count) {}

    //desctructor
    ~Vetor();

    //operators overloading
    Vetor& operator=(const Vetor& v);
    Vetor operator+(const Vetor& v) const;
    Vetor operator-(const Vetor& v) const;
    bool operator==(const Vetor& v) const;
    bool operator!=(const Vetor& v) const;

    //static attribute initialization
    static int totalObj();

    //functions friends
    friend std::ostream& operator<<(std::ostream& out, const Vetor& v);
    friend double dist(const Vetor&u, const Vetor& v);
    friend double norma(const Vetor& u);
};

#endif //VETOR_HPP
