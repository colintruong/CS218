/*
Explanation: Taken from CS141. We want to go through each step of the staircase to identify the difference in altitude from one step to the next. I created a map to store the
frequencies of differences. All but one step should have the same difference. We're simply finding what the difference should be in the diffFinder function.
The returnStair function gets this value and checks three possible scenarios: the first step, any middle steps, or the last step. If the first step to the second
step isn't equal to the difference we calculated but then second to third step does, then it is the first step. For the middle steps, we are simply checking if the next step
minus the current step is not equal to the difference we calculated. If both these scenarios don't fit, then the wrong step is the last step. The time complexity
is O(n) because we're going through a for loop of size n, where n is the number of steps.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int diffFinder(vector<int> v) {
    unordered_map<int, int> diffCount;      // this map will store the differences in stair altitude and also how frequent it is

    for (int i = 1; i < v.size(); i++) {
        diffCount[v[i] - v[i - 1]]++;
    }

    int diff = 0;
    int maxCount = 0;

    for (auto stair : diffCount) {
        if (stair.second > maxCount) {
            maxCount = stair.second;
            diff = stair.first;
        }
    }

    return diff;
}

// test cases for the first step, any step in the middle, and the last step

int returnStair(vector<int> v) {
    int diff = diffFinder(v);
    if (v[1] - v[0] != diff && v[2] - v[1] == diff) {       // first step
        return 1;
    }
    for (int i = 0; i < v.size() - 2; i++) {                // middle steps
        if (v[i + 1] - v[i] != diff) {
            return i + 2;
        }
    }
    return v.size();                                        // last step
}

int main() {
    int numStairs;
    int stairAlt;
    vector<int> alts;

    cin >> numStairs;

    for (int i = 0; i < numStairs; i++) {
        cin >> stairAlt;
        alts.push_back(stairAlt);
    }

    int stair = returnStair(alts);

    cout << stair << endl; 

    return 0;
}