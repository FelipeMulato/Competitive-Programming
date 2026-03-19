#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
vector<int> Pi(string p){
  int n=  p.size();
  vector<int> ans(n+1,0);
  int l =0;
  for(int i=1;i<n;i++){
    int t = i+1;
    while(l>=0 && p[i]!=p[l]){
      if(l>=1) l =ans[l-1];
      else l=-1;
    }
    l++;
    
    
    ans[i]=l;
  }
  
  
  return ans;
}

int kmp(vector<int> &pi, string s, string p){
  int np = p.size(); int ns = s.size();
  int l =0;
  int res=0;
  for(int i=0;i<ns;i++){
    if(l>=0 && s[i]!=p[l]){
      if(l>=1) l =pi[l-1];
      else l = -1;
    }
    
    l++;
    if(l==np){
      l = pi[l-1];
      res++;
    }
    
  
  }
  return res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string p1; cin>>p1;
    string p2; cin>>p2;
    vector<int> pi = Pi(p2);
    
    cout<<kmp(pi,p1,p2)<<endl;
  
    
    
    
    
}
