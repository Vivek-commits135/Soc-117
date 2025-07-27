#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll pow(ll a,ll b) {
    ll ans=1;
    while(b) {
        if(b%2) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return ans;
}
ll sum(ll prime,ll power) {
    return (((pow(prime,power+1)-1)%MOD)*(pow(prime-1,MOD-2)))%MOD;
}
int main() {
    int t;
    ll prime,power,n=1,cur,n_div_1=1,n_div_2=1,res=1,root=1;
    cin>>t;
    while(t--) {
        cin>>prime>>power;
        cur=pow(prime,power);
        n=(n*cur)%MOD;
        root=(root*pow(prime,power/2))%MOD;
        n_div_2=(n_div_2*(power+1))%(2*(MOD-1));
        n_div_1=(n_div_1*(power+1))%MOD;
        res=(res*sum(prime,power))%MOD;
    }
    cout<<n_div_1<<" "<<res<<" "<<((n_div_2%2)? (pow(n,n_div_2/2)*root)%MOD : pow(n,n_div_2/2))<<"\n";
}