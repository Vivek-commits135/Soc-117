#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
typedef vector<vector<long long>> Matrix;
Matrix mul(const Matrix& A,const Matrix& B,int n) {
    Matrix C(n,vector<long long>(n));
    for(int i=0;i<n;i++) for(int k=0;k<n;k++) if(A[i][k]) for(int j=0;j<n;j++) C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
    return C;
}
Matrix pow(Matrix base,long long exp,int n) {
    Matrix res(n,vector<long long>(n));
    for(int i=0;i<n;i++) res[i][i]=1;
    while(exp>0) {
        if(exp%2) res=mul(res,base,n);
        base=mul(base,base,n);
        exp/=2;
    }
    return res;
}
int main() {
    int n;
    long long k;
    cin>>n>>k;
    Matrix A(n,vector<long long>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>A[i][j];
    Matrix res=pow(A,k,n);
    long long tot=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) tot=(tot+res[i][j])%MOD;
    cout<<tot<<"\n";
}