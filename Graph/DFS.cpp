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
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
}