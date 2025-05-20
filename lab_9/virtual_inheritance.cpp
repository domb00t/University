#include <iostream>
#include <cmath>

class Geom{
public:
    virtual double& square() = 0;
    virtual ~Geom() {}
};

class Circle : public Geom {
public:
    Circle(double radi = 0) : r_(radi), s_(M_PI * r_ * r_) {
        if(radi < 0) std :: abort();
    }

    virtual double&  square() {
        return s_;
    }

    double& radi() {
        return r_;
    }

private:
    double r_;
    double s_;
};

class Rectangle : public Geom{
public:
    Rectangle(double leng = 0,double widt = 0) : a_(leng), b_(widt), s_(leng * widt) {
        if(leng < 0 || widt < 0) std :: abort();
    }

    virtual double& square() {
        return s_;
    }

    double& leng() {
        return a_;
    }

    double& widt() {
        return b_;
    }

private:
    double a_;
    double b_;
    double s_;
};


int main() {
    size_t sz = 5;
    Geom** arr = new Geom*[sz];

    for(size_t i = 0; i < sz; ++i) {
        arr[i] = new Rectangle(i + 1,i + 1);
    }

    for(size_t i = 0;i < sz; ++i) {
        std :: cout << arr[i]->square() << std :: endl;
    }

    for(size_t i = 0; i < sz; ++i) {
        delete arr[i];
    }
    delete[] arr;
    return 0;
}