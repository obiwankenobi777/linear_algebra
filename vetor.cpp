#include "vetor.hpp"
#include <cmath>

int Vetor::count = 0;

Vetor::Vetor(double x, double y, double z) : x(x), y(y), z(z), id(++count) {}

Vetor::~Vetor() { --count; }

Vetor& Vetor::operator=(const Vetor& v) {
  if (this != &v) {
    this->x = v.x; this->y = v.y; this->z = v.z;
  }
  return *this;
}

Vetor Vetor::operator+(const Vetor& v) const {
  return Vetor(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vetor Vetor::operator-(const Vetor& v) const {
  return Vetor(this->x - v.x, this->y - v.y, this->z - v.z);
}

bool Vetor::operator==(const Vetor& v) const {
    constexpr double eps = 1e-9;
    return (std::fabs(x - v.x) < eps &&
            std::fabs(y - v.y) < eps &&
            std::fabs(z - v.z) < eps);
}

bool Vetor::operator!=(const Vetor& v) const {
  return (this->x != v.x && this->y != v.y && this->z != v.z);
}

int Vetor::totalObj() {
  return count;
}

std::ostream& operator<<(std::ostream& out, const Vetor& v) {
  out << "(" << v.x << ", " << v.y << ", " << v.z <<  ')';
  return out;
}

double norma(const Vetor& u) {
  return std::sqrt(u.x*u.x + u.y*u.y + u.z*u.z);
}

double dist(const Vetor&u, const Vetor& v) {
  double dx = u.x - v.x;
  double dy = u.y - v.y;
  double dz = u.z - v.z;

  return std::sqrt(dx*dx + dy*dy + dz*dz);
}
