#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
const ll mod = 1e9+7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
ll const inf  = 1e9+7;
/// SOS DP: Sum over subsets DP
// Computes f[mask] = sum of g[submask] for all submasks of mask(submask & mask == submask)
void SOS(vector<ll> &f, int n){
    for(int i=0;i<n;i++){
        for(int mask=0;mask<(1<<n);mask++){
            if(mask&(1<<i))f[mask] += f[mask^(1<<i)];
                
            
        }
    }
}