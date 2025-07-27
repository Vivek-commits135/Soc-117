#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> r(n);
    for(int &v:r) cin>>v;
    long double exp=0.0;
    for(int a=0;a<n;a++) {
        for(int b=a+1;b<n;b++) {
            long long inv_count=0;
            for(int i=1;i<=r[a];i++) {
                inv_count+=min(i-1,r[b]);
            }
            long double prob=(long double)inv_count/(r[a]*r[b]);
            exp+=prob;
        }
    }
    long double ans;
    long long scaled=exp*1e9;
    if(scaled%100==99) scaled=(scaled/100)+1;
    else scaled/=100;
    if(scaled%10==5) {
        if(((scaled%100)/10)%2) ans=(long double)((scaled+10)/10)/1e6;
        else ans=(long double)(scaled/10)/1e6;
    }
    else ans=exp;
    cout<<fixed<<setprecision(6)<<ans<<"\n";
}