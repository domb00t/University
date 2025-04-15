#include <iostream>

#include "linked_list.h"
#include "student.h"

bool onlyOneFour(const Student& student) {
    size_t count = 0;
    if(student.mark_math() == 4) ++count;
    if(student.mark_phys() == 4) ++count;
    if(student.mark_info() == 4) ++ count;
    return (count == 1);
}

void solution(const List& list) {
    for(int i = 0;i < list.size(); ++i) {
        if(onlyOneFour(list[i])) std :: cout << list[i] << std :: endl;
    }
}

int main ()
{

    List list;
    int size = 0;
    std :: cin >> size;
    if(size == 0) {
        std :: cout << "invalid size of list" << std :: endl;
        return -1;
    }

    for(int i = 0; i < size; ++i) {
        list.addNode(Student());
    }
    std :: cout << list.cap();
    for(int i = 0; i < size; ++i) {
        std :: cin >> list[i];
    }

    std :: cout << list.size() << std :: endl;
    for(int i = 0; i < list.size(); ++i) {
        std :: cout << list[i] << std :: endl;
    }


    std :: cout << "------------------------------------------------------------" << std :: endl;
    solution(list);

    return 0;
}
