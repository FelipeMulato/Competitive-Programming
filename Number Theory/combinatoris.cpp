#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
int N = 1e6;
ll const MOD =1e9 +7;
ll fat[N]; ll invfat[N];
ll fastpower(ll a,ll b){
  ll res=1;
  while(b>0){
    if(b%2==0) res=(a%MOD * res%MOD)%MOD;
    a=(a%MOD * a%MOD)%MOD;
    b/=2;
  }
  return res;
}
ll inv(ll a){
    return fastpower(a,MOD-2,MOD);
}
ll precompute(){
    for(ll i=0;i<=N;i++){
        if(i==0){
            fat[i]=1;
            invfat[i]=1;
        }
        else{
            fat[i] = (fat[i-1]*i%MOD)%MOD;
            invfat[i] = inv(fat[i]); 
        }
    }
}
ll nCr(ll n, ll r){
    if(r>n) return 0;
    return (fat[n]*invfat[r]%MOD * invfat[n-r]%MOD)%MOD;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    precompute();
    ll n,r; n=5;r=2;
    cout<<nCr(n,r)<<endl;
    
}