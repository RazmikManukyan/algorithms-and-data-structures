#ifndef Stack_h
#define Stack_h
#include <iostream>

template<typename T>
class Stack {
public:
    Stack();
    ~Stack();

    void push(const T&);
    void pop();
    const T& top() const;
    [[nodiscard]] int get_size() const;
    [[nodiscard]] bool empty() const;
private:
    void resize(std::size_t new_capacity) {
        T* new_storage = new T[new_capacity];
        for(int i = 0; i < m_top; ++i) {
            new_storage[i] = m_storage[i];
        }
        delete[] m_storage;
        m_storage = new_storage;
        new_storage = nullptr;
        m_capacity = new_capacity;
    }
private:
    T* m_storage;
    std::size_t m_capacity;
    std::size_t m_top;
};

#include "Stack.cpp"

#endif