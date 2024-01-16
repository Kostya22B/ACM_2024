#include <bits/stdc++.h>

using namespace std;

struct Door {
    int from, to, knowledge;
};

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<Door> doors(m);
    vector<int> knowledge(n + 1, -INF);
    
    for (int i = 0; i < m; ++i) {
        cin >> doors[i].from >> doors[i].to >> doors[i].knowledge;
    }
    knowledge[1] = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        for (const Door& door : doors) {
            knowledge[door.to] = max(knowledge[door.to], knowledge[door.from] + door.knowledge);
        }
    }
    
    if (knowledge[n] > -INF) {
        cout << knowledge[n] << endl;
    } else {
        cout << ":(" << endl;
    }
    return 0;
}
