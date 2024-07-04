#include <iostream>
using namespace std;

class Heap {
public:
    int elements[20] {};
    int size;

    Heap() {
        this -> size = 0;
    }

    void add(int value) {
        this -> elements[++size] = value;
        bubbleUp(size);
    }

    void remove() {
        this -> elements[1] = this -> elements[this -> size--];
        bubbleDown(1);
    }

    void bubbleUp(int index) {
        int parent = index / 2;
        while(parent >= 1 && this -> elements[parent] > this -> elements[index]) {
            swap(this -> elements[parent], this -> elements[index]);
            index = parent;
            parent = parent / 2;
        }
    }

    void bubbleDown(int index) {
        int minChild;
        while(index < this -> size) {
            minChild = -1;

            if(index * 2 <= this -> size)
                minChild = index * 2;

            if(index * 2 + 1 <= this -> size && this -> elements[index * 2 + 1] < this -> elements[index * 2])
                minChild = index * 2 + 1;

            if(minChild != -1 && this -> elements[minChild] < this -> elements[index]) {
                swap(this -> elements[index], this -> elements[minChild]);
                index = minChild;
            } else {
                index = this -> size + 1;
            }
        }
    }

    int getMin() {
        return this -> elements[1];
    }
};

class PriorityQueue {
public:
    Heap heap;

    void push(int value) {
        this -> heap.add(value);
    }

    void pop() {
        this -> heap.remove();
    }

    int top() {
        return this -> heap.getMin();
    }
};

int main() {
    PriorityQueue pq;
    pq.push(5);
    pq.push(2);
    pq.push(6);
    pq.push(8);

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    return 0;
}
