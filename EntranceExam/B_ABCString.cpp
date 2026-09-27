#include <iostream>
#include <string>

using namespace std;

string ABC = "ABC";

long long length[51];

char findChar(int k, long long pos) {
    if (k == 1) {
        return ABC[pos - 1];
    }
    
    long long prev = length[k - 1];

    if (pos == 1) {
        return 'A';
    } else if (pos <= prev + 1) {
        long long new_pos = pos - 1;
        return findChar(k - 1, new_pos);
    } else if (pos == prev + 2) {
        return 'B';
    } else if (pos <= 2 * prev + 2) {
        long long new_pos = pos - (prev + 2);
        return findChar(k - 1, new_pos);
    } else {
        return 'C';
    }
}

string substring(int k, long long l, long long r) {
    string answer = "";
    for (long long i = l; i <= r; i++) {
        answer += findChar(k, i);
    }
    return answer;
}

int main() {
    length[1] = 3;
    for (int i = 2; i <= 50; i++) {
        length[i] = 2 * length[i - 1] + 3;
    }

    int t, k;
    long long l, r;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> k >> l >> r;
        cout << substring(k, l, r) << endl;
    }
    return 0;
}