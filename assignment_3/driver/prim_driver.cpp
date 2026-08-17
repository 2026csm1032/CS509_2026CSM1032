#include<bits/stdc++.h>
#include "../src/prim.h"
#include "../../assignment_1/src/csr.h"
using namespace std;

void writeResultToFile(ofstream& fout,
vector<pair<pair<int,int>,int>>& mstEdges,
long long totalWeight,
double executionTime){

    fout<<"MST edges:\n";

    for(auto edge:mstEdges){

        fout<<edge.first.first<<" "
            <<edge.first.second<<" "
            <<edge.second<<"\n";
    }

    fout<<"\n";

    fout<<"Total MST weight: "
        <<totalWeight
        <<"\n\n";

    fout<<"Execution Time: "
        <<executionTime
        <<" ms\n";
}
int main(int argc,char* argv[]){

    if(argc!=2){

        cout<<"Usage: ./prim input_file\n";
        return 0;
    }

    string filePath="./tests/";
    filePath+=argv[1];

    ifstream fin(filePath);

    if(!fin){

        cout<<"Input file not found\n";
        return 0;
    }

    int V,E;
    fin>>V>>E;

    vector<vector<pair<int,int>>> adj(V);

    for(int i=0;i<V;i++){

        int u,degree;

        fin>>u>>degree;

        for(int j=0;j<degree;j++){
            int v,wt;
            fin>>v>>wt;
            adj[u].push_back({v,wt});
        }
    }

    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> weights;

    convertToCSR(adj,row_ptr,col_idx,weights);

    auto start=chrono::high_resolution_clock::now();

    auto result=primMST(V,row_ptr,col_idx,weights);

    auto end=chrono::high_resolution_clock::now();

    double executionTime=chrono::duration<double,milli>(end-start).count();

    string outputFile="./outputs/prim_output_"+string(argv[1]);

    ofstream fout(outputFile);

    fout<<"Algorithm: Prim's MST\n\n";

    if(result.second.size()!=V-1){

    fout<<"Invalid Input Graph\n";
    fout<<"Graph is not connected\n\n";
    fout<<"Execution Time: "<<executionTime<<" ms\n";


    }

    else{
        writeResultToFile(fout,result.second,result.first,executionTime);
    }

    fout.close();

    cout<<"Output written to: "<<outputFile<<"\n";

    return 0;
}