#include <iostream>
#include <vector>
#include "leetcode.h"

using namespace std;

/**
 *  To run the code do this steps:
 *  1 - Open the cpp folder in wsl
 *  2 - Run: "make && ./cpp"
 *
 * @return
 */

int hashash(string value){
    int hashValue = 0;
    int capacity = 10;

    for (char c : value){
        hashValue = ( hashValue * 31 + c) % capacity;
    }

    return hashValue;
}

int main() {
    // solution_119();
    vector<string> v = {"banana", "apple", "renan", "miwis"};
    int arr[20];

    for (auto &e : v){
        int r = hashash(e);
        arr[r] = 2;
    }

    for (auto &c : arr)
        cout << c << " ";

    cout << endl;
    return 0;
}
