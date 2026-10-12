#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int computeCandies(vector<pair<long long, long long>> students) {
    long long n = students.size();
    long long total = 0;
    for (long long i = 0; i < n; i++) {     // computing the average candies for everyone if nobody ate the candies for an upper bound
        total += students[i].second;
    }
    long long lower = 0;
    long long upper = total / n;
    while (lower < upper) {
        long long mid = lower + (upper - lower + 1) / 2;
        long long balance = students[0].second - mid;
        for (long long i = 1; i < n; i++) {
            long long distance = students[i].first - students[i - 1].first;
            if (balance >= 0) {
                balance = max(0LL, balance - distance) + (students[i].second - mid);
            } else {
                balance = balance - distance + (students[i].second - mid);
            }
        }
        if (balance >= 0) {
            lower = mid;
        } else {
            upper = mid - 1;
        }
    }
    return lower;
}

int main() {
    int num_students;
    cin >> num_students;

    vector<pair<long long, long long>> students(num_students);

    for (int i = 0; i < students.size(); i++) {
        cin >> students[i].first >> students[i].second;
    }

    cout << computeCandies(students) << endl;

    return 0;
}