#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
      int n;cin>>n;
      vector<pair<ll,ll>> v(n);
      vector<ll> cords;
     
      for(auto &[u,v]:v) {cin>>u>>v; cords.push_back(u);cords.push_back(v);}
      
      //compress
      sort(cords.begin(),cords.end());
      cords.erase(unique(cords.begin(),cords.end()),cords.end());
      
      ll tmax = cords.size();
      vector<ll> cnt(tmax+1,0);
      for(auto [w,v]:v){
        w = lower_bound(cords.begin(),cords.end(),w)-cords.begin();
        v = lower_bound(cords.begin(),cords.end(),v)-cords.begin();
        cnt[w]++;
        cnt[v]--;
      }
      
      vector<ll> sweepline(tmax+1,0);
      for(int i=1;i<=tmax;i++){
        sweepline[i] = sweepline[i-1]+cnt[i-1];
      }
  

    
}
