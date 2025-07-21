#include<bits/stdc++.h>
using namespace std;


class DisjointSet{
  //for union find (rank):
  vector<int> rank;
  vector<int> parent;
  //for union find (size);
  vector<int> size;
  public:

    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
      if(node==parent[node]) return node;

      return parent[node]=findParent(parent[node]);
    }

    void unionByRank(int u,int v){
      int ulP_u=findParent(u);
      int ulP_v=findParent(v);

      if(ulP_u == ulP_v) return;

      if(rank[ulP_u] < rank[ulP_v]){
        parent[ulP_u] = ulP_v;
      }else if(rank[ulP_u] > rank[ulP_v]){
        parent[ulP_v] = ulP_u;
      }else{
        parent[ulP_v] = ulP_u;
        rank[ulP_u]++;
      }
    }

    void unionBySize(int u,int v){
      int ulP_u=findParent(u);
      int ulP_v=findParent(v);

      if(ulP_u == ulP_v) return;

      if(size[ulP_u] < size[ulP_v]){
        parent[ulP_u] = ulP_v;
        size[ulP_v] += size[ulP_u];
      }
      else{
        parent[ulP_v] = ulP_u;
        size[ulP_u] += size[ulP_v];
      }
    }
};