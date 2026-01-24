#include<bits/stdc++.h>
using namespace std;

//for adj list:-
void DFS(vector<vector<int>> &adj,int currNode,vector<int> &visited){
    visited[currNode]=1;
    cout<<currNode<<" ";

    for(int adjNode:adj[currNode]){
        if(!visited[adjNode]){
            DFS(adj,adjNode,visited);
        }
    }
}

int main(){

    vector<vector<int>> adj={
        {1, 2},
        {0, 3, 4},
        {0, 4},
        {1, 5},
        {1, 2},
        {3}
    };
    int n=adj.size();
    vector<int> visited(n,0);
    DFS(adj,0,visited);
}