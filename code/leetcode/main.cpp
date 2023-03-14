#include <iostream>
#include "solutions.h"
#include <string>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <unordered_map>
/*
 *      Para compilar o código, execute os seguintes comandos:
 *      g++ solutions.cpp main.cpp -o main.exe
 *      .\main.exe 
*/

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

int main(){

    ListNode* l11 = new ListNode(4);
    ListNode* l12 = new ListNode(5);
    ListNode* l13 = new ListNode(6);
    ListNode* l14 = new ListNode(7);
    l11->next = l12;
    l12->next = l13;
    l13->next = l14;
    l14->next = nullptr;

    ListNode* l21 = new ListNode(1);
    ListNode* l22 = new ListNode(2);
    ListNode* l23 = new ListNode(88);
    ListNode* l24 = new ListNode(90);
    l21->next = l22;
    l22->next = l23;
    l23->next = l24;
    l24->next = nullptr;


    ListNode* aa = mergeTwoLists(l11, l21);
    ListNode* ss = aa;
    while (ss != nullptr){
        cout << "Eita: " << ss->val << endl;
        ss = ss->next;
    }

    return 0;
}
