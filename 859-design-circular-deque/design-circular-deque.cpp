#include <vector>

class MyCircularDeque {
private:
    std::vector<int> data;
    int front;
    int rear;
    int capacity;
    int count;

public:
    MyCircularDeque(int k) : data(k), front(0), rear(k - 1), capacity(k), count(0) {}
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        data[front] = value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        data[rear] = value;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        count--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return data[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return data[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};