#ifndef QUEUE_H
#define QUEUE_H
 
#define QUEUE_DEFAULT_SIZE 8

template <class S>
class node_t {
    private:
        S data;
        node_t<S>* prev, *next;
    public:
        node_t(S data);
        ~node_t();
        template <class T> friend class queue_t;
};

template <class T>
class queue_t {
    private:
        node_t<T>* head, *tail;
        int max, currentSize;
    public:
        // Constructors, default and dynamic
        queue_t();
        queue_t(int size);
        // Deconstructor
        ~queue_t();
        // push element into the queue
        int enqueue(T data);
        // return element from queue
        T dequeue();
        // return 1 if empty, 0 if not
        int empty();
        // return the current size of the buffer
        int queueSize();
        // return the max size of the buffer
        int maxSize();
};

 
#endif