#include <iostream>

#include "linked_list.h"
#include "student.h"

int main ()
{
    Student sample("egor",3,3,3);
    int n;
    std :: cin >> n;
    List l1(n);
    std :: cout << l1.size();
    for(int i = 0;i < n;i++) {
        std :: cin >> l1[i];
    }
    l1.print();
    std :: cout << l1.size();

    return 0;
}
