#include "gemm_blocking.h"

vector<vector<int>> gemmBlocking(vector<vector<int>>& A,vector<vector<int>>& B,int blockSize){
    int m=A.size();
    int k=A[0].size();
    int n=B[0].size();

    vector<vector<int>> C(m,vector<int>(n,0));

    for(int ii=0;ii<m;ii+=blockSize){
        for(int kk=0;kk<k;kk+=blockSize){
            for(int jj=0;jj<n;jj+=blockSize){

                int iEnd=min(ii+blockSize,m);
                int kEnd=min(kk+blockSize,k);
                int jEnd=min(jj+blockSize,n);

                for(int i=ii;i<iEnd;i++){
                    for(int t=kk;t<kEnd;t++){
                        for(int j=jj;j<jEnd;j++){
                            C[i][j]+=A[i][t]*B[t][j];
                        }
                    }
                }
            }
        }
    }

    return C;
}