#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
const ll mod = 1e9+7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
map<ll, ll> mp1;
map<ll,ll> mp2;
ll get_hash(ll num,map<ll,ll> &mp) {
    if (mp.find(num)==mp.end()) {
        mp[num] = rng();
    }
    return mp[num];
}

int main() {
    int n,m; cin>>n;
    vector<ll> v1(n);
    for(auto &x:v1) cin>>x;
    vector<ll> v2(m);
    for(auto &x:v2) cin>>x;
    
    vector<ll> pref1a(n+1,0); vector<ll> pref1b(n+1,0);
    vector<ll> pref2a(m+1,0); vector<ll> pref2b(m+1,0);
  
  
    for(int i = 0;i<n;i++){
        pref1a[i+1] = pref1a[i]; 
        pref1a[i+1] += get_hash(v1[i],mp1);
        
        pref1b[i+1] = pref1b[i]; 
        pref1b[i+1] += get_hash(v1[i],mp2);
            
        
    }
    
    for(int i = 0;i<m;i++){
        pref2a[i+1] = pref2a[i]; 
        pref2a[i+1] += get_hash(v2[i],mp1);
        
        pref2b[i+1] = pref2b[i]; 
        pref2b[i+1] += get_hash(v2[i],mp2);
            
        
    }
    

    
    
    
    
}