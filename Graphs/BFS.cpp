#include<bits/stdc++.h>
using namespace std;

//bfs can be used to find shortest path in unweighted graph and also for level order traversal in trees and graphs.
//also in graphs where all edges have same weight bfs can be used to find shortest path.

//below code finds bfs traversal and shortest distance from source node(0) to all other nodes in an unweighted graph and also stores the parent of each node to reconstruct the shortest path from any node to node=0.
void BFS(vector<vector<int>>& adj){
    //0 as start node:- (node,distance)
    queue<int> q;
    int p=adj.size();
    vector<int> visited(p,0);
    vector<int> dist(p,0);
    vector<int> parent(p,-1);
    q.push(0);
    visited[0]=1;
    dist[0]=0;

    while(!q.empty()){
        int currNode=q.front();
        int currDist=dist[currNode];

        q.pop();
        cout<<currNode<<" ";

        for(int adjNode:adj[currNode]){
            if(!visited[adjNode]){
                parent[adjNode]=currNode;
                dist[adjNode]=currDist+1;
                q.push(adjNode);
                visited[adjNode]=1;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<p;i++){
        cout<<dist[i]<<" ";
    }


}

//below code finds the shortes path from given source to all other nodes in an unweighted graph using bfs.

void shortestPath(vector<vector<int>> &adj,int src){
    queue<int> q;
    vector<int> dist(adj.size(),INT_MAX);
    q.push(src);
    vector<int> parent(adj.size(),-1);
    
}



int main(){
    vector<vector<int>> adj = {
        {1, 3},
        {0, 2, 4},
        {1, 5},
        {0, 4, 5},
        {1, 3},
        {2, 3}
    };

    BFS(adj);
    return 0;
}