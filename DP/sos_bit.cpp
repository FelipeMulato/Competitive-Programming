#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
const ll mod = 1e9+7;
int const N = 4e5;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

/// Trick to solve subset sum problems in O(N * MAX_SUM/64) using bitsets
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vector<ll> v(n); for(auto &x:v) cin>>x;
    
    bitset<N> bits;
    
    bits[0] =1;
    
    for(int i=0;i<n;i++){
      bits |= (bits<<v[i]);
    }
    
    vector<ll> prefx(N+1,0);
    
    for(int i=1;i<=N;i++){
      prefx[i] +=prefx[i-1] + bits[i];
    }
    
    while(m--){
      int a,b; cin>>b>>a;
      
      cout<<prefx[a]-prefx[b-1]<<endl;
    }
    
}


