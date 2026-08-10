#include<bits/stdc++.h>
#include "../src/bellman_ford.h"
#include "../../assignment_1/src/csr.h"
using namespace std;

void writeResultToFile(ofstream& fout,int source,vector<long long>& dist,bool negativeCycle,double executionTime){

    fout<<"Algorithm: Bellman-Ford\n";
    fout<<"Source: "<<source<<"\n\n";

    if(negativeCycle){

        fout<<"Negative Cycle: true\n";

        fout<<"Execution Time: "<<executionTime<<" ms\n";

        return;
    }

    fout<<"Vertex Distance\n";

    for(int i=0;i<dist.size();i++){

        fout<<i<<" ";

        if(dist[i]==1e18){
            fout<<"INF\n";
        }
        else{
            fout<<dist[i]<<"\n";
        }
    }

    fout<<"\nNegative Cycle: false\n";
    fout<<fixed<<setprecision(12);
    fout<<"Execution Time: "<<executionTime<<" ms\n";
}

int main(int argc,char* argv[]){

    if(argc!=2){
        cout<<"Usage: ./bellman_ford input_file\n";
        return 0;
    }

    string filePath="./tests/bellman_ford/";
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

            int v,w;
            fin>>v>>w;

            adj[u].push_back({v,w});
        }
    }

    string temp;
    int source;

    fin>>temp>>source;

    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> weights;

    convertToCSR(adj,row_ptr,col_idx,weights);

    vector<long long> dist;

    auto start=chrono::high_resolution_clock::now();

    bool negativeCycle=bellmanFord(V,row_ptr,col_idx,weights,source,dist);

    auto end=chrono::high_resolution_clock::now();

    double executionTime=chrono::duration<double,milli>(end-start).count();

    string outputFile="./outputs/bf_output_"+string(argv[1]);

    ofstream fout(outputFile);

    if(!fout){
        cout<<"Unable to create output file\n";
        return 0;
    }

    writeResultToFile(fout,source,dist,negativeCycle,executionTime);

    fout.close();

    cout<<"Output written to: "<<outputFile<<"\n";

    return 0;
}