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
        vector<bool> sieve(n+1,true);
        vector<int> primes;
        sieve[0]=sieve[1]=false;
        for(int i=2;i*i<=n;i++){
            if(sieve[i]){
                primes.push_back(i);
                for(int j=i*i;j<=n;j+=i) sieve[j]=false;
            }
        }
    }
    
}