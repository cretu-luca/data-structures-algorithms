#include <iostream>
using namespace std;

class DLLANode {
public:
    int info;
    int prev;
    int next;

    DLLANode(int info = 0, int prev = -1, int next = -1) {
        this -> info = info;
        this -> prev = prev;
        this -> next = next;
    }
};

class SortedDLLA {
public:
    int capacity = 20;
    int firstEmpty;
    int size;
    int head {};
    int tail {};
    DLLANode *elements[20];

    SortedDLLA() {
        this -> head = -1;
        this -> tail = -1;
        this -> size = 0;
        this -> firstEmpty = 0;

        for(int i = 0; i < capacity; i++) {
            this -> elements[i] = new DLLANode(0, i - 1, i + 1);
        }

        this -> elements[this -> capacity - 1] -> next = -1;
    }

    ~SortedDLLA() {
        for(int i = 0; i < this -> capacity; i++)
            delete this -> elements[i];
    }

    void add(int value) {
        int newPos = this -> firstEmpty;
        this -> elements[newPos] -> info = value;
        this -> firstEmpty = this -> elements[this -> firstEmpty] -> next;

        if(this -> head == -1) {
            this -> head = newPos;
            this -> tail = newPos;
            this -> elements[newPos] -> next = -1;
            this -> elements[newPos] -> prev = -1;
        } else {
            int current = this -> head;
            int previous = -1;

            while(current != -1 && this -> elements[current] -> info < value) {
                previous = current;
                current = this -> elements[current] -> next;
            }

            if(previous == -1) {
                this -> elements[newPos] -> next = this -> head;
                this -> elements[head] -> prev = newPos;
                this -> elements[newPos] -> prev = -1;
                this -> head = newPos;
            } else if(current == -1) {
                this -> elements[previous] -> next = newPos;
                this -> elements[newPos] -> prev = previous;
                this -> elements[newPos] -> next = -1;
                this -> tail = newPos;
            } else {
                this -> elements[newPos] -> prev = previous;
                this -> elements[newPos] -> next = current;
                this -> elements[previous] -> next = newPos;
                this -> elements[current] -> prev = newPos;
            }
        }

        size++;
    }

    void remove(int value) {
        int current = this -> head;

        while(current != -1 && this -> elements[current] -> info != value) {
            current = this -> elements[current] -> next;
        }

        if(current != -1) {
            if(this -> elements[current] -> prev == -1) {
                this -> head = this -> elements[this -> head] -> next;
                if(this -> head != -1)
                    this -> elements[this -> head] -> prev = -1;
                else
                    this -> tail = -1;
            } else if(this -> elements[current] -> next == -1) {
                this -> tail = this -> elements[this -> tail] -> prev;
                if(this -> tail != -1)
                    this -> elements[this -> tail] -> next = -1;
                else
                    this -> head = -1;
            } else {
                this -> elements[this -> elements[current] -> prev] -> next = this -> elements[current] -> next;
                this -> elements[this -> elements[current] -> next] -> prev = this -> elements[current] -> prev;
            }

            this -> elements[current] -> next = this -> firstEmpty;
            this -> firstEmpty = current;

            size--;
           }
        }

    void display() {
        int current = this -> head;

        while(current != -1) {
            cout << this -> elements[current] -> info << " ";
            current = this -> elements[current] -> next;
        }

        cout << "\n";
    }
};

int main() {

    SortedDLLA list;

    list.add(54);
    list.add(20);
    list.add(40);
    list.add(53);
    list.add(45);

    list.display();

    list.remove(20);
    list.remove(45);

    list.display();

    return 0;
}
