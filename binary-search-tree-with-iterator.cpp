#include <iostream>
using namespace std;

class Node {
public:
    int info;

    Node *parent;
    Node *left;
    Node *right;

    Node(int info, Node *parent = nullptr, Node *left = nullptr, Node *right = nullptr) {
        this -> info = info;
        this -> parent = parent;
        this -> left = left;
        this -> right = right;
    }
};

class BinarySearchTree {
public:
    Node *root;

    BinarySearchTree(Node *root = nullptr): root(root) {}

    void add(int value) {
        this -> root = addRecursive(root, value, nullptr);
    }

    Node *addRecursive(Node *current, int value, Node *parent) {
        if (current == nullptr) {
            current = new Node(value);
            current -> parent = parent;
        } else {
            if (value < current -> info) {
                current -> left = addRecursive(current -> left, value, current);
            } else {
                current -> right = addRecursive(current -> right, value, current);
            }
        }

        return current;
    }

    void inorder(Node *node) {
        if(node != nullptr) {
            inorder(node -> left);
            cout << node->info << " ";
            inorder(node -> right);
        }
    }
};

class BinarySearchTreeIterator {
public:
    Node *current;
    BinarySearchTree bst;

    BinarySearchTreeIterator(BinarySearchTree bst) {
        this -> bst = bst;
        if(bst.root != nullptr) {
            current = bst.root;
            while(current -> left != nullptr) {
                current = current -> left;
            }
        }
    }

    void first() {
        current = this -> bst -> root;
        if(current != nullptr) {
            while(current -> left != nullptr) {
                current = current -> left;
            }
        }
    }

    void next() {
        if(valid()) {
            if (current -> right != nullptr) {
                current = current -> right;
                while (current -> left != nullptr) {
                    current = current -> left;
                }
            } else {
                Node *parent = current -> parent;

                while (parent != nullptr && parent -> left != current) {
                    current = parent;
                    parent = parent->parent;
                }

                current = parent;
            }
        } else {
            throw runtime_error("no next!\n");
        }
    }

    int getCurrent() {
        return current -> info;
    }

    bool valid() {
        return this -> current != nullptr;
    }
};

int main() {
    auto node1 = new Node(4);
    BinarySearchTree bst(node1);
    bst.add(2);
    bst.add(6);
    bst.add(5);
    bst.add(7);
    bst.add(3);

    bst.inorder(bst.root);
    cout << "\n\n";

    BinarySearchTreeIterator iter(bst);

    while (iter.valid()) {
        cout << iter.getCurrent() << " ";
        iter.next();
    }
    cout << endl;
}
