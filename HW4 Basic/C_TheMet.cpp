#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfsDown(int u, int parent, const vector<vector<int>>& graph, vector<int>& down) {
    for (int v : graph[u]) {
        if (v == parent) {
            continue;
        }
        dfsDown(v, u, graph, down);
        down[u] = max(down[u], down[v] + 1);
    }
}

void dfsUp(int u, int parent, const vector<vector<int>>& graph, vector<int>& down, vector<int>& up) {
    for (int v : graph[u]) {
        if (v == parent) {
            continue;
        }
        int best = up[u];

        for (int w : graph[u]) {
            if (w == parent || w == v) {
                continue;
            }
            best = max(best, down[w] + 1);
        } 
        up[v] = best + 1;

        dfsUp(v, u, graph, down, up);
    }

    return;
}


int bestPlacement(int n, const vector<vector<int>>& graph) {
    vector<int> down(n + 1, 0);
    vector<int> up(n + 1, 0);

    dfsDown(1, 0, graph, down);
    dfsUp(1, 0, graph, down, up);

    int answer = n;
    for (int u = 1; u <= n; u++) {
        answer = min(answer, max(down[u], up[u]));
    }

    return answer;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << bestPlacement(n, graph) << endl;
    return 0;
}