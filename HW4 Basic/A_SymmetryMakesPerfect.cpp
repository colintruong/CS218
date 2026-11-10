#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int priceHelper(vector<vector<int>>& dp, const map<char, int>& cost, const string& candy, int i, int j) {
    if (i >= j) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (candy[i] == candy[j]) {
        dp[i][j] = priceHelper(dp, cost, candy, i + 1, j - 1);
    } else {
        int left = cost.at(candy[i]) + priceHelper(dp, cost, candy, i + 1, j);
        int right = cost.at(candy[j]) + priceHelper(dp, cost, candy, i, j - 1);
        dp[i][j] = min(left, right);
    }

    return dp[i][j];
}

int price(const map<char, int>& cost, const string& candy) {
    int n = candy.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return priceHelper(dp, cost, candy, 0, n - 1);
}

int main() {
    int n, k;
    int value;
    map<char, int> cost;
    string candy;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        char letter = 'a' + i;
        cin >> value;
        cost[letter] = value;
    }
    cin >> candy;

    int ans = price(cost, candy);

    cout << ans << endl;
    
    return 0;
}