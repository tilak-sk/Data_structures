#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
 public:
  Polynomial(int degree, const vector<int>& coeffs);

  int getDegree() const { return degree_; }
  int getCoeff(int i) const { return coeffs_[i]; }
  double evaluate(double x) const;
  Polynomial add(const Polynomial& other) const;
  Polynomial subtract(const Polynomial& other) const;
  Polynomial multiply(const Polynomial& other) const;
  Polynomial simplify() const;

 private:
  int degree_;
  vector<int> coeffs_;
};

Polynomial::Polynomial(int degree, const vector<int>& coeffs) : degree_(degree) {
  // Copy nonzero coefficients into the coeffs_ array
  for (int i = 0; i <= degree; i++) {
    if (coeffs[i] != 0) {
      coeffs_.push_back(coeffs[i]);
    }
  }
}

double Polynomial::evaluate(double x) const {
  // Evaluate the polynomial using the Horner's method
  double result = 0.0;
  for (int i = degree_; i >= 0; i--) {
    result = result * x + coeffs_[i];
  }
  return result;
}

Polynomial Polynomial::add(const Polynomial& other) const {
  // Add two polynomials by adding their corresponding coefficients
  int degree = max(degree_, other.degree_);
  vector<int> coeffs(degree + 1, 0);
  for (int i = 0; i <= degree; i++) {
    coeffs[i] += getCoeff(i) + other.getCoeff(i);
  }
  return Polynomial(degree, coeffs);
}

Polynomial Polynomial::subtract(const Polynomial& other) const {
  // Subtract two polynomials by subtracting their corresponding coefficients
  int degree = max(degree_, other.degree_);
  vector<int> coeffs(degree + 1, 0);
  for (int i = 0; i <= degree; i++) {
    coeffs[i] += getCoeff(i) - other.getCoeff(i);
  }
  return Polynomial(degree, coeffs);
}

Polynomial Polynomial::multiply(const Polynomial& other) const {
  // Multiply two polynomials by multiplying their corresponding coefficients
  int degree = degree_ + other.degree_;
  vector<int> coeffs(degree + 1, 0);
  for (int i = 0; i <= degree_; i++) {
    for (int j = 0; j <= other.degree_; j++) {
      coeffs[i + j] += getCoeff(i) * other.getCoeff(j);
    }
  }
  return Polynomial(degree, coeffs);
}

Polynomial Polynomial::simplify() const {
  // Simplify the polynomial by removing any zero-coefficient terms
  int degree = degree_;
  while (degree > 0 && coeffs_[degree] == 0) {
    degree--;
  }
  return Polynomial(degree, coeffs_);
}

int main() {
  // Create a polynomial and evaluate it at x = 2.0
  Polynomial p(2, {3, 2, -1});
  double x = 2.0;
  cout << p.evaluate(x) << endl;  // prints "11"

  // Add two polynomials
  Polynomial q(1, {4, -3});
  Polynomial r = p.add(q);
  cout << r.getDegree() << endl;  // prints "2"
  cout << r.getCoeff(0) << endl;  // prints "1"
  cout << r.getCoeff(1) << endl;  // prints "5"
  cout << r.getCoeff(2) << endl;  // prints "3"

  // Multiply two polynomials
  Polynomial s = p.multiply(q);
  cout << s.getDegree() << endl;  // prints "3"
  cout << s.getCoeff(0) << endl;  // prints "-3"
  cout << s.getCoeff(1) << endl;  // prints "1"
  cout << s.getCoeff(2) << endl;  // prints "11"
  cout << s.getCoeff(3) << endl;  // prints "6"

  // Simplify a polynomial
  Polynomial t(3, {0, 0, 3, 0});
  Polynomial u = t.simplify();
  cout << u.getDegree() << endl;  // prints "1"
  cout << u.getCoeff(0) << endl;  // prints "0"
  cout << u.getCoeff(1) << endl;  // prints "3"
  cout << u.getCoeff(2) << endl;  // prints "0"

  return 0;
}
