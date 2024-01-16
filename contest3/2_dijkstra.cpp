#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n, s, f;
    cin >> n >> s >> f;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int weight;
            cin >> weight;
            if (weight != -1) {
                graph[i].push_back({j, weight});
            }
        }
    }
    vector<int> distance(n + 1, INF);
    distance[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > distance[u]) {
            continue;
        }
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }
    if (distance[f] == INF) {
        cout << -1 << endl;
    } else {
        cout << distance[f] << endl;
    }
    return 0;
}
