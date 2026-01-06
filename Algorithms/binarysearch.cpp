#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
bool bs(ll x,vector<ll> &v, ll n){
  ll l = 0;
  ll r = n-1;
  while(l<=r){
    ll mid = l+(r-l)/2;
    if(v[mid]==x) return true;
    if(v[mid]>x) r =mid-1;
    else l = mid+1;
  }
  return false;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;cin>>n>>k;
    vector<ll> v(n);
    for(auto &x:v) cin>>x;
    while(k--){
      ll a; cin>>a;
      if(bs(a,v,n)) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
    
    
}


