#include <iostream>
#include <cmath>

class Complex {
private:
    double re;
    double im;
public:

    Complex() : re(0.0), im(0.0) {}
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

    // useless
    void assign(double _re = 0,double _im = 0) {
        re = _re;
        im = _im;
    }

    void print() {
        if(im < 0) {
            std :: cout << re << im << "i" << std :: endl;
        }else {
            std :: cout << re << "+" << im << "i" << std :: endl;
        }
    }

    Complex add(Complex num) {
        Complex res;
        res.assign();
        re += num.greal();
        im += num.gimage();
        return *this;
    }

    Complex add(double num) {
        re += num;
        return *this;
    }

    double modul() {
        return sqrt(re * re + im * im);
    }

    Complex sub(Complex num) {
        re -= num.greal();
        im -= num.gimage();
        return *this;
    }

    Complex multi(Complex num) {
        re = re * num.re - im * num.im;
        im = re * num.im + im * num.re;
        return *this;
    }

    Complex solution(Complex* lhs,Complex* rhs,size_t length) {
        Complex res;
        bool flag;
        for(size_t index = 0; index < length;++index) {
            flag = true;
            for(size_t index_ = 0; index_ < length;++index_) {
                if(lhs[index].re < rhs[index_].re && lhs[index].im < rhs[index_].im) {
                    flag = false;
                }
            }
            if(flag) res.add(lhs[index]);
        }
        res.print();
        return res;
    }
};




int main() {
    Complex com1(2,3),com2(-1,1);
    com1.add(com2).print();
    com2.sub(com1).print();
    com1.multi(com2).print();
    com1.add(3.8).print();
    std :: cout << com1.modul() << " " <<  com2.modul() << std :: endl;

    int length = 100;

    Complex* arrayx = new Complex[length];
    Complex* arrayy = new Complex[length];

    for(int index = 0;index < length;++index) {
        arrayy[index].assign(pow(-1,index),pow(-1,index));
        arrayx[index].assign();
    }

    // solution in main

    Complex res;
    bool flag;
    for(size_t index = 0; index < length;++index) {
        flag = true;
        for(size_t index_ = 0; index_ < length;++index_) {
            if(arrayy[index].greal() < arrayx[index_].greal() && arrayy[index].gimage() < arrayx[index_].gimage()) {
                flag = false;
            }
        }
        if(flag) res.add(arrayy[index]);
    }
    res.print();

    // as method
    com1.solution(arrayy,arrayx,length);



    delete[] arrayx;
    delete[] arrayy;

    return 0;
}
