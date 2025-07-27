#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 2e5 + 5;
int dist1[MAXN], dist2[MAXN];
pair<int,vector<int>> bfs(int start,int n,vector<vector<int>> graph) {
    vector<int> dist(n+1,-1);
    queue<int> q;
    q.push(start);
    dist[start]=0;
    int farthest=start;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int v:graph[u]) {
            if(dist[v]==-1) {
                dist[v]=dist[u]+1;
                q.push(v);
                if(dist[v]>dist[farthest]) farthest=v;
            }
        }
    }
    return {farthest,dist};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<int>> graph(n+1);
    for(int i=1;i<n;i++) {
        int n1,n2;
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    auto u=bfs(1,n,graph).first;
    auto [v,dist_u]=bfs(u,n,graph);
    auto dist_v=bfs(v,n,graph).second;
    for(int i=1;i<=n;i++) cout<<max(dist_u[i],dist_v[i])<<" ";
    cout<<"\n";
}
