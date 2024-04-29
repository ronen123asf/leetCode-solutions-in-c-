#include "header.h"

int longestCycle(vector<int> &edges){
    int max = -1, n = edges.size();
    unordered_map<int, vector<int>> graph(n);
    vector<int> lca(n);
    vector<int> depths(n);

    for(int i = 0; i < n; i++){
        int u = i;
        int v = edges[i];
        if(v >= 0)
        graph[u].push_back(v);
    }

    stack<int> St;

    vector<bool> visited(n);

    int unvisitedNode = 0;
    while(unvisitedNode < n) {
        while(unvisitedNode < n && visited[unvisitedNode])
            unvisitedNode++;  
      
        if(unvisitedNode > n)
          break;
      
        St.push(unvisitedNode);
        visited[unvisitedNode]= true;
        vector<bool> visited2(n);
        visited2[unvisitedNode] = true;

        while (!St.empty()) {
            int r = St.top();
            St.pop();

            for (auto &s: graph[r]) {
                if (!visited[s]) {
                    visited2[s] = true;
                    lca[s] = r;
                    depths[s] = depths[r] + 1;
                    St.push(s);

                } else if(visited2[s]){
                    visited[s] = true;
                    int cl;
                    if (lca[s] == lca[r])
                        cl = depths[s] + depths[r] + 1;
                    else
                        cl = abs(depths[s] - depths[r]) + 1;
                    if (max < cl)
                        max = cl;
                }
                visited[s] = true;
            }
        }
    }
    return max;
}
