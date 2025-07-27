#include <iostream>
#include <vector>
using namespace std;
#define MAXN 10000001
vector<int> spf(MAXN,0);
void sieve() {
    vector<int> primes;
    for(int i=2;i<MAXN;i++) {
        if(spf[i]==0) {
            spf[i]=i;
            primes.push_back(i);
        }
        for(int p:primes) {
            if(p>spf[i]||p*i>=MAXN) break;
            spf[p*i]=p;
        }
    }
}
vector<int> get_prime_factors(int x) {
    vector<int> ans;
    while(x>1) {
        int p=spf[x];
        ans.push_back(p);
        while(x%p==0) x/=p;
    }
    return ans;
}
int gcd(int a,int b) {
    int temp;
    while(b) {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int n;
    cin>>n;
    vector<int> a(n),d1(n,-1),d2(n,-1);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) {
        int x=a[i];
        vector<int> primes=get_prime_factors(x);
        if(primes.size()>=2) {
            int p1=primes[0];
            int d_1=1,temp=x;
            while(temp%p1==0) {
                d_1*=p1;
                temp/=p1;
            }
            int d_2=x/d_1;
            if(gcd(d_1+d_2,x)==1) {
                d1[i]=d_1;
                d2[i]=d_2;
            }
        }
    }
    for(int x:d1) cout<<x<<" ";
    cout<<"\n";
    for(int x:d2) cout<<x<<" ";
    cout<<"\n";
}