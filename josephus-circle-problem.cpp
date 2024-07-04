#include <iostream>
using namespace std;

class Node {
public:
    int info;
    Node *next;

    Node(int info = 0, Node *next = nullptr) {
        this -> info = info;
        this -> next = next;
    }
};

class CircularLinkedList {
public:
    Node *head {};
    Node *tail {};

    CircularLinkedList() = default;

    void add(int value) {
        if(head == nullptr) {
            head = tail = new Node(value);
            tail -> next = head;
        } else {
            auto temp = new Node(value);
            tail -> next = temp;
            tail = temp;
            tail -> next = head;
        }
    }

    void solve(int k) {
        auto current = head;
        auto previous = tail;

        while(current -> next != current) {
            for(int i = 0; i < k; i++) {
                previous = current;
                current = current -> next;
            }

            previous -> next = current -> next;
        }

        cout << current -> info << "\n";
    }

    void display() {
        auto current = this -> head;
        do {
            cout << current->info << " ";
            current = current -> next;
        } while (current != head);

        cout << "\n";
    }
};

int main() {
    CircularLinkedList cll;

    for(int i = 0; i < 7; i++)
        cll.add(i);

    cll.display();
    cll.solve(3);

    return 0;
}
