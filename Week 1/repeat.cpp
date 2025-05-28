#include <iostream>
#include <vector>
using namespace std;
int main() {
    string s;
    cin>>s;
    int s_len=s.length();
    int max=0;
    int n=0;
    for(int i=0;i<s_len;i++) {
        if(i==0 || s[i]==s[i-1]) n++;
        if(i==s_len-1 || (i!=0 && s[i]!=s[i-1])) {
            if(n>max) max=n;
            n=1;
        }
    }
    cout<<max<<"\n";
}