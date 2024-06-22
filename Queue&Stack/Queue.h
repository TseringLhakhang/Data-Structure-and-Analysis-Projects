//
// Created by Tsering Lhakhang on 9/24/21.
//

#ifndef LANGUAGE_QUEUE_H
#define LANGUAGE_QUEUE_H

#include "Node.h"
#include <iostream>
using std::cout, std::endl;

template<typename Object>
class Queue {
private:
    Node<Object>* front;
    Node<Object>* back;

public:
    Queue() {
        front = back = nullptr;
    }

    // Destructor
    // Automatically called at the end of the lifetime of a Queue object.
    ~Queue() {
        //Prevent memory leaks
        while(front != nullptr) {
            deQueue();
        }
        cout << "No memory leaks in Queue." << endl;
    }
    //Enqueue method will add a value to the Queue
    void enQueue(Object item) {
        // Create a new Node that stores the item
        Node<Object>* newNode = new Node<Object>(item);
        if (back == nullptr) {
            front = back = newNode;
            return;
        }
        //Update the back
        back->setNext(newNode);
        back = newNode;
    }

    //Dequeue method will remove a value from Queue
    Object deQueue() {
        //If front is empty(Queue is empty) then return the default Object
        if (front == nullptr) {
            return Object();
        }
        // Store a copy of front
        Node<Object>* frontCopy = front;
        Object returnVal = front->getItem();
        // Update front to point to the front's next Node
        front = front->getNext();
        // Delete the Node from heap memory
        delete frontCopy;
        frontCopy = nullptr;
        // Return the item that was removed from Queue
        return returnVal;
    }

    // search method will look for a specific value
    bool search(Object item) {
        Node<Object>* curr = front;
        //Linear O(N), N = number of nodes in the Queue.
        while (curr != nullptr) {
            //== works for integers. Won't work with objects, overloaded operator
            if (item == curr->getItem()) {
                //The item is in the Queue
                return true;
            }
            curr = curr->getNext();
        }
        //The item is not in the Queue
        return false;
    }

    //printQueue method will print the Queue from front to back
    void printQueue() {
        cout << "Front of Queue" << endl;
        Node<Object>* curr = front;
        while (curr != nullptr) {
            cout << curr->getItem() <<endl;
            curr = curr->getNext();
        }
        cout << "Back of Queue" << endl;
    }
};
#endif //LANGUAGE_QUEUE_H
