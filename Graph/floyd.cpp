#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int tc; tc=1; while (tc--){
      int n,m,q;cin>>n>>m>>q;
      vector<vector<ll>> dist(n+1,vector<ll>(n+1,LLONG_MAX));
      for(int i=1;i<=n;i++) dist[i][i] =0;
      int a,b;
      ll w;
      for(int i=0;i<m;i++){cin>>a>>b>>w; dist[a][b] =min(w,dist[a][b]); dist[b][a]=min(w,dist[b][a]);}
      
      for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
          for(int i=1;i<=n;i++){
            if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        }}
      }
      while(q--){
        cin>>a>>b;
        if(dist[a][b]!=LLONG_MAX)cout<<dist[a][b]<<endl;
        else cout<<-1<<endl;
      }
    }
    
}