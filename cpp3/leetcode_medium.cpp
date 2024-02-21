//
// Created by Matheus on 14/02/2024.

#include <iostream>
#include <vector>
#include <algorithm>

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


class Solution39 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, result, current, 0);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& current, int start){
        if (target == 0){
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size() && candidates[i] <= target; i++){
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, current, i);
            current.pop_back();
        }
    }
};

void solution_39(){

}