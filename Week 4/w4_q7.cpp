#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
vector<int> pre(int n) {
    vector<int> V(n+1);
    for(int i=2;i<=n;i++) {
        bitset<32> dp;
        for(int a=1;a*2<i;a++) {
            int b=i-a;
            dp[V[a]^V[b]]=1;
        }
        int g=0;
        while(dp[g]) g++;
        V[i]=g;
    }
    return V;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,max=0;
    cin>>t;
    vector<int> V(t);
    for(int i=0;i<t;i++) {
        cin>>V[i];
        if(V[i]>max) max=V[i];
    }
    vector<int> ans=pre(max);
    for(int i=0;i<t;i++) {
        if(ans[V[i]]==0) cout<<"second\n";
        else cout<<"first\n";
    }
}