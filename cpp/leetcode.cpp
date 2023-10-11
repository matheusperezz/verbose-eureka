//
// Created by Matheus on 04/10/2023.
//
// Problem 101  - Symetric BTree                                        - 04/10/23.
// Problem 104  - Maximum Depth of Binary Tree                          - 04/10/23.
// Problem 28   - Find the Index of the First Occurrence in a String    - 05/10/23.
// Problem 58   - Length of Last Word                                   - 06/10/23.
// Problem 66   - Plus One                                              - 07/10/23.
// Problem 67   - Add Binary                                            - 08/10/23.
// Problem 69   - MySquareRoot                                          - 09/10/23.
// Problem 83   - Remove Duplicates from Sorted List                    - 09/10/23.
// Problem 88   - Merge Sorted Array                                    - 10/10/23.


#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <bitset>
#include <queue>

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

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
        while (iss >> w) {
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

class Solution66 {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        vector<int> result(n, 0);
        int carry = 1;

        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            result[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry > 0) {
            result.insert(result.begin(), carry);
        }

        return result;
    }
};

void solution_66() {
    vector<int> v = {6, 1, 4, 5, 3, 9, 0, 1, 9, 5, 1, 8, 6, 7, 0, 5, 5, 4, 3};
    Solution66 s;
    vector<int> output = s.plusOne(v);
    for (auto &e: output)
        cout << e << " ";

    cout << endl;
}

class Solution67 {
public:
    string addBinary(string a, string b) {
        // Certifies that two strings has the same size, filled with zeros
        // if needed

        int l1 = a.length();
        int l2 = b.length();
        int max_l = max(l1, l2);

        a = string(max_l - l1, '0') + a;
        b = string(max_l - l2, '0') + b;

        string result;
        int carry = 0;

        // Make the binary add from right to the left
        for (int i = max_l - 1; i >= 0; i--) {
            int bit1 = a[i] - '0';
            int bit2 = b[i] - '0';

            int sum = bit1 + bit2 + carry;
            result.insert(result.begin(), '0' + (sum % 2));
            carry = sum / 2;
        }

        if (carry > 0) {
            result.insert(result.begin(), '0' + carry);
        }

        return result;
    }
};

void solution_67() {
    Solution67 s;
    string a = "110";   // 6    0110
    string b = "11";    // 3    0011
    //      1001
    string output = s.addBinary(a, b);
    cout << "Output: " << output << endl;
}

class Solution69 {
public:
    int mySqrt(int x) {
        return (int) sqrt(x);
    }

    int mySqrt2(int x) {
        int low = 0;
        int high = x;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (mid * mid == x) return mid;
            else if (mid * mid > x) high = mid - 1;
            else low = mid + 1;

        }
        // return the lower bound of the number
        return high;
    }
};

void solution_69() {
    Solution69 s;
    int output = s.mySqrt(8);
}

class Solution83 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current && current->next) {
            if (current->val == current->next->val){
                ListNode* duplicate = current->next;
                current->next = duplicate->next;
                delete duplicate;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};

void solution_83(){
    Solution83 s;
    ListNode* h = new ListNode(2);
    h->next = new ListNode(3);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(4);
    h->next->next->next->next->next = new ListNode(4);
    h->next->next->next->next->next->next = new ListNode(5);

    s.deleteDuplicates(h);
    ListNode* c = h;
    while (c != nullptr){
        cout << c->val << " ";
        c = c->next;
    }
    cout << endl;
}

class Solution88 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> output;
        int m_counter = 0;
        int n_counter = 0;

        while (m_counter != m && n_counter != n){
            if (nums1[m_counter] <= nums2[n_counter]){
                output.push_back(nums1[m_counter]);
                m_counter++;
            } else {
                output.push_back(nums2[n_counter]);
                n_counter++;
            }
        }

        while (m_counter != m){
            output.push_back(nums1[m_counter]);
            m_counter++;
        }

        while (n_counter != n){
            output.push_back(nums2[n_counter]);
            n_counter++;
        }

        nums1 = output;
    }
};

void solution_88(){
    vector<int> a = {1};
    vector<int> b = {};

    int m = 0;
    int n = 0;

    Solution88 s;
    s.merge(a, m, b, n);

    for (auto &e : a)
        cout << e << " ";

    cout << endl;
}

class Solution100 {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) {
            return true;
        }

        if (!p || !q) {
            return false;
        }

        queue<TreeNode *> q1;
        queue<TreeNode *> q2;

        q1.push(p);
        q2.push(q);

        while (!q1.empty() || !q2.empty()) {
            TreeNode *node1 = q1.front();
            TreeNode *node2 = q2.front();

            if (node1->val != node2->val) {
                return false;
            }

            q1.pop();
            q2.pop();
            // If the node has not NULLPTR, is True
            if (node1->left && node2->left) {
                q1.push(node1->left);
                q2.push(node2->left);
            } else if (node1->left || node2->left) {
                return false;
            }

            if (node1->right && node2->right) {
                q1.push(node1->right);
                q2.push(node2->right);
            } else if (node1->right || node2->right) {
                return false;
            }

        }

        return true;
    }
};

void solution_100() {
    TreeNode *root1 = new TreeNode(1);

    TreeNode *root2 = new TreeNode(0);

    Solution100 s;
    bool output = s.isSameTree(root1->right, root2->right);
    cout << "Is the trees the same? " << (output ? "true" : "false") << endl;
}