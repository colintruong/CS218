#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& graph, int s, vector<char>& visited) {
    vector<int> st = {s};
    visited[s] = 1;
    while (!st.empty()) {
        int u = st.back();
        st.pop_back();
        for (int w : graph[u]) {
            if (!visited[w]) {
                visited[w] = 1;
                st.push_back(w);
            }
        }
    }
}

int lastRoot(const vector<vector<int>>& graph, int n) {
    vector<char> visited(n + 1, 0);
    int root = 1;
    for (int s = 1; s <= n; s++) {
        if (!visited[s]) {
            dfs(graph, s, visited);
            root = s;
        }
    }
    return root;
}

vector<int> findCapitals(int n, const vector<vector<int>>& adj, const vector<vector<int>>& revAdj) {
    int r = lastRoot(revAdj, n);
    vector<char> toR(n + 1, 0);
    dfs(revAdj, r, toR);
    for (int v = 1; v <= n; v++) {
        if (!toR[v]) {
            return {};
        }
    }
    vector<char> fromR(n + 1, 0);
    dfs(adj, r, fromR);

    vector<int> result;
    for (int v = 1; v <= n; v++) {
        if (fromR[v]) {
            result.push_back(v);
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> revAdj(n + 1);
    
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        revAdj[b].push_back(a);
    }

    vector<int> capitals = findCapitals(n, adj, revAdj);
    cout << capitals.size() << endl;
    for (int i = 0; i < capitals.size(); i++) {
        cout << capitals[i] << " ";
    }
    cout << endl;
    return 0;
}