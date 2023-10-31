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

    const int size = 3;

    int matriz1[size][size] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int matriz2[size][size] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int matrizResultado[size][size] = {{0}};

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            for (int k = 0; k < size; k++){
                matrizResultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << matrizResultado[i][j] << " ";
        }
        cout << endl;
    }
}
