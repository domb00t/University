#include <iostream>
#include <list>

#include "student.h"

bool OnlyOneFour(const Student& student) {
    size_t count = 0;
    if(student.mark_math() == 4) ++count;
    if(student.mark_phys() == 4) ++count;
    if(student.mark_info() == 4) ++count;
    return (count == 1);
}

void Solution(const std :: list<Student>& list) {
    for(std :: list<Student> :: const_iterator it  = list.begin(); it != list.end(); ++it) {
        if(OnlyOneFour(*it)) std :: cout << *it;
    }
}

int main() {
    size_t size = 0;
    std :: cin >> size;
    std :: list<Student> list;

    for(size_t i = 0; i < size; ++i) {
        list.push_back(Student());
    }

    for(std :: list<Student> :: iterator it  = list.begin(); it != list.end(); ++it) {
        std :: cin >> *it;
    }

    for(std :: list<Student> :: iterator it  = list.begin(); it != list.end(); ++it) {
        std :: cout << *it << std :: endl;
    }

    std :: cout << "------------------------------------------------------------" << std :: endl;
    Solution(list);

    return 0;
}