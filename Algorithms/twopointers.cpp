#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main() 
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    ll s; cin>>s;
    vector<ll> v(n);
    for(auto &x:v) cin>>x;
    ll cs= 0;
    ll l,r; l =r =0;
    ll res =-1;
    while(r<n){
      cs+=v[r];
      while(cs>s){
        cs-=v[l];
        l++;
      }
      res = max(res,(r-l+1));
      r++;
    }
    cout<<res<<endl;
}
//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/A