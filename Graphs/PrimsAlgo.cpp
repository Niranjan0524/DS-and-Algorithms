#include<bits/stdc++.h>
using namespace std;

//
class Prims{
  public:

    //to find min spanning tree with its total weight:
    // adj has {node, weight} pairs
    pair<vector<pair<int,int>>, int> findMST(int start,vector<vector<pair<int,int>>> &adj){
      vector<pair<int,int>> mst;
      int totalWeight=0;

      priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> pq;
      int noOfNodes=adj.size();
      vector<int> visited(noOfNodes,0);
      pq.push({0,{start,-1}}); //initially push the start node with weight 0 and no parent

      while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int weight=it.first;
        int node=it.second.first;
        int parent=it.second.second;

        
        if(!visited[node]){
          visited[node]=1;
          
          // Only add edge to MST if it's not the starting node (parent != -1)
          if(parent != -1){
            mst.push_back({parent,node});
          }
          totalWeight+=weight;  

          for(auto &it:adj[node]){
            int adjNode=it.first;
            int edgeWeight=it.second;

            if(!visited[adjNode]){
              pq.push({edgeWeight,{adjNode,node}});
            }
          }
        }

      }

      return {mst, totalWeight};
    }
}