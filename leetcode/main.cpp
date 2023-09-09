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

class ListNode
{
public:
    int val;
    ListNode *next;

    // Construtores
    ListNode()
    {
        val = 0;
        next = nullptr;
    }

    ListNode(int val)
    {
        this->val = val;
        next = nullptr;
    }

    ListNode(int val, ListNode *next)
    {
        this->val = val;
        this->next = next;
    }
};

int main()
{

    cout << "testando" << endl;

    return 0;
}
