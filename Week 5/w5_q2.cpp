#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
const int N = 2e5 + 5;
const int MOD = 998244353;
vector<LL> pref(N);
vector<int> pow2(N);
void pre_power() {
    pow2[0]=1;
    for(int i=1;i<N;i++) {
        pow2[i]=(2LL*pow2[i-1])%MOD;
    }
}
void sol() {
    int n;
    cin>>n;
    LL min_pref=1e18;
    pref[0]=0;
    for(int i=1;i<=n;i++) {
        LL x;
        cin>>x;
        pref[i]=pref[i-1]+x;
        min_pref=min(min_pref,pref[i]);
    }
    if(min_pref>=0) {
        cout<<pow2[n]<<'\n';
        return;
    }
    int res=0,count=0;
    for (int i=1;i<=n;i++) {
        if(pref[i]==min_pref) {
            res=(res+1LL*pow2[count]*pow2[n-i])%MOD;
        }
        if(pref[i]>=0) count++;
    }
    cout<<res<<'\n';
}
int main() {
    pre_power();
    int t;
    cin>>t;
    while(t--) sol();
}