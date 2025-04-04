#ifndef _STACK_H
#define _STACK_H

#include <stdexcept>

using namespace std;

const uint32_t
    STACK_SIZE = 16;
  
template <typename StackType>
class Stack {
public:
    Stack(){ 
        count = 0; 
        capacity = STACK_SIZE;
        data = new StackType[STACK_SIZE];
    }
    ~Stack(){ delete[] data; }

    void clear() { count = 0; }
    uint32_t size(){ return count; }
    bool isEmpty(){ return count == 0; }
  

    void push(const StackType &d) {
        // out of space? make more space!
        if (count == capacity) {
            int tmpCap = 2 * capacity;
            StackType *tmpData = new StackType[tmpCap];

            // this shouldn’t happen in practice
            if (tmpData == nullptr)
                throw std::overflow_error("Stack is full");
            // copy data from old array into new array
            for (int i=0;i<capacity;i++)
                tmpData[i] = data[i];

            // toss the old array
            delete[] data;
            // remember the new array and its capacity
            data = tmpData;
            capacity = tmpCap;
        }
        // and we continue on like nothing happened
        data[count] = d;
        count++;
    }
  
    StackType pop() {
        if (count == 0)
            throw underflow_error("Stack is empty");
      
        return data[--count];
    }
    
    StackType peek() {
        if (count == 0)
            throw underflow_error("Stack is empty");
      
        return data[count-1];
    }
  
private:
    StackType *data;
    uint32_t count, capacity;
};

#endif

