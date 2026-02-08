#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int tc;cin>>tc;while(tc--){
        int n = 1e6+9;
        vector<vector<int>> divs(n+1,vector<int>());
        //We can use it to make any operations with the
        // diviros of a given number on O(n log n) time
        for(int i=1;i<=n;i++){
          for(int j=i;j<=n;j+=i) divs[j].push_back(i);
        }
    }
    
}