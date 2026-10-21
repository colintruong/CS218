#include <iostream>
#include <vector>

using namespace std;

void message(int i, int j, int N, int M, string& answer, string curr, vector<string>& arr, vector<vector<bool>>& visited) {
    if (i == N - 1 && j == M - 1) {
        if (answer == "" || curr < answer) {
            answer = curr;
        }
        return;
    }
    visited[i][j] = true;
    vector<pair<int, int>> directions = {
        {i - 1, j}, // up
        {i + 1, j}, // down
        {i, j - 1}, // left
        {i, j + 1}, // right
    };

    for (auto [a, b] : directions) {
        if ((a >= 0 && a < N) && (b >= 0 && b < M) && !visited[a][b]) {
            message(a, b, N, M, answer, curr + arr[a][b], arr, visited);
        }
    }
    visited[i][j] = false;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    string answer = "";

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    message(0, 0, N, M, answer, string(1, arr[0][0]), arr, visited);

    cout << answer << endl;

    return 0;
}
