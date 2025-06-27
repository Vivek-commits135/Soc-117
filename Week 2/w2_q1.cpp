#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> V(n);
    for(int i=0;i<n;i++) cin>>V[i];
    const int MAX_VAL=1e9+5;
    vector<bool> seen(MAX_VAL,false);
    int maxLen=0,start=0;
    for(int end=0;end<n;end++) {
        while(seen[V[end]]) {
            seen[V[start]]=false;
            start++;
        }
        seen[V[end]]=true;
        maxLen=max(maxLen,end-start+1);
    }
    cout<<maxLen<<"\n";
}
