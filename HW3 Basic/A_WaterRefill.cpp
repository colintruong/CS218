#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long time(int n, int m, const vector<int>& students) {
    long long maxTime = 0;
    priority_queue<long long, vector<long long>, greater<long long>> line;
    for (int i = 0; i < m; i++) {
        line.push(students[i]);
        maxTime = max(maxTime, (long long)students[i]);
    }
    for (int i = m; i < n; i++) {
        long long lastStudent = line.top();
        line.pop();
        long long nextStudent = students[i] + lastStudent;
        line.push(nextStudent);
        maxTime = max(maxTime, (long long)nextStudent);
    }
    return maxTime;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> students(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }
    cout << time(n, m, students) << endl;
    return 0;
}