#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vector<ll> a(n);
    for(auto &x: a) cin>>x;
    ll x; cin>>x;
    int l = 0, r = n-1;
    while(r>l+1){
        int m1 = l+(r-l)/3;
        int m2 = r-(r-l)/3;
        if(fun(m1)<fun(m2)) r = m2;
        else l = m1;
    }
   

}