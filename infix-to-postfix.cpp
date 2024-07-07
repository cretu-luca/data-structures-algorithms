#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int priority(char ch) {
    if(ch == '+' || ch == '-')
        return 1;

    return 2;
}

queue<char> transform(const string& expression) {
    stack<char> st;
    queue<char> q;

    for (char e : expression) {
        if (e >= '0' && e <= '9') {
            q.push(e);
        } else if (e == '(') {
            st.push(e);
        } else if (e == ')') {
            while (!st.empty() && st.top() != '(') {
                q.push(st.top());
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && st.top() != '(' && priority(st.top()) >= priority(e)) {
                q.push(st.top());
                st.pop();
            }
            st.push(e);
        }
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    return q;
}

void printQueue(queue<char> q) {
    while (!q.empty()) {
        cout << q.front();
        q.pop();
    }
    cout << endl;
}

int main() {
    string expression = "2+5*(2*3-4)/(1+2*3)-5";
    queue<char> postfix = transform(expression);
    printQueue(postfix);
    return 0;
}
