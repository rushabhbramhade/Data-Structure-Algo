// DFS Template
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void dfs(unordered_map<int, vector<int>> &graph, int node, unordered_set<int> &visited) {
    visited.insert(node);
    cout << node << endl;

    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, neighbor, visited);
        }
    }
}

int main() {
    unordered_map<int, vector<int>> graph = {
        {0, {1, 2}},
        {1, {0, 3}},
        {2, {0, 3}},
        {3, {1, 2}}
    };

    unordered_set<int> visited;
    dfs(graph, 0, visited);
    return 0;
}
