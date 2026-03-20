#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
const ll mod = 1e9+7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<int> Z(string p){
  int n=  p.size();
  vector<int> z(n,0);
  int l =0; int r = 0;
  for(int i=1;i<n;i++){
    if(i<=r){
      int k = i-l;
      z[i] = min(r-i+1, z[k]);
    }
     
    while(i + z[i]<n && p[z[i]]==p[i+z[i]]){
      z[i]++;
    }
    if(i + z[i]-1>r){
      l=i;
      r = i+ z[i]-1;
    }
    
  }
  return z;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string p1; cin>>p1;
    
    vector<int> z = Z(p1);
    for(auto x: z) cout<<x<<" ";
    cout<<endl;

    
    
    
}