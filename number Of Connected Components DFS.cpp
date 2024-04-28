#include "header.h"

int numberOfConnectedComponentsDFS(int n, vector<vector<int>> &edges){

    int components = 1;
    unordered_map<int, vector<int>> graph(n);
    for(auto &edge : edges) {

        int u = edge[1];
        int v = edge[0];

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    bool visited[n];
    int visitedPtr = 0;

    stack<int> St;

    while(visitedPtr < n){
        while(visited[visitedPtr])
            visitedPtr++;

        if(visitedPtr >= n)
            break;

        St.push(visitedPtr);
        visitedPtr = 0;

        while(!St.empty()){
            int u = St.top();
            St.pop();
            visited[u] = true;

            for(auto &v : graph[u]){
                if(!visited[v]) {
                    visited[v] = true;
                    St.push(v);
                }
            }
        }
        components++;
    }

    return components;
}