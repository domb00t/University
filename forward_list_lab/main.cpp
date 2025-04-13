#include <iostream>

#include "linked_list.h"
#include "student.h"

int main ()
{
    /*
    Student sample2;
    std :: cin >> sample2;
    Student sample3 = sample2;
    std :: cout << sample << std :: endl << sample2 << std :: endl << sample3 << std :: endl;
    std :: cout << (sample2 == sample);
    */
    Student sample("Rossokhin",3,3,3);

    List list;
    int size = 0;
    std :: cin >> size;
    if(size) {
        for(int i = 0; i < size; ++i) {
            list.addNode(sample);
        }
    }
    std :: cin >> size;
    std :: cout << list.size() << std :: endl;
    for(int i = 0; i < list.size(); ++i) {
        std :: cout << list[i] << std :: endl;
    }

    return 0;
}
