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
private:
    Node *head {};

public:

    LinkedList() = default;

    void add(int value) {
        if(head == nullptr) {
            this -> head = new Node(value);
        } else {
            auto node = new Node(value, head);
            this -> head = node;
        }
    }

    int getNthNode(int n) {
        auto first = head, second = head;
        int index = 1;

        while(first != nullptr && index < n) {
            first = first -> next;
            index++;
        }

        while(first -> next != nullptr) {
            first = first -> next;
            second = second -> next;
        }

        return second -> info;
    }

    void insertPosition(int position, int value) {
        if(position < 1) {
            cout << "invalid position\n";
            return;
        } else if(position == 1) {
            auto node = new Node(value, head);
            this -> head = node;

        } else {
            int currentPosition = 0;
            Node *currentNode = head;

            while (currentPosition < position - 1 && currentNode != nullptr) {
                currentNode = currentNode -> next;
                currentPosition++;
            }

            if (currentNode == nullptr) {
                cout << "invalid position\n";
                return;
            } else {
                auto node = new Node(value);
                node -> next = currentNode -> next;
                currentNode -> next = node;
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


int main() {
    LinkedList ll;

    for(int i = 0; i < 10; i++) {
        ll.add(i);
        ll.display();
    }

    cout << "\n\n";

    ll.insertPosition(5, -1);
    ll.display();
    ll.remove(-1);

    cout << "\n\n";

    for(int i = 0; i < 10; i++) {
        ll.remove(i);
        ll.display();
    }

    return 0;
}
