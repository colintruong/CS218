#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

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