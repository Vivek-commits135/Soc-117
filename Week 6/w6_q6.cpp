#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 200005
int n,m;
vector<int> g[2*MAX],rg[2*MAX];
vector<bool> vis;
vector<int> order,comp;
void add_clause(int x,bool xval,int y,bool yval) {
    int a=2*x+!xval;
    int b=2*y+!yval;
    g[a^1].push_back(b);
    g[b^1].push_back(a);
    rg[b].push_back(a^1);
    rg[a].push_back(b^1);
}
void dfs1(int u) {
    vis[u]=1;
    for(int v:g[u]) if(!vis[v]) dfs1(v);
    order.push_back(u);
}
void dfs2(int u,int label) {
    comp[u]=label;
    for(int v:rg[u]) if(comp[v]==-1) dfs2(v,label);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        string s1,s2;
        int a,b;
        cin>>s1>>a>>s2>>b;
        bool a_pos=(s1=="+");
        bool b_pos=(s2=="+");
        add_clause(a,a_pos,b,b_pos);
    }
    int vars=m+1;
    vis.assign(2*vars,false);
    comp.assign(2*vars,-1);
    for(int i=2;i<2*vars;i++) if(!vis[i]) dfs1(i);
    reverse(order.begin(),order.end());
    int label=0;
    for(int u:order) if(comp[u]==-1) dfs2(u,label++);
    vector<char> result(m+1);
    for(int i=1;i<=m;i++) {
        if(comp[2*i]==comp[2*i+1]) {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
        result[i]=(comp[2*i]>comp[2*i+1]) ? '+' : '-';
    }
    for(int i=1;i<=m;i++) cout<<result[i];
    cout<<"\n";
}