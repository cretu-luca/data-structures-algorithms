#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    stack<int> first, second;

    void push(int value) {
        first.push(value);
    }

    void pop() {
        if(second.empty()) {
            while(!first.empty()) {
                second.push(first.top());
                first.pop();
            }

            second.pop();
        } else {
            second.pop();
        }
    }

    int front() {
        if(second.empty()) {
            while(!first.empty()) {
                second.push(first.top());
                first.pop();
            }

            return second.top();
        } else {
            return second.top();
        }
    }
};

int main() {

    Queue q;

    q.push(1);
    cout << q.front() << " ";
    q.push(2);
    cout << q.front() << " ";

    q.pop();
    cout << q.front() << " ";
    q.pop();

    q.push(4);
    cout << q.front() << " ";
    q.pop();
    q.push(5);
    cout << q.front() << " ";
    q.push(6);
    cout << q.front() << " ";

    // 1 1 2 4 5 5

    return 0;
}
