#include <iostream>
using namespace std;

class Node {
public:
    string word;
    int integer;

    Node *nextW {};
    Node *nextI {};
    Node *prevW {};
    Node *prevI {};

    Node(string word, int integer) {
        this -> word = word;
        this -> integer = integer;
    }
};

class SortedMultiLinkedList {
public:
    Node *headW {};
    Node *headI {};

    SortedMultiLinkedList() = default;

    void add(string word, int integer) {
        auto node = new Node(word, integer);
        auto currentW = this -> headW;
        auto currentI = this -> headI;

        if(currentW == nullptr) {
            headW = node;
        } else {
            while(currentW != nullptr && currentW -> word < word) {
                currentW = currentW -> nextW;
            }

            if(currentW == nullptr) {
                auto tailW = headW;
                while(tailW -> nextW != nullptr)
                    tailW = tailW -> nextW;

                tailW -> nextW = node;
                node -> prevW = tailW;
            } else if(currentW -> prevW == nullptr) {
                node -> nextW = headW;
                headW -> prevW = node;
                headW = node;
            } else {
                node -> nextW = currentW;
                node -> prevW = currentW -> prevW;
                currentW -> prevW -> nextW = node;
                currentW -> prevW = node;
            }
        }

        if(currentI == nullptr) {
            headI = node;
        } else {
            while(currentI != nullptr && currentI -> integer < integer) {
                currentI = currentI -> nextI;
            }

            if(currentI == nullptr) {
                auto tailW = headI;
                while(tailW -> nextI != nullptr)
                    tailW = tailW -> nextI;

                tailW -> nextI = node;
                node -> prevI = tailW;
            } else if(currentI -> prevI == nullptr) {
                node -> nextI = headI;
                headI -> prevI = node;
                headI = node;
            } else {
                node -> nextI = currentI;
                node -> prevI = currentI -> prevI;
                currentI -> prevI -> nextI = node;
                currentI -> prevI = node;
            }
        }
    }
};

class IteratorFirst {
public:
    Node *head;
    Node *current;

    IteratorFirst(SortedMultiLinkedList smll) {
        this -> head = smll.headW;
        this -> current = this -> head;
    }

    void next() {
        if(!valid()) {
            throw runtime_error("invalid!\n");
        } else {
            this -> current = this -> current -> nextW;
        }
    }

    string getCurrent() {
        return this -> current -> word;
    }

    void first() {
        this -> current = this -> head;
    }

    bool valid() {
        return this -> current != nullptr;
    }
};

class IteratorSecond {
public:
    Node *head;
    Node *current;

    IteratorSecond(SortedMultiLinkedList smll) {
        this -> head = smll.headI;
        this -> current = this -> head;
    }

    void next() {
        if(!valid()) {
            throw runtime_error("invalid!\n");
        } else {
            this -> current = this -> current -> nextI;
        }
    }

    int getCurrent() {
        return this -> current -> integer;
    }

    void first() {
        this -> current = this -> head;
    }

    bool valid() {
        return this -> current != nullptr;
    }
};

int main() {
    SortedMultiLinkedList smll;

    smll.add("abc", 19);
    smll.add("aaa", 16);
    smll.add("bab", 21);
    smll.add("abb", 18);

    IteratorFirst iterFirst(smll);
    while(iterFirst.valid()) {
        cout << iterFirst.getCurrent() << " ";
        iterFirst.next();
    }
    cout << "\n\n";

    IteratorSecond iterSecond(smll);
    while(iterSecond.valid()) {
        cout << iterSecond.getCurrent() << " ";
        iterSecond.next();
    }
}
