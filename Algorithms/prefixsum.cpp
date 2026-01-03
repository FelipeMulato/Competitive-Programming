#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q;cin>>n>>q;
    vector<ll> v(n);
    for(auto &x:v) cin>>x;
    vector<ll> prefix(n+1,0);
    for(int i=1;i<=n;i++){
      prefix[i] = prefix[i-1]+v[i-1];
    }
    while(q--){
      int a,b; cin>>a>>b;
      cout<<prefix[b]-prefix[a-1]<<endl;
    }
    
  
    
}
