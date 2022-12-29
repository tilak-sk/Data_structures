#include <iostream>

const int defaultSize = 10;
const float defaultValue = 0.0;

class CppArray {
 public:
  // Constructor
  CppArray(int size = defaultSize, float initvalue = defaultValue)
      : size_(size) {
    array_ = new float[size_];
    for (int i = 0; i < size_; i++) {
      array_[i] = initvalue;
    }
  }

  // Copy constructor
  CppArray(const CppArray& cp2) : size_(cp2.size_) {
    array_ = new float[size_];
    for (int i = 0; i < size_; i++) {
      array_[i] = cp2.array_[i];
    }
  }

  // Assignment operator
  CppArray& operator=(const CppArray& cp2) {
    if (this != &cp2) {
      delete[] array_;
      size_ = cp2.size_;
      array_ = new float[size_];
      for (int i = 0; i < size_; i++) {
        array_[i] = cp2.array_[i];
      }
    }
    return *this;
  }

  // Destructor
  ~CppArray() { delete[] array_; }

  // Subscript operator with range checking
  float& operator[](int i) {
    if (i < 0 || i >= size_) {
      std::cerr << "Error: index out of range" << std::endl;
      exit(0);
    }
    return array_[i];
  }

  // GetSize function
  int GetSize() { return size_; }

  // Friend function to overload the << operator for printing
  friend std::ostream& operator<<(std::ostream& os, const CppArray& cp) {
    for (int i = 0; i < cp.size_; i++) {
      os << cp.array_[i] << " ";
    }
    return os;
  }

  // Friend function to overload the >> operator for reading
  friend std::istream& operator>>(std::istream& is, CppArray& cp) {
    for (int i = 0; i < cp.size_; i++) {
      is >> cp.array_[i];
    }
    return is;
  }

 private:
  int size_;
  float* array_;
};

int main() {
  // Create an array with size 5 and initial value 1.0
  CppArray cp1(5, 1.0);

  // Print the array
  std::cout << cp1 << std::endl;

  // Assign cp1 to cp2
  CppArray cp2;
  cp2 = cp1;

  // Print cp2
  std::cout << cp2 << std::endl;

  // Read values into cp2
  std::cin >> cp2;

  // Print cp2 again
  std::cout << cp2 << std::endl;

  // Access element at index 3 of cp2
}