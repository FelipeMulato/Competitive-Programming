#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    vector<vector<ll>> v(n,vector<ll>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>v[i][j];
    }
    vector<vector<ll>> prefix(n+1,vector<ll>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]+v[i-1][j-1] - prefix[i-1][j-1];
        }
    }
    int q;cin>>q;
    int a,b,c,d;
    while (q--){
        cin>>a>>b>>c>>d;
        cout<<prefix[c][d]-prefix[a-1][d]-prefix[c][b-1]+prefix[a-1][b-1]<<endl;
    }
    
    
}