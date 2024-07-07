#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(const string& postfix) {
    stack<int> st;

    for (char elem : postfix) {
        if (isdigit(elem)) {
            st.push(elem - '0');
        } else {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            int res;
            switch (elem) {
                case '+': res = op2 + op1; break;
                case '-': res = op2 - op1; break;
                case '*': res = op2 * op1; break;
                case '/': res = op2 / op1; break;
                default: return 0;
            }
            st.push(res);
        }
    }

    int result = st.top();
    st.pop();
    return result;
}

int main() {
    std::string postfix = "231*+9-";
    int result = evaluatePostfix(postfix);
    cout << "result: " << result << "\n";
    return 0;
}
