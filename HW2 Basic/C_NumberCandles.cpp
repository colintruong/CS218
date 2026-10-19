#include <iostream>
#include <vector>

using namespace std;

int main() {

    int M;
    vector<int> prices(10);
    
    cin >> M;

    for (int i = 1; i <= 9; i++) {
        cin >> prices[i];
    }

    int minPrice = INT_MAX;
    for (int i = 1; i <= 9; i++) {
        minPrice = (prices[i] < minPrice) ? prices[i] : minPrice;
    }
    int maxCandle = 0;
    for (int i = 1; i <= 9; i++) {
        if (prices[i] == minPrice) {
            maxCandle = i;
        }
    }

    int maxDigits = M / minPrice;

    string answer(maxDigits, '0' + maxCandle);

    M -= maxDigits * minPrice;

    for (int pointer = 0; pointer < maxDigits; pointer++) {
        for (int i = 9; i > maxCandle; i--) {
            if (prices[i] - minPrice <= M) {
                answer[pointer] = '0' + i;
                M -= prices[i] - minPrice;
                break;
            }
        }
    }

    cout << answer << endl;

    return 0;
}