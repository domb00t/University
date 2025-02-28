#include <cstdlib>
#include <iostream>

class Vector {
public:
    Vector() : arr(nullptr), sz(0) {}

    Vector(int sz) : arr(nullptr), sz(sz) {
        if(sz < 1) {
            std :: cout << "invalid size" << std :: endl;
        } else {
            arr = new int[sz];
            for(int index = 0;index < sz;++index) {
                arr[index] = index + 1;
            }
        }
    }

    int& at(int index) {
        if(index < 0 || index >= sz) {
            std :: cout << "out of range" << std :: endl;
            std :: exit(1);
        }
        return arr[index];
    }

    int size() {
        return sz;
    }

    //solution as method
    void sort() {
        bool flag = true;
        int tmp;
        while(flag) {
            flag = false;
            for(int index = 0;index < sz - 1;++index) {
               if(arr[index] < arr[index + 1]) {
                   tmp = arr[index + 1];
                   arr[index + 1 ] = arr[index];
                   arr[index] = tmp;
                   flag = true;
               }
            }
        }
    }

    void print() {
        for(int index = 0;index < sz;++index) {
            std :: cout << arr[index] << "\t";
        }
        std :: cout <<std :: endl;
    }

    ~Vector() {
        if(arr) {
            delete[] arr;
        }
    }
private:
    int* arr;
    int sz;

};

int main() {
    int size;
    std :: cin >> size;
    Vector v1(size);
    v1.sort();
    v1.print();

    Vector v2(size);

    //solution as function in main
    bool flag = true;
    int tmp;
    while(flag) {
        flag = false;
        for(int index = 0;index < v2.size() - 1;++index) {
           if(v2.at(index)< v2.at(index + 1)) {
               tmp = v2.at(index + 1);
               v2.at(index + 1) = v2.at(index);
               v2.at(index) = tmp;
               flag = true;
           }
        }
    }
    v2.print();



    return 0;
}
