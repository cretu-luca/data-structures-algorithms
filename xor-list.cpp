#include <iostream>
using namespace std;

class XORNode {
public:
    int info;
    XORNode *link;

    XORNode(int info = 0, XORNode *link = nullptr) {
        this -> info = info;
        this -> link = link;
    }
};

class XORList {
public:
    XORNode *head {};
    XORNode *tail {};

    XORList() = default;

    void add(int value) {
        auto node = new XORNode(value, head);
        if(head == nullptr) {
            head = node;
            tail = node;
        } else {
            head -> link = reinterpret_cast<XORNode*>(
                    reinterpret_cast<uintptr_t>(head -> link) ^ reinterpret_cast<uintptr_t>(node));
            head = node;
        }
    }

    void displayForward() const {
        XORNode *previous = nullptr;
        auto current = head;

        while(current != nullptr) {
            cout << current -> info << " ";
            auto nextNode = reinterpret_cast<XORNode*>(
                    reinterpret_cast<uintptr_t>(previous) ^ reinterpret_cast<uintptr_t>(current -> link));
            previous = current;
            current = nextNode;
        }

        cout << "\n";
    }

    void displayBackward() const {
        XORNode *previous = nullptr;
        auto current = tail;

        while(current != nullptr) {
            cout << current -> info << " ";
            auto nextNode = reinterpret_cast<XORNode*>(
                    reinterpret_cast<uintptr_t>(previous) ^ reinterpret_cast<uintptr_t>(current -> link));
            previous = current;
            current = nextNode;
        }

        cout << "\n";
    }
};

int main() {

    XORList list;

    for(int i = 0; i < 10; i++)
        list.add(i);

    list.displayForward();
    list.displayBackward();

    return 0;
}
