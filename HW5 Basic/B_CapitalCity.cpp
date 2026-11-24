#include <iostream>
#include <vector>

using namespace std;

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

    return 0;
}