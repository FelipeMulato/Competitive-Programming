using namespace std;
#define endl '\n'
#define ll long long
const int inf = 1e9;
vector<vector<ll>> v;
vector<bool> vis;
void DFS(int u){
    int n = v.size();
    vector<int> dist(n+1,inf),par(n+1,-1);
    queue<int> q;
    dist[u]=0;

    q.push(u);
    while (!q.empty()){
        int top = q.front(); q.pop();
        for(auto w:v[top]){
            if(dist[w]>dist[top]+1){
                dist[w] = 1+dist[top];
                par[w] =top;
                q.push(w);
            }
        }
    
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
}