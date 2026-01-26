#include<bits/stdc++.h>
using namespace std;


// time complexity: O(V^3)
// space complexity: O(V^2)

//This algo is for all pairs shortest path in a weighted graph
//dist matrix has initial distances between nodes (-1 if no edge else weight of edge)
void floydWarshall(vector<vector<int>> &dist) {
    int n = dist.size();

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}