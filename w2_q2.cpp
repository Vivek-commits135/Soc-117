#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int n,i,x,temp;
    cin>>n>>x;
    unordered_map<int,int> M;
    for(i=0;i<n;i++) {
        cin>>temp;
        if(M.count(x-temp)) {
            cout<<M[x-temp]+1<<" "<<i+1<<"\n";
            break;
        }
        else if(temp<=x) M[temp]=i;
    }
    if(i==n) cout<<"IMPOSSIBLE\n";
}