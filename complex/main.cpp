#include <iostream>
#include <cmath>

struct Complex {
private:
    double re;
    double im;
public:
    Complex() : re(0), im(0) {}
    Complex(double re,double im) : re(re), im(im) {}

    void sreal(double re_) {
        re = re_;
    }
    void simage(double im_) {
        im = im_;
    }
    double greal() {
        return re;
    }
    double gimage() {
        return im;
    }
    void print() {
        if(im < 0) {
            std :: cout << re << im << "i" << std :: endl;
        }else {
            std :: cout << re << "+" << im << "i" << std :: endl;
        }
    }
};

Complex* init(size_t sz) {
    Complex* ptr;
    sz ? ptr =  new Complex[sz] : ptr = nullptr;
    return ptr;
}

Complex add(Complex lhs,Complex rhs) {
    Complex res;
    res.sreal(lhs.greal() + rhs.greal());
    res.simage(lhs.gimage() + rhs.gimage());
    return res;
}

void del(Complex* array) {
    if(array) {
        delete[] array;
    }
}

Complex sum(Complex* lhs,Complex* rhs,size_t length) {
    Complex res;
    bool flag;
    for(size_t index = 0; index < length;++index) {
        flag = true;
        for(size_t index_ = 0; index_ < length;++index_) {
            if(lhs[index].greal() < rhs[index_].greal() && lhs[index].gimage() < rhs[index_].gimage()) {
                flag = false;
            }
        }
        if(flag) res = add(res,lhs[index]);
        res.print();
    }
    return res;
}

int main() {
    size_t length = 100;

    Complex* arrayx = init(length);
    Complex* arrayy = init(length);

    for(size_t index = 0; index < length;++index) {
        arrayy[index].sreal(pow(-1,index));
        arrayy[index].simage(pow(-1,index));
    }

    for(size_t index = 0; index < length;++index) {
        arrayx[index].sreal(0);
        arrayx[index].simage(0);
    }


    sum(arrayy,arrayx,length).print();

    del(arrayx);
    del(arrayy);


    return 0;
}
