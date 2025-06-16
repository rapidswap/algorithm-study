#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<char, TreeNode*> nodes;
    for (char c = 'A'; c <= 'Z'; ++c) {
        nodes[c] = new TreeNode(c);
    }

    for (int i = 0; i < n; ++i) {
        char parent_char, left_char, right_char;
        cin >> parent_char >> left_char >> right_char;

        TreeNode* parent_node = nodes[parent_char];

        if (left_char != '.') {
            parent_node->left = nodes[left_char];
        }
        if (right_char != '.') {
            parent_node->right = nodes[right_char];
        }
    }

    TreeNode* root = nodes['A'];

    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';

    for (char c = 'A'; c <= 'Z'; ++c) {
        if (nodes.count(c)) {
            delete nodes[c];
        }
    }

    return 0;
}
