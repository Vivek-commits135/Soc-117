#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void ans(int begin,int end,vector<int> par) {
    vector<int> cycle;
    cycle.push_back(end);
    while(end!=begin) {
        end=par[end];
        cycle.push_back(end);
    }
    reverse(cycle.begin(),cycle.end());
    cout<<cycle.size()+1<<"\n";
    for(int x:cycle) cout<<x<<" ";
}
bool dfs(int u,int p,vector<vector<int>>& graph,vector<bool>& vis,vector<int>& par) {
    vis[u]=1;
    for(int v:graph[u]) {
        if(v==p) continue;
        if(vis[v]) {
            par[v]=u;
            ans(v,u,par);
            cout<<v<<"\n";
            return 1;
        }
        else {
            par[v]=u;
            if(dfs(v,u,graph,vis,par)) return 1;
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    while(m--) {
        int n1,n2;
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    vector<bool> vis(n+1);
    vector<int> par(n+1);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            par[i]=-1;
            if(dfs(i,-1,graph,vis,par)) return 0;
        }
    }
    cout<<"IMPOSSIBLE\n";
}