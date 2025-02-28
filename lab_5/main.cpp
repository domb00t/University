#include <iostream>

class Matrix{
public:

    Matrix() : ptr(nullptr), row(0), col(0) {}

    Matrix(int rows,int columns) : ptr(nullptr), row(rows), col(columns) {
        for(int index = 0;index < row;++index) {
            ptr[index] = new int[col];
            for(int _index = 0;_index < col;++_index) {
                ptr[index][_index] = index + _index;
            }
        }
    }

    ~Matrix() {
        if(ptr) {
            for(int index = 0;index < row;++index) {
                delete[] ptr[index];
            }
            delete[] ptr;
        }
    }

private:
    int** ptr;
    int row;
    int col;

};

int main() {
    return 0;
}
