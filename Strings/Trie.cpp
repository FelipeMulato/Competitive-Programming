#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
const ll mod = 1e9+7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
struct Node{
  int sz;
  Node * next[26];
  Node(){
    sz =0;
    for(int i=0;i<26;i++){
      next[i] = NULL;
    }
  }
};
void add(Node* root, string p){
  root->sz++;
  Node* curr = root;
  for(auto ch:p){
     int idx = ch-'a';
     if(curr->next[idx]==NULL){
       Node* tt = new Node;
       curr->next[idx] = tt;
     }
     curr= curr->next[idx];
     curr->sz++;
  }
}
int query(Node* root, string p){
  Node* curr = root;
  for(auto ch:p){
     int idx = ch-'a';
     if(curr->next[idx]==NULL) return 0;
     curr= curr->next[idx];
     
  }
  return curr->sz;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin>>n>>q;
    Node *root = new Node;
    string p1;
    while(n--){
      cin>>p1;
      add(root,p1);
    }
    while(q--){
      cin>>p1;
      cout<<query(root,p1)<<endl;
    }
    
    
}