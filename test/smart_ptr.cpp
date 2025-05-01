#include <iostream>

template<typename T>
class Smart_ptr{
public:
    Smart_ptr() : ptr_(nullptr) {}
    Smart_ptr(T* ptr) : ptr_(ptr) {}
    Smart_ptr(const T* ptr) 
    Smart_ptr& operator=(const Smart_ptr& ptr) 
    ~Smart_ptr() {
        if(ptr_) {
            delete[] ptr_;
        }
    }
private:
    T* ptr_;

};

int main() {
    Smart_ptr<char> = new char[100];
    return 0;
}