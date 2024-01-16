#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    int n, s, f;
    cin >> n >> s >> f;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> graph[i][j];
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (graph[i][k] != -1 && graph[k][j] != -1) {
                    if (graph[i][j] == -1 || graph[i][j] > graph[i][k] + graph[k][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }

    int distance = graph[s][f];

    if (distance == -1 || distance == INF) {
        cout << -1 << endl;
    } else {
        cout << distance << endl;
    }

    return 0;
}
