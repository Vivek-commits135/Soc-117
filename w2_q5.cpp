#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int median(vector<int> V,int n) {
    sort(V.begin(),V.end());
    return V[(n-1)/2];
}
int main() {
    int n;
    long long sum=0;
    cin>>n;
    vector<int> V(n);
    for(int i=0;i<n;i++) {
        cin>>V[i];
    }
    int med=median(V,n);
    for(int i=0;i<n;i++) {
        sum+=abs(V[i]-med);
    }
    cout<<sum<<"\n";
}