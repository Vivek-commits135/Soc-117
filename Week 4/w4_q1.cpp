#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll pow(ll a,ll b,ll mod) {
    ll ans=1;
    while(b) {
        if(b%2) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ans;
}
ll cal(ll a,ll b,ll c) {
    if(a==0&&b==0&&c!=0) return 1;
    if(c==0) return a;
    return pow(a,pow(b,c,MOD-1),MOD);
}
int main() {
    int n;
    ll a,b,c;
    cin>>n;
    while(n--) {
        cin>>a>>b>>c;
        cout<<cal(a,b,c)<<"\n";
    }
}
