#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long long MOD = 1000000007;
const long long BASE = 131;

int maxPartitions(const string& s) {
    int n = s.size();

    vector<long long> hash(n + 1, 0);
    vector<long long> power(n + 1, 1);
    for (int i = 0; i < n; i++) {
        hash[i + 1] = (hash[i] * BASE + (s[i] - '0' + 1)) % MOD;
        power[i + 1] = (power[i] * BASE) % MOD;
    }

    int ans = 0;
    int l = 0;

    for (int i = 0; i < n - 1 - i; i++) {
        int r1 = n - 1 - i;
        int r2 = n - 1 - l;

        long long left = (hash[i + 1] - hash[l] * power[i - l + 1] % MOD + MOD) % MOD;
        long long right = (hash[r2 + 1] - hash[r1] * power[r2 - r1 + 1] % MOD + MOD) % MOD;

        if (left == right) {
            ans += 2;
            l = i + 1;
        }
    }

    if (l <= n - 1 - l) ans++;

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << maxPartitions(s) << endl;
    }
    return 0;
}