
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
// Problem 100  - Same Tree                                             - 11/10/23.
// Problem 110  - Balanced Binary                                       - 12/10/23.
// Problem 108  - Convert Sorted Array to Binary Search Tree            - 13/10/23.
// Problem 111  - Minimum Depth of Binary Tree                          - 14/10/23.
// Problem 112  - Path sum                                              - 16/10/23.
// Problem 118  - Pascal's Triangle                                     - 16/10/23.
// Problem 119  - Pascal's Triangle II                                  - 17/10/23.
// Problem 121  - Best Time to Buy and Sell                             - 19/10/23.
// Problem 125  - Valid Palindrome                                      - 20/10/23.
// Problem 125  - Sinlge Number                                         - 21/10/23.
// Problem 141  - Linked List                                           - 22/10/23.
// Problem 144  - Binary Tree Preorder Traversal                        - 23/10/23.
// Problem 145  - Binary Tree Postrder Traversal                        - 24/10/23.
// Problem 160  - Intersection of Two Linked Lists                      - 25/10/23.
// Problem 168  - Excel Sheet Column Title                              - 25/10/23.
// Problem 169  - Majority Element                                      - 26/10/23.
// Problem 171  - Excel Sheet Column Number                             - 29/10/23.
// Problem 190  - Reverse Bits                                          - 29/10/23.
// Problem 190  - Number of 1 Bits                                      - 30/10/23.
// Problem 202  - Happy Number                                          - 01/11/23.
// Problem 203  - Remove Linked List Elements                           - 02/11/23.
// Problem 205  - Isomorphic Strings                                    - 03/11/23.
// Problem 206  - Reversed Linked List                                  - 03/11/23.
// Problem 217  - Contains Duplicate                                    - 04/11/23.
// Problem 217  - Contains Duplicate II                                 - 05/11/23.
// Problem 222  - Count Complete Tree Nodes                             - 06/11/23.
// Problem 226  - Invert Binary Trees                                   - 08/11/23.

#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <bitset>
#include <cctype>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <cstdint>
#include <unordered_set>

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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *current = head;
        while (current && current->next) {
            if (current->val == current->next->val) {
                ListNode *duplicate = current->next;
                current->next = duplicate->next;
                delete duplicate;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};

void solution_83() {
    Solution83 s;
    ListNode *h = new ListNode(2);
    h->next = new ListNode(3);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(4);
    h->next->next->next->next->next = new ListNode(4);
    h->next->next->next->next->next->next = new ListNode(5);

    s.deleteDuplicates(h);
    ListNode *c = h;
    while (c != nullptr) {
        cout << c->val << " ";
        c = c->next;
    }
    cout << endl;
}

class Solution88 {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> output;
        int m_counter = 0;
        int n_counter = 0;

        while (m_counter != m && n_counter != n) {
            if (nums1[m_counter] <= nums2[n_counter]) {
                output.push_back(nums1[m_counter]);
                m_counter++;
            } else {
                output.push_back(nums2[n_counter]);
                n_counter++;
            }
        }

        while (m_counter != m) {
            output.push_back(nums1[m_counter]);
            m_counter++;
        }

        while (n_counter != n) {
            output.push_back(nums2[n_counter]);
            n_counter++;
        }

        nums1 = output;
    }
};

void solution_88() {
    vector<int> a = {1};
    vector<int> b = {};

    int m = 0;
    int n = 0;

    Solution88 s;
    s.merge(a, m, b, n);

    for (auto &e: a)
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

class Solution110 {
public:
    int getHeight(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    int getHeight2(TreeNode *root) {
        if (root == nullptr) return 0;

        int left = getHeight2(root->left);
        int right = getHeight2(root->right);

        if (left == -1 or right == -1 or abs(left - right) > 1) return -1;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (abs(leftHeight - rightHeight) <= 1 and isBalanced(root->left) and isBalanced(root->right)) {
            return true;
        }

        return false;
    }

    bool isBalanced2(TreeNode *root) {
        if (root == nullptr) return true;
        if (getHeight2(root) == -1) return false;
        return true;
    }
};

void solution_110() {
    Solution110 s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    bool varIsBalanced = s.isBalanced(root);

    if (varIsBalanced) {
        cout << "A árvore está balanceada." << endl;
    } else {
        cout << "A árvore não está balanceada." << endl;
    }
}

class Solution108 {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        /**
         *  First of all, i can take the center of vector to be the root
         *
         *  After that, take the left side of the array and the right side of the array
         *
         *  Finally, do the recursive to fill the tree
         */
        if (nums.empty()) {
            return nullptr;
        }

        int mid = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        vector<int> leftSubTree(nums.begin(), nums.begin() + mid);
        vector<int> rightSubTree(nums.begin() + mid + 1, nums.end());

        root->left = sortedArrayToBST(leftSubTree);
        root->right = sortedArrayToBST(rightSubTree);

        return root;
    }

    void printTree(TreeNode *root) {
        if (root) {
            printTree(root->left);
            cout << root->val << " ";
            printTree(root->right);
        }
    }
};

void solution_108() {
    Solution108 s;
}

class Solution111 {
public:
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }

        // if the nodes are nullptr, calc the oposite side depth
        if (!root->left) {
            return minDepth(root->right) + 1;
        }

        if (!root->right) {
            return minDepth(root->left) + 1;
        }

        int leftMax = minDepth(root->left);
        int rightMax = minDepth(root->right);

        return min(leftMax, rightMax) + 1;
    }
};

