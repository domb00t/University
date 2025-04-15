#include "student.h"

Student::Student() : surname_(nullptr), 
                     cap_(0), 
                     mark_math_(0), 
                     mark_physics_(0), 
                     mark_informatics_(0) {}

Student::Student(const char * str, int mmark, int pmark, int imark) : surname_(new char[strlen(str) + 1]), 
                                                                      cap_(strlen(str) + 1), 
                                                                      mark_math_(mmark), 
                                                                      mark_physics_(pmark), 
                                                                      mark_informatics_(imark) {
    std :: memcpy(surname_,str,cap_);
}

Student::Student(const Student& other) : surname_(new char[other.cap_]), 
                                         cap_(other.cap_), 
                                         mark_math_(other.mark_math_), 
                                         mark_physics_(other.mark_physics_), 
                                         mark_informatics_(other.mark_informatics_) {
    std :: memcpy(surname_,other.surname_,cap_);
}

Student :: ~Student() {
    if(surname_) {
        delete[] surname_;
    }
}

int Student::mark_math() {
    return mark_math_;
}

int Student::mark_phys() {
    return mark_physics_;
}

int Student::mark_info() {
    return mark_informatics_;
}

int Student::mark_math() const {
    return mark_math_;
}

int Student::mark_phys() const  {
    return mark_physics_;
}

int Student::mark_info() const {
    return mark_informatics_;
}

Student& Student::operator=(const Student& other) {
    if(this == &other) return *this;
    Student copy(other);
    swap(copy);
    return *this;
}   

void Student::swap(Student& other) {
    
    char* tempSurname = surname_;
    surname_ = other.surname_;
    other.surname_ = tempSurname;

    size_t tempCap = cap_;
    cap_ = other.cap_;
    other.cap_ = tempCap;

    int tempMath = mark_math_;
    mark_math_ = other.mark_math_;
    other.mark_math_ = tempMath;

    int tempPhysics = mark_physics_;
    mark_physics_ = other.mark_physics_;
    other.mark_physics_ = tempPhysics;

    int tempInformatics = mark_informatics_;
    mark_informatics_ = other.mark_informatics_;
    other.mark_informatics_ = tempInformatics;
}

std::ostream &operator<<(std::ostream& os, const Student& student) {
    os << "|surname: " << student.surname_ << "|mark_math: " << student.mark_math_ << "|mark_physics: " << student.mark_physics_ << "|mark_informatics: " << student.mark_informatics_ << "|";
    return os;
}

std::istream &operator>>(std::istream& is, Student& student) {
    char buffer[512];

    std :: cout << "enter surname: ";
    is.ignore();
    is.getline(buffer,512);

    std :: cout << "enter marks: ";
    is >> student.mark_math_ >> student.mark_physics_ >> student.mark_informatics_;

    Student tmp(buffer,student.mark_math_,student.mark_physics_,student.mark_informatics_);
    student =  tmp;

    is.clear();
    return is;
}

bool operator==(const Student& lhs, const Student& rhs) {
    return strcmp(lhs.surname_, rhs.surname_) == 0 &&
           lhs.mark_math_ == rhs.mark_math_ &&
           lhs.mark_physics_ == rhs.mark_physics_ &&
           lhs.mark_informatics_ == rhs.mark_informatics_;
}
