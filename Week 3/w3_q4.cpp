#include <iostream>
#include <vector>
using namespace std;
int main() {
    string a,b;
    cin>>a>>b;
    int l1=a.length(),l2=b.length();
    vector<vector<int>> dp(l1+1,vector<int>(l2+1));
    for(int i=0;i<=l1;i++) {
        for(int j=0;j<=l2;j++) {
            if(j==0) {dp[i][j]=i; continue;}
            if(i==0) {dp[i][j]=j; continue;}
            int c=(a[i-1]==b[j-1]) ? 0 : 1;
            dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+c);
        }
    }
    cout<<dp[l1][l2]<<"\n";
}