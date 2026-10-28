#include <iostream>
#include <vector>

using namespace std;

int path(const vector<vector<int>>& nums, vector<vector<int>>& dp, int i, int j) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int r = nums.size();
    int c = nums[0].size();
    int best = 1;
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};
    for (int z = 0; z < 4; z++) {
        int newI = i + x[z];
        int newJ = j + y[z];
        if (newI >= 0 && newJ >= 0 && newI < r && newJ < c && nums[newI][newJ] < nums[i][j]) {
            best = max(best, path(nums, dp, newI, newJ) + 1);
        }
    }
    return dp[i][j] = best;
    
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> nums(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
           cin >> nums[i][j]; 
        }
    }
    vector<vector<int>> dp(r + 1, vector<int>(c + 1, -1));
    int longestPath = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            longestPath = max(longestPath, path(nums, dp, i, j));
        }
    }
    cout << longestPath << endl;
    return 0;
}