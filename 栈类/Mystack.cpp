#include"Mystack.h"

template<typename T>
Stack<T>::Stack(void) {
    cnt = 0;
    head = new Node<T>;
}

template<typename T>
void Stack<T>::push(T item) {
    Node<T>* node = new Node<T>(item);
    node->next = head->next;
    head->next = node;
    sTop = head->next;
    cnt++;
}

template<typename T>
void Stack<T>::pop(void) {
    Node<T>* tmp = sTop;
    sTop = sTop->next;
    head->next = sTop;
    delete tmp;
    cnt--;
}

template<typename T>
T Stack<T>::top(void) {
    return sTop->data;
}

template<typename T>
int Stack<T>::count(void) {
    return cnt;
}

template<typename T>
bool Stack<T>::isEmpty(void) {
    return cnt>0 ? false : true;
}