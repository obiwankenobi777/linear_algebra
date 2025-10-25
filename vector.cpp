#include "vetor.hpp"
#include <cmath>

int Vetor::count = 0;

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z), id(++count) {}

Vector::~Vector() { --count; }

Vector& Vector::operator=(const Vector& v) {
  if (this != &v) {
    this->x = v.x; this->y = v.y; this->z = v.z;
  }
  return *this;
}

const Vector Vector::operator+(const Vector& v) const {
  return Vector(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vector Vector::operator-(const Vector& v) const {
  return Vector(this->x - v.x, this->y - v.y, this->z - v.z);
}

bool Vector::operator==(const Vector& v) const {
    constexpr double eps = 1e-9;
    return (std::fabs(x - v.x) < eps &&
            std::fabs(y - v.y) < eps &&
            std::fabs(z - v.z) < eps);
}

bool Vector::operator!=(const Vector& v) const {
  return (this->x != v.x && this->y != v.y && this->z != v.z);
}

int Vector::totalObj() {
  return count;
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
  out << "(" << v.x << ", " << v.y << ", " << v.z <<  ')';
  return out;
}

double norma(const Vector& u) {
  return std::sqrt(u.x*u.x + u.y*u.y + u.z*u.z);
}

double dist(const Vector&u, const Vector& v) {
  double dx = u.x - v.x;
  double dy = u.y - v.y;
  double dz = u.z - v.z;

  return std::sqrt(dx*dx + dy*dy + dz*dz);
}
