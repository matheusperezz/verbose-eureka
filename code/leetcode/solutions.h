#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ListNode;
ListNode* removeNthFromEnd(ListNode* head, int n);
vector<string> letterCombinations(string digits);
int threeSumClosest(vector<int>& nums, int target);
vector<vector<int>> threeSum(vector<int>& nums);
int maxArea(vector<int>& height);
string longestPalindrome(string s);
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
int lengthOfLongestSubstring(string s);
void addTwoNumbersLinkedLists(ListNode* l1, ListNode* l2);
ListNode* reverseList(ListNode* head);

#endif