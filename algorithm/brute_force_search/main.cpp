#include <iostream>
#include <string>
#include <vector>

using namespace std;

int search(string text, string pattern){

    int text_length = text.length();
    int pattern_length = pattern.length();
    for (int i = 0; i <= text_length - pattern_length; i++){
        int j;
        for (j = 0; j < pattern_length; j++){
            cout << text[i + j] << " --- ";
            cout << pattern[j] << endl; 
            if (text[i + j] != pattern[j]){
                break;
            }
        }

        if (j == pattern_length){
            return i;
        }
    }

    return -1;
}

vector<int> compute_prefix_function(string pattern){
    int pattern_length = pattern.length();
    vector<int> prefix_function(pattern_length, 0);
    int k = 0;

    for (int i = 1; i < pattern_length; i++){
        while (k > 0 && pattern[k] != pattern[i]){
            k = prefix_function[k - 1];
        }

        if (pattern[k] == pattern[i]){
            k++;
        }
        prefix_function[i] = k;
    }

}

int main(){
    
    string text = "The quick brown fox jumps over the lazy dog.";
    string pattern = "brown";
    int index = search(text, pattern);

    if (index >= 0){
        cout << "O padrão '" << pattern << "' foi encontrado na posição '" << index << "'" << endl;
    } else {
        cout << "O padrão '" << pattern << "' nao foi encontrado na string" << endl;
    }

    return 0;
}