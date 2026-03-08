#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
const ll mod = 1e9+7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int const N = (1e5)*4;
vector<ll> BITS(N+5,0);
ll query(int x){
  ll res=0;
  while(x>0){
    res+=BITS[x];
    
    x -= (x & -x);
  }
  
  return res;
}
void update(int x,ll y){
  while(x<=N){
    
    
    BITS[x]+=y;
    x += (x & -x);
  }
  
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    }
}