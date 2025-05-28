#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> digits(int n) {
    vector<int> V;
    for(int i=0;n/int(pow(10,i));i++) {
        V.push_back((n/int(pow(10,i)))%10);
    }
    return V;
}
int diff(vector<int> digits) {
    int min=0,max=0;
    for(int i=0;i<digits.size();i++) {
        if(digits[i]>max) max=digits[i];
        if(digits[i]<min || i==0) min=digits[i];
    }
    return max-min;
}
int main() {
    int t,l,r,max;
    cin>>t;
    for(int i=0;i<t;i++) {
        cin>>l>>r;
        pair<int,int> P=make_pair(l,0);
        for(int j=l;j<=r;j++) {
            int cur=diff(digits(j));
            if(cur>P.second) {
                P.second=cur;
                P.first=j;
            }
            if(cur==9) break;
        }
        cout<<P.first<<"\n";
    }
}
