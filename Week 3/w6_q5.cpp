#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int nodes,edges;
    cin>>nodes>>edges;
    vector<vector<int>> graph(nodes+1);
    vector<int> deg(nodes+1);
    for(int i=0;i<edges;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        deg[v]++;
    }
    queue<int> q;
    for(int i=1;i<=nodes;i++) if(deg[i]==0) q.push(i);
    vector<int> dp(nodes+1);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int v:graph[u]) {
            dp[v]=max(dp[v],dp[u]+1);
            if(--deg[v]==0) q.push(v);
        }
    }
    int ans=0;
    for(int i=1;i<=nodes;i++) ans=max(ans,dp[i]);
    cout<<ans<<"\n";
}