#include <iostream>
#include <exception>
#include <stdexcept>

struct A
{
    A() {
       //if(true) throw std :: invalid_argument("error");
    }
    ~A() = default;
};



template <typename T>
class Matrix {
public:
    Matrix() : matr_(nullptr), row_(0), col_(0) {}

    Matrix(size_t rows, size_t cols) : matr_(new T*[rows]), row_(rows), col_(cols) {
        if( row_ == 0 || col_ == 0) {
            throw std :: invalid_argument("invalid arguments");
        }

        size_t allocated_rows = 0;

        try {

            for(; allocated_rows < row_; ++allocated_rows) {
                matr_[allocated_rows] = new T[col_];
            }

            for(size_t i = 0; i < row_; ++i) {
                for(size_t j = 0; j < col_; ++j) {
                    matr_[i][j] = T();
                }
            }
        } catch(std :: exception& ex) {
           ExceptionsCleanup_(allocated_rows);
            throw;
        }
    }
    
    Matrix(size_t rows, size_t cols, T value) : Matrix(rows,cols) {
        size_t initialized_rows = 0;
        try {
            for(; initialized_rows < row_; ++initialized_rows) {
                for(size_t j = 0; j < col_; ++j) {
                    matr_[initialized_rows][j] = value;
                }
            }
        } catch (std :: exception& ex) {
            ExceptionsCleanup_(initialized_rows);
            throw;
        }
    }
private:
    void swap(Matrix& other) {
        std :: swap(matr_,other.matr_);
        std :: swap(row_,other.row_);
        std :: swap(col_,other.col_);
    }

    void ExceptionsCleanup_(size_t sz) {
        for(size_t i = 0; i < sz; ++i) {
                delete[] matr_[i];
            }
            delete[] matr_;
            matr_ = nullptr;
            row_ = 0;
            col_ = 0;
            throw;
    }

    T** matr_;
    size_t row_;
    size_t col_;
};


int main() {
    Matrix<A> matr(3,3);
    return 0;
}