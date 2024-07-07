#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int info;
    Node *left;
    Node *right;

    Node(int info, Node *left = nullptr, Node *right = nullptr) {
        this -> info = info;
        this -> left = left;
        this -> right = right;
    }
};

class BinaryTree {
public:
    Node *root;

    BinaryTree(Node *root) {
        this -> root = root;
    }

    bool isMinHeap() {
        if (root == nullptr) 
            return true;

        queue<Node*> q;
        q.push(root);

        bool flag = false;

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp -> left != nullptr) {
                if (flag) 
                    return false;
                if (temp -> info > temp -> left -> info)
                    return false;
                q.push(temp -> left);
            } else {
                flag = true;
            }

            if (temp -> right != nullptr) {
                if (flag)
                    return false;
                if (temp -> info > temp -> right -> info)
                    return false;
                q.push(temp -> right);
            } else {
                flag = true;
            }
        }
        return true;
    }
};

int main() {
    auto node7 = new Node(7);
    auto node6 = new Node(6);
    auto node5 = new Node(5);
    auto node4 = new Node(4);

    auto node3 = new Node(3, node4, node5);
    auto node2 = new Node(2, node6, node7);
    auto node1 = new Node(1, node2, node3);

    BinaryTree bt(node1);
    cout << bt.isMinHeap();
}
