#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class Node {
public:
    int info;
    Node *next;

    Node(int info = 0, Node *next = nullptr ) {
        this -> info = info;
        this -> next = next;
    }
};

class MinStack {
public:
    Node *elementsHead;
    Node *minimumsHead;

    MinStack() {
        this -> elementsHead = nullptr;
        this -> minimumsHead = nullptr;
    }

    void push(int value) {
        auto newElem = new Node(value, elementsHead);
        this -> elementsHead = newElem;

        auto newMinimum = new Node(min(getMinimum(), value), minimumsHead);
        this -> minimumsHead = newMinimum;
    }

    void pop() {
        auto tempElem = this -> elementsHead -> next;
        auto tempMinimum = this -> minimumsHead -> next;

        delete this -> elementsHead;
        delete this -> minimumsHead;

        this -> elementsHead = tempElem;
        this -> minimumsHead = tempMinimum;
    }

    int top() {
        return this -> elementsHead -> info;
    }

    int getMinimum() {
        if(this -> minimumsHead != nullptr)
            return this -> minimumsHead -> info;
        else
            return INT_MAX;
    }
};


int main() {
    MinStack stack;

    stack.push(100);
    cout << stack.top() << endl;
    cout << stack.getMinimum() << endl;
    stack.push(200);
    cout << stack.top() << endl;
    cout << stack.getMinimum() << endl;
    stack.pop();
    cout << stack.top() << endl;
    cout << stack.getMinimum() << endl;

    stack.push(5);
    cout << stack.getMinimum() << endl;
    stack.push(3);
    cout << stack.getMinimum() << endl;
    stack.push(7);
    cout << stack.getMinimum() << endl;
    stack.push(2);
    cout << stack.getMinimum() << endl;
    stack.push(8);
    cout << stack.getMinimum() << endl;

    stack.pop();
    cout << stack.getMinimum() << endl;
    stack.pop();
    cout << stack.getMinimum() << endl;
    stack.pop();
    cout << stack.getMinimum() << endl;
    stack.pop();
    cout << stack.getMinimum() << endl;
    stack.pop();
    cout << stack.getMinimum() << endl;
}
