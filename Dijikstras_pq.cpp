#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(int start, vector<vector<pii>>& adj_list, vector<int>& distances) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, start));
    distances[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto edge : adj_list[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distances[v] > distances[u] + weight) {
                distances[v] = distances[u] + weight;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
}

int main() {
    int num_nodes, num_edges, start_node;
    cin >> num_nodes >> num_edges >> start_node;

    vector<vector<pii>> adj_list(num_nodes);
    vector<int> distances(num_nodes, INT_MAX);

    for (int i = 0; i < num_edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj_list[u].push_back(make_pair(v, weight));
    }

    dijkstra(start_node, adj_list, distances);

    for (int i = 0; i < num_nodes; i++) {
        cout << "Distance from " << start_node << " to " << i << " is " << distances[i] << endl;
    }

    return 0;
}
