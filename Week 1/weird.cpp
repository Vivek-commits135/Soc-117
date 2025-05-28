#include <iostream>
#include <vector>
using namespace std;
int main() {
    long long n;
    cin>>n;
    cout<<n<<" ";
    while(n!=1) {
        if(n%2) n=(3*n)+1;
        else n=n/2;
        cout<<n<<" ";
    }
    cout<<"\n";
}