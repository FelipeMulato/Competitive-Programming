#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main() 
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    ll k;cin>>k;
    vector<ll> v(n);
    for(auto &x:v) cin>>x;
  
    ll r = 0;
    ll l =0;
    ll dif=0;
    map<ll,ll> mp;
    ll res =0;
    while(r<n){
      if(mp[v[r]]==0) dif++;
      mp[v[r]]++;
      while(dif>k){
        mp[v[l]]--;
        if(mp[v[l]]==0) dif--;
        l++;
      }
      res+=(r-l+1);
      r++;
    }
    cout<<res<<endl;
  }
//https://cses.fi/problemset/task/2428/