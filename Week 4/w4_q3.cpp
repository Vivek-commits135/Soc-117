#include <iostream>
#include <vector>
#define MOD 1000000007
#define MAX 1000000
typedef long long ll;
using namespace std;
vector<ll> fac(MAX+1),inv(MAX+1);
ll pow(ll a,ll b) {
    ll ans=1;
    while(b>0) {
        if(b%2==1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return ans;
}
void init() {
    fac[0]=1;
    for(int i=1;i<=MAX;i++) fac[i]=(fac[i-1]*i)%MOD;
    inv[MAX]=pow(fac[MAX],MOD-2);
    for(int i=MAX-1;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%MOD;
}
int main() {
    int n;
    cin>>n;
    init();
    ll a,b;
    for(int i=0;i<n;i++) {
        cin>>a>>b;
        cout<<fac[a]*inv[b]%MOD*inv[a-b]%MOD<<"\n";
    }
}