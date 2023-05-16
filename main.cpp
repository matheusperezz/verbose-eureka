#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    for (int i = 1; i < n; i++){
        if (i > n/2){
            cout << n << endl;
            break;
        }

        if (n % i == 0){
            cout << i << " ";
        }
    }

    return 0;
}