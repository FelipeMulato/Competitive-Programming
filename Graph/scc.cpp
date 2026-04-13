#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
const ll mod = 1e9+7;
void dfs(int u, vector<int> &vis,vector<vector<int>> &adj, stack<int> &st){
        vis[u] =1;
        for(auto nx:adj[u]){
            if(vis[nx]==0) dfs(nx,vis,adj,st);
        }
        st.push(u);
    }
void dfs2(int u, vector<int> &vis,vector<vector<int>> &adj,vector<int> &cp){
        vis[u] =1;
        for(auto nx:adj[u]){
            if(vis[nx]==0) dfs2(nx,vis,adj,cp);
        }
        cp.push_back(u);
        
    }
int kosaraju(int V, vector<vector<int>> &adj, vector<vector<int>> &comps){
      int n = V;
      vector<int> vis(n,0);
      stack<int> st;

      for(int i=0;i<n;i++){
        if(vis[i]==0) dfs(i,vis,adj,st);
      }
      vector<vector<int>> adjT(n,vector<int>());
      for(int i=0;i<n;i++){
        for(auto nx:adj[i]) adjT[nx].push_back(i);
      }

      int scc =0;
      for(int i=0;i<n;i++) vis[i]=0;
      while(!st.empty()){
        int curr = st.top(); st.pop();

        if(vis[curr]==0){
            vector<int> cp;
            scc++;
            dfs2(curr,vis,adjT,cp);
            comps.push_back(cp);
        }
      }
      return scc;
    }
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n,vector<int>());
    for(int i=0;i<m;i++){
      int a,b; cin>>a>>b; a--;b--;
      adj[a].push_back(b);
      
    }
    vector<vector<int>> comps;
    int scc = kosaraju(n,adj,comps);
    vector<int> gp(n,-1);
    int v = comps.size();
    for(int i=0;i<v;i++){
      for(auto x:comps[i]) gp[x]=i+1;
    }
    vector<vector<int>> dag(v,vector<int>());
    
    for(int i=0;i<n;i++){
      for(auto j:adj[i]){
        if(gp[i]!=gp[j]) dag[gp[i]].push_back(gp[j]);
      }
    }
   
    for (int i = 0; i < v; i++) {
      sort(dag[i].begin(), dag[i].end());
      dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
     }

    cout<<v<<endl;
    for(auto x:res) cout<<x<<" ";
    
    
}
