#include <iostream>
using namespace std;

class Node {
public:
    int info;
    Node *next {};
    Node *prev {};

    Node(int info = 0): info(info) {}
};

class Stack {
public:
    Node *head;
    Node *middle;

    int size;

    Stack() {
        size =  0;
        head = nullptr;
        middle = nullptr;
    }

    void push(int value) {
        auto newNode = new Node(value);
        if(head == nullptr) {
            head = newNode;
            middle = head;
        } else {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
            if(size % 2 == 0) {
                middle = middle -> prev;
            }
        }

        size++;
    }

    void pop() {
        if(head == nullptr) {
            cout << "stack is empty!\n";
        } else {
            head = head -> next;
            if(head != nullptr)
                head -> prev = nullptr;
            if(size % 2 == 1) {
                middle = middle -> next;
            }
            size--;
        }
    }

    int top() {
        if(head == nullptr) {
            cout << "stack is empty!\n";
            return -1;
        } else {
            return head -> info;
        }
    }

    int getMiddle() {
        if(middle == nullptr) {
            cout << "stack is empty!\n";
            return -1;
        } else {
            return middle -> info;
        }
    }

    void popMiddle() {
        if(middle == nullptr) {
            cout << "stack is empty!\n";
            return;
        }

        Node *nodeToRemove = middle;

        if(nodeToRemove -> prev != nullptr) {
            nodeToRemove -> prev -> next = nodeToRemove -> next;
        }
        if(nodeToRemove -> next != nullptr) {
            nodeToRemove -> next -> prev = nodeToRemove -> prev;
        }

        if(size % 2 == 1) {
            middle = middle -> next;
        } else {
            middle = middle -> prev;
        }

        if(nodeToRemove == head) {
            head = head -> next;
            if(head != nullptr) {
                head -> prev = nullptr;
            }
        }

        delete nodeToRemove;
        size--;
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
    Stack st;

    for(int i = 0; i < 10; i++) {
        st.push(i);
        st.display();
        cout << "middle: " << st.getMiddle() << "\n\n\n";
    }

    cout << "popping middle:\n";
    st.popMiddle();
    st.display();
    cout << "middle: " << st.getMiddle() << "\n\n\n";

    cout << "popping middle:\n";
    st.popMiddle();
    st.display();
    cout << "middle: " << st.getMiddle() << "\n\n\n";
}
