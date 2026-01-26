#include<bits/stdc++.h>
using namespace std;

// time complexity: O((V + E) log V)
// space complexity: O(V)


//this algo finds shortest path from source to all other nodes in a weighted graph with non-negative weights
void dijkstra(vector<vector<pair<int, int>>> &adj, int src, vector<int> &dist) {
    int n = adj.size();
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        if (currDist > dist[currNode]) continue;

        for (auto &edge : adj[currNode]) {
            int adjNode = edge.first;
            int weight = edge.second;

            if (dist[currNode] + weight < dist[adjNode]) {
                dist[adjNode] = dist[currNode] + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
}
