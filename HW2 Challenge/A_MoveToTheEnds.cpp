#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        int a;
        vector<int> positions(size + 1);
        for (int i = 0; i < size; i++) {
            cin >> a;
            positions[a] = i;
        }
        int currentLength = 1;
        int maxLength = 1;
        for (int i = 2; i <= size; i++) {
            if (positions[i] > positions[i - 1]) {
                currentLength++;
            } else {
                currentLength = 1;
            }
            maxLength = max(maxLength, currentLength);
        }
        cout << size - maxLength << endl;
    }
    

    return 0;
}