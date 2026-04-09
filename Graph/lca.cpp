#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
const ll mod = 1e9+7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int LG = 20;

vector<vector<int>> up;
vector<int> dep;
vector<int> sz;
vector<vector<int>> par;
void dfs(int u, int p = 0) {
  up[u][0] = p;
  dep[u] = dep[p] + 1;
  sz[u] = 1;
  for (int i = 1; i <= LG; i++) up[u][i] = up[up[u][i - 1]][i - 1];
  
  for (auto v: par[u]){ 
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = LG; k >= 0; k--) if (dep[up[u][k]] >= dep[v]) u = up[u][k];
  if (u == v) return u;
  for (int k = LG; k >= 0; k--) if (up[u][k] != up[v][k]) u = up[u][k], v = up[v][k];
  return up[u][0];
}
int kth(int u, int k) {
  assert(k >= 0);
  for (int i = 0; i <= LG; i++) if (k & (1 << i)) u = up[u][i];
  return u;
}
int dist(int a, int b){
	return dep[a]+dep[b] - 2*dep[lca(a,b)];
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin>>n>>q;
    up = vector<vector<int>>(n,vector<int>(LG+1));
    dep = vector<int>(n,0);
    sz = vector<int>(n,0);
    par = vector<vector<int>>(n,vector<int>());
    for(int i=1;i<n;i++){
      int a; cin>>a;
      a--;
      par[i].push_back(a);
      par[a].push_back(i);
    }
    dfs(0);
    
    while(q--){
      int a,b; cin>>a>>b;
      cout<<lca(a-1,b-1)+1<<endl;
      
    }
    
    
}





