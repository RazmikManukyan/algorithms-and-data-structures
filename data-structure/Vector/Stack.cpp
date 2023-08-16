#include "Stack.h"

template<typename T>
Stack<T>::Stack()
    :m_capacity(1), m_top(-1) {
    m_storage = new T[m_capacity];
}

template<typename T>
Stack<T>::~Stack() {
    delete[] m_storage;
}

template<typename T>
void Stack<T>::push(const T &val) {
    if(m_top + 1 == m_capacity) {
        resize(m_capacity * 2);
    }
    m_storage[++m_top] = val;
}

template<typename T>
void Stack<T>::pop() {
    if(!empty()) {
        --m_top;
    }
}

template<typename T>
const T& Stack<T>::top() const {
    if(!empty()) {
        return m_storage[m_top];
    }
    throw std::runtime_error("Stack is empty!");
}

template<typename T>
int Stack<T>::get_size() const{
    return m_top + 1;
}

template<typename T>
bool Stack<T>::empty() const{
    return m_top == -1;
}

