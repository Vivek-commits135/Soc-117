#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
typedef long long ll;
using namespace std;
bool adopt(pair<ll,ll> bounds,ll& low,ll& high) {
    if(bounds.first>high||bounds.second<low) return false;
    low=max(low,bounds.first);
    high=min(high,bounds.second);
    return true;
}
pair<ll,ll> bounds(ll a,ll b,ll time) {
    return (time>1) ? make_pair(a+(time-2)*(a-b)+1,a+(time-1)*(a-b)) : make_pair(1LL,a);
}
ll search(ll a,ll b,ll low,ll high) {
    ll up=(high>a) ? (high-b-1)/(a-b)+1 : 1;
    ll down=(low>a) ? (low-b-1)/(a-b)+1 : 1;
    if(up==down) return down;
    return -1;
}
int main() {
    int t,n;
    cin>>t;
    while(t--) {
        ll option,a,b,time;
        ll low=0,high=LLONG_MAX;
        cin>>n;
        while(n--) {
            cin>>option;
            if(option==1) {
                cin>>a>>b>>time;
                if(adopt(bounds(a,b,time),low,high)) cout<<"1 ";
                else cout<<"0 ";
            }
            else {
                cin>>a>>b;
                cout<<search(a,b,low,high)<<" ";
            }
        }
        cout<<"\n";
    }
}