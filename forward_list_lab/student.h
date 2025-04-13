#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
#include <cstring>

class Student {
public:

    Student();
    Student(const char*,int,int,int);
    Student(const Student&);
    ~Student();

    
    Student& operator=(const Student&);
    friend std :: ostream& operator<<(std :: ostream&, const Student&);
    friend std :: istream& operator>>(std :: istream&, Student&);
    friend bool operator==(const Student&,const Student&);

private:

    void swap(Student&);

    char* surname_;
    size_t cap_;

    int mark_math_;
    int mark_physics_;
    int mark_informatics_;
};

#endif
