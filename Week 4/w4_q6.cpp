#include <iostream>
using namespace std;
int main() {
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++) {
        cin>>n;
        long long sum=0,temp; 
        for(int j=0;j<n;j++) {
            cin>>temp;
            sum^=temp;
        }
        if(sum) cout<<"first\n";
        else cout<<"second\n";
    }
}