#include <iostream>

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}


class Matrix {
public:
  Matrix() : ptr(nullptr), row(0), col(0) {}

  Matrix(int rows, int columns,int value = 0) : ptr(nullptr), row(rows), col(columns) {
    if (!(row and col)) {
      std ::cout << "invalid size of Matrix" << std ::endl;
      std ::abort();
    }
    ptr = new int *[row];
    for (int index = 0; index < row; ++index) {
      ptr[index] = new int[col];
      for (int _index = 0; _index < col; ++_index) {
        ptr[index][_index] = value * k;
      }
    }
  }

  Matrix(const Matrix& other) : ptr(nullptr), row(other.row), col(other.col) {
      if (!(row and col)) {
        std ::cout << "invalid size of Matrix" << std ::endl;
        std ::abort();
      }
      ptr = new int *[row];
      for (int index = 0; index < row; ++index) {
        ptr[index] = new int[col];
        for (int _index = 0; _index < col; ++_index) {
          ptr[index][_index] =  other.ptr[index][_index];
        }
      }
  }

  int &at(int index_i, int index_j) {
    if ((index_i < 0 || index_j < 0) || (index_i >= row || index_j >= col)) {
      std ::cout << "invalid index" << std ::endl;
      std ::abort();
    }
    return ptr[index_i][index_j];
  }

  int at(int index_i, int index_j) const {
    if ((index_i < 0 || index_j < 0) || (index_i >= row || index_j >= col)) {
      std ::cout << "invalid index" << std ::endl;
      std ::abort();
    }
    return ptr[index_i][index_j];
  }

  void print() {
    for (int index = 0; index < row; ++index) {
      for (int _index = 0; _index < col; ++_index) {
        std ::cout << ptr[index][_index] << " ";
      }
      std ::cout << std ::endl;
    }
  }

  int rows() { return row; }

  int cols() { return col; }

  int rows() const { return row; }

  int cols() const { return col; }



  ~Matrix() {
    if (ptr) {
      for (int index = 0; index < row; ++index) {
        delete[] ptr[index];
      }
      delete[] ptr;
    }
  }

  int max() {
      int max = ptr[0][0];
      for(int index = 0;index < row; ++index) {
        for(int _index = 1;_index < col; ++_index) {
            if(max < ptr[index][_index]) max = ptr[index][_index];
        }
      }
      return max;
  }

  static int& min_() {
    return min;
  }


  static int& k_() {
    return k;
  }

  Matrix& assign(const Matrix& other) {
      Matrix copy(other);
      matr_swap(copy);
      return  *this;
  }



private:

    void matr_swap(Matrix& other) {
        int ** ptr_tmp;
        ptr_tmp = other.ptr;
        other.ptr = this->ptr;
        this->ptr = ptr_tmp;
        swap(row,other.row);
        swap(col,other.col);
    }

    int **ptr;
    int row;
    int col;
    static int min;
    static int k;
};

int Matrix :: min = 3;
int Matrix :: k = 3;

class Derived : public Matrix {
  public:
  using Matrix :: Matrix;
  int search() {
    int min = at(0,0);
    if(cols() != rows()) {
      std :: abort();
    } else {
      for(int index = 1; index < rows(); ++index) {
        if(at(index,index) < min) min = at(index,index);
      }
    }
    return min;
  }
};

int main() {
  Derived mat1(3,3);
  for(int i = 0; i < mat1.rows(); ++i) {
    for(int j =0; j < mat1.cols(); ++j) {
      std :: cin >> mat1.at(i,j);
    }
  }
  mat1.print();
  std :: cout << mat1.search() << std :: endl;
  return 0;
}
