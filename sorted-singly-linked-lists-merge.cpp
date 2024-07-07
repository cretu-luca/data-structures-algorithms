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

class LinkedList {
public:

    Node *head {};

    LinkedList() = default;

    void add(int value) {
        auto current = head;
        auto node = new Node(value);

        if(current == nullptr) {
            head = node;
        } else {
            Node *prev = nullptr;
            while (current != nullptr && current -> info < value) {
                prev = current;
                current = current -> next;
            }

            if(prev == nullptr) {
                node -> next = head;
                head = node;
            } else {
                prev -> next = node;
                node -> next = current;
            }
        }
    }

    void remove(int value) {
        auto current = head;
        Node *prev = nullptr;

        while (current != nullptr) {
            if (current -> info == value) {
                if(prev != nullptr) {
                    prev->next = current->next;
                } else {
                    head = current -> next;
                }

                delete current;
                return;
            }

            prev = current;
            current = current->next;
        }
    }

    void display() {
        auto current = head;
        while(current != nullptr) {
            cout << current -> info << " ";
            current = current -> next;
        }
        cout << "\n";
    }
};

Node *merge(LinkedList l1, LinkedList l2) {
    Node *head = nullptr;
    Node *tail = nullptr;
    auto first = l1.head;
    auto second = l2.head;

    if(first -> info < second -> info) {
        head = first;
        first = first -> next;
    } else {
        head = second;
        second = second -> next;
    }

    tail = head;

    while(first != nullptr && second != nullptr) {
        if (first -> info < second -> info) {
            tail -> next = first;
            first = first -> next;
        } else {
            tail -> next = second;
            second = second -> next;
        }

        tail = tail -> next;
    }

    if(first != nullptr)
        tail -> next = first;
    else
        tail -> next = second;

    l1.head = nullptr;
    l2.head = nullptr;

    return head;
}

int main() {
    LinkedList l1, l2;

    l1.add(5);
    l1.add(2);
    l1.add(9);
    l1.add(3);
    l1.add(6);

    l1.display();

    l2.add(4);
    l2.add(10);
    l2.add(1);
    l2.add(7);
    l2.add(8);

    l2.display();

    auto res = merge(l1, l2);
    while(res != nullptr) {
        cout << res -> info << " ";
        res = res -> next;
    }

    return 0;
}
