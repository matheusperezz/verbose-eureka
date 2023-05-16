#include <iostream>

using namespace std;

int main(){

    const int ARR_SIZE = 7;
    int arr[ARR_SIZE] = {8, 9, 2, 3, 12, 0, -4};

    for (int i = 0; i < ARR_SIZE; i++){
        for (int j = i; j < ARR_SIZE; j++){
            int temp;
            if (arr[i] > arr[j]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            } 
        }
    }


    for (int i = 0; i < ARR_SIZE; i++){
        cout << arr[i] << endl;
    }

    return 0;
}