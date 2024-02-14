//
// Created by Matheus on 14/02/2024.

#include <iostream>

using namespace std;

int testFunctionMediumLeetCode() {
    return 42;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

/*
 * Solutions
 */

class Solution24 {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *node = head;
        while (node != nullptr) {
            cout << node->val << " ";
            node = node->next;
        }
    }
};

void solution_24() {
    Solution24 s;
    auto *head = new ListNode(10);
    ListNode *current = head;

    // Adicionando os elementos restantes
    for (int i = 9; i > 0; --i) {
        current->next = new ListNode(i);
        current = current->next;
    }

    ListNode *temp = head;
    while (temp != nullptr) {

    }
}
