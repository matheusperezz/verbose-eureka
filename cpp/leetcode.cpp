//
// Created by Matheus on 04/10/2023.
// Problem 101 Leetcode

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution101 {
public:
    bool isSymetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        }

        if (!left || !right) {
            return false;
        }

        return (left->val == right->val &&
                isMirror(left->left, right->right) &&
                isMirror(left->right, right->left));
    }
};

void solution_101() {

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution101 solution101;
    bool output = solution101.isSymetric(root);
    cout << (output ? "true" : "false") << endl;
}

int minhaFuncao() {
    return 42;
}