#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n;
    long long x,sum=0;
    cin>>x>>n;
    vector<int> V(n);
    for(int i=0;i<n;i++) {
        cin>>V[i];
        sum+=V[i];
    }
    priority_queue<long long,vector<long long>,greater<long long>> Q(V.begin(),V.end());
    long long ans=0;
    while(Q.size()>1) {
        long long a=Q.top();
        Q.pop();
        long long b=Q.top();
        Q.pop();
        ans+=a+b;
        Q.push(a+b);
    }
    cout<<ans<<"\n";
}