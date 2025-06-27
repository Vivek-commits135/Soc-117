#include <iostream>
#include <deque>
using namespace std;
int main() {
    int n;
    cin>>n;
    deque<long long> list={1,2,4,8,16,32};
    if(n<=6) {
        cout<<list[n-1]<<"\n";
        return 0;
    }
    for(int i=0;i<n-6;i++) {
        list.push_back((list[0]+list[1]+list[2]+list[3]+list[4]+list[5])%(1000000007));
        list.pop_front();
    }
    cout<<list[5]<<"\n";
}