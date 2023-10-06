//
// Created by Matheus on 04/10/2023.
//
// Problem 101  - Symetric BTree                                        - 04/10/23.
// Problem 104  - Maximum Depth of Binary Tree                          - 04/10/23.
// Problem 28   - Find the Index of the First Occurrence in a String    - 05/10/23.
// Problem 58   - Length of Last Word                                   - 06/10/23.


#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int minhaFuncao() {
    return 42;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* Solutions */
class Solution28 {
public:
    int strStr(string haystack, string needle) {
        int needle_len = needle.length();
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack.substr(i, needle_len) == needle) {
                return i;
            }
        }
        return -1;
    }
};

void solution_28() {
    Solution28 s;
    int output = s.strStr("leetcode", "leeto");
    cout << "Output: " << output << endl;
}

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

class Solution104 {
public:
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);

        return max(leftMax, rightMax) + 1;
    }
};

void solution_104() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(5);

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(8);
    root->right->left->right = new TreeNode(98);

    Solution104 s;
    int depth = s.maxDepth(root);
    cout << "Max Depth: " << depth << endl;
}

class Solution58 {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        vector<string> words;
        string w;
        while (iss >> w){
            words.push_back(w);
        }
        int result = words.back().length();
        return result;
    }
};

void solution_58() {
    Solution58 s;
    int output = s.lengthOfLastWord("   fly me   to   the moon  ");
    cout << output << endl;
}