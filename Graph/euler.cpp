#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
const ll mod = 1e9+7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<vector<int>> par;
vector<int> sta;
vector<int> ed;
vector<ll> flat;
int t;
void dfs(int s,int ant){
  sta[s] = t;
  flat[t]=s;
  t++;
 
  for(auto nx:par[s]){
    if(nx!=ant) dfs(nx,s);
  }
  ed[s] =t;
  flat[t] =s;
  t++;
}
