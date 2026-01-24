#include<bits/stdc++.h>
using namespace std;

void topoSort(vector<vector<int>> &adj,int currNode,vector<int> &visited,stack<int> &s){
    visited[currNode]=1;

    for(int adjNode:adj[currNode]){
        if(!visited[adjNode]){
            topoSort(adj,adjNode,visited,s);
        }
    }

    s.push(currNode);
}

int main(){
    vector<vector<int>> adjList = {
        {1, 2},
        {3, 4},
        {3, 5},
        {4, 6},
        {5, 6},
        {6},
        {}
    };
    
    int n = adjList.size();
    vector<int> visited(n, 0);
    stack<int> s;
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            topoSort(adjList, i, visited, s);
        }
    }
    

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}