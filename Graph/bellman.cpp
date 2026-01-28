#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int tc; tc=1; while (tc--){
        
        vector<vector<ll>> egdes;
        int n,m; cin>>n>>m;
        int a,b;
        ll w;
        for(int i=0;i<m;i++){
          cin>>a>>b>>w;
          egdes.push_back({a,b,w});
        }
        vector<ll> dist(n+1,0);
        vector<ll> parent(n+1,-1);
      
      
        for(int i=0;i<n-1;i++){
          for(auto x:egdes){
            int a  = x[0]; int b = x[1]; ll w = x[2];
            if( dist[a]!=LLONG_MAX && dist[b]>dist[a]+w){
              dist[b] = dist[a]+w;
              parent[b] =a;
            } 
          }
        }
        
        
        vector<int> way;
        int last =-1;
        for(auto x:egdes){
            int a  = x[0]; int b = x[1]; ll w = x[2];
            if(dist[b]>dist[a]+w){
              last =b;
              parent[b] =a;
              dist[b] = dist[a]+w; 
            }
          }
        if(last==-1) cout<<"NO"<<endl;
        else{
         
          for(int i=0;i<n-1;i++) last = parent[last];
          int b = last;
          way.push_back(b);
          b = parent[b];
        
          while(b!=last){
            way.push_back(b);
            b = parent[b];}
          way.push_back(b);
          cout<<"YES"<<endl;
          reverse(way.begin(),way.end());
          for(auto x:way) cout<<x<<" ";
        }
          
          
        
    }
    
}
