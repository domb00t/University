#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>
#include <cstring>

#include "student.h"

class List
{
private:

    struct Node_t
    {
        Student data;
        Node_t *next;

        Node_t() : data(Student()), next(nullptr) {}
    };

    void deleteByValue(Student);
    void eraseLastNode();
    void deleteList(Node_t *);



    Node_t *head;
    size_t sz;

public:
    List();
    List(size_t);
    void addNode(Student);
    void clear();
    void print();
    Student& operator[](size_t);
    size_t size() const;
    bool isContains(Student);
    ~List();
};

#endif
