#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int start, end, weight;
};

const int INF = 30000;

vector<int> bellmanFord(int n, const vector<Edge>& edges) {
    vector<int> distance(n + 1, INF);
    distance[1] = 0;
    for (int i = 1; i < n; ++i) {
        for (const Edge& edge : edges) {
            if (distance[edge.start] < INF) {
                distance[edge.end] = min(distance[edge.end], distance[edge.start] + edge.weight);
            }
        }
    }
    return distance;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].start >> edges[i].end >> edges[i].weight;
    }
    vector<int> distances = bellmanFord(n, edges);
    for (int i = 1; i <= n; ++i) {
        if (distances[i] == INF) {
            cout << INF << " ";
        } else {
            cout << distances[i] << " ";
        }
    }
    return 0;
}
