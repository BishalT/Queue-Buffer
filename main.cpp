#include <iostream>
#include "buff.hpp"

using namespace std;

int main () {

    cout << "Making the queue" << endl;
    int sizes[2] = {8, 16};
    myBuffer<int> *newBuf = new myBuffer<int>(8);
    cout << "Created Buffer" << endl;

    for(int i = 0 ; i < newBuf->maxBufSize(); i++){
        cout << "Enqueuing an item: " << i << endl; 
        newBuf->enqueue(i);
    }

    cout << "Fully enqueued.\n" << endl;

    while(!newBuf->empty()){
        int elem = newBuf->dequeue();
        cout << "Dequeued Element: " << elem << endl;
    }

    cout << "Deleting buffer...\n" << endl;

    delete newBuf;

    cout << "Creating a new buffer..." << endl;

    myBuffer<char> *newerBuf = new myBuffer<char>(16);

    for(int i = 0 ; i < newBuf->maxBufSize(); i++){
        cout << "Enqueuing an item: " << char(i+'A'-1) << endl; 
        newerBuf->enqueue(char(i+'A'-1));
    }

    cout << "Fully enqueued.\n" << endl;

    while(!newBuf->empty()){
        auto elem = newerBuf->dequeue();
        cout << "Dequeued Element: " << elem << endl;
    }

    return 0;
}

// #include <iostream>
// using namespace std;
// int main(){
//     cout << "Hello world" << endl;
//     return 0;
// }