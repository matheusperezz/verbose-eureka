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

void dynamic_push(){
    const int size = 4;
    const int new_size = size + 1;
    int some_array[size] = {1,2,3,4};
    int* myPointer = (int*) calloc(4, sizeof(int));
    
    for (int i = 0; i < size; i++){
        myPointer[i] = some_array[i];
    }
    
    for (int i = 0; i < new_size; i++){
        cout << "Position " << i << ": " << myPointer[i] << endl;
    }

    myPointer = (int*) realloc(myPointer, new_size * sizeof(int));
    myPointer[size] = 24;

    for (int i = 0; i < new_size; i++){
        cout << "Position " << i << ": " << myPointer[i] << endl;
    }

    for (int i = 0; i < new_size; i++){
        some_array[i] = myPointer[i];
    }

    for (int i = 0; i < new_size; i++){
        cout << "Position some_array" << i << ": " << some_array[i] << endl;
    }

    free(myPointer);
}

int main(int argc, char *argv[]){

    dynamic_push();
    return 0;
}