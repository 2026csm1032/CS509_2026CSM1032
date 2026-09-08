#include<bits/stdc++.h>
#include "../src/vertex_coloring.h"
#include "../../assignment_1/src/csr.h"
using namespace std;

int main(int argc,char* argv[]){

    if(argc!=2){

        cout<<"Usage: vertex_coloring input_file\n";
        return 0;
    }

    string filePath="./tests/vertex_coloring/";
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

    long long edgeCount=0;

    for(int i=0;i<V;i++){

        int u,degree;

        if(!(fin>>u>>degree)){

            cout<<"Invalid input file\n";
            return 0;
        }

        if(u<0 || u>=V){

            cout<<"Invalid vertex id\n";
            return 0;
        }

        for(int j=0;j<degree;j++){

            int v;

            if(!(fin>>v)){

                cout<<"Degree and neighbour count mismatch\n";
                return 0;
            }

            if(v<0 || v>=V){

                cout<<"Invalid vertex id\n";
                return 0;
            }

            if(v==u){

                cout<<"Self loop detected\n";
                return 0;
            }

            adj[u].push_back(v);

            edgeCount++;
        }
    }

    vector<int> row_ptr;
    vector<int> col_idx;

    convertToCSR(adj,row_ptr,col_idx);

    auto start=chrono::high_resolution_clock::now();

    pair<vector<int>,int> result=vertexColoring(V,row_ptr,col_idx);

    auto end=chrono::high_resolution_clock::now();

    double executionTime=chrono::duration<double,milli>(end-start).count();

    string outputFile="./outputs/vertex_coloring_output_"+string(argv[1]);

    ofstream fout(outputFile);

    fout<<"Algorithm: Greedy Vertex Coloring\n\n";

    fout<<"Vertex colors:\n";

    for(int i=0;i<V;i++){

        fout<<i<<" "<<result.first[i]<<"\n";
    }

    fout<<"\nColors used: "<<result.second<<"\n";

    fout<<"\nExecution time: "<<fixed<<setprecision(6)<<executionTime<<" ms\n";

    fout.close();

    cout<<"Output written to: "<<outputFile<<"\n";

    return 0;
}