void solution_111() {
    // [2,null,3,null,4,null,5,null,6]
    TreeNode *root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(5);
    root->right->right->right->right = new TreeNode(6);


    Solution111 s;
    int outputMinDepth = s.minDepth(root);

    cout << "Min Depht: " << outputMinDepth << endl;

    vector<int> nums = {-10, -3, 0, 5, 9};
    vector<int> nums2 = {1, 3};

    // TreeNode* output = s.sortedArrayToBST(nums2);
}

class Solution112 {
public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        return mapRootToLeaf(root, targetSum, 0);
    }

    bool mapRootToLeaf(TreeNode *node, int targetSum, int currentSum) {
        if (node == nullptr) {
            return false;
        }

        currentSum += node->val;

        if (node->left == nullptr && node->right == nullptr) {
            return currentSum == targetSum;
        }

        // Verifying the left and right paths
        bool leftPath = mapRootToLeaf(node->left, targetSum, currentSum);
        bool rightPath = mapRootToLeaf(node->right, targetSum, currentSum);

        return leftPath || rightPath;
    }
};

void solution_112() {
    Solution112 s;

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    bool result = s.hasPathSum(root, 29);
    cout << "The target as been find? " << (result ? "True" : "False") << endl;

}

class Solution118 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; i++) {
            vector<int> row;

            if (i == 0) {
                row.push_back(1);
            } else {
                row.push_back(1);
                for (int j = 1; j < i; j++) {
                    int num = triangle[i - 1][j - 1] + triangle[i - 1][j];
                    row.push_back(num);
                }

                row.push_back(1);
            }
            triangle.push_back(row);
        }

        return triangle;
    }
};

void solution_118() {
    Solution118 s;
    vector<vector<int>> result = s.generate(4);
    for (auto &i: result) {
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

class Solution119 {
public:
    vector<int> getRow(int rowIndex) {

        vector<vector<int>> triangle;

        for (int i = 0; i <= rowIndex; i++) {
            vector<int> row;

            if (i == 0) {
                row.push_back(1);
            } else {
                row.push_back(1);
                for (int j = 1; j < i; j++) {
                    int num = triangle[i - 1][j - 1] + triangle[i - 1][j];
                    row.push_back(num);
                }

                row.push_back(1);
            }
            triangle.push_back(row);
        }

        return triangle.back();
    }
};

void solution_119() {
    Solution119 s;
    vector<int> result = s.getRow(3);
    for (auto &e: result)
        cout << e << " ";

    cout << endl;
}

class Solution121 {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int price: prices) {
            if (price < minPrice) {
                minPrice = price;
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }

        return maxProfit;
    }

    int maxProfit2(vector<int> &prices) {
        int currMin = prices[0];
        int minIndex = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (currMin > prices[i]) {
                currMin = prices[i];
                minIndex = i;
            }
        }

        if (minIndex == prices.size() - 1) {
            return 0;
        }

        auto currMax = max_element(prices.begin() + minIndex, prices.end());

        cout << "currmax: " << *currMax << " currmin: " << currMin << endl;
        return (*currMax - currMin);
    }
};

void solution_121() {
    Solution121 s;
    vector<int> arr = {2, 4, 1};
    int a = s.maxProfit(arr);
    cout << "result: " << a << endl;
}

class Solution125 {
public:
    bool isPalindrome(string s) {
        for (char &c: s) {
            c = tolower(c);
        }

        // remove non alphanumeric chars
        s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }), s.end());

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

void solution_125() {
    Solution125 s;
    string test = "aA";
    bool result = s.isPalindrome(test);
    cout << "Is a palindrome? " << (result ? "Yes" : "No") << endl;
}

class Solution136 {
public:
    int singleNumber(vector<int> &nums) {
        int result = 0;

        for (int n: nums) {
            // result XOR n
            // This makes the sum of unique numbers, once the number has twice appers, his subtract the value duplicated
            // Just keeping the unique number
            result ^= n;
        }

        return result;
    }
};

