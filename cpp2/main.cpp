#include <iostream>
#include <vector>
#include "leetcode.h"
#include <string>

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
    solution_169();
    return 0;
}
