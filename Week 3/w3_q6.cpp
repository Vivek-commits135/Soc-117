#include <iostream>
#include <vector>
#include <limits>
using namespace std;
int knap(int k,int u,vector<int> weights,vector<int> values) {
    if(k==0&&u==0) return 0;
    else if(k==0) return numeric_limits<int>::min();
    return max(knap(k-1,u,weights,values),knap(k-1,u-weights[k-1],weights,values)+values[k-1]);
}
int main() {
    int n,max_weight,ans=0;
    cin>>n>>max_weight;
    vector<int> weights(n);
    vector<int> values(n);
    for(int i=0;i<n;i++) {
        cin>>weights[i]>>values[i];
    }
    for(int i=max_weight;i>0;i--) {
        ans=max(ans,knap(n,i,weights,values));
    }
    cout<<ans<<"\n";
}