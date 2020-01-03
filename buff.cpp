#include "buff.hpp"
#include <iostream>

using namespace std;

template <class T>
myBuffer<T>::myBuffer(){
    buf = new queue<T>;
    bufferSize = DEFAULT_SIZE;
}

template <class T>
myBuffer<T>::myBuffer(int size){
    buf = new queue<T>;
    bufferSize = size;
}

template <class T>
myBuffer<T>::~myBuffer(){
    delete this->buf;
}

template <class T>
int myBuffer<T>::enqueue(T element){
    if(this->bufferSize == this->buf->size())
        return -1;
    this->buf->push(element); 
    return 0;
}

template <class T>
T myBuffer<T>::dequeue(){
    if(this->empty())
        return -1;
    T element = this->buf->front();
    this->buf->pop();
    return element;
}

template <class T>
int myBuffer<T>::empty(){
    if(this->buf->size() > 0)
        return 0;
    return 1;
}

template <class T>
int myBuffer<T>::bufSize(){
    return this->buf->size();
}

template <class T>
int myBuffer<T>::maxBufSize(){
    return this->bufferSize;
}