#include <cstdlib>
#include <iostream>

class Complex {
public:
    Complex(double re = 0.0,double im = 0.0) : re(re), im(im) {}

    void real(double re) {
        this->re = re;
    }
    int real() const {
        return re;
    }
    void imag(double im) {
        this->im = im;
    }
    int imag() const {
        return im;
    }

    Complex& operator=(const Complex& other) {
        Complex copy(other);
        swap(copy);
        return *this;
    }

    Complex& operator+=(const Complex& other) {
        re += other.re;
        im += other.im;
        return *this;
    }


    friend std :: istream& operator>>(std :: istream& is,Complex& num);
    friend std :: ostream& operator<<(std :: ostream& os,const Complex& num);

    friend Complex operator+(const Complex& lhs,const Complex& rhs);
    friend bool operator==(const Complex& lhs,const Complex& rhs);

private:
    void swap(double& lhs,double& rhs) {
        double tmp = lhs;
        lhs = rhs;
        rhs = tmp;
    }
    void swap(Complex& other) {
        swap(re,other.re);
        swap(im,other.im);
    }
    double re;
    double im;
};

class Vector {
public:
    Vector() : arr(nullptr), sz(0) {}

    Vector(size_t sz) : arr(nullptr), sz(sz) {
        if(sz < 1) {
            std :: cout << "invalid size" << std :: endl;
        } else {
            arr = new Complex[sz];
            for(size_t index = 0;index < sz;++index) {
                arr[index] = Complex();
            }
        }
    }

    Vector(const Vector& other) : arr(nullptr), sz(other.sz) {
        if(arr) {
            for(size_t index = 0;index < sz;++index) {
                arr[index] = other[index];
            }
        } else {
            std :: cout << "invalid siz" << std :: endl;
            std :: abort();
        }
    }

    Complex& operator[](size_t index) {
        if(index < 0 || index >= sz) {
            std :: cout << "out of range" << std :: endl;
            std :: exit(1);
        }
        return arr[index];
    }

    Complex operator[](size_t index) const {
        if(index < 0 || index >= sz) {
            std :: cout << "out of range" << std :: endl;
            std :: exit(1);
        }
        return arr[index];
    }

    size_t size() const {
        return sz;
    }

    void print() const {
        for(size_t index = 0;index < sz;++index) {
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
    Complex* arr;
    size_t sz;

};

int search(const Vector& v1,const Vector& v2) {
    int count = 0;
    if(v1.size() != v1.size()) return count;
    for(size_t index = 0; index < v1.size(); ++index) {
        if(v1[index] ==v2[index]) ++count;
    }
    return count;
}


Vector solution(const Vector& vect) {
    int count = 0;
    for(size_t index = 0;index < vect.size();++index) {
        if(vect[index].real() > 0 && vect[index].imag() > 0) ++count;
    }
    std :: cout << count << std :: endl;
    Vector res(count);
    size_t j = 0;
    while(j < res.size()) {
        for(size_t index = 0;index < vect.size();++index) {
            if(vect[index].real() > 0 && vect[index].imag() > 0) {
                res[j] = vect[index];
                ++j;
            }
        }
    }
    return res;
}

int main() {
    size_t size = 0;
    std :: cout << "enter size: " << std :: endl;
    std :: cin >> size;
    Vector v1(size), v2(size);

    std :: cout << "enter v1[i]: " << std :: endl;
    for(size_t index = 0;index < v1.size(); ++ index) {
        std :: cin >> v1[index];
    }

    std :: cout << "enter v2[i]: " << std :: endl;
    for(size_t index = 0;index < v2.size(); ++ index) {
        std :: cin >> v2[index];
    }

    v1.print();
    v2.print();

    std :: cout << search(v1,v2) << std :: endl;

    Vector v3(size);
    for(size_t index = 0;index < v3.size();++index) {
        std :: cin >> v3[index];
    }

    Vector res(solution(v3));

    res.print();

    return 0;
}

std::istream &operator>>(std::istream &is, Complex &num) {
    is >> num.re >> num.im;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Complex &num) {
    num.im < 0 ? os << num.re << num.im << "i"  : os << num.re << "+" << num.im << "i";
    return os;
}

Complex operator+(const Complex &lhs, const Complex &rhs)
{
    Complex copy(lhs);
    return copy += rhs;
}

bool operator==(const Complex &lhs, const Complex &rhs) {
    return (lhs.re == rhs.re && lhs.im == rhs.im);
}
