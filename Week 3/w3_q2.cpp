#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long produced(long long time, const vector<int>& mach) {
    long long sum=0;
    for(int m : mach) sum+=time/m;
    return sum;
}
int main() {
    int n;
    long long goods;
    cin>>n>>goods;
    vector<int> mach(n);
    for(int i=0;i<n;i++) cin>>mach[i];
    long long min=(goods* *min_element(mach.begin(),mach.end()))/n,max=(*max_element(mach.begin(),mach.end())/ *min_element(mach.begin(),mach.end())<1e8) ? goods* *max_element(mach.begin(),mach.end()) : 10e9,ans=max;
    while(min<=max) {
        long long mid=(min+max)/2;
        if(produced(mid,mach)>=goods) {
            ans=mid;
            max=mid-1;
        }
        else min=mid+1;
    }
    cout<<ans<<"\n";
}