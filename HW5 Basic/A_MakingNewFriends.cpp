#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int cost;
    int u, v;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

int findSet(int x, vector<int>& parent) {
    if (parent[x] != x)
        parent[x] = findSet(parent[x], parent);
    return parent[x];
}

bool unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findSet(a, parent);
    b = findSet(b, parent);
    if (a == b) return false;
    if (rank[a] < rank[b])
        parent[a] = b;
    else {
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
    return true;
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> classroom(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> classroom[i][j];

    vector<Edge> edges;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    auto node = [&](int x, int y) {
        return x * c + y;
    };


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                    int cost = min(classroom[i][j], classroom[ni][nj]);
                    edges.push_back({cost, node(i, j), node(ni, nj)});
                }
            }
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        if (a.u != b.u) return a.u < b.u;
        return a.v < b.v;
    });
    edges.erase(unique(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        return (a.u == b.u && a.v == b.v) || (a.u == b.v && a.v == b.u);
    }), edges.end());

    sort(edges.begin(), edges.end());

    vector<int> parent(r * c), rank(r * c, 0);
    for (int i = 0; i < r * c; i++) parent[i] = i;

    int totalCost = 0;
    int edgesUsed = 0;

    for (auto& e : edges) {
        if (unionSet(e.u, e.v, parent, rank)) {
            totalCost += e.cost;
            edgesUsed++;
            if (edgesUsed == r * c - 1) break;
        }
    }

    cout << totalCost << endl;

    return 0;
}