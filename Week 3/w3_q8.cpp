#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin>>n;
    vector<int> V(n),V_sort(n);
    for(int i=0;i<n;i++) {
        cin>>V[i];
        V_sort[i]=V[i];
    }
    sort(V_sort.begin(),V_sort.end());
    vector<ll> dp(n),prev_dp(n);
    for(int i=0;i<n;i++) {
        ll min_val=LLONG_MAX;
        for(int j=0;j<n;j++) {
            min_val=min(min_val,(i>0?prev_dp[j]:0));
            dp[j]=abs(V[i]-V_sort[j])+min_val;
        }
        swap(dp,prev_dp);
    }
    cout<<*min_element(prev_dp.begin(),prev_dp.end())<<"\n";
}