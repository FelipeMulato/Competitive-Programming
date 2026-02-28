#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
const ll mod = 1e9+7;
struct segtree{
  int sz;
  vector<ll> sums;
  
  segtree(int n){
    sz = 1;
    while(sz<n) sz*=2;
    sums = vector<ll>(sz*2,0);
  }
  void set2(int i, ll v, int x, int lx, int rx){
    if(rx-lx==1){
      sums[x] = v;
      return;
    }
    
    int m = (rx+lx)/2;
    if(i<m){
      set2(i,v,2*x+1,lx,m);
    }
    else{
      set2(i,v,2*x+2,m,rx);
    }
    
    sums[x] = sums[2*x+1]+sums[2*x+2];
  }
  void set(int i, ll v){
    set2(i,v,0,0,sz);
  }
  ll sum2(int l, int r, int x, int lx, int rx){
    if(lx>=r||l>=rx) return 0;
    if(lx>=l && rx<=r) return sums[x];
    
    int m = (rx+lx)/2;
    
    return sum2(l,r,2*x+1,lx,m) + sum2(l,r,2*x+2,m,rx);
    
  }
  ll sum(int l ,int r){
    return sum2(l,r,0,0,sz);
  }
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    segtree t(n);
    for(int i=0;i<n;i++){
      ll x; cin>>x;
      t.set(i,x);
    }
    while(m--){
      ll op,a,b; cin>>op>>a>>b;
      if(op==1){
        t.set(a,b);
      }
      else{
        cout<<t.sum(a,b)<<endl;
      }
    }
    
    
    
    
    
    
    
}