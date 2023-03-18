#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> v, int element){
    
    int start = 0;
    int end = v.size();
    int operations = 0;

    while(start != end){
        int middle = (start + end) / 2;
        if (element == v[middle]){
            operations++;
            cout << "total operations: " << operations << endl;
            return middle;
            break;
        } else if (element < v[middle]){
            operations++;
            cout << "total operations: " << operations << endl;
            end = middle - 1;
        } else {
            operations++;
            cout << "total operations: " << operations << endl;
            start = middle + 1;
        }
    }
    return -1;

}

int main(){
    vector<int> some_vector;
    
    cout << binary_search(some_vector, 12) << endl;
}