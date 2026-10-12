#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> male(n);
    vector<int> female(m);

    for (int i = 0; i < n; i++) {
        cin >> male[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> female[i];
    }

    sort(male.begin(), male.end());
    sort(female.begin(), female.end());

    int m_pointer = male.size() - 1;
    int f_pointer = female.size() - 1;
    int count = 0;

    while (m_pointer >= 0 && f_pointer >= 1) {
        if (male[m_pointer] > female[f_pointer]) {
            m_pointer--;
            f_pointer -= 2;
            count++;
        } else {
            f_pointer--;
        }
    }

    cout << count << endl;

    return 0;
}