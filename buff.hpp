#ifndef BUFF_H
#define BUFF_H
 
#include <iostream>
#include <queue>

#define DEFAULT_SIZE 8

template <class T>
class myBuffer {
    private:
        std::queue<T> *buf;
        int bufferSize;
    public:
        // Constructors, default and dynamic
        myBuffer();
        myBuffer(int size);
        // Deconstructor
        ~myBuffer();

        // push element into the queue
        int enqueue(T element);
        // return element from queue
        T dequeue();
        // return 1 if empty, 0 if not
        int empty();
        // return the current size of the buffer
        int bufSize();
        // return the max size of the buffer
        int maxBufSize();
};

 
#endif