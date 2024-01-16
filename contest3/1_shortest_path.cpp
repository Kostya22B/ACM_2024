#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, weight;
};

void dijkstra(int n, const vector<vector<Edge>>& graph, int start, int finish) {
    vector<int> distance(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
    if (distance[finish] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << distance[finish] << endl;
        vector<int> path;
        int current = finish;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int start, finish;
    cin >> start >> finish;
    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int b, e, w;
        cin >> b >> e >> w;
        graph[b].push_back({e, w});
        graph[e].push_back({b, w});
    }
    dijkstra(n, graph, start, finish);
    return 0;
}
