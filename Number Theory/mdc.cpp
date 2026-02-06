#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mdc(ll a, ll b){
    if(b==0) return a;
    
    return mdc(b,a%b);
}
int main() {
    ll a,b; cin>>a>>b;
    
    cout<<mdc(max(a,b),min(a,b))<<endl;
}