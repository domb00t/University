#include <iostream> 
#include <cmath>

struct Complex {
    double re;
    double im;
};

Complex assign(double re = 0,double im = 0) {
    Complex res;
    res.re = re;
    res.im = im;
    return res;
}


void print(Complex num) {
    if(num.im < 0) {
        std :: cout << num.re << num.im << "i" << std :: endl;
    }else { 
        std :: cout << num.re << "+" << num.im << "i" << std :: endl;
    }
}

Complex add(Complex lhs,Complex rhs) {
    Complex res;
    res = assign();
    res.re = lhs.re + rhs.re;
    res.im = lhs.im + rhs.im;
    return res;
}

Complex add(Complex lhs,double x) {
    Complex res;
    res = assign();
    res.re = lhs.re + x;
    return res;
}

Complex add(double x,Complex rhs) {
    Complex res;
    res = assign();
    res.re = x + rhs.re;
    return res;
}

double modul(Complex num) {
    return sqrt(num.re * num.re + num.im * num.im);
}

Complex sub(Complex lhs,Complex rhs) {
    Complex res;
    res = assign();
    res.re = lhs.re - rhs.re;
    res.im = lhs.im - rhs.im;
    return res;
}

Complex multi(Complex lhs,Complex rhs) {
    Complex res;
    res = assign();
    res.re = lhs.re * rhs.re - lhs.im * rhs.im;
    res.im = lhs.re * rhs.im + lhs.im * rhs.re;
    return res;
}

Complex solution(Complex* lhs,Complex* rhs,int length) {
    Complex res;
    bool flag;
    for(int index = 0; index < length;++index) {
        flag = true;
        for(int index_ = 0; index_ < length;++index_) {
            if(lhs[index].re < rhs[index_].re && lhs[index].im < rhs[index_].im) {
                flag = false;
            }
        }
        if(flag) res = add(res,lhs[index]);
        print(res);
    }
    return res;
}


int main() {
    int legnth = 100;
    
    Complex* arrayx = new Complex[legnth];
    Complex* arrayy = new Complex[legnth];

    for(int index = 0;index < legnth;++index) {
        arrayy[index] = assign(pow(-1,index),pow(-1,index));
        arrayx[index] = assign();
    }

    print(solution(arrayy,arrayx,legnth));

    delete[] arrayx;
    delete[] arrayy;

    return 0;
}