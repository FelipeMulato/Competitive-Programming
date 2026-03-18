#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
const ll mod = 1e9+7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll B1 = 313, M1 = 1e9 + 7;
const ll B2 = 317, M2 = 1e9 + 9;

vector<ll> powers1, powers2;
vector<ll> prefix_hash1, prefix_hash2,prefix_hash3, prefix_hash4;

void powers(int n){
  powers1.assign(n+1, 1); powers2.assign(n+1, 1);
  for(int i=0;i<n;i++) {
        
        powers1[i+1] =(powers1[i]*B1) % M1;
        powers2[i+1] =(powers2[i]*B2) % M2;
    }
}

void precompute_hashes(string p1,vector<ll> &prefix_hash1, vector<ll> &prefix_hash2) {
    int n = p1.size();
    
    prefix_hash1.assign(n+1, 0);prefix_hash2.assign(n+1, 0);

    for(int i=0;i<n;i++) {
        ll val1 = p1[i]-'a'+1; 
        
        
        prefix_hash1[i+1] =((prefix_hash1[i]*B1)% M1 + val1)% M1;
        prefix_hash2[i+1] =((prefix_hash2[i]*B2)% M2 + val1)% M2;
        
        
    }
}

bool sub_Hasher(int i, int j,int k, int q){
  int len = j-i+1;
  int len2 =q-k;
  ll h1 = (prefix_hash1[j+1] - (prefix_hash1[i]*powers1[len])%M1 +M1)%M1;
  ll h2 = (prefix_hash2[j+1] - (prefix_hash2[i]*powers2[len])%M2 +M2)%M2;
  
  ll h3 = (prefix_hash1[k+1] - (prefix_hash1[1]*powers1[len])%M1 +M1)%M1;
  ll h4 = prefix_hash4[m];
  
  return h1==h3 && h2==h4;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string p1; cin>>p1;
    string p2; cin>>p2;
    int n = p1.size();
    int m  =p2.size();
    powers(max(n,m));
    precompute_hashes(p1,prefix_hash1,prefix_hash2);
    precompute_hashes(p2,prefix_hash3,prefix_hash4);
    
    ll res=0;
    int l = 0; int r =m-1;
    while(r<n){
      if(sub_Hasher(l,r,m)) res++;
      l++; r++;
    }
    cout<<res<<endl;
    
    
    
    
}