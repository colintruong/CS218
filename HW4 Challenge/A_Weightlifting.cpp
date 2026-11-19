#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void calculatePlates(int n, int x, const vector<double>& weights, vector<vector<vector<int>>>& dp) {
    for (int i = 1; i <= n; i++) {
        int weight = (int)round(weights[i - 1] * 2);
        for (int a = 0; a <= x; a++) {
            for (int b = 0; b <= x; b++) {
                dp[i][a][b] = dp[i - 1][a][b];                                      // skip
                if (a >= weight)
                    dp[i][a][b] = min(dp[i][a][b], dp[i - 1][a - weight][b] + 1);  // left
                if (b >= weight)
                    dp[i][a][b] = min(dp[i][a][b], dp[i - 1][a][b - weight] + 1);  // right
            }
        }
    }
}

int minPlates(int n, int x, const vector<double>& weights, vector<int>& left, vector<int>& right) {
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(x + 1, vector<int>(x + 1, INF)));
    dp[0][0][0] = 0;
    calculatePlates(n, x, weights, dp);

    if (dp[n][x][x] >= INF) return -1;

    int a = x, b = x;
    for (int i = n; i >= 1; i--) {
        int weight = (int)round(weights[i - 1] * 2);
        if (dp[i][a][b] == dp[i - 1][a][b]) {
            // plate i is skipped
        } else if (a >= weight && dp[i][a][b] == dp[i - 1][a - weight][b] + 1) {
            left.push_back(i);
            a -= weight;
        } else {
            right.push_back(i);
            b -= weight;
        }
    }
    return dp[n][x][x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<double> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];

    vector<int> left, right;
    int k = minPlates(n, x, weights, left, right);
    if (k == -1) {
        cout << "-1" << endl;
    } else {
        cout << k << endl;
        for (int i = 0; i < (int)left.size(); i++) {
            if (i > 0) {
                cout << " ";
            } 
            cout << left[i];
        }
        cout << endl;
        for (int i = 0; i < (int)right.size(); i++) {
            if (i > 0) {
                cout << " ";
            }
            cout << right[i];
        }
    }
    cout << endl;

    return 0;
}