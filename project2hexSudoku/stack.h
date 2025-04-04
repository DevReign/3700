#pragma once

#ifndef _STACK_H
#define _STACK_H

#include <stdexcept>
#include <cstdint>

const int STACK_SIZE = 256;

template<typename StackType>
class Stack {
public:
    Stack() { count = 0; }
    ~Stack() {}

    void clear() { count = 0; }
    int size() { return count; }
    bool isEmpty() { return count == 0; }

    void push(const StackType& d) {

        if (count == STACK_SIZE)
            throw std::overflow_error("push: SimpleStack is full");

        data[count++] = d;
    }

    StackType pop() {

        if (!count) {
            throw std::underflow_error("pop: SimpleStack is empty");
        }

        return data[--count];
    }

    StackType peek() {
        if (!count)
            throw std::underflow_error("peek: SimpleStack is empty");

        return data[count - 1];
    }
private:
    StackType data[STACK_SIZE];
    int count;
};

#endif
