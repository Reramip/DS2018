#include"Myqueue.h"

template<typename T>
Queue<T>::Queue(void) {
    head = new Node<T>;
    cnt = 0;
}

template<typename T>
void Queue<T>::push(T item) {
    Node<T>* node = new Node<T>(item);
    if (cnt == 0) {
        qFront = qBack = node;
        head->next = qFront;
    }
    else {
        qBack->next = node;
        qBack = qBack->next;
        qFront = head->next;
    }
    cnt++;
}

template<typename T>
void Queue<T>::pop(void) {
    Node<T>* tmp = qFront;
    qFront = qFront->next;
    head->next = qFront;
    delete tmp;
    cnt--;
}

template<typename T>
T Queue<T>::front(void) {
    return qFront->data;
}

template<typename T>
int Queue<T>::length(void) {
    return cnt;
}

template<typename T>
bool Queue<T>::isEmpty(void) {
    return cnt>0 ? false : true;
}