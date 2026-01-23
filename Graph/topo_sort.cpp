#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
vector<vector<ll>> edges;
vector<vector<ll>> adj;
vector<bool> vis;
int n;
void topo_sorto(){
    int n = v.size();
    vector<int> indegree(n+1,0);
    for(auto [u,v]:edges){
        indegree[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> ord;
    while (!q.empty()){
        int curr =q.front(); q.pop();
        ord.push_back(curr);
        for(auto nx:adj[curr]){
            indegree[nx]--;
            if(indegree[nx]==0) q.push(nx);

        }
    }
    
}
vector<bool> vis;
void dfs_topo_sort(int u, vector<int> &order){
    vis[u] = true;
    for(auto nx:v[u]){
        if(!vis[nx]) dfs(nx,order);
    }
    order.push_back(u);
}