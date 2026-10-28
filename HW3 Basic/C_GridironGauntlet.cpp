#include <iostream>
#include <vector>

using namespace std;

struct chuck {
    int time;
    int track;
};

bool checkAlive(const vector<vector<bool>>& grid) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (grid[r][c] == true) {
                return true;
            }
        }
    }
    return false;
}

int maxTime(int n, vector<chuck>& chucks) {
    if (n == 0) {
        return 0;
    }
    vector<vector<bool>> grid(5, vector<bool>(5, true));
    int index = 0;
    int tMax = chucks[chucks.size() - 1].time;

    for (int t = 0; t <= tMax; t++) {
        if (t > 0) {
            vector<vector<bool>> updatedGrid(5, vector<bool>(5, false));
            for (int r = 0; r < 5; r++) {
                for (int c = 0; c < 5; c++) {
                    if (!grid[r][c]) {
                        continue;
                    }
                    updatedGrid[r][c] = true;
                    vector<pair<int, int>> directions = {
                        {r - 1, c}, // up
                        {r + 1, c}, // down
                        {r, c - 1}, // left
                        {r, c + 1}, // right
                    };
                    for (auto [a, b] : directions) {
                        if ((a >= 0 && a < 5) && (b >= 0 && b < 5)) {
                            updatedGrid[a][b] = true;
                        }
                    }
                }
            }
            grid = updatedGrid;
        }
        vector<bool> attacked(11, false);
        while (index < n && chucks[index].time == t) {
            attacked[chucks[index].track] = true;
            index++;
        }

        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                if (attacked[r + 1] || attacked[c + 6]) {
                    grid[r][c] = false;
                }
            }
        }

        if (!checkAlive(grid)) {
            return t;
        }
    }

    return tMax + 1;
}

int main() {
    int n;
    cin >> n;
    vector<chuck> chucks(n);
    for (int i = 0 ; i < n; i++) {
        cin >> chucks[i].time >> chucks[i].track;
    }
    cout << maxTime(n, chucks) << endl;
    return 0;
}