#include <iostream>
using namespace std;

class Stacks {
private:
    int array[20];
    int index1, index2;
    int capacity = 20;

public:

    Stacks() {
        this -> index1 = 0;
        this -> index2 = this -> capacity - 1;
    }

    void push1(int value) {
        if(this -> index1 <= this -> index2)
            this -> array[this -> index1++] = value;
        else
            throw overflow_error("stack overflow!\n");
    }

    void push2(int value) {
        if(this -> index1 <= this -> index2)
            this -> array[this -> index2--] = value;
        else
            throw overflow_error("stack overflow!\n");
    }

    void pop1() {
        if(this -> index1 > 0)
            this -> index1--;
        else
            throw underflow_error("stack underflow!\n");
    }

    void pop2() {
        if(this -> index2 < capacity - 1)
            this -> index2++;
        else
            throw underflow_error("stack underflow!\n");
    }

    int top1() {
        if(this -> index1 > 0)
            return this -> array[this -> index1 - 1];
        else
            throw runtime_error("stack is empty\n");
    }

    int top2() {
        if(this -> index2 < capacity - 1)
            return this -> array[this -> index2 + 1];
        else
            throw runtime_error("stack is empty!\n");
    }
};

int main() {
    Stacks s;

    s.push1(1);
    cout << s.top1() << " "; // 1
    s.push1(2);
    cout << s.top1() << " "; // 2
    s.push1(3);
    cout << s.top1() << " "; // 3

    s.pop1();
    cout << s.top1() << " "; // 2

    s.push2(4);
    cout << s.top2() << " "; // 4
    s.push2(5);
    cout << s.top2() << " "; // 5
    s.push2(6);
    cout << s.top2() << " "; // 6

    s.pop2();
    cout << s.top2() << " "; // 5

    return 0;
}
