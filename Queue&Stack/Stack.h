//
// Created by Tsering Lhakhang on 9/24/21.
//

#ifndef LANGUAGE_STACK_H
#define LANGUAGE_STACK_H

#include "Node.h"
#include <iostream>
using std::cout, std::endl;

template<typename Object>
class Stack {
private:
    Node<Object>* top;

public:
    // Constructor
    Stack() {
        // Start with an empty Stack
        top = nullptr;
    }

    // Destructor
    // Automatically called at the end of the lifetime of a Stack object
    ~Stack() {
        // We want to make sure we don't have memory leaks. Delete the remaining Nodes from the Stack
        while(top != nullptr) {
            pop();
        }
        cout << "No memory leaks in Stack" << endl;
    }

    // Push method to add a value to the Stack
    void push(Object item) {
        // Create a new Node that stores the item and points to the current top Node
        Node<Object>* newNode = new Node<Object>(item, top);
        // Update top to point to the new Node
        top = newNode;
    }

    // Pop method to remove a value from the Stack
    Object pop() {
        if (top == nullptr) {
            // The Stack is empty. There's nothing to pop. Return the default Object.
            return Object();
        }
        // Store a copy of top
        Node<Object>* topCopy = top;
        // Store a copy of the return value
        Object returnVal = top->getItem();
        // Update top to point to the top's next Node
        top = top->getNext();
        // Delete the Node from heap memory
        delete topCopy;
        topCopy = nullptr;
        // Return the item that is popped from the Stack
        return returnVal;
    }

    // Search the Stack for a particular value
    bool search(Object item) {
        Node<Object>* curr = top;
        //Linear O(N), N = number of nodes in the stack.
        while (curr != nullptr) {
            //== works for integers. Won't work with Language objects, overloaded operator
            if (item == curr->getItem()) {
                //The item is in the Stack
                return true;
            }
            curr = curr->getNext();
        }
        //The item is not in the stack
        return false;
    }

    // Print the Stack from top to bottom
    void printStack() {
        cout << "Top of Stack" << endl;
        Node<Object>* curr = top;
        while (curr != nullptr) {
            cout << curr->getItem() << endl;
            curr = curr->getNext();
        }
        cout << "Bottom of Stack" << endl;
    }
};

#endif //LANGUAGE_STACK_H
