#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, cost;
};

int main() {
    int n;
    cin >> n;
    vector<int> fuelCost(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> fuelCost[i];
    }
    int m;
    cin >> m;
    vector<vector<Edge>> graph(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, fuelCost[u]});
        graph[v].push_back({u, fuelCost[v]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n + 1, INF);
    
    pq.push({0, 1});
    distance[1] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > distance[u]) {
            continue;
        }
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int w = edge.cost;

            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }
    if (distance[n] == INF) {
        cout << -1 << endl;
    } else {
        cout << distance[n] << endl;
    }

    return 0;
}
