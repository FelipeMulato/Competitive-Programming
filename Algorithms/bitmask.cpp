#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
bool solve(){
  int n;cin>>n;
  vector<int> v(n);
  for(auto &x:v) cin>>x;
  
  for(int mask=0;mask<(1<<n);mask++){
    int cs=0;
    for(int i=0;i<n;i++){
      if(1&(mask>>i)) cs+=v[i];
      else cs-=v[i];
      
      cs%=360;
    }
    if(cs==0) return true;
  }
  return false;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    if(solve()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    
}
    