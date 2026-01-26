#include<bits/stdc++.h>
using namespace std;

// time complexity: O(V*E)
// space complexity: O(V)

//This algo finds shortest path from source to all other nodes in a weighted graph which may contain negative weight edges
// here edges are in form of { {u, v, weight} } from -to -weight
void bellmanFord(vector<vector<vector<int>>> &edges, int src, vector<int> &dist) {
    int n = dist.size();
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto &edge : edges) {
            int u = edge[0][0];
            int v = edge[0][1];
            int weight = edge[0][2];

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto &edge : edges) {
        int u = edge[0][0];
        int v = edge[0][1];
        int weight = edge[0][2];

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }
}
