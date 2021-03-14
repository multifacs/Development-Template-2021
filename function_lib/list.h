#pragma once
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

struct LinkedList {
    Node* head;
    LinkedList() { head = nullptr; }

    void print();
    void push_back(int data);

    bool find_loop_floyd();
    bool find_loop_reverse();
};

