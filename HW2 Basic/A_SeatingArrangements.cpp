#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, r;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> r;
        int a;
        int total = 0;
        int rows_used = 0;
        
        for (int j = 0; j < n; j++) {
            cin >> a;
            total += a;
            rows_used += (a % 2 == 0) ? a / 2 : (a / 2) + 1;
        }
        int happy = min(total, total - ((rows_used - r) * 2));
        cout << happy << endl;
    }

    return 0;
}