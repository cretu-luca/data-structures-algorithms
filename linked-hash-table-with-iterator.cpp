#include <iostream>
using namespace std;

class Node {
public:
    int info;
    Node *nextH {};
    Node *prevL {};
    Node *nextL {};

    Node(int info) {
        this -> info = info;
    }
};

class LinkedHashTable {
public:
    int capacity = 10;
    Node *array[10];
    Node *head {};
    Node *tail {};

    LinkedHashTable() = default;

    void add(int value) {
        int key = value % capacity;

        auto node = new Node(value);
        node -> nextH = this -> array[key];
        this -> array[key] = node;

        if(head == nullptr) {
            head = node;
            tail = node;
        } else {
            auto current = head;
            Node *previous = nullptr;

            while(current != nullptr && current -> info < value) {
                previous = current;
                current = current -> nextL;
            }

            if(previous == nullptr) {
                node -> nextL = head;
                head -> prevL = node;
                head = node;
            } else if(current == nullptr) {
                previous -> nextL = node;
                node -> prevL = previous;
                tail = node;
            } else {
                previous -> nextL = node;
                node -> prevL = previous;
                node -> nextL = current;
                current -> prevL = node;
            }
        }
    }

    void remove(int value) {
        int key = value % capacity;
        auto current = array[key];
        Node *nodeToBeRemoved = nullptr;

        if(current != nullptr && current -> info == value) {
            nodeToBeRemoved = current;
            this -> array[key] = current -> nextH;
        } else {
            Node *previous = nullptr;
            while(current != nullptr && current -> info != value) {
                previous = current;
                current = current -> nextH;
            }

            if(current != nullptr) {
                nodeToBeRemoved = current;
                previous -> nextH = current -> nextH;
            } else {
                throw runtime_error("value not found!\n");
            }
        }

        if(nodeToBeRemoved != nullptr) {
            if(nodeToBeRemoved == head) {
                if(nodeToBeRemoved == tail) {
                    head = nullptr;
                    tail = nullptr;
                } else {
                    head = head -> nextL;
                    head -> prevL = nullptr;
                }
            } else if(nodeToBeRemoved == tail) {
                tail = tail -> prevL;
                tail -> nextL = nullptr;
            } else {
                nodeToBeRemoved -> prevL -> nextL = nodeToBeRemoved -> nextL;
                nodeToBeRemoved -> nextL -> prevL = nodeToBeRemoved -> prevL;
            }

            delete nodeToBeRemoved;
        }
    }

    bool search(int value) {
        int key = value % capacity;
        auto current = array[key];

        if(current == nullptr) {
            return false;
        } else {
            while(current != nullptr && current -> info != value) {
                current = current -> nextH;
            }

            if(current == nullptr) {
                return false;
            } else {
                return true;
            }
        }
    }
};

class LinkedHashTableIterator {
public:
    Node *current;
    LinkedHashTable lht;

    LinkedHashTableIterator(LinkedHashTable lht) {
        this -> lht = lht;
        this -> current = lht.head;
    }

    void next() {
        if(!valid()) {
            throw runtime_error("invalid.\n");
        } else {
            current = current -> nextL;
        }
    }

    void first() {
        this -> current = lht.head;
    }

    int getCurrent() {
        return this -> current -> info;
    }

    bool valid() {
        return current != nullptr;
    }
};

int main() {
    LinkedHashTable lht;

    lht.add(25);
    lht.add(4);
    lht.add(14);
    lht.add(7);
    lht.add(5);
    lht.add(17);

    LinkedHashTableIterator iter(lht);

    while(iter.valid()) {
        cout << iter.getCurrent() << " ";
        iter.next();
    }
    cout << "\n";

    lht.remove(17);
    lht.remove(7);
    lht.add(20);

    iter.first();
    while(iter.valid()) {
        cout << iter.getCurrent() << " ";
        iter.next();
    }
    cout << "\n";
}
