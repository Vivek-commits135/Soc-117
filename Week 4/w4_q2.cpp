#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
int main() {
    long long n,sum=0;
    cin>>n;
    for(long long i=1,j;i<=n;i=j+1) {
        long long q=n/i;
        j=n/q;
        long long count=j-i+1;
        long long cur=((i+j)%MOD)*(count%MOD)%MOD;
        cur=(cur*((MOD+1)/2))%MOD;
        sum=(sum+q%MOD*cur%MOD)%MOD;
    }
    cout<<sum<<"\n";
}