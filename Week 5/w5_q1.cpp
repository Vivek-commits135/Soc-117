#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    string s;
    cin>>s;
    int n=s.length(),max=0,count=1;
    vector<int> len(n);
    stack<int> st;
    for(int i=0;i<n;i++) {
        if(s[i]=='(') st.push(i);
        else {
            if(!st.empty()) {
                int last=st.top(),cur;
                st.pop();
                cur=i-last+1;
                if(last>0) cur+=len[last-1];
                len[i]=cur;
                if(cur>max) {
                    max=cur;
                    count=1;
                }
                else if(cur==max) count++;
            }
        }
    }
    cout<<max<<" "<<count<<"\n";
}
