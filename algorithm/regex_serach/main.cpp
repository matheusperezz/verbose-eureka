#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(){

    string text = "The quick brown fox brow jumps over the lazy dog.";

    regex pattern("brown");

    smatch matches;

    if (regex_search(text, matches, pattern)){
        cout << "Encontrado '" << matches.str() << "' no texto." << endl;
    } else {
        cout << "Padrao nao encontrado." << endl;
    }

    return 0;
}