#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    long long n,k;
    cin>>t;
    for(int i=0;i<t;i++) {
        cin>>n>>k;
        if(k%2==0 && n%2!=0) cout<<"NO"<<"\n";
        else cout<<"YES"<<"\n";
    }
}
