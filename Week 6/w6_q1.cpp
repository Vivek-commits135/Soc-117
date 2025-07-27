#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 200005;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> graph(n+1);
    vector<int> maxStamina(n+1,-1);
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<k;i++) {
        int p,h;
        cin>>p>>h;
        pq.push({h,p});
    }
    while(!pq.empty()) {
        auto [stamina,node]=pq.top();
        pq.pop();
        if(maxStamina[node]>stamina) continue;
        maxStamina[node] = stamina;
        if(stamina==0) continue;
        for(int neighbor:graph[node]) if(maxStamina[neighbor]<stamina-1) pq.push({stamina-1,neighbor});
    }
    vector<int> guarded;
    for(int i=1;i<=n;i++) if(maxStamina[i]>=0) guarded.push_back(i);
    cout<<guarded.size()<<"\n";
    for(int v:guarded) cout<<v<<" ";
    cout<<"\n";
}
