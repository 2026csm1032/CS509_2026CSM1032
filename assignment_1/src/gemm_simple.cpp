#include "gemm_simple.h"

vector<vector<int>> gemmSimple(vector<vector<int>>& A,vector<vector<int>>& B){
    int m=A.size();
    int k=A[0].size();
    int n=B[0].size();

    vector<vector<int>> C(m,vector<int>(n,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int t=0;t<k;t++){
                C[i][j]+=A[i][t]*B[t][j];
            }
        }
    }

    return C;
}