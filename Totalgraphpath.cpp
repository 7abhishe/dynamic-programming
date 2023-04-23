#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<vector<int>>& graph, int node, int target, vector<int>& path, vector<vector<int>>& paths){
    path.push_back(node);
    if(node == target){
        paths.push_back(path);
    } else {
        for(int neighbor : graph[node]){
            backtrack(graph, neighbor, target, path, paths);
        }
    }
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> paths;
    vector<int> path;
    int source = 0;
    int target = graph.size() - 1;
    backtrack(graph, source, target, path, paths);
    return paths;
}

int main() {
    vector<vector<int>> graph = {{1,2},{3},{3},{}}; // Example graph
    vector<vector<int>> paths = allPathsSourceTarget(graph);
    for(int i=0;i<paths.size();i++){
        for(int j=0;j<paths[i].size();j++){
            cout << paths[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
