#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
#include <cstring>

struct Student {
    char* surname_;
    int mark_math_;
    int mark_physics_;
    int mark_informatics_;

    Student();
    Student(const char* surname,int mark_math,int mark_physics,int mark_informatics);
    Student(const Student& other);

    void swap(Student& other);
    Student& operator=(const Student& other);

    void reserve(size_t sz);

    friend std :: ostream& operator<<(std :: ostream& os,const Student& student);
    friend std :: istream& operator>>(std :: istream& is, Student& student);
    friend bool operator==(const Student lhs,const Student& rhs);

    ~Student();

};

#endif
