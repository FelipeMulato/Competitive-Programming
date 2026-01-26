using namespace std;
#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
const int inf = 1e9;
vector<vector<pair<int,ll>>> adj;
int N;
void dijkstra(int s,int e){
    vector<ll> dis(N+1,inf);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    dist[s] = 0;
    pq.push({dist[s],s});

    while (!pq.empty()){
        ll curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();
        for(auto [nx_dist,nx_node]:adj[pq]){
            if(dist[nx_node]>dist[curr_node]+nx_dist){
                dist[nx_node]= dist[curr_node]+nx_dist;
                pq.push({dist[nx_node],nx_node});
            }
        }

    }
    return dist[e];
    
}