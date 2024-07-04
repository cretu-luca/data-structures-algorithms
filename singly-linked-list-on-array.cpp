#include <iostream>
using namespace std;

class LinkedListOnArray {
public:
    int elements[20];
    int next[20];
    int firstEmpty;
    int head;

    LinkedListOnArray() {
        this -> firstEmpty = 0;
        this -> head = -1;
        this -> next[19] = -1;
        for(int i = 0; i < 19; i++) {
            this -> elements[i] = 0;
            this -> next[i] = i + 1;
        }
    }

    void add(int value) {
        /*
        int newPosition = this -> firstEmpty;
        this -> elements [newPosition] = value;
        this -> firstEmpty = this -> next [this -> firstEmpty];
        this -> next [newPosition] = this -> head;
        this -> head = newPosition;
         */

        int newPos = this -> firstEmpty;
        this -> firstEmpty = this -> next[this -> firstEmpty];
        this -> elements [newPos] = value;

        if(head == -1) {
            this -> next[newPos] = -1;
            this -> head = newPos;
        } else {
            int current = head;
            int previous = -1;

            while(current != -1 && this -> elements[current] < value) {
                previous = current;
                current = this -> next[current];
            }

            if(previous == -1) {
                this -> next [newPos] = this -> head;
                this -> head = newPos;
            } else {
                this -> next[previous] = newPos;
                this -> next[newPos] = current;
            }
        }
    }

    void remove(int value) {
        int current = head;
        int previous = -1;

        while(current != -1 && this -> elements[current] != value) {
            previous = current;
            current = this -> next[current];
        }

        if(current != -1) {
            if(previous == -1) {
                this -> head = this -> next[this -> head];
            } else {
                this -> next[previous] = this -> next[current];
            }
        }
    }

    void display() {
        int current = head;
        while(current != -1) {
            cout << this -> elements[current] << " ";
            current = this -> next[current];
        }

        cout << "\n";
    }
};

int main() {

    LinkedListOnArray list;

    list.add(45);
    list.add(53);
    list.add(21);
    list.add(59);
    list.add(20);
    list.add(63);

    list.display();

    list.remove(21);
    list.remove(45);
    list.remove(59);

    list.display();

    return 0;
}
