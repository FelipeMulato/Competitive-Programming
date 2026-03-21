#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double

ll fastpower(ll a,ll b){
  ll res=1;
  while(b>0){
    if(b&1) res*=a;
    a*=a;
    b/=2;
  }
  return res;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int tc;tc=1;while(tc--){
        cout<<fastpower(5,5)<<endl;
    }
}