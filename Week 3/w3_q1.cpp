#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    long long time=0,ans=0;
    cin>>n;
    vector<pair<int,int>> V(n);
    for(int i=0;i<n;i++) cin>>V[i].first>>V[i].second;
    sort(V.begin(),V.end());
    for(int i=0;i<n;i++) {
        time+=V[i].first;
        ans+=V[i].second-time;
    }
    cout<<ans<<"\n";
}
