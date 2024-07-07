#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
    queue<int> q;

    Stack() = default;

    void add(int value) {
        this -> q.push(value);

        for(int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if(!q.empty())
            this -> q.pop();
        else
            cout << "stack is empty.\n";
    }

    int top() {
        if (!q.empty()) {
            return q.front();
        } else {
            cout << "stack is empty.\n";
            return -1;
        }
    }

    bool empty() const {
        return q.empty();
    }

    size_t size() const {
        return q.size();
    }
};

int main() {

    Stack st;

    st.add(5);
    cout << st.top() << "\n";
    st.add(6);
    cout << st.top() << "\n";
    st.add(2);
    cout << st.top() << "\n";
    st.add(9);
    cout << st.top() << "\n";

    st.pop();

    cout << st.top() << "\n";

    return 0;
}
