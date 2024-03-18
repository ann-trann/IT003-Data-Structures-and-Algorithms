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
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }


    void postOrder(Node *root) {
        if (root == NULL)
            return;
        stack<Node*> st1, st2;
        st1.push(root);

        while(!st1.empty()){
            Node *cur = st1.top();
            st1.pop();
            st2.push(cur);
            if (cur->left != NULL)
                st1.push(cur->left);
            if (cur->right != NULL)
                st1.push(cur->right);
        }
        while (!st2.empty()){
            Node *cur = st2.top();
            st2.pop();
            cout << cur->data << " ";
        }
    }

}; //End of Solution

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

    myTree.postOrder(root);

    return 0;
}
