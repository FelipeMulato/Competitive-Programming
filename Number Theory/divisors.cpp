#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int tc; cin>>tc;while(tc--){
        ll n; cin>>n;
        vector<ll> divisors;
        for(ll i=1;i*i<=n;i++){
            if(n%i==0){
                divisors.push_back(i);
                if(i!=n/i) divisors.push_back(n/i);
            }
        }
        sort(divisors.begin(), divisors.end());
        for(auto d : divisors) cout << d << " ";
        cout << endl;
    }
    
}