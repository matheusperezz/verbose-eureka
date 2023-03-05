#include <iostream>

using namespace std;

// Data class that represents a Node in LinkedList
class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode* prev;

        // Constructors
        ListNode(){
            val = 0;
            next = nullptr;
        }

        ListNode(int val){
            this->val = val;
            next = nullptr;
        }

        ListNode(int val, ListNode* prev, ListNode* next){
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
};

ListNode* searchNode(ListNode* head ,int val){
    ListNode* current = head;
    while(current != nullptr){
        if (current->val == val){
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void pushNode(ListNode* head, ListNode* tail){
    ListNode* current = head;
    while(current != nullptr){
        if (current->next == nullptr){
            current->next = tail;
            tail->prev = current;
            break;
        }
        current = current->next;
    }
}

int main(){

    ListNode* head = new ListNode(2);
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(4);
    ListNode* n56 = new ListNode(9);
    head->prev = nullptr;
    head-> next = n1;
    n1->prev = head;
    n1->next = n2;
    n2->prev = n1;
    n2->next = nullptr;
    pushNode(head, n56);

    ListNode* valueOfThree = searchNode(head, 3);
    cout << valueOfThree->val << endl;
    cout << n2->next->val << endl;

    return 0;
}