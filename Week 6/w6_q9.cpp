#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 200005
vector<int> tree[MAXN];
int in[MAXN],sz[MAXN],flat[MAXN],time=0;
void dfs(int u) {
    in[u]=time;
    flat[time++]=u;
    sz[u]=1;
    sort(tree[u].begin(),tree[u].end());
    for(int v:tree[u]) {
        dfs(v);
        sz[u]+=sz[v];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++) {
        int p;
        cin>>p;
        tree[p].push_back(i);
    }
    dfs(1);
    while(q--) {
        int u,k;
        cin>>u>>k;
        if(sz[u]<k) cout<<"-1\n";
        else cout<<flat[in[u]+k-1]<<"\n";
    }
}