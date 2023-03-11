#include <iostream>

using namespace std;

const int MAX_SIZE = 3;

class CircularQueue {
    private:
        int write, read;
        int arr[MAX_SIZE];
    
    public:
        CircularQueue(){
            write = -1;
            read = -1;

            for (int i = 0; i < MAX_SIZE; i++){
                arr[i] = 0;
            }
        }

        bool isFull(){
            if ((write == 0 && read == MAX_SIZE - 1) || (read == write - 1)){
                return true;
            }
            return false;
        }

        bool isEmpty(){
            if (write == -1 && read == -1){
                return true;
            }
            return false;
        }

        void enqueue(int val){
            if (isFull()){
                cout << "Queue is full, can't add more elements" << endl;
                return;
            } else if (isEmpty()){
                write = 0;
                read = 0;
            } else if (read == MAX_SIZE - 1 && write != 0){
                read = 0;
            } else {
                read++;
            }
            arr[read] = val;
        }

        int dequeue(){
            int x;
            if (isEmpty()){
                cout << "Queue is empty, can't remove elements" << endl;
                return 0;
            } else if (write == read){
                x = arr[write];
                arr[write] = 0;
                write = -1;
                read = -1;
            } else if (write == MAX_SIZE - 1){
                x = arr[write];
                arr[write] = 0;
                write = 0;
            } else {
                x = arr[write];
                arr[write] = 0;
                write++;
            }
            return x;
        }

        void display(){
            if (isEmpty()){
                cout << "Queue is empty." << endl;
                return;
            }
            cout << "Elements in queue: ";
            if (read >= write) {
                for (int i = write; i <= read; i++){
                    cout << arr[i] << " ";
                }
            } else {
                for (int i = write; i < MAX_SIZE; i++){
                    cout << arr[i] << " ";
                }
                
                for (int i = 0; i <= read; i++){
                    cout << arr[i] << " ";
                }
            }
            cout << endl;
        }

};

int main(){

    CircularQueue q;
    q.enqueue(9);
    q.enqueue(8);
    q.enqueue(7);
    q.dequeue();
    q.enqueue(1);
    q.display();
    
    return 0;
}