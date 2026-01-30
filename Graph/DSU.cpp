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
void unite(int i, int j, vector<int> &parent,vector<ll> &rank){
  int s1 = find(i,parent);
  int s2 = find(j,parent);
  
  if(s1!=s2){
    if(rank[s1]<rank[s2]){
      parent[s1] = s2;
      rank[s2]+=rank[s1];
    }
    else{
      parent[s2] = s1;
      rank[s1]+=rank[s2];
    }
  }
  
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    
}