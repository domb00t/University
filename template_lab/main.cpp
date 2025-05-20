#include <iostream>

class Complex{
public:
  Complex() : re_(0.0), im_(0.0) {}
  Complex(double real,double imag) : re_(real), im_(imag) {}
  Complex(const Complex& other) : re_(other.re_), im_(other.im_) {}
  
  Complex& operator=(const Complex& other) {
    if(this == &other) return *this;
    Complex copy(other);
    swap(copy);
    return *this;
  }

  Complex& operator+=(const Complex& other) {
    re_ += other.re_;
    im_ += other.im_;
    return *this;
  }

  Complex& operator-=(const Complex& other) {
    re_ -= other.re_;
    im_ -= other.im_;
    return *this;
  }

  friend Complex operator+(const Complex& lhs, const Complex& rhs);
  friend Complex operator-(const Complex& lhs, const Complex& rhs);
  friend bool operator==(const Complex& lhs, const Complex& rhs);
  friend bool operator!=(const Complex& lhs, const Complex& rhs);
  friend std :: istream& operator>>(std :: istream& is, Complex& complex);
  friend std :: ostream& operator<<(std :: ostream& os, const Complex& complex);

  ~Complex() = default;
private:
  double re_;
  double im_;

  void swap(Complex& other) {
    std :: swap(re_,other.re_);
    std :: swap(im_,other.im_);
  }
};

Complex operator+(const Complex& lhs, const Complex& rhs) {
  Complex copy(lhs);
  return copy += rhs;
}

Complex operator-(const Complex &lhs, const Complex &rhs) {
  Complex copy(lhs);
  return copy -= rhs;
}

bool operator==(const Complex& lhs, const Complex& rhs) {
  return (lhs.re_ == rhs.re_ && lhs.im_ == rhs.im_);
}

bool operator!=(const Complex& lhs, const Complex& rhs) {
  return !(lhs == rhs);
}

std :: istream& operator>>(std :: istream& is, Complex& complex) {
  is >> complex.re_ >> complex.im_;
  return is;
}

std :: ostream& operator<<(std :: ostream& os, const Complex& complex) {
  if(complex.im_ < 0) {
    std :: cout << complex.re_ << complex.im_ << "i";
  } else {
    std :: cout << complex.re_ << "+"<< complex.im_ << "i";
  }
  return os;
}

template <typename T>
class Matrix
{
public:
  Matrix() : ptr(nullptr), row(0), col(0) {}

  Matrix(int rows, int columns, T value = T()) : ptr(nullptr), row(rows), col(columns)
  {
    if (!(row and col))
    {
      std ::cout << "invalid size of Matrix" << std ::endl;
      std ::abort();
    }
    ptr = new T *[row];
    for (int index = 0; index < row; ++index)
    {
      ptr[index] = new T[col];
      for (int _index = 0; _index < col; ++_index)
      {
        ptr[index][_index] = value;
      }
    }
  }

  Matrix(const Matrix &other) : ptr(nullptr), row(other.row), col(other.col)
  {
    if (!(row and col))
    {
      std ::cout << "invalid size of Matrix" << std ::endl;
      std ::abort();
    }
    ptr = new T *[row];
    for (int index = 0; index < row; ++index)
    {
      ptr[index] = new T[col];
      for (int _index = 0; _index < col; ++_index)
      {
        ptr[index][_index] = other.ptr[index][_index];
      }
    }
  }

  T &at(int index_i, int index_j)
  {
    if ((index_i < 0 || index_j < 0) || (index_i >= row || index_j >= col))
    {
      std ::cout << "invalid index" << std ::endl;
      std ::abort();
    }
    return ptr[index_i][index_j];
  }

  T at(int index_i, int index_j) const {
    if ((index_i < 0 || index_j < 0) || (index_i >= row || index_j >= col))
    {
      std ::cout << "invalid index" << std ::endl;
      std ::abort();
    }
    return ptr[index_i][index_j];
  }
  

  void print()
  {
    for (int index = 0; index < row; ++index)
    {
      for (int _index = 0; _index < col; ++_index)
      {
        std ::cout << ptr[index][_index] << " ";
      }
      std ::cout << std ::endl;
    }
  }

  int rows() { return row; }

  int cols() { return col; }

  int rows() const  { return row; }

  int cols() const  { return col; }

  ~Matrix()
  {
    if (ptr)
    {
      for (int index = 0; index < row; ++index)
      {
        delete[] ptr[index];
      }
      delete[] ptr;
    }
  }

  Matrix &operator=(const Matrix &other)
  {
    Matrix copy(other);
    swap(copy);
    return *this;
  }

private:
  void swap(Matrix &other)
  {
    /*
    int ** ptr_tmp;
    ptr_tmp = other.ptr;
    other.ptr = this->ptr;
    this->ptr = ptr_tmp;
    swap(row,other.row);
    swap(col,other.col);
    */

    std ::swap(ptr, other.ptr);
    std ::swap(row, other.row);
    std ::swap(col, other.col);
  }

  T **ptr;
  int row;
  int col;
};

template<typename T>
void input(Matrix<T>& matr) {
  for(size_t i = 0; i < matr.rows(); ++i) {
    for(size_t j = 0; j < matr.cols(); ++j) {
      std :: cin >> matr.at(i,j);
    }
  }
  matr.print();
}

template<typename T>
int search(const Matrix<T>& matr,T sample) {
  for(size_t i = 0; i < matr.rows(); ++i) {
    for(size_t j = 0; j < matr.cols(); ++j) {
      if(matr.at(i,j) != sample) return i;
    }
  }
  return -1;
}

template<typename T>
bool solution(const Matrix<T>& matr,T sample) {
  if(search<T>(matr,sample) != -1) {
    std :: cout << search<T>(matr,sample) << " ";
    return true;
  }
  return false;
}




int main()
{
  int iSample;
  std :: cin >> iSample;
  Matrix<int> iMatr(2,2);

  input<int>(iMatr);

  if(solution<int>(iMatr,iSample)) {
    std :: cout << "the first matching line is" << std :: endl;
  } else {
    std :: cout << "There are no rows with no equal element" << std :: endl;
  }


  std :: cout << "-----------------------------" << std :: endl;

  Complex comSample;
  std :: cin >> comSample;
  Matrix<Complex> comMatr(2,2);

  input<Complex>(comMatr);

  if(solution<Complex>(comMatr,comSample)) {
    std :: cout << "the first matching line is" << std :: endl;
  } else {
    std :: cout << "There are no rows with no equal element" << std :: endl;
  }

  return 0;
}

