#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>

class List
{
private:

    struct Node_t
    {
        int data;
        Node_t *next;
    };

    void deleteByValue(int);
    void eraseLastNode();
    void deleteList(Node_t *);
    void sort();


    Node_t *head;
    size_t sz;

public:
    List();
    void addNode(int);
    void clear();
    void print();

    size_t size() const;
    bool isContains(int);
    ~List();
};

#endif
