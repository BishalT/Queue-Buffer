#include "queue.hpp"
#include <iostream>

using namespace std;


// Node Functions
template <class T>
node_t<T>::node_t(T data){
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
}

template <class T>
node_t<T>::~node_t(){
    if(this->next)
        this->next = nullptr;
    if(this->prev)
        this->prev = nullptr;
}

// Queue functions
template <class T>
queue_t<T>::queue_t(){
    this->head = nullptr;
    this->tail = nullptr;
    this->maxSize = QUEUE_DEFAULT_SIZE;
    this->currentSize = 0;
}

template <class T>
queue_t<T>::queue_t(int size){
    this->head = nullptr;
    this->tail = nullptr;
    this->max = size;
    this->currentSize = 0;
}

template <class T>
queue_t<T>::~queue_t(){
    while(this->head != nullptr){
        node_t<T> *curr = this->head;
        this->head = curr->next;
        delete curr;
    }
}

// enqueue the element at the end of the queue
template <class T>
int queue_t<T>::enqueue(T data){
    // create a new node
    node_t<T> *element = new node_t<T>(data);

    if(this->maxSize() == this->queueSize() || element == nullptr)
        return -1;
    
    // if it is the first element in the list
    if(this->queueSize() == 0){
        this->head = element;
        this->tail = element;
    } 
    else {
        this->tail->next = element; // set the next of tail to element
        element->prev = this->tail; // set the previous of element to the tail
        this->tail = element;   // set tail to the element
    }

    this->currentSize++;

    return 0;
}

// dequeue the element at the front of the queue
template <class T>
T queue_t<T>::dequeue(){
    if(this->empty())
        return -1;
    // get the head node
    node_t<T>* headNode = this->head;
    T returnVal = headNode->data;
    // set the head to the next node

    if(this->queueSize() <= 1){
        this->head = nullptr;
        this->tail = nullptr;
    }
    else {
        this->head = headNode->next;
        // set the new head prev to null
        this->head->prev = nullptr;
    }
    // delete the node
    delete headNode;
    
    this->currentSize--;
    return returnVal;
}

template <class T>
int queue_t<T>::empty(){
    if(this->queueSize() > 0)
        return 0;
    return 1;
}

template <class T>
int queue_t<T>::queueSize(){
    return this->currentSize;
}

template <class T>
int queue_t<T>::maxSize(){
    return this->max;
}
