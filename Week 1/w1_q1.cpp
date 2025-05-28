#include <iostream>
#include <vector>
using namespace std;
int main() {
    long long n;
    cin>>n;
    long long sum=(n*(n+1))/2;
    int num;
    while(cin>>num) {
        sum-=num;
    }
    cout<<sum;
}
