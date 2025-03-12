#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cutRod(vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0);

    // preenchendo o array dp de forma iterativa (bottom up)
    for (int i = 1; i <= n; i++) {
        int max_val = 0;
        for (int j = 1; j <= i; j++) {
            max_val = max(max_val, prices[j - 1] + dp[i - j]);
        }

        dp[i] = max_val;
    }

    return dp[n]; // retorna o lucro máximo possível para a haste de tamanho n
}

int main() {
    vector<int> prices = {1, 5, 8, 9}; // Preços para cada tamanho de 1 a 8
    const int n = prices.size(); // Comprimento total da haste

    cout << "Lucro maximo: " << cutRod(prices, n) << endl;

    return 0;
}