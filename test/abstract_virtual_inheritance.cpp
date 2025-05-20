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
        std :: cout << "circle" << std :: endl;
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
        std :: cout << "rect" << std :: endl;
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

    Geom** arr = new Geom*[5];
    arr[0] = new Rectangle(333,2);


    for(int i = 1; i < 5; ++i) {
        if( i < 3) {
            arr[i] = new Rectangle(3,2);
        } else {
            arr[i] = new Circle(3);
        }
    }

    for(int i = 1; i < 5; ++i) {
        arr[0]->square() -= arr[i]->square();
    }

    std :: cout << arr[0]->square() << std  :: endl;

    for(int i = 1; i < 5; ++i) {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}