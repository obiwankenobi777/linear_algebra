#include "vetor.hpp"

int main() {
  Vetor a, b(1), c(1, 2), d(1, 2, 3), u(6, 8, 10), v(34, 58, 29);
  std::cout << a << '\n';
  std::cout << b << ", " << c << ", " << d << '\n';
  std::cout << u << ", " << v << '\n';

  std::cout << norma(a) << ", " << norma(b) << '\n';
  std::cout << norma(c) << ", " << norma(d) << '\n';
  std::cout << "The norma of " << u << " is: " << norma(u) << '\n';
}
