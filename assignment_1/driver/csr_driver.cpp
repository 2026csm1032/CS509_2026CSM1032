#include<bits/stdc++.h>
#include "../src/csr.h"
using namespace std;

void writeCSRToFile(ofstream& fout,vector<int>& row_ptr,vector<int>& col_idx,double executionTime){

    fout<<"CSR Representation\n\n";

    fout<<"row_ptr:\n";

    for(int x:row_ptr){
        fout<<x<<" ";
    }

    fout<<"\n\n";

    fout<<"col_idx:\n";

    for(int x:col_idx){
        fout<<x<<" ";
    }

    fout<<"\n\n";

    fout<<"Execution Time: "<<executionTime<<" ms\n";
}

int main(int argc,char* argv[]){

    if(argc!=2){
        cout<<"Usage: ./csr test_file\n";
        return 0;
    }

    string filePath="./tests/csr/";
    filePath+=argv[1];

    ifstream fin(filePath);

    if(!fin){
        cout<<"Input file not found\n";
        return 0;
    }

    int V,E;
    fin>>V>>E;

    vector<vector<int>> adj(V);

    for(int i=0;i<V;i++){

        int u,degree;
        fin>>u>>degree;

        for(int j=0;j<degree;j++){

            int v;
            fin>>v;

            adj[u].push_back(v);
        }
    }

    fin.close();

    vector<int> row_ptr;
    vector<int> col_idx;

    auto start=chrono::high_resolution_clock::now();

    convertToCSR(adj,row_ptr,col_idx);

    auto end=chrono::high_resolution_clock::now();

    double execution_time=
        chrono::duration<double,milli>(end-start).count();

    string outputFile="./outputs/csr_output_"+string(argv[1]);

    ofstream fout(outputFile);

    if(!fout){
        cout<<"Unable to create output file\n";
        return 0;
    }

    writeCSRToFile(fout,row_ptr,col_idx,execution_time);

    fout.close();

    cout<<"Output written to: "<<outputFile<<"\n";

    return 0;
}