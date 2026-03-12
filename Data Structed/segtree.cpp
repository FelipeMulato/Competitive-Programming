#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
const ll mod = 1e9+7;
struct Node{
  int num;
  Node(){
    num = 0;
  }
};
Node Merge(Node a,Node b){
  Node out;
  // add problem logic here
  out.num = a.num + b.num;
  return out;
}
struct SegTree{
  int sz;
  vector<Node> seg;
  SegTree(int n){
    sz = 1;
    while(sz<n) sz*=2;
    seg = vector<Node>(sz*2);
  }
  void update(ll i, ll v, ll x,ll lx,ll rx){
    if(rx-lx==1){
      seg[x].num+=v;
      return;
    }
    int mid = (rx+lx)/2;
    if(i<mid) update(i,v,2*x+1,lx,mid);
    else update(i,v,2*x+2,mid,rx);
    
    seg[x] = Merge(seg[2*x+1],seg[2*x+2]);
  }
  Node query(ll l, ll r, ll x, ll lx,ll rx){
    if(lx>=r||rx<=l){
      Node out; return out;
    }
    if(lx>=l && r>=rx) return seg[x];
    int mid = (rx+lx)/2;
    
    return Merge(query(l,r,2*x+1,lx,mid),query(l,r,2*x+2,mid,rx));
  }
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    }
    
    
    
    
    
    
    
}