void solution_136() {
    Solution136 s;
    vector<int> inputVector = {4, 1, 2, 1, 2};
    int result = s.singleNumber(inputVector);
    cout << "Non duplicated item: " << result << endl;
}

class Solution141 {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }

        auto *slow = head;
        auto *fast = head;

        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

void solution_141() {
    auto *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);

    Solution141 s;
    bool result = s.hasCycle(head);
    cout << "Is a Cycle?: " << (result ? "Yes" : "False") << endl;

}

class Solution144 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> output;
        stack<TreeNode *> nodeStack;
        auto *current = root;
        while (current != nullptr or !nodeStack.empty()) {
            while (current != nullptr) {
                nodeStack.push(current);
                output.push_back(current->val);
                current = current->left;
            }

            current = nodeStack.top();
            nodeStack.pop();
            current = current->right;
        }

        return output;
    }
};

void solution_144() {
    Solution144 s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    auto result = s.preorderTraversal(root);
    for (int c: result) {
        cout << c << " ";
    }
    cout << endl;
}

class Solution145 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> output;
        stack<TreeNode *> nodeStack;
        TreeNode *current = root;
        TreeNode *lastVisited = nullptr;

        while (current != nullptr or !nodeStack.empty()) {
            if (current != nullptr) {
                nodeStack.push(current);
                current = current->left;
            } else {
                TreeNode *peekNode = nodeStack.top();
                if (peekNode->right != nullptr and lastVisited != peekNode->right) {
                    // If the right node is not visited, visit!
                    current = peekNode->right;
                } else {
                    // Else, visited the current node
                    output.push_back(peekNode->val);
                    lastVisited = peekNode;
                    nodeStack.pop();
                }
            }
        }

        return output;
    }
};

void solution_145() {
    Solution145 s;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    auto result = s.postorderTraversal(root);
    for (int r: result) {
        cout << r << " ";
    }
    cout << endl;
}

class Solution160 {
private:
    int getLength(ListNode *head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        // make the two lists on the same size
        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }

        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }

        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr; // No intersection
    }
};

void solution_160() {
    Solution160 s;

    // ListA
    auto *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    // ListB
    auto *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = new ListNode(8);
    headB->next->next->next->next = new ListNode(4);
    headB->next->next->next->next->next = new ListNode(5);

    auto result = s.getIntersectionNode(headA, headB);
    cout << "Result = " << result->val << endl;

}

class Solution168 {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while (columnNumber > 0) {
            int rem = (columnNumber - 1) % 26;
            result = char('A' + rem) + result;
            columnNumber = (columnNumber - 1) / 26;
        }
        return result;
    }
};

void solution_168() {
    Solution168 s;
    string result = s.convertToTitle(4208);
    cout << "Result: " << result << endl;
}

class Solution169 {
public:
    // 3, 2, 3
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> count;
        int majority = -1;
        int maxCount = 0;

        for (const int num: nums) {
            count[num]++;
            if (count[num] > maxCount) {
                maxCount = count[num];
                majority = num;
            }
        }

        if (maxCount > nums.size() / 2) {
            return majority;
        } else {
            return -1;
        }
    }
};

void solution_169() {
    Solution169 s;
    vector<int> v = {3, 2, 3};
    auto output = s.majorityElement(v);
    cout << "Output: " << output << endl;
}

class Solution171 {
public:
    int titleToNumber(string columnTitle) {
        // Basically a number format with 26base
        int result = 0;
        int multiplier = 1;

        for (int i = columnTitle.size() - 1; i >= 0; --i) {
            // ASCII Table operation
            int value = columnTitle[i] - 'A' + 1;
            cout << "Columntitle[i] " << columnTitle[i] << "  -  (A+1) " << ('A' + 1) << " Result: " << value << endl;
            result += value * multiplier;
            multiplier *= 26;
        }
        return result;
    }
};

void solution_171() {
    Solution171 s;
    string input = "AB";
    int output = s.titleToNumber(input);
    cout << "result is: " << output << endl;
}

class Solution190 {
private:
    unordered_map<char, int> nums;
public:
    Solution190() {
        nums['0'] = 0;
        nums['1'] = 1;
        nums['2'] = 2;
        nums['3'] = 3;
        nums['4'] = 4;
        nums['5'] = 5;
        nums['6'] = 6;
        nums['7'] = 7;
        nums['8'] = 8;
        nums['9'] = 9;
    }

    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int bitPosition = 31; // Starting at the leftter (?) bit position

        while (n > 0) {
            uint32_t bit = n & 1; // get the less significant bit
            result |= (bit << bitPosition); // Define the correspondent bit on operation
            n >>= 1; // Change the bit to the right
            bitPosition--;
        }

