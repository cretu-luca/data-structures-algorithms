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
        while(parent >= 1 && this -> elements[parent] < this -> elements[index]) {
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

            if(index * 2 + 1 <= this -> size && this -> elements[index * 2 + 1] > this -> elements[index * 2])
                minChild = index * 2 + 1;

            if(minChild != -1 && this -> elements[minChild] > this -> elements[index]) {
                swap(this -> elements[index], this -> elements[minChild]);
                index = minChild;
            } else {
                index = this -> size + 1;
            }
        }
    }

    int getMax() {
        return this -> elements[1];
    }
};

void heapSort(int array[10]) {
    Heap heap;

    for(int i = 0; i < 10; i++)
        heap.add(array[i]);

    for(int i = 0; i < 10; i++) {
        array[9 - i] = heap.getMax();
        heap.remove();
    }
}

int main() {
    int array[] = {92, 54, 23, 42, 10, 34, 100, 56, 78, 47};
    heapSort(array);

    for(int i = 0; i < 10; i++)
        cout << array[i] << " ";

    return 0;
}
