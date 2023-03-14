#include "solutions.h"
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;

        // Construtores
        ListNode(){
            val = 0;
            next = nullptr;
        }

        ListNode(int val){
            this->val = val;
            next = nullptr;
        }

        ListNode(int val, ListNode* next){
            this->val = val;
            this->next = next;
        }
};

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* previous = nullptr;

    while (curr != nullptr){
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }

    head = prev;

    // Agora podemos remover o n-ésimo elemento a partir do final
    ListNode* temp = head;
    for (int i = 1; i < n; i++){
        previous = temp;
        temp = temp->next;
    }
    
    if (temp->next == nullptr){
        if (previous == nullptr) {
            head = nullptr;
        } else {
            previous->next = previous->next->next;
        }
    } else {
        temp->val = temp->next->val;
        temp->next = temp->next->next;
    }

    // Invertendo novamente a lista
    prev = nullptr;
    curr = head;
    while (curr != nullptr){
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    
    return prev;
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()){
        return result;
    }
    unordered_map<char, string> map_digit = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    result.push_back("");

    for (char digit: digits){
        vector<string> new_result;
        for (char letter: map_digit[digit]){
            for (string combination : result){
                new_result.push_back(combination + letter);
            }
        }
        result = new_result;
    }


    return result;
}

int threeSumClosest(vector<int>& nums, int target){
    sort(nums.begin(), nums.end()); // ordena o vetor
    int closest = nums[0] + nums[1] + nums[2]; // inicializa com o primeiro triplo de valores
    for (size_t i = 0; i < nums.size() - 2; i++) {
        size_t j = i + 1, k = nums.size() - 1; // duas ponteiras
        while (j < k) {
            int current = nums[i] + nums[j] + nums[k];
            unsigned diff = (current > target) ? current - target : target - current; // calcula a diferença sem usar abs()
            if (diff == 0) return current; // caso especial: encontrou um triplo que soma exatamente o valor desejado
            if (diff < abs(target - closest)) closest = current; // atualiza o valor mais próximo
            (current > target) ? k-- : j++; // move a ponteira esquerda ou direita, dependendo do valor da soma
        }
    }
    return closest;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end()); // sort the input array
    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                res.push_back({nums[i], nums[left], nums[right]});
                ++left;
                --right;
                while (left < right && nums[left] == nums[left-1]) ++left; // skip duplicates
                while (left < right && nums[right] == nums[right+1]) --right; // skip duplicates
            } else if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }
    }
    return res;
}

int maxArea(vector<int>& height){
    int max_area = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right) {
        int curr_area = min(height[left], height[right]) * (right - left);
        max_area = max(max_area, curr_area);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max_area;
}

string longestPalindrome(string s){
    
    string result = "";
    for (int i = 0; i < s.length(); i++){
        
        if (s.length() - i < result.length()){
            break;
        }

        for (int j = i; j < s.length(); j++){

            string current = s.substr(i, j+1);
            if (current.length() < result.length()){
                continue;
            }

            string reversed = "";
            for ( int i = result.length() - 1; i >= 0; i-- ){
                reversed += result[i];
            }

            if (current == reversed && current.length() > result.length()){
                result = current;
            }
        }
    }

    return result;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){

    vector<int> merged(nums1.size() + nums2.size());
    int i = 0, j = 0, k = 0;

    while (i < nums1.size() && j < nums2.size()){
        if (nums1[i] < nums2[j]){
            merged[k] = nums1[i];
            i++;
        } else {
            merged[k] = nums2[j];
            j++;
        }
        k++;
    }

    while (i < nums1.size()){
        merged[k] = nums1[i];
        i++;
        k++;
    }

    while (j < nums2.size()){
        merged[k] = nums2[j];
        j++;
        k++;
    }

    int middleIndex = merged.size() / 2;
    if (merged.size() % 2 == 0){
        return (merged[middleIndex - 1] + merged[middleIndex]) / 2.0;
    } else {
        return merged[middleIndex];
    }
}

int lengthOfLongestSubstring(string s){
    
    unordered_set<char> substringChars;
    int maxLength = 1;
    int start = 0;

    for(int i = 0; i < s.length(); i++){
        char currentChar = s[i];
        if (substringChars.count(currentChar) > 0){
            while (s[start] != currentChar){
                substringChars.erase(s[start]);
                start++;
            }
            start++;
        } else {
            substringChars.insert(currentChar);
            maxLength = max(maxLength, i - start + 1);
        }

    }
    return maxLength;
}

void addTwoNumbersLinkedLists(ListNode* l1, ListNode* l2){
    long decimalControl = 1;
    long theSum = 0;

    ListNode* node1 = l1;
    while (node1 != nullptr){
        theSum += node1->val * decimalControl;
        decimalControl *= 10;
        node1 = node1->next;
    }

    decimalControl = 1;

    ListNode* node2 = l2;
    while (node2 != nullptr){
        theSum += node2->val * decimalControl;
        decimalControl *= 10;
        node2 = node2->next;
    }

    string reversed = "";
    string theSumString = to_string(theSum);
    for (int i = theSumString.length() - 1; i >= 0; i--){
        reversed += theSumString[i];
    }

    ListNode* head = new ListNode();
    ListNode* current = head;

    for (int i = 0; i < reversed.length(); i++){
        int val = stoi(string(1, reversed[i]));
        ListNode* newNode = new ListNode(val);
        current->next = newNode;
        current = newNode;
    }

    /*
     *      Mostrando Resultado do algoritmo
     *          NodeList1: 4 -> 5 -> 6 = 456
     *          NodeList2: 1 -> 3 -> 8 = 138
     *          456 + 138 = 594
     *          ListNodeResult = 4 -> 9 -> 5
    */ 

   ListNode* nodeResult = head->next;
    while (nodeResult != nullptr){
        cout << nodeResult->val << endl;
        nodeResult = nodeResult->next;
    }

}

ListNode* reverseList(ListNode* head){

    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr){
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }

    return prev;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode* result = new ListNode();
    ListNode* head = result;

    ListNode* head1 = list1;
    ListNode* head2 = list2;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->val < head2->val) {
            head->next = head1;
            head1 = head1->next;
        } else {
            head->next = head2;
            head2 = head2->next;
        }
        head = head->next;
    }

    if (head1 != nullptr) {
        head->next = head1;
    } else if (head2 != nullptr) {
        head->next = head2;
    }

    head = result->next;
    delete result;
    return head;
}
