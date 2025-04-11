#include "linked_list.h"

List ::List() : head(nullptr), sz(0) {}

void List ::addNode(int value)
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
    sort();
    ++sz;
}

void List ::print()
{
    Node_t *current = head;
    while (current != nullptr)
    {
        std ::cout << current->data << ' ';
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
        delete current->next->next;
        current->next = nullptr;
    }
}

bool List ::isContains(int value)
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

void List ::deleteByValue(int value)
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

void List :: sort()
{
    Node_t* current = head;
    if(current != nullptr)
    {
        bool is_sorted = false;
        while(!is_sorted)
        {
            is_sorted = true;
            current = head;
            while(current->next != nullptr)
            {
                if(current->data > current->next->data)
                {
                    Node_t* tmp = new Node_t;
                    tmp->data = current->data;
                    current->data = current->next->data;
                    current->next->data = tmp->data;
                    delete tmp;
                    is_sorted = false;
                }
                current = current->next;
            }
        }
    }
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

void List :: deleteList(Node_t*node)
{
    if(node != nullptr)
    {
        deleteList(node->next);
        delete node;
    }
}
