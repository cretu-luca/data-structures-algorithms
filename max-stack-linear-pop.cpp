#include <iostream>
#include <stack>
using namespace std;

class MaxStack {
public:
    stack<int> st;
    stack<int> maxSt;
    stack<int> aux;

    MaxStack() = default;

    void push(int value) {
        this -> st.push(value);
        if (maxSt.empty()) {
            this -> maxSt.push(value);
        } else {
            this -> maxSt.push(max(value, maxSt.top()));
        }
    }

    void pop() {
        this -> st.pop();
        this -> maxSt.pop();
    }

    int top() {
        return this -> st.top();
    }

    int getMax() {
        return this -> maxSt.top();
    }

    void popMax() {
        int currentMax = this -> getMax();

        while(this -> getMax() == currentMax) {
            aux.push(st.top());
            st.pop();
            maxSt.pop();
        }

        aux.pop();

        while(!aux.empty()) {
            this -> push(aux.top());
            aux.pop();
        }
    }
};

int main() {
    MaxStack s;

    s.push(5);
    cout << s.getMax() << " ";
    s.push(3);
    cout << s.getMax() << " ";
    s.push(7);
    cout << s.getMax() << " ";
    s.push(10);
    cout << s.getMax() << " ";
    s.push(2);
    cout << s.getMax() << " ";
    s.push(1);
    cout << s.getMax() << "\n";

    s.popMax();
    cout << s.getMax() << "\n";
    s.popMax();
    cout << s.getMax() << "\n";
}
