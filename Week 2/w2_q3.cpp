#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n,x;
    cin>>n>>x;
    bool b=1;
    vector<pair<int,int>> V(n);
    for(int i=0;i<n;i++) {
        cin>>V[i].first;
        V[i].second=i;
    }
    sort(V.begin(),V.end());
    int i;
    for(i=0;i<n&&b;i++) {
        int begin=i+1,end=n-1,tar=x-V[i].first;
        while(end>begin) {
            if(V[end].first+V[begin].first>tar) end--;
            else if(V[end].first+V[begin].first<tar) begin++;
            else {
                cout<<V[i].second+1<<" "<<V[begin].second+1<<" "<<V[end].second+1<<"\n";
                b=0;
                break;
            }
        }
    }
    if(b==1) cout<<"IMPOSSIBLE\n";
}
