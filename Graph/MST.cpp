#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
//DSU
int find(int i, vector<int> &parent){
  if(parent[i]==-1) return i;
 
  return parent[i]=find(parent[i],parent);
}
bool same(int i,int j,vector<int> &parent){
  return find(i,parent)==find(j,parent);
}
void unite(int i, int j, vector<int> &parent,vector<ll> &rank){
  int s1 = find(i,parent);
  int s2 = find(j,parent);
  

      if(rank[s2]>=rank[s1]){
        parent[s1] = s2;
        rank[s2]+=rank[s1];
      }
      else{
        parent[s2] = s1;
        rank[s1] +=rank[s2];
      }
  
 
  
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vector<int> parent(n+1,-1);
    vector<ll> rank(n+1,1);
    vector<pair<ll,pair<int,int>>> egdes;
    int a,b;
    ll w;
    for(int i=0;i<m;i++){
      cin>>a>>b>>w;
      egdes.push_back({w,{a,b}});
    }
    ll res=0;
    sort(egdes.begin(),egdes.end());
    for(auto [a,x]:egdes){
      int b = x.first;
      int c = x.second;
      if(!same(b,c,parent)){
        unite(b,c,parent,rank);
        res+=a;
      }
    }
    cout<<res<<endl;
    
    
}



