#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool edge_cmp(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

int find(int u, vector<int>& parent) {
    while (parent[u] != u) {
        u = parent[u];
    }
    return u;
}

void union_sets(int u, int v, vector<int>& parent) {
    int parent_u = find(u, parent);
    int parent_v = find(v, parent);
    parent[parent_u] = parent_v;
}

vector<Edge> kruskal(int num_nodes, vector<Edge>& edges) {
    vector<Edge> mst;
    vector<int> parent(num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(), edge_cmp);

    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        if (find(u, parent) != find(v, parent)) {
            mst.push_back(edge);
            union_sets(u, v, parent);
        }
    }

    return mst;
}

int main() {
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    vector<Edge> edges(num_edges);
    for (int i = 0; i < num_edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges[i] = {u, v, weight};
    }

    vector<Edge> mst = kruskal(num_nodes, edges);

    for (auto edge : mst) {
        cout << edge.u << " " << edge.v << " " << edge.weight << endl;
    }

    return 0;
}
