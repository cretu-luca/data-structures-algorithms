#include <iostream>
using namespace std;

class Node {
public:
    int info;
    Node *next {};
    Node *prev {};

    Node(int info = 0, Node *prev = nullptr, Node *next = nullptr) {
        this -> info = info;
        this -> prev = prev;
        this -> next = next;
    }
};

class Queue {
public:
    Node *rear {};
    Node *front {};

    Queue() = default;

     void push(int value) {
         auto node = new Node(value, rear, nullptr);
         if(rear == nullptr) {
             this -> rear = this -> front = node;
         } else {
             this -> rear -> next = node;
             this -> rear = node;
         }
     }

     void pop() {
         if(this -> front == nullptr)
             return;
         else {
             auto temp = this -> front -> next;
             delete this -> front;
             this -> front = temp;
             if(this -> front == nullptr)
                 this -> rear = nullptr;
             else
                 front -> prev = nullptr;
         }
     }

     int getFront() {
         return this -> front -> info;
     }
};

int main() {
    Queue q;

    q.push(10);
    cout << q.getFront() << endl;

    q.push(20);
    cout << q.getFront() << endl;

    q.push(30);
    cout << q.getFront() << endl;

    q.pop();
    cout << q.getFront() << endl;

    q.pop();
    cout << q.getFront() << endl;

    q.push(50);
    q.pop();
    cout << q.getFront() << endl;

    return 0;
}
