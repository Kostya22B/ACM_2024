#include <bits/stdc++.h>

using namespace std;

struct Bus {
    int start, departure_time, end, arrival_time;
};

struct Vertex {
    int village, time;
    bool operator>(const Vertex& other) const {
        return time > other.time;
    }
};

const int INF = numeric_limits<int>::max();

int dijkstra(int n, int d, int v, int r, const vector<Bus>& buses) {
    vector<vector<int>> min_time(n + 1, vector<int>(10001, INF));
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
    pq.push({d, 0});
    min_time[d][0] = 0;
    while (!pq.empty()) {
        Vertex current = pq.top();
        pq.pop();
        int current_village = current.village;
        int current_time = current.time;
        if (current_village == v) {
            return current_time;
        }
        for (const Bus& bus : buses) {
            if (bus.start == current_village && bus.departure_time >= current_time) {
                int next_time = max(bus.arrival_time, current_time) + (bus.end == v ? 0 : 1);
                if (next_time < min_time[bus.end][bus.arrival_time]) {
                    min_time[bus.end][bus.arrival_time] = next_time;
                    pq.push({bus.end, bus.arrival_time});
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, d, v, r;
    cin >> n >> d >> v >> r;
    vector<Bus> buses(r);
    for (int i = 0; i < r; ++i) {
        cin >> buses[i].start >> buses[i].departure_time >> buses[i].end >> buses[i].arrival_time;
    }
    int result = dijkstra(n, d, v, r, buses);
    cout << result << endl;
    return 0;
}
