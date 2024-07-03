#include <iostream>
#include <cmath>

using namespace std;

class Node {
public:
    int info;
    Node *next;
    Node *previous;

    Node(int info = 0, Node *previous = nullptr, Node *next = nullptr) {
        this -> info = info;
        this -> previous = previous;
        this -> next = next;
    }
};

class SortedDoublyLinkedList {
public:
    Node *head {};
    Node *tail {};

    SortedDoublyLinkedList() = default;

    void add(int value) {
        auto node = new Node(value);
        if(head == nullptr) {
            this -> head = this -> tail = node;
        } else if(value < head -> info) {
            node -> next = head;
            head -> previous = node;
            head = node;
        } else {
            auto current = head;
            while(current -> next != nullptr && current -> next -> info < value) {
                current = current -> next;
            }

            node -> next = current -> next;
            node -> previous = current;

            if(current -> next != nullptr) {
                current -> next -> previous = node;
            } else {
                tail = node;
            }

            current -> next = node;
        }
    }

    void display() {
        auto current = this -> head;
        while(current != nullptr) {
            cout << current -> info << " ";
            current = current -> next;
        }
        cout << "\n";
    }

    void remove(int value) {
        auto current = head;

        if(head -> info == value) {
            auto temp = head;
            head = head -> next;
            if(head != nullptr) {
                head -> previous = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
        } else {
            while (current != nullptr && current -> info != value) {
                current = current -> next;
            }

            if(current == nullptr) {
                return;
            }

            if(current -> next != nullptr) {
                current -> next -> previous = current -> previous;
            } else {
                tail = current -> previous;
            }

            if(current -> previous != nullptr) {
                current -> previous -> next = current -> next;
            }
            delete current;
        }
    }
};

int main() {
    SortedDoublyLinkedList dll;

    dll.add(5);
    dll.add(2);
    dll.add(14);
    dll.add(8);

    dll.display();
    cout << "\n\n";

    dll.remove(5);
    dll.display();
    dll.remove(14);
    dll.display();
    dll.remove(2);
    dll.display();
    dll.remove(8);
    dll.display();
}
