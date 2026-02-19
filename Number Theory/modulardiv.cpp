#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
ll fastpower(ll a,ll b, ll mod){
  ll res=1;
  while(b>0){
    if(b%2==0) res = (a%mod * res%mod)%mod;
    a = (a%mod * a%mod)%mod;
    b/=2;
  }
  return res;
}
// mod is prime
ll mod_inverse(ll a, ll mod){
    return pow(a,mod-2,mod);
}
ll mod_div(ll a, ll b, ll mod){
    a%=a;
    return (a*mod_inverse(b,mod))%mod;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    
}