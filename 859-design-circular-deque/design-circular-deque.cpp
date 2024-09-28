class Node {

public:
    int value;
    Node* next;
    Node* prev;

    Node() {
        this->value = 0;
        next = nullptr;
        prev = nullptr;
    }

    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class MyCircularDeque {
public:
    int size = 0;
    Node* front;
    Node* rear;
    int cnt = 0;

    MyCircularDeque(int k) { 
        size = k; 
        front = new Node();
        rear = new Node();

        front->next=rear;
        rear->prev=front;
    }

    bool insertFront(int value) {

        if (cnt == size)
            return false;
        Node* n = new Node(value);
        n->next = front->next;
        n->prev = front;
        front->next->prev = n;
        front->next = n;
        cnt++;

        return true;
    }

    bool insertLast(int value) {
        if (cnt == size)
            return false;

        Node* n = new Node(value);
        n->next = rear;
        n->prev = rear->prev;
        rear->prev->next = n;
        rear->prev = n;
        cnt++;

        return true;
    }

    bool deleteFront() {
        if (cnt == 0)
            return false;
        Node* n = front->next;
        front->next = front->next->next;
        front->next->prev = front;
        cnt--;

        delete n;
        return true;
    }

    bool deleteLast() {
        if (cnt == 0)
            return false;
        Node* n = rear->prev;
        rear->prev = rear->prev->prev;
        rear->prev->next = rear;
        cnt--;

        delete n;
        return true;
    }

    int getFront() {
        if (cnt == 0)
            return -1;
        return front->next->value;
    }

    int getRear() {
        if (cnt == 0)
            return -1;
        return rear->prev->value;
    }

    bool isEmpty() {
        if (cnt == 0)
            return true;
        else
            return false;
    }

    bool isFull() {
        if (cnt == size)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */