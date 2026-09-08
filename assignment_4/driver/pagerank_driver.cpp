#include<bits/stdc++.h>
#include "../src/pagerank.h"
#include "../../assignment_1/src/csr.h"
using namespace std;

int main(int argc,char* argv[]){

    if(argc!=2){

        cout<<"Usage: pagerank input_file\n";
        return 0;
    }

    string filePath="./tests/pagerank/";
    filePath+=argv[1];

    ifstream fin(filePath);

    if(!fin){

        cout<<"Input file not found\n";
        return 0;
    }

    int V,E;

    fin>>V>>E;

    if(V<=0){

        cout<<"Invalid input file\n";
        return 0;
    }

    vector<vector<int>> adj(V);

    for(int i=0;i<V;i++){

        int u,outdegree;

        if(!(fin>>u>>outdegree)){

            cout<<"Invalid input file\n";
            return 0;
        }

        if(u<0 || u>=V){

            cout<<"Invalid vertex id\n";
            return 0;
        }

        for(int j=0;j<outdegree;j++){

            int v;

            if(!(fin>>v)){

                cout<<"Degree and neighbour count mismatch\n";
                return 0;
            }

            if(v<0 || v>=V){

                cout<<"Invalid vertex id\n";
                return 0;
            }

            adj[u].push_back(v);
        }
    }

    string keyword;

    double damping;
    double tolerance;
    int maxIterations;

    fin>>keyword>>damping;
    fin>>keyword>>tolerance;
    fin>>keyword>>maxIterations;

    if(damping<=0 || damping>=1){

        cout<<"Invalid damping factor\n";
        return 0;
    }

    if(tolerance<=0){

        cout<<"Invalid tolerance\n";
        return 0;
    }

    if(maxIterations<=0){

        cout<<"Invalid max iterations\n";
        return 0;
    }

    vector<int> row_ptr;
    vector<int> col_idx;

    convertToCSR(adj,row_ptr,col_idx);

    auto start=chrono::high_resolution_clock::now();

    PageRankResult result=pageRank(V,row_ptr,col_idx,damping,tolerance,maxIterations);

    auto end=chrono::high_resolution_clock::now();

    double executionTime=chrono::duration<double,milli>(end-start).count();

    string outputFile="./outputs/pagerank_output_"+string(argv[1]);

    ofstream fout(outputFile);

    fout<<fixed<<setprecision(6);

    fout<<"Algorithm: PageRank\n";
    fout<<"Damping: "<<damping<<"\n\n";

    fout<<"Vertex ranks:\n";

    double rankSum=0.0;

    for(int i=0;i<V;i++){

        fout<<i<<" "<<result.rank[i]<<"\n";

        rankSum+=result.rank[i];
    }

    fout<<"\nSum of ranks: "<<rankSum<<"\n";

    fout<<"Iterations: "<<result.iterations<<"\n";

    fout<<"Converged: "<<(result.converged?"true":"false")<<"\n";

    fout<<"Execution time: "<<executionTime<<" ms\n";

    fout.close();

    cout<<"Output written to: "<<outputFile<<"\n";

    return 0;
}