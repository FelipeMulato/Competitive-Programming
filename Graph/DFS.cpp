#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
vector<vector<ll>> v;
vector<bool> vis;
void DFS(int u){
    vis[u] =true;
    for(auto next:v[u]){
        if(!vis[next])  DFS(next);
    }
    return;
}
//Test if a given graph is bipartite
bool DFS_Color(int u, vector<int> &color, int c){
    color[u] = c;
    for(auto next:v[u]){
        if(color[u]==0){
            if(!DFS_Color(next,color,c*(-1))) return false;
        }
        if(color[u]==color[next]) return false;
    }
    return true;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
}