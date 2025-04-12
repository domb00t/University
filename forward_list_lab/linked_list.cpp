#include "linked_list.h"
#include "student.h"

List ::List() : head(nullptr), sz(0) {}

List :: List(size_t size) : head(nullptr), sz(0) {
    for(size_t index = 0;index < size;++index) {
        addNode(Student());
    }
}

void List ::addNode(Student value)
{
    Node_t *new_node = new Node_t;
    new_node->data = value;
    new_node->next = nullptr;
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        Node_t *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    ++sz;
}

void List ::print()
{
    Node_t *current = head;
    while (current != nullptr)
    {
        std ::cout << current->data << std :: endl;
        current = current->next;
    }
}

void List::eraseLastNode()
{
    if(head == nullptr) {} else if(head->next== nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node_t *current = head;
        while (current->next->next != nullptr)
        {
            current = current->next;
        }
        delete current->next;
        --sz;
        current->next = nullptr;
    }
}

bool List ::isContains(Student value)
{
    Node_t *current = head;
    bool fl = false;
    if (current != nullptr)
    {
        while (current != nullptr)
        {
            fl = fl || current->data == value;
            current = current->next;
        }
    }

    return fl;
}

void List ::deleteByValue(Student value)
{
    Node_t *current = head;
    Node_t *previous = head;
    bool fl = true;
    if (current != nullptr)
    {
        if (current->data == value)
        {
            head = current->next;
            delete current;
        }
        else
        {

            while (current != nullptr && fl)
            {

                if (current->data == value)
                {
                    previous->next = current->next;
                    delete current;
                    fl = false;
                }
                else
                {
                    previous = current;
                    current = current->next;
                }
            }
        }
    }
    --sz;
}

List :: ~List()
{
    deleteList(head);
}

void List :: clear() {
    deleteList(head);
    head = nullptr;
    sz = 0;
}

size_t List :: size() const {
    return sz;
}

Student& List:: operator[](size_t index) {

    Node_t* current = head;
    if (index < 0 || index >= sz) {
        std :: cout << "out_of_range" << std :: endl;
        std :: abort();
    } else {
        if(current == nullptr) {
            std :: cout << "list is empty" << std :: endl;
            std :: abort();
        } else if (current->next == nullptr) {
            return current->data;
        } else {
            size_t _index = 0;
            while(_index < sz && current->next) {
                current = current->next;
                ++_index;
            }
        }
    }
    return current->data;
}

void List :: deleteList(Node_t*node)
{
    if(node != nullptr)
    {
        deleteList(node->next);
        delete node;
    }
}
