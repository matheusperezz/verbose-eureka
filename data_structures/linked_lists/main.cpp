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

int sizeOfLinkedList(ListNode* head){
    int count = 0;
    ListNode* current = head;
    while (current != nullptr){
        count++;
        current = current->next;
    }
    return count;
}

bool isEmptyLinkedList(ListNode* head){
    int count = 0;
    ListNode* current = head;
    while (current != nullptr){
        count++;
        current = current->next;
    }
    if (count == 0){
        return true;
    } else {
        return false;
    }
}

ListNode* findNodeByPosition(ListNode* head, int position){
    int pivot = 0;
    ListNode* current = head;
    while (current != nullptr){
        if (pivot == position){
            return current;
        }
        pivot++;
        current = current->next;
    }
}

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

void popNode(ListNode* head){
    ListNode* current = head;
    ListNode* current_prev = head->prev;
    while(current != nullptr){
        if (current->next == nullptr){
            current = current_prev;
            current->next = nullptr;
            break;
        }
        current = current->next;
        current_prev = current->prev;
    }
}

void pushValue(ListNode* head, int value){
    ListNode* current = head;
    ListNode* next_current = new ListNode(value);
    while(current != nullptr){
        if (current->next == nullptr){
            current->next = next_current;
            next_current->next = nullptr;
        }
        current = current->next;
    }
}

void nodeInsert(ListNode* head, int position, int value){
    int pivot = 0;
    ListNode* current = head;
    ListNode* current_prev = head->prev;
    ListNode* current_copy;
    ListNode* newNode = new ListNode(value);
    while(current != nullptr){
        if(pivot == position){
            current->prev = newNode;
            newNode->next = current;
            newNode->prev = current_prev;
            current_prev->next = newNode;
            break;
        }
        pivot++;
        current = current->next;
        current_prev = current->prev;
    }
}

void nodeErase(ListNode* head, int position){
    int pivot = 0;
    ListNode* current = head;
    ListNode* current_prev = head->prev;
    ListNode* current_next = head->next;
    while(current != nullptr){
        if(pivot == position){
            current_prev->next = current_next;
            current_next->prev = current_prev;
            delete current;
            break;
        }

        pivot++;
        current = current->next;
        current_prev = current->prev;
        current_next = current_next->next;
    }
}

int main(){

    ListNode* head = new ListNode(2);
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(4);
    ListNode* n56 = new ListNode(9);
    ListNode* n99 = nullptr;
    head->prev = nullptr;
    head-> next = n1;
    n1->prev = head;
    n1->next = n2;
    n2->prev = n1;
    n2->next = nullptr;
    pushNode(head, n56);

    ListNode* valueOfThree = searchNode(head, 3);
    ListNode* positionTwo = findNodeByPosition(head, 2);
    int linkedListSize = sizeOfLinkedList(head);
    bool isEmpty = isEmptyLinkedList(n99);

    cout << valueOfThree->val << endl;
    cout << head->val << endl;
    cout << "find by position 2: " << positionTwo->val << endl;
    cout << "Size of linked list: " << linkedListSize << endl;
    cout << "Is n99 empty? " << isEmpty << endl;
    popNode(head);
    cout << "Now im poping the last item" << endl;
    
    pushValue(head, 6);
    nodeInsert(head, 2, 8);
    nodeErase(head, 2);

    ListNode* current = head;
    while (current != nullptr){
        cout << current->val << " ";
        current = current->next; 
    }
    cout << endl;

    return 0;
}