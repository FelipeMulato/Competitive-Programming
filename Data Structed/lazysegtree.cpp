#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
struct Node {
    ll num;
    Node() : num(0){}; //Elemento Neutro 
    Node(ll v) : num(v) {}
};

struct Tag {
    ll op;
    bool has = false; 
    Tag() : op(0), has(false) {}
    Tag(ll v) : op(v), has(true) {}
};
// Como unir dois nós (ex: min entre dois filhos)
Node merge(Node n1, Node n2) {
    return Node(n1.num+n2.num);
}
// Como aplicar uma Tag a um Nó (Update de intervalo)
void apply(Node &n, Tag &t, ll sz) {
    if (!t.has) return;
    n.num = t.op *sz; 
}
// Como unir duas Tags (Lazy sobre Lazy)
void compose(Tag &parent, Tag child) {
    if (!child.has) return;
    parent.op = child.op; 
    parent.has = true;
}

struct SegTree {
    int sz;
    vector<Node> tree;
    vector<Tag> lazy;

    SegTree(int n) {
        sz = 1;
        while (sz <=n) sz *= 2;
        tree = vector<Node>(sz*2);
        lazy = vector<Tag>(sz*2);
    }

    void propagate(int x, int lx, int rx) {
        if (!lazy[x].has||rx-lx == 1) return;
        ll mid = (rx+lx)/2;
        apply(tree[2*x+1], lazy[x],mid-lx);
        apply(tree[2*x+2], lazy[x],rx-mid);
        
       
        compose(lazy[2*x+1], lazy[x]);
        compose(lazy[2*x+ 2], lazy[x]);
        
        lazy[x] = Tag(); 
    }
    void build(vector<ll> &a, int x, int lx, int rx) {
        if (rx-lx==1) {
            if (lx < a.size()) tree[x] = Node(a[lx]);
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);
        tree[x] = merge(tree[2*x + 1], tree[2*x + 2]);
    }

    void modify(int l, int r, ll v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            Tag t(v);
            apply(tree[x], t, rx-lx);
            compose(lazy[x], t);
            return;
        }
        int mid = (lx + rx) / 2;
        modify(l, r, v, 2*x+1, lx, mid);
        modify(l, r, v, 2*x+2, mid, rx);
        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }

    Node query(int l, int r, int x, int lx, int rx) {
        propagate(x,lx,rx);
        if (lx>=r || rx<=l) return Node(); 
        if (lx>=l && rx<=r) return tree[x];
        
        int mid = (lx+rx)/2;
        return merge(query(l, r, 2*x+1, lx, mid), query(l, r, 2*x+2, mid, rx));
    }

    void modify(int l, int r, ll v) { modify(l, r, v, 0, 0, sz); }
    Node query(int l, int r) { return query(l, r, 0, 0, sz); }
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    SegTree st(n); int a,b;
    vector<ll> v(n,0);
    
    while(m--){
      int op; cin>>op;
      if(op==1){
        cin>>a>>b;
        ll v; cin>>v;
        st.modify(a,b,v);
      }
      else{
        cin>>a>>b;
        cout<<st.query(a,b).num<<endl;
       
      }
    }
    
}