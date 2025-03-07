#include <iostream>
#include <cmath>

void swap(int& a,int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

class Matrix{
public:

    Matrix() : ptr(nullptr), row(0), col(0) {}

    Matrix(int rows,int columns) : ptr(nullptr), row(rows), col(columns) {
        if(!(row and col)) {
            std :: cout << "invalid size of Matrix" << std :: endl;
            std :: abort();
        }
        ptr = new int*[row];
        for(int index = 0;index < row;++index) {
            ptr[index] = new int[col];
            for(int _index = 0;_index < col;++_index) {
                ptr[index][_index] = 0;
            }
        }
    }

    int& at(int index_i, int index_j) {
        if((index_i < 0 || index_j < 0) || (index_i >= row || index_j >= col)) {
            std :: cout << "invalid index" << std :: endl;
            std :: abort();
        }
        return ptr[index_i][index_j];
    }


    void print() {
        for(int index = 0;index < row;++index) {
            for(int _index = 0;_index < col; ++_index) {
                std :: cout << ptr[index][_index] << " ";
            }
            std :: cout << std :: endl;
        }
    }

    int rows() {
        return row;
    }

    int cols() {
        return col;
    }

    ~Matrix() {
        if(ptr) {
            for(int index = 0;index < row;++index) {
                delete[] ptr[index];
            }
            delete[] ptr;
        }
    }
    
    // solution as method
    void solution(int b,int c) {
        
        int sum = 0;
        for(int index = 0;index < row;++index) {
            for(int _index = 0;_index < col;++_index) {
                if((index >= (row / 2) - 1 ) && (_index <= index)) {
                if(ptr[index][_index] > c &&  ptr[index][_index] < b) ++sum;
                }
            }
        }
        
        if(sum % 2 == 0) {
            int start = 0;
            int end = row - 1;
            
            while (start < end) {
            swap(ptr[start][start],ptr[end][end]);
                start++;
                end--;
            }
            this->print();
        } else {
            std :: cout << "the number is odd" << std :: endl;
        }
    }

private:
    int** ptr;
    int row;
    int col;

};


int main() {
    Matrix matr(3,3);

    int b = 0;
    int c = 0;

    std :: cin >> b >> c ;

    for(int index = 0;index < matr.rows();++index) {
        for(int _index = 0;_index < matr.cols();++_index) {
            matr.at(index,_index) = index * matr.cols() + _index;
        }
    }

    matr.print();
    
    // solution in main
    int sum = 0;
    for(int index = 0;index < matr.rows();++index) {
        for(int _index = 0;_index < matr.cols();++_index) {
            if((index >= (matr.rows() / 2) - 1 ) && (_index <= index)) {
               if(matr.at(index,_index) > c && matr.at(index,_index) < b) ++sum;
            }
        }
    }

    

    if(sum % 2 == 0) {
        int start = 0;
        int end = matr.rows() - 1;
        
        while (start < end) {
           swap(matr.at(start,start),matr.at(end,end));
            start++;
            end--;
        }

        matr.print();
    } else {
        std :: cout << sum << " the number is odd" << std :: endl;
    }

    matr.solution(b,c);

    return 0;
}
