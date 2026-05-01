#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
const ll mod = 1e9+7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
ll const inf  = 1e9+7;
\\ SOS DP to find the minimum number of elements needed to achieve each sum from 0 to n in O(n*sqrt(n)) time complexity
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<ll> v(n); for(auto &x:v) cin>>x;
    vector<ll> freq(n+1,0);
    for(auto x:v) freq[x]++;

    vector<pair<ll,ll>> compress;
    
    
    for(ll i=1;i<=n;i++){
      if(freq[i]>0) compress.push_back({i,freq[i]});
    }
    vector<ll> dp(n+1,inf);
    
    dp[0] =0;
    
    for(auto [w,k]:compress){
     
      vector<ll> ndp = dp;
      
      for(ll p=0;p<w;p++){
        ll sum =0;
        
        deque<pair<ll, ll>> window;

        for (int j = p, mul = 0; j <= n; j += w, mul++) {
            while (!window.empty() && window.front().second < mul - k)
                window.pop_front();

            if (!window.empty()) ndp[j] =min(ndp[j], window.front().first + mul);

            while (!window.empty() && window.back().first >= dp[j] - mul)
                window.pop_back();
            
            window.emplace_back(dp[j] - mul, mul);
        }
        
        
      }
      swap(ndp,dp);
    }
    \\ Output the minimum number of elements needed to achieve each sum from 0 to n
    for(int i=0;i<=n;i++){
      if(dp[i] >= inf) cout<<"-1 ";
      else cout<<dp[i]<<" ";
    }
    
}