#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
vector<int> V[N];
vector<int> count1,count2,vis,big,res,color;

vector<vector<int>> adj;
int dfs1(int s){
  vis[s]=1;

  int sz=0; int ch = -1;
  int add =1;
  for(auto nx:adj[s]){
    if(vis[nx]==0){
      int sub = dfs1(nx);
      if(sub>sz){
        ch =nx; sz =sub;
      }
      add+=sub;
    }
  }
  big[s] =ch;
  return add;
}

vector<vector<pair<int,int>>> queries;

void dfs2(int s, int ant, int keep){
  int child = big[s];
  int n = adj.size();
  int mx =0; int ans = 0;
  for(auto nx:adj[s]){
    if(nx!=ant && nx!=child) dfs2(nx,s,0);
  }
  if(child!=-1){
    dfs2(child,s,1);
    
    swap(V[s],V[child]);
    
  }
  V[s].push_back(s);
  

  if(count1[color[s]]!=0) update(count1[color[s]],-1);
  count1[color[s]]++;
  update(count1[color[s]],+1);
  for(auto nx:adj[s]){
    if(nx!=ant && nx!=child){
        for(auto ff:V[nx]){
         
          V[s].push_back(ff);
          
          if(count1[color[ff]]!=0)update(count1[color[ff]],-1);
          count1[color[ff]]++;
          update(count1[color[ff]],+1);
          
          
          }
          
        }
        
    }

    for(auto [k,idx]:queries[s]){
      res[idx] = query(n+1)-query(k-1);
    }

  if(keep==0){
    for(auto ff: V[s]){
      update(count1[color[ff]],-1);
      count1[color[ff]]--;
      if(count1[color[ff]]!=0) update(count1[color[ff]],+1);
    }
  }
  
  

}