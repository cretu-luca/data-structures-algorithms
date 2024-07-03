#include <iostream>
using namespace std;

class Queue {
public:
    int rear, front;
    int *elements;
    int capacity, size;

    Queue() : rear(0), front(0), capacity(5), size(0) {
        elements = new int[capacity];
    }

    ~Queue() {
        delete []elements;
    }

    void push(int value) {
        if(size == capacity) {
            resize();
        }

        elements[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }

    void display() {
        int i = front;
        for(int count = 0; count < size; count++) {
            cout << elements[i] << " ";
            i = (i + 1) % capacity;
        }

        cout << "\n";
    }

    void pop() {
        if (size == 0) {
            cout << "Queue is empty, cannot pop" << endl;
            return;
        }

        elements[front] = 0;
        front = (front + 1) % capacity;
        size--;
    }

    int getCurrent() {
        if (size == 0) {
            cout << "Queue is empty, no current element" << endl;
            return -1;
        }
        return elements[front];
    }

    void resize() {
        int newCapacity = 2 * capacity;
        int *newElements = new int[newCapacity];

        for (int i = 0; i < size; i++) {
            newElements[i] = elements[(front + i) % capacity];
        }

        delete []elements;
        elements = newElements;
        capacity = newCapacity;
        front = 0;
        rear = size;
    }
};

int main() {
    Queue q;
    for (int i = 0; i < 10; i++) {
        q.push(i);
        q.display();
    }

    cout << "\n\n";

    while (q.size) {
        cout << q.getCurrent() << " ";
        q.pop();
    }

    return 0;
}
