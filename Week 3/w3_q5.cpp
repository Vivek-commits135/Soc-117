#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
int main() {
    int t,m=0;
    cin>>t;
    vector<int> V(t);
    for(int &v:V) {
        cin>>v;
        m=max(m,v);
    }
    vector<pair<long long,long long>> dp(m+1);
    dp[1]=make_pair(1,1);
    for(int i=2;i<=m;i++) {
        dp[i].first=(((dp[i-1].first*2)%MOD)+dp[i-1].second)%MOD;
        dp[i].second=(((dp[i-1].second*4)%MOD)+dp[i-1].first)%MOD;
    }
    for(int v:V) cout<<(dp[v].first+dp[v].second)%MOD<<"\n";
}