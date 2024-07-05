#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
    queue<int> first, second;

    Stack() = default;

    void push(int value) {
        first.push(value);
    }

    void pop() {
        if(first.empty()) {
            throw runtime_error("stack is empty!\n");
        }

        while(first.size() > 1) {
            second.push(first.front());
            first.pop();
        }

        first.pop();
        swap(first, second);
    }

    int top() {
        while(first.size() != 1) {
            second.push(first.front());
            first.pop();
        }

        int value = first.front();
        second.push(first.front());
        first.pop();
        swap(first, second);
        return value;
    }

};

int main() {
    Stack s;

    s.push(1);
    cout << s.top() << "\n";
    s.push(2);
    cout << s.top() << "\n";
    s.push(3);
    cout << s.top() << "\n";

    s.pop();
    cout << s.top() << "\n";
    s.pop();
    cout << s.top() << "\n";

    s.push(4);
    cout << s.top() << "\n";
    s.pop();
    cout << s.top() << "\n";

    // 1 2 3 2 1 4 1

    return 0;
}
