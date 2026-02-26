#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
const ll mod=1e9+7;
const int sz = 2;
ll mod_add(ll a, ll b){return (a%mod+b%mod)%mod;}
ll mod_mut(ll a, ll b){return (a%mod*b%mod)%mod;}
struct Matrix{
  ll mat[sz][sz];
  Matrix(){
    memset(mat,0,sizeof(mat));
  }
  void indentidy(){
    for(int i=0;i<sz;i++){
      mat[i][i]=1;
    }
  }
  Matrix operator* (Matrix a){
    Matrix res;
    for(int i=0;i<sz;i++){
      for(int j=0;j<sz;j++){
        for(int k=0;k<sz;k++){
          res.mat[i][j]=mod_add(res.mat[i][j],mod_mut(mat[i][k],a.mat[k][j]));
        }
      }
    }
    return res;
  }
};
Matrix fastpower(Matrix a, ll b){
  Matrix res;
  res.indentidy();
  while(b>0){
    if(b&1) res = res*a;
    a=a*a;
    b/=2;
    
  }
  return res;
}
ll fib(ll n){
  if(n==0) return 0;
  if(n<=2) return 1;
  Matrix x;
  x.mat[0][0] =1; x.mat[0][1]=1; x.mat[1][0]=1;
  
  x=fastpower(x,n-2);
  
  ll res = (x.mat[0][0]+x.mat[0][1])%mod;
  return res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin>>n;
    cout<< fib(n);
    
    
    
}
 
 
 
 
