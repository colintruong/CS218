#include <iostream>
#include <vector>

using namespace std;

int numSwaps(vector<int>& candies) {
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int swaps = 0;
    for (int i = 0; i < candies.size(); i++) {  // we first want to count the # of 1's, 2's, 3's
        if (candies[i] == 1) {
            count1++;
        } else if (candies[i] == 2) {
            count2++;
        } else {
            count3++;
        }
    }

    vector<int> expected(candies.size());

    for (int i = 0; i < expected.size(); i++) { // make a new array that represents what the sorted array is supposed to be
        if (i < count1) {
            expected[i] = 1;
        } else if (i < count1 + count2) {
            expected[i] = 2;
        } else {
            expected[i] = 3;
        }
    }

    int misplaced = 0;

    for (int i = 0; i < candies.size(); i++) {  // count the number of misplaced elements
        if (candies[i] != expected[i]) {
            misplaced++;
        }
    }

    int one_two = 0;
    int one_three = 0;
    int two_one = 0;
    int two_three = 0;
    int three_one = 0;
    int three_two = 0;

    for (int i = 0; i < candies.size(); i++) {  // write down what candy is supposed to be where (ex: one_two is candy with value of 1 is in a position where a value of 2 is supposed to be)
        if (candies[i] == 1 && expected[i] == 2) {
            one_two++;
        } else if (candies[i] == 1 && expected[i] == 3) {
            one_three++;
        } else if (candies[i] == 2 && expected[i] == 1) {
            two_one++;
        } else if (candies[i] == 2 && expected[i] == 3) {
            two_three++;
        } else if (candies[i] == 3 && expected[i] == 1) {
            three_one++;
        } else if (candies[i] == 3 && expected[i] == 2) {
            three_two++;
        }
    }

    int easy = min(one_two, two_one) + min(one_three, three_one) + min(two_three, three_two);   // the # of "easy" direct swaps we can make
    int remaining = misplaced - (2 * easy); // remaining elements after we make easy swaps
    int cycleSwaps = (remaining / 3) * 2; // the rest of the elements need to be in a cycle swap where element triplets are sorted using two sorts
    return easy + cycleSwaps;
}

int main() {
    int num;
    
    cin >> num;

    vector<int> candies(num);

    for (int i = 0; i < num; i++) {
        cin >> candies[i];
    }

    cout << numSwaps(candies) << endl;

    return 0;
}