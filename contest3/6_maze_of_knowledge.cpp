#include <bits/stdc++.h>

using namespace std;

struct Door {
    int to;
    int knowledgeChange;
    Door(int _to, int _knowledgeChange) : to(_to), knowledgeChange(_knowledgeChange) {}
};

vector<vector<Door>> graph;
vector<bool> visited;
vector<int> knowledge;
void dfs(int room) {
    visited[room] = true;
    for (const Door& door : graph[room]) {
        int nextRoom = door.to;
        int knowledgeChange = door.knowledgeChange;
        if (!visited[nextRoom]) {
            knowledge[nextRoom] = max(knowledge[nextRoom], knowledge[room] + knowledgeChange);
            dfs(nextRoom);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, false);
    knowledge.resize(n + 1, INT_MIN);
    
    for (int i = 0; i < m; ++i) {
        int from, to, change;
        cin >> from >> to >> change;
        graph[from].emplace_back(to, change);
    }

    knowledge[1] = 0;
    dfs(1);

    if (visited[n]) {
        if (knowledge[n] == INT_MIN) {
            cout << ":(" << endl;
        } else {
            if (knowledge[n] < 0) {
                cout << ":)" << endl;
            } else {
                cout << knowledge[n] << endl;
            }
        }
    } else {
        cout << ":(" << endl;
    }

    return 0;
}
