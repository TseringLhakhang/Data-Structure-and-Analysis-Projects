//
// Created by Tsering Lhakhang on 9/24/21.
//

#ifndef LANGUAGE_NODE_H
#define LANGUAGE_NODE_H

template <typename Object>
class Node {
private:
    Object item;
    Node* next;
public:
    Node(Object newItem) {
        item = newItem;
        next = nullptr;
    }

    Node(Object newItem, Node* nextNode) {
        item = newItem;
        next = nextNode;
    }

    void setItem(Object newItem) {
        item = newItem;
    }

    Object getItem() {
        return item;
    }

    void setNext(Node* nextNode) {
        next = nextNode;
    }

    Node* getNext() {
        return next;
    }
};
#endif //LANGUAGE_NODE_H
