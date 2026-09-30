/*
Explanation: Taken from CS142. There is a longest increasing subsequence function that uses dynamic programming and a longest decreasing subsequence that also uses dp.
For unimodal, I just combined them both.

*/

#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int>& dp, const vector<int>& array, int i) {
    if (dp[i] != -1) {
        return dp[i];
    }
    int best = 1;
    for (int j = 0; j < i; j++) {
        if (array[j] < array[i]) {
            best = max(best, lis(dp, array, j) + 1);
        }
    }
    return dp[i] = best;
}

int lds(vector<int>& dp, const vector<int>& array, int i) {
    if (dp[i] != -1) {
        return dp[i];
    }
    int best = 1;
    for (int j = i + 1; j < array.size(); j++) {
        if (array[j] < array[i]) {
            best = max(best, lds(dp, array, j) + 1);
        }
    }
    return dp[i] = best;
}

int unimodal(const vector<int>& array) {
    int n = array.size();
    vector<int> incDP(n, -1);
    vector<int> decDP(n, -1);
    int answer = 0;
    for (int i = 0; i < array.size(); i++) {
        answer = max(answer, lis(incDP, array, i) + lds(decDP, array, i) - 1);
    }
    return answer;
}

int main() {
    int n;
    int input;
    vector<int> array;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        array.push_back(input);
    }
    int answer = unimodal(array);
    cout << answer << endl;
    return 0;
}