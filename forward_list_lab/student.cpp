#include "student.h"
#include <cstring>
#include <istream>

void Student :: reserve(size_t sz) {
    if(!surname_) {
        surname_ = new char[sz + 1];
        surname_[sz] = '\0';
    } else {
        std :: cout << "bad_alloc" << std :: endl;
        std :: abort();
    }
}

std :: ostream& operator<<(std :: ostream& os,const Student& student) {
    os << "surname: " << student.surname_ << " math mark: " << student.mark_math_ << " physics mark: " << student.mark_physics_ << " informatics mark: " << student.mark_informatics_;
    return os;
}

std :: istream& operator>>(std :: istream& is, Student& student) {
    is.getline(student.surname_,strlen(student.surname_));
    is >> student.mark_math_ >> student.mark_physics_ >> student.mark_informatics_;
    return is;
}

Student::Student()
    : surname_(nullptr), mark_math_(0), mark_physics_(0), mark_informatics_(0) {}

Student::Student(const char* surname, int mark_math, int mark_physics, int mark_informatics)
    : surname_(nullptr), mark_math_(mark_math), mark_physics_(mark_physics), mark_informatics_(mark_informatics) {
    reserve(strlen(surname));
    memcpy(surname_, surname, strlen(surname) + 1);
}

Student::Student(const Student& other)
    : surname_(nullptr), mark_math_(other.mark_math_), mark_physics_(other.mark_physics_), mark_informatics_(other.mark_informatics_) {
    reserve(strlen(other.surname_));
    memcpy(surname_, other.surname_, strlen(other.surname_) + 1);
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        Student temp(other);
        swap(temp);
    }
    return *this;
}

void Student::swap(Student& other) {
    char* tmp = surname_;
    surname_ = other.surname_;
    other.surname_ = tmp;

    int tempMark;

    tempMark = mark_math_;
    mark_math_ = other.mark_math_;
    other.mark_math_ = tempMark;

    tempMark = mark_physics_;
    mark_physics_ = other.mark_physics_;
    other.mark_physics_ = tempMark;

    tempMark = mark_informatics_;
    mark_informatics_ = other.mark_informatics_;
    other.mark_informatics_ = tempMark;
}

bool operator==(const Student lhs,const Student& rhs) {
    if (lhs.surname_ == nullptr || rhs.surname_ == nullptr) return false;
    return std::strcmp(lhs.surname_, rhs.surname_) == 0 &&
           lhs.mark_math_ == rhs.mark_math_ &&
           lhs.mark_physics_ == rhs.mark_physics_ &&
           lhs.mark_informatics_ == rhs.mark_informatics_;
}



Student :: ~Student() {
    if(surname_) {
        delete[] surname_;
    }
}
