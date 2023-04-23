#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> pii;

void prim(int start, vector<vector<pii>>& adj_list, vector<int>& distances, vector<int>& parent) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, start));
    distances[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto edge : adj_list[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distances[v] > weight) {
                distances[v] = weight;
                parent[v] = u;
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
    vector<int> parent(num_nodes, -1);

    for (int i = 0; i < num_edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj_list[u].push_back(make_pair(v, weight));
        adj_list[v].push_back(make_pair(u, weight));
    }

    prim(start_node, adj_list, distances, parent);

    for (int i = 0; i < num_nodes; i++) {
        cout << "Parent of node " << i << " is " << parent[i] << endl;
    }

    return 0;
}