        return result;
    }

    uint32_t reverseBits2(uint32_t n) {
        uint32_t result = 0;
        // Convert to Binary
        auto bit_string = bitset<32>(n).to_string();
        // Invert the bits
        string inverted_bits;
        for (int i = bit_string.size() - 1; i >= 0; i--) {
            inverted_bits += bit_string[i];
        }
        // Converto to decimal
        int controller = 0;
        for (int j = 0; j < inverted_bits.size(); j++) {
            result += nums[inverted_bits[j]] * pow(2, j);
        }
        // Return
        return result;
    }
};

void solution_190() {
    Solution190 s;
    uint32_t input = 964176192;
    auto result = s.reverseBits(input);
    cout << "result: " << result << endl;
}

class Solution191 {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for (int bitPos = 0; bitPos < 32; ++bitPos) {
            uint32_t mask = 1 << bitPos;
            if ((n & mask) != 0) {
                result++;
            }
        }
        return result;
    }
};

void solution_191() {
    Solution191 s;
    uint32_t input = 11;
    int output = s.hammingWeight(input);
    cout << "Result: " << output << endl;
}

class Solution202 {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1) {
            if (seen.find(n) != seen.end()) {
                return false; // Detected a cycle, so it's not a happy number
            }

            seen.insert(n);
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return true; // If n reaches 1, it's a happy number
    }
};

void solution_202() {
    Solution202 s;
    bool result = s.isHappy(2);
    cout << "Is a happy number? " << (result ? "Yes" : "No") << endl;
}

class Solution203 {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        auto current = head;
        while (current) {
            if (current->val == val) {
                auto temp = current;
                prev->next = current->next;
                current = current->next;
                delete temp;
            } else {
                prev = current;
                current = current->next;
            }
        }
        return dummy.next;
    }
};

void solution_203() {
    Solution203 s;
    /*
        Input: head = [1,2,6,3,4,5,6], val = 6
        Output: [1,2,3,4,5]
     */
    int val = 6;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    ListNode *output = s.removeElements(head, val);
    auto current = output;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

class Solution205 {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, char> sToT;
        std::unordered_map<char, char> tToS;

        for (int i = 0; i < s.length(); i++) {
            char charS = s[i];
            char charT = t[i];

            // Verificar o mapeamento de s para t
            if (sToT.find(charS) == sToT.end()) {
                sToT[charS] = charT;
            } else if (sToT[charS] != charT) {
                return false;
            }

            // Verificar o mapeamento de t para s
            if (tToS.find(charT) == tToS.end()) {
                tToS[charT] = charS;
            } else if (tToS[charT] != charS) {
                return false;
            }
        }

        return true;
    }
};

void solution_205() {

}

class Solution206 {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *current = head;
        while (current) {
            ListNode *next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        return prev;
    }
};

void solution_206() {
    Solution206 s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    ListNode *output = s.reverseList(head);
    auto current = output;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

class Solution217 {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> seen;
        for (const int n: nums) {
            if (seen.find(n) != seen.end()) {
                return true;
            } else {
                seen.insert(n);
            }
        }
        return false;
    }
};

void solution_217() {
    Solution217 s;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 1, 8, 9};
    bool output = s.containsDuplicate(v);
    cout << "Contains duplicate ? " << (output ? "yes" : "no") << endl;
}

class Solution219 {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> elementIndexMap;

        for (int i = 0; i < nums.size(); i++) {
            if (elementIndexMap.find(nums[i]) != elementIndexMap.end()) {
                int prevIndex = elementIndexMap[nums[i]];
                if (abs(i - prevIndex) <= k) {
                    return true;
                }
            }
            elementIndexMap[nums[i]] = i;
        }

        return false;
    }
};

void solution_219() {
    Solution219 s;
    vector<int> v = {1,2,3,1,2,3};
    int k = 2;
    bool output = s.containsNearbyDuplicate(v, k);
    cout << "Contains nearby duplicates? " << (output ? "Yes":"No") << endl;
}

class Solution222 {
public:
    int countNodes(TreeNode* root) {
        int output = 0;
        stack<TreeNode *> nodeStack;
        auto *current = root;
        while (current != nullptr or !nodeStack.empty()) {
            while (current != nullptr) {
                nodeStack.push(current);
                output++;
                current = current->left;
            }

            current = nodeStack.top();
            nodeStack.pop();
            current = current->right;
        }

        return output;
    }
};

void solution_222(){
    auto* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);

    Solution222 s;
    int result = s.countNodes(root);
    cout << "Size of tree: " << result << endl;
}

class Solution226 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root){
            return nullptr;
        }
        TreeNode* aux = root->left;
        root->left = root->right;
        root->right = aux;

        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        return root;
    }
};

void solution_226(){

}