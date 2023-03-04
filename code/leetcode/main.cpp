#include <iostream>
#include "solutions.h"
#include <string>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <unordered_map>
/*
 *      Para compilar o código, execute os seguintes comandos:
 *      g++ solutions.cpp main.cpp -o main.exe
 *      .\main.exe 
*/

using namespace std;


int main(){
    unordered_map<int, string> months = {
        {1, "Janeiro"},{2, "Fevereiro"},{3, "Março"},
        {4, "Abril"},{5, "Maio"},{6, "Junho"},
        {7, "Julho"},{8, "Agosto"},{9, "Setembro"},
        {10, "Outubro"},{11, "Novembro"},{12, "Dezembro"},
    };

    int n;
    cin >> n;
    cout << months[n] << endl;
    return 0;
}
