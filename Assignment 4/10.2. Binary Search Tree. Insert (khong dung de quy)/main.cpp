#include <bits/stdc++.h>
using namespace std;


class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
        void preOrder(Node *root) {

            if( root == NULL )
                return;
            std::cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }

    Node * insert(Node *root, int data) {
        Node *cur = new Node(data);
        if (root == NULL) {
            return cur;
        }
        Node *prev = NULL;
        Node *temp = root;
        while (temp != NULL) {
            if (temp->data > data) {
                prev = temp;
                temp = temp->left;
            }
            else if (temp->data < data) {
                prev = temp;
                temp = temp->right;
            }
        }
        if (prev->data > data)
            prev->left = cur;
        else
            prev->right = cur;
        return root;
    }
};

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.preOrder(root);

    cin >> data;
    root = myTree.insert(root, data);
    myTree.preOrder(root);

    return 0;
}
