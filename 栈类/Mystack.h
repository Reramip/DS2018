#pragma once

template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node<T>* next;
        Node(void) :next(nullptr) {};
        Node(T item) :data(item), next(nullptr) {};
    };

    int cnt;
    Node<T>* head;
    Node<T>* sTop;
public:
    Stack(void);
    void push(T item);
    void pop(void);
    T top(void);
    int count(void);
    bool isEmpty(void);
};