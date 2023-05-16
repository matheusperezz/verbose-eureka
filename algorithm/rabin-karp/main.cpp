#include <iostream>
#include <string>
#include <cmath>
#define d 256 // Max characters in a string

using namespace std;

void search(string pattern, string text, int q){
    int n = text.length();
    int m = pattern.length();
    int h = pow(d, m-1);
    int p = 0;
    int t = 0;

    // calc the pattern hash and first m chars of a string
    for (int i = 0; i < m; i++){
        p = (d*p + pattern[i]) % q;
        t = (d*t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++){
        if (p == t){
            bool match = true;
            for (int j = 0; j < m; j++){
                if (text[i+j] != pattern[j]){
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Padrão encontrado na posição " << i << endl;
            }
        }
        // Calc the hash of the next string
        if (i < n - m){
            t = (d*(t - text[i]*h) + text[i+m]) % q;
            if (t < 0){
                t += q;
            }
        }
    }
}

int main(){
    string text = "O rato roeu a roupa do rei de roma";
    string pattern = "ro";
    int q = 101; // prime number to prevents collisions

    search(pattern, text, q);

    return 0;
}