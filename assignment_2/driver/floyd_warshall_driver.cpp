#include<bits/stdc++.h>
#include "../src/floyd_warshall.h"
using namespace std;

void writeResultToFile(ofstream& fout,vector<vector<long long>>& dist,bool negativeCycle,double executionTime){

    fout<<"Algorithm: Floyd-Warshall\n\n";

    if(negativeCycle){
        fout<<"Negative Cycle: true\n";
        fout<<"Execution Time: "<<executionTime<<" ms\n";
        return;
    }

    fout<<"Distance Matrix:\n";

    for(int i=0;i<dist.size();i++){

        for(int j=0;j<dist[i].size();j++){

            if(dist[i][j]==1e18){
                fout<<"INF ";
            }
            else{
                fout<<dist[i][j]<<" ";
            }
        }

        fout<<"\n";
    }

    fout<<"\nNegative Cycle: false\n";

    fout<<"Execution Time: "<<executionTime<<" ms\n";
}

int main(int argc,char* argv[]){

    if(argc!=2){
        cout<<"Usage: ./floyd_warshall input_file\n";
        return 0;
    }

    string filePath="./tests/floyd_warshall/";
    filePath+=argv[1];

    ifstream fin(filePath);

    if(!fin){
        cout<<"Input file not found\n";
        return 0;
    }

    int V;
    fin>>V;

    long long INF=1e18;

    vector<vector<long long>> dist(V,vector<long long>(V));

    for(int i=0;i<V;i++){

        for(int j=0;j<V;j++){

            string x;
            fin>>x;

            if(x=="INF"){
                dist[i][j]=INF;
            }
            else{
                dist[i][j]=stoll(x);
            }
        }
    }

    auto start=chrono::high_resolution_clock::now();

    bool negativeCycle=floydWarshall(dist);

    auto end=chrono::high_resolution_clock::now();

    double executionTime=chrono::duration<double,milli>(end-start).count();

    string outputFile="./outputs/fw_output_"+string(argv[1]);

    ofstream fout(outputFile);

    if(!fout){
        cout<<"Unable to create output file\n";
        return 0;
    }

    writeResultToFile(fout,dist,negativeCycle,executionTime);

    fout.close();

    cout<<"Output written to: "<<outputFile<<"\n";

    return 0;
}