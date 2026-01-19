#include <bits/stdc++.h>
using namespace std;
class Graph{
public:
  int n;
  vector<int> *v;
  Graph(int n1){
    n = n1;
    v = new vector<int>[n+1];
  }
  void add_egde(int a,int b){
    v[a].push_back(b);
  }
};
int main(){
    return 0;
}