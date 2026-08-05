#include<bits/stdc++.h>
#include "../src/gemm_simple.h"
#include "../src/gemm_blocking.h"
using namespace std;

void writeResultToFile(ofstream& fout,
                       string algorithm,
                       vector<vector<int>>& mat,
                       double executionTime){

    fout<<"Algorithm: "<<algorithm<<"\n";
    fout<<"Result Matrix:\n";

    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            fout<<mat[i][j]<<" ";
        }
        fout<<"\n";
    }

    fout<<"Execution Time: "
        <<executionTime
        <<" ms\n\n";
}

int main(int argc,char* argv[]){

    if(argc!=2){
        cout<<"Usage: ./gemm input_file\n";
        return 0;
    }

    string filePath="./tests/gemm/";
    filePath+=argv[1];

    ifstream fin(filePath);

    if(!fin){
        cout<<"Input file not found\n";
        return 0;
    }

    int M,K,N;
    fin>>M>>K>>N;

    vector<vector<int>> A(M,vector<int>(K));
    vector<vector<int>> B(K,vector<int>(N));

    for(int i=0;i<M;i++){
        for(int j=0;j<K;j++){
            fin>>A[i][j];
        }
    }

    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++){
            fin>>B[i][j];
        }
    }

    auto start1=chrono::high_resolution_clock::now();
     vector<vector<int>> ans1=gemmSimple(A,B);
   auto end1=chrono::high_resolution_clock::now();


    double gemm_simple_time=chrono::duration<double,milli>(end1-start1).count();

   auto start2=chrono::high_resolution_clock::now();
   vector<vector<int>> ans2=gemmBlocking(A,B,32);
    auto end2=chrono::high_resolution_clock::now();

    double gem_blocking_time=chrono::duration<double,milli>(end2-start2).count();

    string outputFile="./outputs/gemm_output_"+string(argv[1]);
     ofstream fout(outputFile);

    if(!fout){
        cout<<"Unable to create output file\n";
        return 0;   
    }
    writeResultToFile(fout,"GEMM Simple",ans1,gemm_simple_time);

    writeResultToFile(fout,"GEMM Blocking",ans2,gem_blocking_time);
    fout.close();

    cout<<"Output written to: "<<outputFile<<"\n";

    return 0;
}