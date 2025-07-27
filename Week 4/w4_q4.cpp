#include <iostream>
#define MOD 1000000007
using namespace std;
long long pow(long long a,int b) {
    long long ans=1;
    while(b>0) {
        if(b%2) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return ans;
}
long long ans(int n, int m) {
    long long num=1,den=1;
    for(int i=1;i<=m;i++) {
        den=(den*i)%MOD;
        num=(num*(i+n-1))%MOD;
    }
    den=pow(den,MOD-2)%MOD;
    return (num*den)%MOD;
}
int main() {
    int n,m;
    cin>>n>>m;
    cout<<ans(n,m)<<"\n";
}