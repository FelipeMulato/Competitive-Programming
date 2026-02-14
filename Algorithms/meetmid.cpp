#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int tc;tc=1;while(tc--){
      ll n; cin>>n;
      ll k; cin>>k;
      vector<ll> v(n);
      for(auto &x:v) cin>>x;
      
      ll met = n/2;
      
      vector<ll> p1;
      for(ll mask = 0; mask<(1<<met);mask++){
        ll curr=0;
        for(ll i=0;i<met;i++){
           if(mask &(1<<i)) curr+=v[i];
        }
        p1.push_back(curr);
      }
      
      
      vector<ll> p2;
      for(ll mask = 0; mask<(1<<(n-met));mask++){
        ll curr=0;
        for(ll i=0;i<(n-met);i++){
           if(mask &(1<<i)) curr+=v[i+met];
        }
        p2.push_back(curr);
      }
      
      ll count =0;
      sort(p2.begin(),p2.end());
      for(auto x:p1){
        count+=(upper_bound(p2.begin(),p2.end(),k-x)-lower_bound(p2.begin(),p2.end(),k-x));
      }
      cout<<count<<endl;
        
    }
    
}