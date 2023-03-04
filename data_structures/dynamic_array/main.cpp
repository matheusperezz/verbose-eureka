#include <iostream>

using namespace std;

void dynamic_array_impl(){
    int size = 4;
    int new_size = 5;
    int* array = new int[size];

    for (int i = 0; i < size; i++){
        array[i] = i*2;
    }

    int* new_array = new int[new_size];

    for (int i =  0; i < size; i++){
        new_array[i] = array[i];
    }

    new_array[size] = 999;

    delete[] array;

    array = new_array;

    for (int i = 0; i < new_size; i++){
        cout << array[i] << " ";
    }
}

int main(int argc, char *argv[]){


    return 0;
}