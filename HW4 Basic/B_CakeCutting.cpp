#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long helper(const vector<long long>& cake, vector<vector<long long>>& dp, int l, int r) {
    if (l > r) {
        return 0;
    } else if (l == r) {
        return cake[l];
    }

    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    long long goLeft;

    if (cake[l + 1] > cake[r]) {
        goLeft = helper(cake, dp, l + 2, r) + cake[l];
    } else {
        goLeft = helper(cake, dp, l + 1, r - 1) + cake[l];
    }
    long long goRight;

    if (cake[l] > cake[r - 1]) {
        goRight = helper(cake, dp, l + 1, r - 1) + cake[r];
    } else {
        goRight = helper(cake, dp, l, r - 2) + cake[r];
    }
    long long best = max(goLeft, goRight);
    return dp[l][r] = best;
}

long long maxCake(const vector<long long>& cake) {
    long long best = 0;
    int n = cake.size();

    if (n == 1) {
        return cake[0];
    }
    
    vector<vector<long long>> dp(2*n, vector<long long>(2*n, -1));
    vector<long long> temp = cake;
    temp.insert(temp.end(), cake.begin(), cake.end());
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = i + n - 1;
        if (temp[l] > temp[r]) {
            l++;
        } else {
            r--;
        }
        best = max(helper(temp, dp, l, r) + temp[i], best);
    }
    return best;
}

int main() {
    int n;
    cin >> n;
    vector<long long> cake(n);
    for (int i = 0; i < cake.size(); i++) {
        cin >> cake[i];
    }
    cout << maxCake(cake) << endl;
    return 0;
}