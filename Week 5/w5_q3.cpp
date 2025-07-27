#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int i,n=s.length();
        for(i=0;i<n;i++) {
            if(i==0&&int(s[i])-48!=1) break;
            else if(i<n-1&&int(s[i])-48==0) break;
            else if(i==n-1&&int(s[i])-48==9) break;
        }
        cout<<(i<n ? "NO\n":"YES\n");
    }
}