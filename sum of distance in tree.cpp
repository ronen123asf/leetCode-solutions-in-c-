#include "header.h"

vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    //PART 1 : build graph
    unordered_map<int, vector<int>> graph(n);
    for (auto &edge: edges) {
        int u = edge[0];
        int v = edge[1];
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    //PART 2 DFS
    vector<int> depth(n);
    stack<int> St;
    St.push(0);
    vector<bool> visited(n);
    visited[0] = true;
    vector<int> deg(n);

    while (!St.empty()) {
        int u = St.top();
        St.pop();

        for (auto &v: graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                St.push(v);
                depth[v] = depth[u] + 1;
                deg[u]++;
                deg[v]++;
            }
        }
    }
    //PART 4 : counting the sum of dist from the root 0
    vector<int> outputSums(n);

    for (int i = 0; i < n; i++)
        outputSums[0] += depth[i];

    //PART 5 : building outputSums List
    St.push(0);
    vector<bool> visited2(n);

    while (!St.empty()) {
        int u = St.top();
        St.pop();

        for (auto &v: graph[u]) {
            if (!visited2[v]) {
                visited2[v] = true;
                St.push(v);
                outputSums[v] = outputSums[u] + n - 2 * deg[v];
            }
        }
    }

    return outputSums;
}