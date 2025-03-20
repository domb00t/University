#include <iostream>

class Vect{
private:
    int size;
    int* array;
public:
    Vect(int length) {
        std :: cout << "created" << std :: endl;
        array = new int[length];
        size = length;
    }

    ~Vect() {
        std :: cout << "deleted" << std :: endl;
        delete[] array;
    }
};

int main() {
    Vect v1(3);

    return 0;
}
