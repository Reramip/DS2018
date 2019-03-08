#pragma once

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node<T>* next;
        Node(void) :next(nullptr) {};
        Node(T item) :data(item), next(nullptr) {};
    };

    int cnt;
    Node<T>* head;
    Node<T>* qFront;
    Node<T>* qBack;
public:
    Queue(void);
    void push(T item);
    void pop(void);
    T front(void);
    int length(void);
    bool isEmpty(void);
};