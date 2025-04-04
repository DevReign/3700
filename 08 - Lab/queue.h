#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdexcept>

using namespace std;

const uint32_t
    QUEUE_SIZE = 16;
  
template <typename QueueType>
class Queue {
public:
    Queue() {
        count = tail = 0;
        head = QUEUE_SIZE - 1;
        capacity = QUEUE_SIZE;
        data = new QueueType[QUEUE_SIZE];
    }
  
    ~Queue() { delete[] data; }
  
    void clear() { count = tail = 0; head = QUEUE_SIZE - 1; }
    uint32_t size() { return count; }
    bool isEmpty() { return count == 0; }
  
    void enqueue(const QueueType &d) {
        if (count == capacity) {
            int tmpCap = 2 * capacity;
            QueueType* tmpData = new QueueType[tmpCap];

            if(tmpData==nullptr)
                throw overflow_error("Queue is full");

            for (uint32_t i = 0; i < capacity; i++)
                tmpData[i] = data[i];

            delete[] data;

            data = tmpData;
            capacity = tmpCap;
            tail = count;
            head = capacity - 1;
        }
      
        data[tail] = d;
        tail = ++tail % capacity;
        count++;
    }
  
    QueueType dequeue() {
        if (count == 0)
            throw underflow_error("Queue is empty");

        head = ++head % capacity;
        count--;

        return data[head];
    }

private:
    QueueType *data;
    uint32_t head,tail,count,capacity;
};

#endif
