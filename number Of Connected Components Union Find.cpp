#include "header.h"

int numberOfConnectedComponentsUnionFind(int n, vector<vector<int>> &edges){

    vector<int> root(n) ;

    for(int i = 1; i < n; i++)
        root[i] = -1;

    for(auto &edge : edges) {

        int u = edge[0];
        int v = edge[1];

        if(root[u] == -1 && root[v] == -1) {
            root[v] = u;
            root[u] = u;
        }

        if(root[v] == -1)
            root[v] = root[u];

        if(root[u] == -1)
            root[u] = root[v];

    }

    vector<bool> visited(n);
    int components = 0;

    for(int i = 0; i < n; i++) {

        if (root[i] == -1)
            components++;

        if (!visited[root[i]] && root[i] != -1) {
            visited[root[i]] = true;
            components++;
        }
    }


    return components;
}
