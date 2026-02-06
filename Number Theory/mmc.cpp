#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mdc(ll a, ll b){
    if(b==0) return a;
    return mdc(b,a%b);
}
ll mmc(ll a, ll b){
  return (a*b)/(mdc(a,b));
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b; cin>>a>>b;
    cout<<mmc(a,b)<<endl;
    
}